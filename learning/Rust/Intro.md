- Rust fastest after C
- **No garbage collector** (faster runtime) 
- Guarantees memory safety
- Concurrent programming
- 

- Functions are declared using fn
- println is used to print to the stout
### Variables 
- assigned using let
- Variables can be re declared in the same scope with the same name using shadowing
- if a variable is not being Uninitialized but also unused rust generates a warning and to avoid it we can prefix it with an underscore
```rust
fn main() {
    let x: i32; // Uninitialized but used, ERROR !
    let y: i32; // Uninitialized but also unused, only a Warning !
    let _y1: i32; // Uninitialized but also unused, But no warning !
    assert_eq!(x, 5);
    println!("Success!");
}
```
- Variables in rust are immutable and we have to mark them as mut to make them mutable
```rust
fn main(){
	let mut x : i32 = 1;
	x = x + 2;
	println!("Success")
}
```

**Char** : Character of 4 bytes
**Unit** : Empty tuple of size 0 bytes used to return "nothing in expressions or function"

#### Constants
- Should be annotated
- Are constants set in compile time

### Shadowing
You can declare a new variable with the same name as a previous variable.
Basically the second variable overshadows the first variable.
```rust
fn main() 
{ 
	let spaces = " ";
	let spaces = spaces.len()
}
```

In the above code the type of spaces is different, so what is happening is that when I wrote the 2nd line I am creating a new variable with the same name and it shadows the variable before if I had return it in a scope that shadowing would have ended after the scope.

#### Data Types
Two types of datatypes : **Scalar** and **Compound**

**Scalar**
A _scalar_ type represents a single value. Rust has four primary scalar types: integers, floating-point numbers, Booleans, and characters

So let's say you defined a variable with data type i8 ; which means it can range from 0 - 255. so when it overflows two things may happen
case 1 : Debug Mode - It causes a panic at runtime (basically error)
case 2 : Release Mode - It wraps around the value i.e. 257 becomes 1

**Compound**
_Compound types_ can group multiple values into one type. Rust has two primitive compound types: tuples and arrays.
- Tuples
	- Have fixed value
	- Can store variety of types
	*The tuple without any values has a special name, **unit**. This value and its corresponding type are both written `()` and represent an empty value or an empty return type. Expressions implicitly return the unit value if they don’t return any other value.*

Arrays allocate data on stack

#### Functions
```rust
fn main() { 
	let x = plus_one(5); 
	println!("The value of x is: {x}"); 
} 

fn plus_one(x: i32) -> i32 { 
	x + 1 
}
```
#### Control Flow

#### [Returning Values from Loops](https://doc.rust-lang.org/book/ch03-05-control-flow.html#returning-values-from-loops)

One of the uses of a `loop` is to retry an operation you know might fail, such as checking whether a thread has completed its job. You might also need to pass the result of that operation out of the loop to the rest of your code. To do this, you can add the value you want returned after the `break` expression you use to stop the loop; that value will be returned out of the loop so you can use it, as shown here:

```rust
fn main() {     
	let mut counter = 0;      
	let result = loop {         
		counter += 1;          
		if counter == 10 {             
			break counter * 2;         
			}     
		};      
	println!("The result is {result}"); }
```
#### [Loop Labels to Disambiguate Between Multiple Loops](https://doc.rust-lang.org/book/ch03-05-control-flow.html#loop-labels-to-disambiguate-between-multiple-loops)

#### Ownership
Rules
- Each value in rust must have an *owner*.
- There can only be one owner at a time
- When the owner goes out of scope, the value gets dropped.

Note: In C++, this pattern of deallocating resources at the end of an item’s lifetime is sometimes called _Resource Acquisition Is Initialization (RAII)_

Rust takes a different path: the memory is automatically returned once the variable that owns it goes out of scope. Here’s a version of our scope example from Listing 4-1 using a `String` instead of a string literal:

```rust
{         
	let s = String::from("hello"); // s is valid from this point forward                                             // do stuff with s     
}                             // this scope is now over, and s is no longer valid
```

There is a natural point at which we can return the memory our `String` needs to the allocator: when `s` goes out of scope. When a variable goes out of scope, Rust calls a special function for us. This function is called [`drop`](https://doc.rust-lang.org/std/ops/trait.Drop.html#tymethod.drop), and it’s where the author of `String` can put the code to return the memory. Rust calls `drop` automatically at the closing curly bracket.


Let's say I create a string s1
```rust
    let s1 = String::from("hello");
    let s2 = s1;
```
Rust stores this data on the heap and String is made of 3 parts
![[Pasted image 20231109114519.png]]
The length is how much memory, in bytes, the contents of the `String` are currently using. The capacity is the total amount of memory, in bytes, that the `String` has received from the allocator.

let's say now we assign s1 to s2. we then don't copy the data on the heap that the pointer refers to. we copy the pointer.
![[Pasted image 20231109114649.png]]

But the problem is now that
when a variable goes out of scope rust calls the drop function and cleans up the heap memory for that variable. but in this case when both s1 and s2 go out of scope the same Rust will try to free up the same memory. This is known as a _double free_ error and is one of the memory safety bugs we mentioned previously. Freeing memory twice can lead to memory corruption, which can potentially lead to security vulnerabilities.

To ensure memory safety, after the line `let s2 = s1;`, Rust considers `s1` **as no longer valid.** Therefore, Rust doesn’t need to free anything when `s1` goes out of scope. Check out what happens when you try to use `s1` after `s2` is created; it won’t work:
If you’ve heard the terms _shallow copy_ and _deep copy_ while working with other languages, the concept of copying the pointer, length, and capacity without copying the data probably sounds like making a shallow copy. But because Rust also invalidates the first variable, instead of being called a shallow copy, it’s known as a _move_. In this example, we would say that `s1` was _moved_ into `s2`.
#### Reading from the input
```rust

use std::io::{Write}

fn main(){
	let mut name;
	io::stdin().read_line(&mut name).expect("Didn't receive name")

}
```

### Options
Sometimes it's desirable to catch the failure of some parts of a program instead of calling `panic!`; this can be accomplished using the `Option` enum.

The `Option<T>` enum has two variants:

- `None`, to indicate failure or lack of value, and
- `Some(value)`, a tuple struct that wraps a `value` with type `T`.

```rust
// An integer division that doesn't `panic!`
fn checked_division(dividend: i32, divisor: i32) -> Option<i32> {
    if divisor == 0 {
        // Failure is represented as the `None` variant
        None
    } else {
        // Result is wrapped in a `Some` variant
        Some(dividend / divisor)
    }
}

// This function handles a division that may not succeed
fn try_division(dividend: i32, divisor: i32) {
    // `Option` values can be pattern matched, just like other enums
    match checked_division(dividend, divisor) {
        None => println!("{} / {} failed!", dividend, divisor),
        Some(quotient) => {
            println!("{} / {} = {}", dividend, divisor, quotient)
        },
    }
}

fn main() {
    try_division(4, 2);
    try_division(1, 0);

    // Binding `None` to a variable needs to be type annotated
    let none: Option<i32> = None;
    let _equivalent_none = None::<i32>;
    let optional_float = Some(0f32);

    // Unwrapping a `Some` variant will extract the value wrapped.
    println!("{:?} unwraps to {:?}", optional_float, optional_float.unwrap());

    // Unwrapping a `None` variant will `panic!`
    println!("{:?} unwraps to {:?}", none, none.unwrap());
}
```

#### Result

Option is used to return value where as Result is used to return value or Error
The `Result<T, E>` enum has two variants:

- `Ok(value)` which indicates that the operation succeeded, and wraps the `value` returned by the operation. (`value` has type `T`)
- `Err(why)`, which indicates that the operation failed, and wraps `why`, which (hopefully) explains the cause of the failure. (`why` has type `E`)

```rust
pub fn div(x: f64, y: f64) -> MathResult {
        if y == 0.0 {
            // This operation would `fail`, instead let's return the reason of
            // the failure wrapped in `Err`
            Err(MathError::DivisionByZero)
        } else {
            // This operation is valid, return the result wrapped in `Ok`
            Ok(x / y)
        }
    }
fn op(x: f64, y: f64) -> f64 {
    match div(x, y) {
        Err(why) => panic!("{:?}", why),
        Ok(ratio) => ratio,
    }
}
fn main() {
    // Will this fail?
    println!("{}", op(1.0, 10.0));
}

```

### Generics
We use generics to create definitions for items like function signatures or structs, which we can then use with many different concrete data types

```rust
fn largest<T>(list: &[T]) -> &T {
```

We read this definition as: the function `largest` is generic over some type `T`. This function has one parameter named `list`, which is a slice of values of type `T`. The `largest` function will return a reference to a value of the same type `T`.

### [Performance of Code Using Generics](https://doc.rust-lang.org/book/ch10-01-syntax.html#performance-of-code-using-generics)

You might be wondering whether there is a runtime cost when using generic type parameters. The good news is that using generic types won't make your program run any slower than it would with concrete types.

Rust accomplishes this by performing monomorphization of the code using generics at compile time. _Monomorphization_ is the process of turning generic code into specific code by filling in the concrete types that are used when compiled. In this process, the compiler does the opposite of the steps we used to create the generic function in Listing 10-5: the compiler looks at all the places where generic code is called and generates code for the concrete types the generic code is called with.
#### Structs

#### Iterators

### Conditional expressions 

### Match

### arrays

### Loops
```rust
fn main() {
    println!("Hello, world!");
    // While loops
    let mut x = 0;

    while x < 10 {
        println!("x is {}", x);
        x += 1;
    }

    // For loops
    for x in 0..10 {
        println!("x is {}", x);
    }

    // loop
    let mut x = 0;
    loop {
        println!("x is {}", x);
        x += 1;
        if x == 10 {
            break;
        }
    }
}
```

### Tuple

### String
We have two types of string
- **String** : Vector of bytes that can be changed
- **&str** : reference , points to a string

### Vectors
### Slices

### Generics

### Hashmaps

### Match 
- Some


### Traits

A _trait_ defines functionality a particular type has and can share with other types. We can use traits to define shared behavior in an abstract way. We can use _trait bounds_ to specify that a generic type can be any type that has certain behavior.

We want to make a media aggregator library crate named `aggregator` that can display summaries of data that might be stored in a `NewsArticle` or `Tweet` instance. To do this, we need a summary from each type, and we’ll request that summary by calling a `summarize` method on an instance. Listing 10-12 shows the definition of a public `Summary` trait that expresses this behavior.

```rust
pub trait Summary {    
	fn summarize(&self) -> String; 
}
```

**Implementation of Traits**
```rust
pub struct NewsArticle 
{ 
	pub headline: String, 
	pub location: String, 
	pub author: String, 
	pub content: String, 
} 

impl Summary for NewsArticle { 
	fn summarize(&self) -> String { 
		format!("{}, by {} ({})", self.headline, self.author, self.location) 
	} 
}
```

