Tog get input from user we use a library `std::io`

```rust
use std::io;

fn main() {
    println!("Please input your guess.");

    let mut guess = String::new();

    io::stdin()
        .read_line(&mut guess)
        .expect("Failed to read line");

    println!("You guessed: {guess}");
}
```

`let apples = 5;`
- This creates a new variable named apples and binds it to the value 5
- Variables are immutable by default
- Add mut before to make it mutable

**Associated function** is a function that's implemented on a type
In the above case ***new*** is an associated function of the ***String*** type
We can call the associated functions by using **::**

References are immutable by default hence we need to write `&mut guess` to make it immutable rather than `&guess`

read_line appends the data into the given string rather than overwriting its contents.

read_line returns a `Result` which is an enumeration.

`Result` - variants are `Ok` and `Err`. The `Ok` variant indicated the operation was usccessful and the `Ok` variables has the successfully generated value and the `Err` variant means the operation failed and `Err` contains information about how or why the operation failed

Except is a method of result and it return value for Ok and it will cause the program to crash and disply the message that we passed as an argument

A _crate_ is the smallest amount of code that the Rust compiler considers at a time. Even if you run `rustc` rather than `cargo` and pass a single source code file, the compiler considers that file to be a crate.

Library crates contain code which is intended to be used in other programs and can't be executed on own

When you _do_ want to update a crate, Cargo provides the command `update`, which will ignore the _Cargo.lock_ file and figure out all the latest versions that fit your specifications in _Cargo.toml_

by default, Cargo will only look for versions greater than 0.8.5 and less than 0.9.0. If the `rand` crate has released the two new versions 0.8.6 and 0.9.0, you would see the following if you ran `cargo update`:
```rust
$ cargo update 
	Updating crates.io index 
	Updating rand v0.8.5 -> v0.8.6
```
Cargo ignores the 0.9.0 release. At this point, you would also notice a change in your _Cargo.lock_ file noting that the version of the `rand` crate you are now using is 0.8.6. To use `rand` version 0.9.0 or any version in the 0.9._x_ series, you’d have to update the _Cargo.toml_ file to look like this instead:

```toml
[dependencies] 
rand = "0.9.0"
```
