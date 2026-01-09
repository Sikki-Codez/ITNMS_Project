## 🚇 Intelligent Transport Network Management System (ITNMS)

The **Intelligent Transport Network Management System (ITNMS)** is a comprehensive course project developed for the **CS221 – Data Structures & Algorithms** course. The project simulates a smart city transportation network and is designed to demonstrate the **practical application of core data structures and algorithms** in a realistic, large-scale system.

This project strictly avoids built-in data structures and algorithm libraries, ensuring that **all logic is implemented manually** to meet academic requirements.

---

## 🎯 Project Objectives

* Apply fundamental **Data Structures & Algorithms (DSA)** to a real-world problem
* Strengthen understanding of **graphs, trees, hashing, heaps, stacks, and queues**
* Practice **object-oriented design (OOD)** in C++
* Analyze and document **time and space complexity** of algorithms
* Build a modular, extensible, and well-documented system

---

## 🛠️ Technical Requirements

* **Language:** C++
* **Paradigm:** Object-Oriented Programming (OOP)
* **Constraint:**

  * No STL containers for core data structures
  * No external graph or algorithm libraries
  * All searching, sorting, and data structures implemented manually

---

## 💡 Core Data Structures Used

| Data Structure               | Usage                                                     |
| ---------------------------- | --------------------------------------------------------- |
| **Graphs**                   | Transport network (stations as vertices, routes as edges) |
| **Hash Tables**              | Vehicle and passenger lookup (with chaining)              |
| **Queues**                   | Passenger ticketing system (FIFO)                         |
| **Stacks**                   | Undo/redo operations, navigation history                  |
| **Binary Search Tree (BST)** | Route/station metadata, analytics                         |
| **Heaps (Min-Heap)**         | Fastest vehicle assignment, traffic priority              |
| **Arrays**                   | Static data storage (stations, fares, routes)             |
| **Linked Lists**             | Hash table chaining, dynamic queues                       |

---

## 📋 System Modules & Algorithms

### 1. 🚏 Route & Station Management (Graph Module)

* Add / Delete stations
* Add / Delete routes (edges)
* Display connected stations
* **Graph Traversals:**

  * Breadth First Search (BFS)
  * Depth First Search (DFS)
* **Shortest Path:** Dijkstra’s Algorithm
* **Network Analysis:**

  * Minimum Spanning Tree (MST)
  * Cycle detection

---

### 2. 🎟️ Passenger Ticketing System (Queue)

* FIFO passenger queue
* Passenger enters queue
* Process next passenger
* Display waiting queue

---

### 3. 🚗 Vehicle Database (Hash Table)

* Insert vehicle
* Search vehicle
* Remove vehicle
* Collision handling using **chaining (linked lists)**

---

### 4. 🔄 History & Undo Operations (Stack)

* Store last visited stations or actions
* Undo last operation
* Action history tracking

---

### 5. 🔍 Searching & Sorting Module

Users can choose which algorithm to apply on datasets.

#### Searching Algorithms

* Linear Search
* Binary Search

#### Sorting Algorithms

* Bubble Sort
* Selection Sort
* Insertion Sort
* Merge Sort
* Quick Sort
* Heap Sort

Each algorithm includes:

* Best, Average, and Worst-case time complexity
* Space complexity
* Sample execution on test data

---

### 6. 🌳 Binary Search Tree (BST) Module

* Insert, search, and delete operations
* In-order traversal for sorted output
* Used for metadata storage and analytics

---

### 7. ⏱️ Heap / Priority Queue Module

* Custom Min-Heap implementation
* Insert and extract-min operations
* Used for:

  * Fastest vehicle assignment
  * Traffic prioritization

---

### 8. 📊 Analytics & Reporting Module

* Station visit frequency tracking
* Most crowded station detection
* Busiest route analysis
* Route weight analysis
* Traffic density prediction (Heap-based)
* Daily usage trend analysis (BST-based)
* Summary reports for system insights

---

## 📁 Project Structure

```
├── main.cpp          // Program entry point & menu system
├── CityGraph.h      // Graph operations (BFS, DFS, Dijkstra, MST)
├── VehicleMap.h     // Hash table for vehicle management
├── CoreDS.h         // Stack and Queue implementations
├── SortSearch.h     // Searching & sorting algorithms
├── Tree.h           // Binary Search Tree implementation
├── Heap.h           // Min-Heap / Priority Queue
├── Analytics.h      // Reporting & analytics logic
├── Models.h         // Data models and structures
```

> **Note:** This project uses a **header-only architecture** as per course constraints.

---

## 💻 How to Compile & Run

### 1️⃣ Clone the Repository

```bash
git clone https://github.com/MuhammadAhmadF2005/DSA_project.git
cd DSA_project
```

### 2️⃣ Compile

**Linux / macOS:**

```bash
g++ main.cpp -o ITNMS_Project
```

**Windows (MinGW):**

```bash
g++ main.cpp -o ITNMS_Project.exe
```

### 3️⃣ Run

**Linux / macOS:**

```bash
./ITNMS_Project
```

**Windows:**

```bash
ITNMS_Project.exe
```

---

## ✅ Usage

Use the interactive menu to:

* Add stations and routes
* Find shortest paths
* Manage passenger queues
* Insert/search vehicles
* Apply sorting and searching algorithms
* View analytics and reports

---

## 📚 Academic Notes

* All data structures are **implemented from scratch**
* No STL containers are used for core logic
* Designed strictly according to **CS221 DSA course guidelines**

---

## 👨‍💻 Authors

* **Muhammad Ahmad**
* **Raja Hamza**
* **Muhammad Haider Ali**
* **Muhammad Zaid**

CS | GIKI

---

## 📜 License

This project is intended for **academic and learning purposes only**.
