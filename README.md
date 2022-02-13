[![42](https://img.shields.io/badge/BornToCode-2_Circle-00babc?style=flat-square&logo=42)](https://42seoul.kr/)
[![result](https://img.shields.io/badge/Success-90/100-5cb85c?style=flat-square&logoWidth=12&logo=data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAADAAAAAwCAYAAABXAvmHAAAAAXNSR0IArs4c6QAAAylJREFUaEPtmDmLVEEUhb+LK+IG7qIibuCKYCYYOSoGomjimoggOgiKmYGhgYEMGqgYiJmIG4ig4IKGitsv8Ae4m7ocuWO108u8flWvu+030JXN9Kmqc+49devWM0b4sBHOn56Abmewl4FeBnIiIGk6cBtYCxwzs2vVU0ptIUkzgEfAmkBawFEzu1QRUVoBgfxjYHVdklzEETO77P8vpYAm5CtafgMH3U6lEyBpJuCRX5VzPH4BB0olIJB/AqyMrG4fSiNA0izAya+IJO+wp6UQkGCbam3vgL6uCyhgGxfxl7zZx64KCLbxAxvr+RryXS2jBT3/L/JdvcjaRX7YDEhaBJwB3gOnzexHQlXIhUqa69UDWJYLHgK8DZ7/VD+n5gxIWgfcB7yk+bgF7DaznwmbZUIlzQ6XVEqpbLDNsM2cpI2h65tcx+AmsKdVEYG81/nlCcHwyG/yapM1ZzADkvYBV4ExGcAbwF4z8+s7eUiaF2yzJGFypm1qMiCpH7gQ0di5wENm5o1U9ChI/k3w/Oe8jUzSd2BSHjD8fgU4bGbe0uYOSfND5BfngocA0eR9igu4C2xP2OAi0J8nQtKC0NukkH8dPJ8b+QpfFzABeABsSBBxHjieJaJg5KM8X8+xcoinhPLmZTR2DJjZiXpwwcgXIj9ooQqB8Hh+ltjOnjOzk1VruG38kvLLMHYUJl8jwP8It+RzIMW3Z4FTYc5DYGEsc+BV8PyXhDk10IZuVJITcBFeQWLH11DJRsVOaAf5hgxUWWEp4Haak0AoBeql0m/Yht4mZZFMAcFO/jnD/TwtddEcfFKdz9u76YNGkn8NcxFT8xaK/L2t5JtmoMpO6wE/nBMjSWbB2k4+SkCwUx9wDxhfUETyDRu7T/SbWNI2wFvrsbGLB9xLYLOZeaVq+4gWEDKxFbgDjItk0rHIV/ZPEhBE7AD8fZD1dqis/QLY0qnIFxYQROwErjcR0fHItyQgR8R/Ix9dhbL8LmlXyMTogPHexg9sdD8feZYyYclnoH4lSW6ngfC5b7+ZfWuVVMr8lgWkbNYJbE9AJ6KasmYvAynR6gR2xGfgD5kpEElZbxKNAAAAAElFTkSuQmCC)](https://projects.intra.42.fr/minitalk/sarchoi)

[![code-size](https://img.shields.io/github/languages/code-size/srngch/42push_swap?style=flat-square)](https://github.com/srngch/42push_swap)
[![last-commit](https://img.shields.io/github/last-commit/srngch/42push_swap?style=flat-square)](https://github.com/srngch/42push_swap)

<details>
  <summary>Table of Contents</summary>
  <ol>
    <li><a href="#summary">Summary</a></li>
    <li><a href="#project-structure">Project Structure</a></li>
    <li><a href="#environment">Environment</a></li>
    <li><a href="#installation">Compile</a></li>
		<li><a href="#execute">Execute</a></li>
		<li><a href="#example">Example</a></li>
		<li><a href="#links">Links</a></li>
  </ol>
</details>

# push_swap

This project involves sorting data on a stack, with a limited set of instructions, and the smallest number of moves. To make this happen, you will have to manipulate various sorting algorithms and choose the most appropriate solution(s) for optimized data sorting.

### Instructions
- `sa`: swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
- `sb`: swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
- `ss`: `sa` and `sb` at the same time.
- `pa`: push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- `pb`: push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- `ra`: rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
- `rb`: rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
- `rr`: `ra` and `rb` at the same time.
- `rra`: reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
- `rrb`: reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
- `rrr`: `rra` and `rrb` at the same time.

## Summary

|                      |                                           |
| -------------------- | ----------------------------------------- |
| **Program name**     | `push_swap`                               |
| **Makefile**         | `all`, `clean`, `fclean`, `re`            |
| **Arguments**        | a random list of integers                 |
| **External functs.** | `write`, `read`, `malloc`, `free`, `exit` |
| **Libft authorized** | Yes                                       |

## Project Structure

```shell
./
├── includes/	# header files
├── libft/		# library files
├── src/		# source files
└── Makefile
```

## Environment

- MacOS 12.1(Monterey, Intel)

Developed and tested in this environment.

## Compile

### Mandatory

```shell
$ git clone https://github.com/srngch/42minitalk
$ make
```

## Execute

Run compiled executable file in the root folder.

```shell
$ ./push_swap [numbers]
```

## Example

```shell
# print instructions
$ ./push_swap 1 3 2 5 4
pb
ra
pb
sa
rra
pa
pa

# print nothing if the list is already sorted
$ ./push_swap 1 2 3 4 5

# print nothing if argument is not provided
$ ./push_swap

# print error if argument is not a integer
$ ./push_swap 0 one 2 3
Error

# print error if argument is not a range of integers
$ ./push_swap 2147483648
Error

# print error if argument is duplicated
$ ./push_swap 1 2 3 1
Error

# check if the list is sorted
$ ARG="1 5 2 4 3"; ./push_swap $ARG | ./checker_Mac $ARG
OK
```


## Links

- [Subject - 42 Intra](https://projects.intra.42.fr/projects/42cursus-push_swap)
- [Subject - 42Seoul Translation](https://github.com/42seoul-translation/subject_ko/blob/master/push_swap/push_swap.ko.md)
