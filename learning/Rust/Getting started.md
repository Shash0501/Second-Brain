Running a rust program
`rustc main.rs`

What is the difference between `println!` and `println`
Basically the first one calls a macro and second one calls function (Add links)

When you compile a rust program in windows a .pdb file is also generated along with a .exe file

This file is a program database file and contains debugging information produced by compilers


### Cargo

It is rust's build system and package manager
TOML - Tom's obvious minimal language

- We can create project with cargo- `cargo new <project_name>`
- We can create a project using `cargo new`.
- We can build a project using `cargo build`.
- We can build and run a project in one step using `cargo run`.
- We can build a project without producing a binary to check for errors using `cargo check`.

