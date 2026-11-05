# ft_printf

A from-scratch re-implementation of the C library function `printf()`, built on **variadic arguments** (`<stdarg.h>`). It writes directly with `write()` and does not reproduce `printf`'s internal buffering.

```c
int ft_printf(const char *format, ...);
```

Written for the 42 curriculum. Like `printf`, it returns the number of characters printed.

## Supported conversions

| Specifier | Output |
|-----------|--------|
| `%c` | a single character |
| `%s` | a string |
| `%p` | a pointer, in hexadecimal |
| `%d`, `%i` | a signed decimal integer |
| `%u` | an unsigned decimal integer |
| `%x`, `%X` | an unsigned hexadecimal integer, lower or upper case |
| `%%` | a literal `%` |

## How it works

`ft_printf` walks the format string one character at a time with a `va_list`:

- an ordinary character is written straight through;
- after a `%`, the next character is checked against the list of supported specifiers, and `ft_printformat` dispatches to the right handler, which pulls the matching argument with `va_arg` and returns how many characters it wrote;
- the handlers' return values are summed into the final result.

If the format string is `NULL`, or a `%` is followed by an unsupported character, the function returns `-1`.

Each conversion lives in its own small function, so adding a new one means adding one branch to the dispatcher:

| File | Contents |
|------|----------|
| `ft_printf.c` | main function and the `ft_printformat` dispatcher |
| `ft_printnumb.c` | signed (`%d`, `%i`) and unsigned (`%u`) decimal output |
| `ft_printhex.c` | hexadecimal conversion for `%x` and `%X` |
| `ft_printptr.c` | pointer conversion for `%p` |
| `ft_helpers.c` | character and string output helpers |
| `ft_printf.h` | prototype and includes |

Numbers are converted without any allocation, so the function never leaks memory.

## Build and use

```bash
make            # builds libftprintf.a
make clean
make fclean
make re
```

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("%s is %d years old (0x%x)\n", "Alice", 42, 42);
    return (0);
}
```

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o demo
```
