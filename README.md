# StoryScript

StoryScript is a story-themed programming language and compiler built with Flex and Bison. It lets you write programs in a narrative style while still using familiar programming concepts such as variables, arithmetic, conditions, loops, functions, input, and output.

## Project Overview

The compiler reads a StoryScript source file, builds an abstract syntax tree, checks syntax and basic semantic rules, executes the program, and generates target code for one of four languages:

- C
- C++
- Java
- Python

The language is designed around readable story-like keywords. For example, programs begin with `story`, use `character` for declarations, `narrate` for output, `listen` for input, `when` / `otherwise` for branching, `during` for loops, and `chapter` for functions.

## Features

- Variable declarations and assignments
- Arithmetic expressions and logical conditions
- Conditional branching
- Looping constructs
- Function definitions and function calls
- Console input and output
- AST printing, symbol table tracking, and target code generation

## Running

The compiler can read from a file passed on the command line or from standard input. When it starts, it asks you to choose a target language, then parses and processes the StoryScript program.

Example input:

```storyscript
story Basic begins

character a holds 5;
narrate a;

end story
```

## Language Notes

- Programs must start with `story <name> begins` and end with `end story`.
- Statements are separated with semicolons.
- Function definitions use `chapter ... takes ... return ... end chapter`.
- Conditions support comparison and logical operators such as `==`, `!=`, `>`, `<`, `>=`, `<=`, `and`, `or`, and `not`.
