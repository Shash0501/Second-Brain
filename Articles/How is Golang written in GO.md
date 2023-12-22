- Go compiler is written in Go itself

#### Bootstrapping Process
- It is done using a process called bootstraping.
- It is the process of building a compiler for a language using an existing compiler for that language or another language.

### Steps
- Initially Go developed the language with bootstrap compiler written in C
- This compiler only compiled a minimal subset of Go code
- The subset of Go code compiled by the C compiler included just enough to implement a basic Go runtime and a simple garbage collector.
- From now onwards the team began to write the compiler in go itself 
