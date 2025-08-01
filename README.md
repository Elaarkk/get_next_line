[README.md](https://github.com/user-attachments/files/21548261/README.md)

# get_next_line

Get Next Line is a 42 school project where you have to implement a function in C that reads a file or input one line at a time.
Each call to the function returns the next line, until the end of the file is reached.

The project focuses on precise memory management, buffer handling, and smart partial reading. It comes with strict requirements, such as:

- Only using ````read()```` to perform reading operations
- Not using standard line-reading functions like ````fgets()```` or ````getline()````
- Properly handling large files or very long lines
- Supporting multiple file descriptors simultaneously


## Installation & Usage

This function is not a standalone program — it must be included and compiled as part of another project.

Don't forget to include the header in your source file:

````#include "get_next_line.h"````

To compile your project with the standard version of ````get_next_line````:

````gcc -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c main.c -o my_program````

Replace main.c with your own file containing a main() function.
You can adjust BUFFER_SIZE depending on your needs.

To add bonus version, just add ````_bonus```` at the end of ````get_next_line```` files.
