*This activity has been created as part of the 42 curriculum by saalomar.*

# ft_printf

##  Description
**ft_printf** is a reimplementation of the standard C `printf` function.  
This project is part of the **42 curriculum** and focuses on variadic functions, and formatted output.

The goal is to reproduce the behavior of `printf` for a limited set of format specifiers while respecting 42’s coding standards.

---

## Supported Conversions

| Specifier | Description |
|----------|------------|
| `%c` | Prints a single character |
| `%s` | Prints a string |
| `%p` | Prints a pointer address |
| `%d` | Prints a decimal number |
| `%i` | Prints an integer |
| `%u` | Prints an unsigned decimal |
| `%x` | Prints a hexadecimal number (lowercase) |
| `%X` | Prints a hexadecimal number (uppercase) |
| `%%` | Prints a percent sign |

---

## Compilation
```bash
make
```
-creates libftprintf.a from all .c files.
other commands:
```bash
make clean
make fclean
make re
```
## usage
```c
#include "ft_printf.h"
```
## Resources
42 school libft instructions
AI
github
---
## library overview
ft_printf.c
ft_putchar.c
ft_puthex.c
ft_putnbr.c
ft_putpointer.c
ft_putstr.c
ft_putunsigned.c

---
