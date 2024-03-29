<div align = center>

# Get Next Line: A C function that reads any valid file line by line until the end

[![Norminette and Build](https://github.com/mendes-jv/get-next-line/actions/workflows/main.yml/badge.svg)](https://github.com/mendes-jv/get-next-line/actions/workflows/main.yml)
![42 São Paulo](https://img.shields.io/badge/42-SP-1E2952)
![License](https://img.shields.io/github/license/mendes-jv/get-next-line?color=dark-green)
![Code size in bytes](https://img.shields.io/github/languages/code-size/mendes-jv/get-next-line?color=dark-green)
![Top language](https://img.shields.io/github/languages/top/mendes-jv/get-next-line?color=dark-green)
![Last commit](https://img.shields.io/github/last-commit/mendes-jv/get-next-line?color=dark-green)

</div>

## Index:

* [Grade](#grade)
* [Description](#description)
* [How to execute](#how-to-execute)

## Grade:

<div align = center>

![](https://game.42sp.org.br/static/assets/achievements/get_next_linem.png)

[![jovicto2's 42 get_next_line Score](https://badge42.vercel.app/api/v2/clj244ax4006908l8zkjw830s/project/3105573)](https://github.com/JaeSeoKim/badge42)

</div>

## Description:

Get Next Line is the second project at 42 and it's a C function that returns a line, read from a file descriptor. In short, it can read any valid file and does that line by line to optimize memory, since the file size is not known. It's an extremely useful function that can be used in following school's projects.

## The project:

The line is, by definition, a string ending in "\n" (line break) or "EOF" (to the end of the file) and which, according to the subject, must be read in a buffer of a size defined in the compilation. get_next_line runs the read function and stores what was read during the call, only then it looks for a "\n" - when it finds it, we know we've reached the end of the line; if it doesn't find the "\n" but read returns 0, we know that there is nothing ahead to be read (EOF); in other cases, we simply do not reach the end of the line and what was read is stored in the line that will be returned, as we continue reading the file. Most of the time, the buffer does not match the exact size of the line and it is also not possible to read the same stretch of the line two times. This creates one of the biggest problems in the development of get_next_line: what happens in the cases where, for example, the BUFFER_SIZE is 10 and the line ends at the 6th character? The 4 characters remaining after the line break would be lost and reading would continue into the next 10 character buffer. But not in our implementation, as we solve this using a static variable.

## How to execute:

First, clone this repository and `cd` into it:

```zsh
git clone https://github.com/mendes-jv/get-next-line && cd get-next-line
```

To use the function in your code, simply include its header:

```zsh
#include "get_next_line.h"
```

Or, if you want to test the bonus version of the functions (it's the same functions but it can read multiple files in this version):

```sh
#include "get_next_line_bonus.h"
```

Now, when compiling your code, add the source files and the required flag:   

```sh
[gcc | cc | clang] [flags] -D BUFFER_SIZE=[any number > 0] src/mandatory/get_next_line.c src/mandatory/get_next_line_utils.c && ./a.out
```
Or, if you want to compile the bonus files:

```sh
[gcc | cc | clang] [flags] -D BUFFER_SIZE=[any number > 0] src/bonus/get_next_line_bonus.c src/bonus/get_next_line_utils_bonus.c && ./a.out
```

You can test the function with the files provided by me in this respository using:

```sh
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=42 src/mandatory/get_next_line.c src/mandatory/get_next_line_utils.c src/main.c && ./a.out
```
Or

```sh
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=42 src/bonus/get_next_line_bonus.c src/bonus/get_next_line_utils_bonus.c src/main.c && ./a.out
```
This functions is also avaliable to use at my other 42 project called [Libft](https://github.com/mendes-jv/libft).
