# C++ Exercises — Praktikum Informatik 1

Selected exercises from the *Praktikum Informatik 1* lab course (2022–2023). Comments and console text are in German, as written for the course.

| Folder | Topic | What it does |
|---|---|---|
| `versuch02-substitutionschiffre` | Arrays | Encrypts and decrypts a word with a 2 × 26 substitution-cipher key table |
| `versuch06-stl-studentendatenbank` | STL containers | Menu-driven student database on `std::vector`: add/remove at front and back, delete by matriculation number, print forwards/backwards, save to and load from a text file |

The larger course project, a Qt route planner with Dijkstra, has its own repository: **streetplanner**.

## Build

Each folder is a standalone console program:

```bash
g++ -std=c++17 versuch06-stl-studentendatenbank/*.cpp -o studenten
g++ -std=c++17 versuch02-substitutionschiffre/*.cpp -o chiffre
```

The sample records in Versuch 6 are fictional data provided by the course.
