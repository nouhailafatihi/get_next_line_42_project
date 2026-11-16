*This project has been created as part of the 42 curriculum by nfatihi.*

# Get Next Line

## Description
The `get_next_line` project is a programming challenge at 42 that introduces the concept of static variables and file descriptors in C. The main goal is to write a function that returns a single line read from a file descriptor, ending with a newline character (`\n`), each time it is called—effectively allowing you to read a text file line by line until the end of the file (EOF) is reached.

Under the hood, the program efficiently manages memory and buffers of a user-defined size (`BUFFER_SIZE`). Because a single `read()` call might pull in multiple lines or partial lines, get_next_line uses a static variable to store leftover characters between function calls, ensuring that no data is lost and lines are parsed accurately regardless of how large or small the `BUFFER_SIZE` is.

This project introduces us to advanced C concepts such as:
* Dynamic memory allocation (`malloc` and `free`).
* File descriptors and read operation (`read()`).
* Static variables to retain state between function calls.

### Features
- **Reads by Buffer Size:** Reads from the file based on the given `buffer size` (less or more than one line), returning one line at a time.
- **Saves Leftovers:** Keeps the leftover data in a static variable between calls, repeating the process until we reach the end of the file.
- **Multiple Files (Bonus):** Manages multiple files at the same time by using an array of strings as a static variable, so for each file descriptor (`fd`), we keep what we read from it in its own string from the array.
- **Memory Management:** Carefully allocates, joins, and frees memory to prevent leaks.

#### Instructions
`get_next_line` does not include a `main` function by default. To test or use it in your own code, you need to compile your source files together and define the `BUFFER_SIZE` macro.

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c 
```

##### Resources
* [File Descriptors in C - GeeksforGeeks](https://www.geeksforgeeks.org/input-output-system-calls-c-create-open-close-read-write/)
* Understanding Static Variables in C
* Thanks to **sbouadai** for taking the time to explain how files work in C !
* Understanding Core Concepts: AI was used to explain and break down complex concepts, such as how static variables preserve their values and state between consecutive function calls, and how file descriptors (`fd`) operate under the hood.
* Documentation & Structure: AI helped draft and organize this `README.md` file.
* *Note:* All core algorithmic design, writing, coding, and debugging of the project were done manually by me.