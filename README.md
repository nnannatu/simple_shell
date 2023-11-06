# Simple Shell Project

## Description

This is a simple UNIX command interpreter project developed by Geofrey Ochieng and Nnanna Atu as part of the ALX School Software Engineering program. The project aims to create a custom shell that can interpret and execute UNIX commands and handle various shell features, built-in commands, logical operators, and more.

## Project Timeline

- Start Date: November 1, 2023, 6:00 AM
- End Date: November 16, 2023, 6:00 AM
- Checker Release: November 15, 2023, 1:12 AM

## Background Context

This project is a significant challenge designed to test your skills and knowledge in programming, C, problem-solving, group work, and learning how to learn. It is essential to follow ALX SE's principles of learning and avoid copying or looking at other people's code, online articles, or videos.

## Learning Objectives

By the end of this project, you are expected to understand the following concepts:

- General UNIX knowledge
- Basics of C programming
- Basics of thinking like an engineer
- Group work and collaboration
- How a shell works
- Process IDs (PID) and Parent Process IDs (PPID)
- Environment manipulation
- The difference between functions and system calls
- Creating processes
- Working with PATH to find programs
- Executing programs with the execve system call
- Process suspension
- Understanding EOF (End-of-File)

## Requirements

- Allowed editors: vi, vim, emacs
- Code compilation on Ubuntu 20.04 LTS using gcc with specific options
- All code files should end with a new line
- A mandatory README.md file at the root of the project folder
- Follow the Betty style for code formatting
- Ensure no memory leaks in your shell
- Limit functions per file to no more than 5
- Use include guards in header files
- Use system calls only when necessary
- Include an AUTHORS file listing contributors
- Collaboration through a single project repository

## Output

The project should have the same output and error messages as the `/bin/sh` (standard UNIX shell). When an error is displayed, ensure the program name is equivalent to `argv[0]`.

## Allowed Functions and System Calls

The project allows the use of a specific set of functions and system calls (see [List of allowed functions and system calls](#list-of-allowed-functions-and-system-calls)).

## Compilation

To compile your shell, use the following command:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

