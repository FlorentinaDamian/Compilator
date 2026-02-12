# Mini C++ Compiler

A compiler for a simplified C++-like language, implemented in C++ using Flex and Bison.
The project implements the classical stages of a compiler: lexical analysis, syntax analysis, semantic analysis, and Abstract Syntax Tree (AST) construction.

## Descriere

The implemented language is a simplified C++-like language that supports:
  -Integer, float, string, and boolean variables
  -Arithmetic operations (+, -, *, /)
  -Boolean operations (==, <=, >=, <, >, and, or, !)
  -Control structures: if, while, for, do...while
  -Variable assignments

This compiler analyzes source programs written in this language and verifies both syntactic and semantic correctness.

Compiler Components

The project includes:
  - Lexical Analysis (Flex)
  - Syntax Analysis (Bison)
  - Abstract Syntax Tree (AST) Construction
  - Symbol Table Implementation
  - Syntactic and Semantic Error Detection

---
##  Arhitectură

| Fișier | Descriere |
|--------|------------|
| `parser.l` | Token definitions (Flex lexer) |
| `parser.y` | Grammar rules (Bison parser) |
| `ASTNode.*` | Abstract Syntax Tree implementation |
| `SymTable.*` | Symbol Table implementation |
| `Value.h` | Value handling |
| `compile.sh` | Build script |
| `test.txt` | Example input |
| `test_corect.txt` | Valid program |
| `test_incorect.txt` | Program containing errors |


---
##  Technologies Used

- C++
- Object-Oriented Programming (OOP)
- Flex (Lexical Analyzer Generator)
- Bison (Parser Generator)
- STL (Standard Template Library)
- GCC / G++
- Bash (build script)

## Build & Run

### Build

```bash
chmod +x compile.sh
```

### Run
```bash
./compile.sh
```
