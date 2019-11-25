# Sebastian Lopez and Jorge Chaux Simple Shell
![Simple_shell](https://s3.amazonaws.com/intranet-projects-files/holbertonschool-low_level_programming/235/shell.jpeg "Simple_shell")

**Table of Contents**

[TOCM]

[TOC]
### Name
simple_shell
### Description
simple_shell is an emulation of UNIX command interpreter.
### Overview
As an emulation, the simple_shell is a command that reads lines from either a file or the terminal, interprets them, and generally executes other commands.
### Invocation
 If no args are present and if the standard input of the shell is connected  to  a terminal the shell is considered an interactive shell.
 
An  interactive  shell generally prompts before each command and handles programming and command errors differently.

This was done as an exercise for [Holberton School](https://www.holbertonschool.com/)
## Learning Objectives
### General
- Who designed and implemented the original Unix operating system
- Who wrote the first version of the UNIX shell
- Who invented the B programming language (the direct predecessor to the C programming language)
- Who is Ken Thompson
- How does a shell work
- What is a pid and a ppid
- How to manipulate the environment of the current process
- What is the difference between a function and a system call
- How to create processes
- What are the three prototypes of main
- How does the shell use the PATH to find the programs
- How to execute another program with the execve system call
- How to suspend the execution of a process until one of its children terminates
- What is EOF / end-of-file?

## Requirements
### General
- Allowed editors: vi, vim, emacs
- All your files will be compiled on Ubuntu 14.04 LTS
- Your C programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
- All your files should end with a new line
- A README.md file, at the root of the folder of the project is mandatory
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- No more than 5 functions per file
- All your header files should be include guarded
- Use system calls only when you need to (why?)
## More Info
### Output
- Unless specified otherwise, your program must have the exact same output as sh (/bin/sh) as well as the exact same error output.
- The only difference is when you print an error, the name of the program must be equivalent to your argv[0] (See below)

Example of error with sh:

    $ echo "qwerty" | /bin/sh
    /bin/sh: 1: qwerty: not found
    $ echo "qwerty" | /bin/../bin/sh
    /bin/../bin/sh: 1: qwerty: not found
    $
Same error with your program hsh:


    $ echo "qwerty" | ./hsh
    ./hsh: 1: qwerty: not found
    $ echo "qwerty" | ./././hsh
    ./././hsh: 1: qwerty: not found
    $

### List of allowed functions and system calls

- access (man 2 access)
- chdir (man 2 chdir)
- close (man 2 close)
- closedir (man 3 closedir)
- execve (man 2 execve)
- exit (man 3 exit)
- _exit (man 2 _exit)
- fflush (man 3 fflush)
- fork (man 2 fork)
- free (man 3 free)
- getcwd (man 3 getcwd)
- getline (man 3 getline)
- isatty (man 3 isatty)
- kill (man 2 kill)
- malloc (man 3 malloc)
- open (man 2 open)
- opendir (man 3 opendir)
- perror (man 3 perror)
- read (man 2 read)
- readdir (man 3 readdir)
- signal (man 2 signal)
- stat (__xstat) (man 2 stat)
- lstat (__lxstat) (man 2 lstat)
- fstat (__fxstat) (man 2 fstat)
- strtok (man 3 strtok)
- wait (man 2 wait)
- waitpid (man 2 waitpid)
- wait3 (man 2 wait3)
- wait4 (man 2 wait4)
- write (man 2 write)

### Compilation
Your shell will be compiled this way:

    gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

### Testing
Your shell should work like this in interactive mode:

     $ ./hsh
     ($) /bin/ls
      hsh main.c shell.c
      ($)
      ($) exit
       $

But also in non-interactive mode:

    $ echo "/bin/ls" | ./hsh
    hsh main.c shell.c test_ls_2
    $
    $ cat test_ls_2
    /bin/ls
    /bin/ls
    $
    $ cat test_ls_2 | ./hsh
    hsh main.c shell.c test_ls_2
    hsh main.c shell.c test_ls_2
    $
### Included files
The following files contain different functions that where used:
- allowed_library.c
- environ.c
- executer_tools.c
Functions to execute a line.
- holberton.h
- list_tools.c
- main.c
- parser_tools.c 
Contain functions to read a line, replace a new line, find the lengt of a token and process tokens.
- shell_loop.c 
Main shell function
- string-tools.c
Contain functions to manage strings

### Credits
Code written by [Sebastian Lopez](https://github.com/sebas119/) and [Jorge Chaux](https://github.com/jorgechauxjr/) 