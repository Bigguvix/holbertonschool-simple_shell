# Holbertonschool simple shell.

In this repository we'll be programming a simple shell.

## Requirements:

### General:
- Allowed editors: `vi, vim, emacs`

- All your files will be compiled on Ubuntu 20.04 LTS using `gcc` , using the options `Wall -Werror -Wextra -pedantic -std=gnu89`

- All your files should end with a new line

- A README.md file, at the root of the folder of the project is mandatory

- Your code should use the Betty style. It will be checked using [betty-style.pl](https://github.com/hs-hq/Betty/blob/main/betty-style.pl) and [betty-doc.pl](https://github.com/hs-hq/Betty/blob/main/betty-doc.pl)

- Your shell should not have any memory leaks

- No more than 5 functions per file

- All your header files should be include guarded

- Use system calls only when you need to ([why?](https://www.quora.com/Why-are-system-calls-expensive-in-operating-systems))

### GitHub

There should be one project repository per group. If you clone/fork/whatever a project repository with the same name before the second deadline, you risk a 0% score.

## What is a Shell?

A Unix shell is a command-line interpreter or shell that provides a command line user interface for Unix-like operating systems. The shell is both an interactive command language and a scripting language, and is used by the operating system to control the execution of the system using shell scripts.

Generally, a shell is a program that executes other programs in response to text commands. A sophisticated shell can also change the environment in which other programs execute by passing named variables, a parameter list, or an input source.
## Flow Chart:

![Alt text](https://i.postimg.cc/HnckD8bc/609bd8d4-a0f8-4d75-83cb-80fc83db7696.jpg)


## Installation:

### Requierments:

- O.S.:`Ubuntu 20.04 LTS`

- Compiler: `GCC 4.8.4`

### Cloning:

If you want to test the shell yourself, you should clone this reposotory, to do so, you have this methods:

#### HTTPS

- `git clone https://github.com/Bigguvix/holbertonschool-simple_shell.git`

#### SSH

- `git clone git@github.com:Bigguvix/holbertonschool-simple_shell.git`
    
## Testing:

- interactive mode:

If git is not already installed on your terminal:

```javascript
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
- non-interactive mode:

```javascript
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
```


## Authors
- [@Bigguvix](https://www.github.com/Bigguvix)
- [@Mazionach](https://github.com/Mazionach)


