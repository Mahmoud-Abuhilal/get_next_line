*This project has been created as part of the 42 curriculum by mabuhila.*

# get_next_line

## Description

**get_next_line** is a C function that reads text line-by-line from a file descriptor until End-of-File (EOF) or an error occurs.

The goal is to learn about static variables, low-level I/O (`read`), and memory allocation without creating memory leaks.

### Features

* Reads lines including their trailing `\n`.
* Customizable buffer size at compile time using `-D BUFFER_SIZE=N`.
* **Bonus:** Supports multiple open file descriptors at the same time.

## Algorithm Explanation & Justifications

### How It Works

1. **`read_remainder`**: Calls `read()` to load data in `BUFFER_SIZE` chunks and appends it to a static variable (`remainder[fd]`) until a `\n` or EOF is reached.
2. **`extract_line`**: Finds the first `\n` in `remainder[fd]` and allocates memory to extract that single line.
3. **`update_remainder`**: Removes the extracted line from `remainder[fd]`, keeping only the leftover characters for the next function call.
4. **Cleanup**: Frees buffers and sets static pointers to `NULL` when reading ends or fails.

### Technical Choices

* **Heap Allocation for `buffer`**: Prevents stack overflows when large buffer sizes (e.g., `BUFFER_SIZE=1000000`) are passed.
* **Static Array (`remainder[FOPEN_MAX]`)**: Allows each open file descriptor (`fd`) to keep its own isolated static memory buffer.
* **Dangling Pointer Guard**: Resetting static pointers with `remainder[fd] = NULL` after freeing prevents double-free crashes and memory leaks.

## Instructions

### Compilation

```bash
# Mandatory
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl

# Bonus
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main.c -o gnl_bonus
```

### Usage Example

```c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
    int   fd = open("test.txt", O_RDONLY);
    char *line;

    if (fd < 0)
        return (1);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

### Memory Check

```bash
valgrind --leak-check=full ./gnl
```

## Resources

### References

* [man2 read](https://man7.org/linux/man-pages/man2/read.2.html) - Linux manual page.
* *The C Programming Language* (K&R) - Section 4.6 (Static Variables).

### Usage of AI

AI tools (Gemini / LLMs) were used for:
1. Preparing technical explanations for peer evaluation defense.
2. Checking code formatting against Norminette rules.
3. Structuring and editing this `README.md`.
