# 🦝 Racoonia

A text-based RPG adventure developed in C++.

Racoonia is a console-based role-playing game where the player creates a character, explores a world inhabited by magical raccoons and other creatures, fights enemies, collects loot, gains experience and faces a final boss.

The project was developed as a personal learning exercise to practice Object-Oriented Programming and game system design using standard C++.

---

## Features

- Character creation system
- Turn-based combat
- Experience and level progression
- Inventory management
- Equipment system
- Random enemy encounters
- Loot generation
- Boss battle with unique attack behavior
- ASCII art and humorous dialogue

---

## Technologies Used

- C++
- Standard Template Library (STL)
- Visual Studio Code

---

## Object-Oriented Design

The project is structured using multiple classes:

### Character
Base class containing core statistics and combat functionality.

### Hero
Represents the player character.

Features:
- Character creation
- Inventory management
- Equipment handling
- Experience system
- Level progression

### Enemy
Derived from `Character`.

Features:
- Combat behavior
- Experience rewards
- Loot drops

### Boss
Derived from `Enemy`.

Features:
- Unique attack behavior
- Increased combat difficulty

### Object
Represents items and equipment that can improve player statistics.

---

## Concepts Practiced

This project was created to improve understanding of:

- Object-Oriented Programming (OOP)
- Inheritance
- Polymorphism
- Class composition
- Dynamic memory management
- STL containers (`std::vector`)
- Game loop implementation
- Code organization across multiple files
- Basic RPG system design

---

## How to Build

Compile all source files using a C++ compiler.

Example with g++:

```bash
g++ *.cpp -o Racoonia
```

Run:

```bash
./Racoonia
```

---

## Future Improvements

- Save and load system
- Expanded equipment system
- Additional enemy types
- Character classes
- Skills and abilities
- Improved combat balancing

---

## Author

Mattia Giuseppe Persano

Personal project developed to practice C++ programming and software development fundamentals.
