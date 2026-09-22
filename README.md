# C++ Library Management System

A console-based C++ application that models a small library management workflow using object-oriented programming.

> **Türkçe özet:** Kitap, üye ve kütüphane ekleme/listeleme/silme işlemlerini içeren; kalıtım ve sınıf yapılarıyla geliştirilmiş C++ konsol uygulamasıdır.

## Features

- Add, list, and remove books
- Add and remove student or staff members through polymorphism
- Add, list, and remove libraries
- Simple credential prompt and menu-driven flow
- Fixed-size in-memory collections for the active session

## Concepts demonstrated

- Classes, constructors, and encapsulation
- Inheritance and abstract base classes
- Polymorphic member handling with pointers
- Dynamic memory cleanup in destructors

## Build and run

Compile with a C++17-compatible compiler:

```bash
g++ -std=c++17 main.cpp -o library-management
./library-management
```

## Notes

- The project is an academic console application.
- Data is held in memory and is not persisted after the program closes.
- The portfolio copy is UTF-8 encoded for readable Turkish console messages.
