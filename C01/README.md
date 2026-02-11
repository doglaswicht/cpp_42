*This project has been created as part of the 42 curriculum by dleite-b.*
---

## 📚 Module Overview

This module introduces fundamental concepts of Object-Oriented Programming in C++, including:

- Stack vs Heap memory
- Constructors and Destructors
- References and Pointers
- Dynamic memory allocation (`new`, `delete`, `new[]`, `delete[]`)
- File handling with streams
- Member function pointers

---

## 📂 Exercises

### 🧟 ex00 – BraiiiiiiinnnzzzZ

Implementation of a `Zombie` class to understand:

- Object creation on stack and heap
- Proper use of constructors and destructors
- Manual memory management with `new` and `delete`

---

### 🧟🧟 ex01 – Moar brainz!

Creation of a Zombie horde using dynamic array allocation:

- `new Zombie[N]`
- `delete[]`

Focus on:
- Default constructors
- Matching `new[]` with `delete[]`
- Avoiding memory leaks

---

### 🧠 ex02 – HI THIS IS BRAIN

Introduction to:

- Pointers
- References
- Memory addresses

Understanding:
- The difference between a pointer and a reference
- Dereferencing (`*`)
- Address-of operator (`&`)
- Reference as an alias

---

### ⚔️ ex03 – Unnecessary violence

Implementation of:

- `Weapon`
- `HumanA` (always armed – uses reference)
- `HumanB` (can be unarmed – uses pointer)

Focus on:
- When to use references
- When to use pointers
- Object sharing and ownership

---

### 📄 ex04 – Sed is for losers

Program that:

- Reads a file
- Replaces occurrences of a string
- Writes the result to `<filename>.replace`

Focus on:
- `ifstream` and `ofstream`
- `std::string::find`
- Manual string manipulation without using `std::string::replace`

---

### 📢 ex05 – Harl 2.0

Implementation of a logging system using:

- Member function pointers
- Array-based dispatch instead of multiple `if/else`

Focus on:
- `void (Class::*ptr)()` syntax
- Calling member functions dynamically
- Cleaner and scalable code structure

---

## 🛠 Compilation

Each exercise contains its own `Makefile`.

To compile an exercise:

```bash
make
