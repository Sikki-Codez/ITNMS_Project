## 🚇 Intelligent Transport Network Management System (ITNMS)

[cite_start]This project, developed for the CS221 Data Structures & Algorithms course (Fall 2025) [cite: 1, 2][cite_start], simulates a smart city transportation network[cite: 6]. [cite_start]It is designed to provide students with hands-on experience in applying core Data Structures and Algorithms (DSA) to design and implement a complex, real-world software system[cite: 5, 130].

[cite_start]The system manages vehicles, passengers, routes, stations, ticketing, shortest paths, and traffic operations[cite: 6].

### 🛠️ Technical Requirements & Constraints

  * [cite_start]**Programming Language:** C++[cite: 74].
  * [cite_start]**Design:** Object-Oriented Design (OOD)[cite: 75]. [cite_start]Use separate classes for each module[cite: 77].
  * [cite_start]**Code Quality:** Must be modular, readable, and documented[cite: 78]. [cite_start]Provide complexity analysis for each algorithm used[cite: 79].
  * [cite_start]**Mandatory Constraint:** All data structures must be implemented manually[cite: 122]. [cite_start]Searching and sorting must be coded by students (not built-in)[cite: 123]. [cite_start]No use of external libraries for graph algorithms (except I/O)[cite: 121].

### 💡 Core Data Structures Implemented

[cite_start]The project integrates all major concepts of CS221, including arrays, linked lists, queues, stacks, trees, graphs, hashing, and a complete set of searching and sorting algorithms[cite: 7].

| Concept | Usage in ITNMS | Implementation Required |
| :--- | :--- | :--- |
| **Graphs** | Main transport network, modeling stations and routes. | [cite_start]Adjacency List/Matrix[cite: 22]. |
| **Hash Tables** | [cite_start]Vehicle/passenger lookup[cite: 22]. | [cite_start]Collision handling (preferably chaining)[cite: 43]. |
| **Queues** | [cite_start]Passenger waiting line for the Ticketing System[cite: 22, 33]. | [cite_start]Linked-List Queue or Circular Queue allowed[cite: 37]. |
| **Stacks** | [cite_start]Undo/redo, navigation history[cite: 22, 44]. | [cite_start]Storing operations history[cite: 47]. |
| **Trees (BST/AVL)** | [cite_start]Store route or station metadata[cite: 22]. | [cite_start]BST or AVL[cite: 22]. |
| **Heaps** | [cite_start]Fastest vehicle, traffic prioritization[cite: 22, 70, 71]. | [cite_start]Priority Queue implementation[cite: 22]. |
| **Arrays** | [cite_start]Store static data (e.g., station list, fare list)[cite: 22]. | [cite_start]Custom implementation[cite: 22]. |
| **Linked Lists** | [cite_start]Used in hash table chaining, dynamic queues[cite: 22]. | [cite_start]Custom implementation[cite: 22]. |

### 📋 System Modules & Required Algorithms

#### 1\. Route & Station Management (Graphs)

  * [cite_start]Add/Delete Station [cite: 25] [cite_start]and Route (edge)[cite: 26].
  * [cite_start]Display all connected stations[cite: 27].
  * [cite_start]Perform BFS & DFS[cite: 28].
  * [cite_start]**Shortest Path:** Find Shortest Path using **Dijkstra's Algorithm**[cite: 29].
  * [cite_start]**Topology:** Generate Minimum Spanning Tree (MST) [cite: 30] [cite_start]and Detect cycles in the network[cite: 31].

#### 2\. Passenger Ticketing System (Queues)

  * [cite_start]Implement a FIFO queue for ticket requests[cite: 33].
  * [cite_start]Functions: Passenger enters queue [cite: 34][cite_start], Process next passenger [cite: 36][cite_start], Display queue[cite: 35].

#### 3\. Vehicle Database (Hashing)

  * [cite_start]Use a hash table to store and retrieve vehicles[cite: 39].
  * [cite_start]Functions: Insert vehicle [cite: 40][cite_start], Search vehicle [cite: 41][cite_start], Remove vehicle[cite: 42].
  * [cite_start]Handle collisions (preferably chaining)[cite: 43].

#### 4\. History & Undo Operations (Stacks)

  * [cite_start]Use a stack to store operations such as last visited station [cite: 46] [cite_start]or actions history[cite: 47].
  * [cite_start]Function: Undo last action[cite: 48].

#### 5\. Searching & Sorting Module

[cite_start]The user must select the algorithm to apply on a dataset[cite: 50].

| Category | Algorithms Required |
| :--- | :--- |
| **Searching** | [cite_start]Linear Search [cite: 52][cite_start], Binary Search[cite: 53]. |
| **Sorting** | [cite_start]Bubble Sort [cite: 55][cite_start], Selection Sort [cite: 56][cite_start], Insertion Sort [cite: 57][cite_start], Merge Sort [cite: 58][cite_start], Quick Sort [cite: 59][cite_start], Heap Sort[cite: 60]. |

For each algorithm, the implementation must include:

  * [cite_start]Best/Worst/Average time complexity[cite: 63].
  * [cite_start]Space complexity[cite: 64].
  * [cite_start]Sample dataset execution[cite: 65].

### 💻 Instructions to Run the Project

1.  **Clone the Repository:**
    ```bash
    git clone [repository_url]
    cd ITNMS
    ```
2.  **Compilation:**
    Compile all source files together using a C++ compiler (like g++):
    ```bash
    g++ main.cpp CityGraph.cpp VehicleMap.cpp CoreDS.cpp SortSearch.cpp -o ITNMS_Project
    ```
    (Ensure you compile all necessary `.cpp` files if you follow a modular structure.)
3.  **Execution:**
    ```bash
    ./ITNMS_Project
    ```
4.  **Usage:** Follow the menu prompts to test the core functions like adding stations, creating routes, calculating the shortest path, and managing the passenger queue.