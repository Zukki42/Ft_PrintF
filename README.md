# 🖨️ ft_printf

**ft_printf** is a reimplementation of the standard C `printf()` function —  
rewritten from scratch, by hand, in pure C.  

It handles formatted output to the terminal just like the real thing,  
but built entirely without using the standard `printf` from libc.  

This project is part of the **42 curriculum**, and a direct continuation of **Libft**,  
aiming to deepen understanding of **variadic functions**, **format parsing**, and **low-level output control**.

---

## 📘 What It Does

`ft_printf` reproduces the core behavior of `printf` —  
reading a format string, interpreting format specifiers, and printing corresponding arguments.  

Supported conversions:

%c Character
%s String
%d Signed decimal integer
%i Signed integer (same as %d)
%u Unsigned integer
%x Hexadecimal (lowercase)
%X Hexadecimal (uppercase)
%p Pointer address
%% Literal percent sign


Basically — it’s `printf`, but smaller, sassier, and written with your own hands. 😄

---

## ⚙️ Building

Use the included **Makefile** to compile the project:

make

Other useful targets:

make clean     # Remove object files
make fclean    # Remove object files and library
make re        # Rebuild everything from scratch

---

## 🧠 Why It Matters

This project teaches you:

How variadic arguments work in C (stdarg.h)
How to parse and interpret format strings
How to handle different data types dynamically
How to write modular, reusable, and error-safe code

In short , it’s the ultimate printf bootcamp.
By the end, you’ll really understand what happens when you type printf("Hello %s!", name);

---

## 🖋️ Author

Balica Virgil Eduard | Intra : bavirgil
42 Student | C Developer in Progress
