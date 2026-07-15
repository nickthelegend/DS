# DS — Data Structures & Algorithms in C

> A collection of classic data-structures and algorithms implemented from scratch in plain C.

## Overview

This repository is a study collection of core data-structures and algorithm programs written in C. Each topic lives in its own folder as a small, self-contained program with a `main()` that demonstrates the structure or algorithm. It's meant as a hands-on reference for learning how these fundamentals work under the hood — no external libraries, just the standard library.

## Features

- **Singly Linked List** — insert at end, insert at position, delete at position, update at position, and display.
- **Queue** — linked-list-based queue with an interactive menu for enqueue, dequeue, and display.
- **Binary Search Tree** — node creation, ordered insertion, recursive search, and in-order traversal.
- **Tree Traversals** — in-order, pre-order, and post-order in both recursive and stack-based non-recursive forms.
- **Graph Traversal** — Breadth-First Search (BFS) and Depth-First Search (DFS), each in recursive and non-recursive variants, over an adjacency matrix.
- **Merge Sort** — classic divide-and-conquer sorting.
- **Heap Sort** — in-place sorting using a max-heap with `heapify`.

## Tech Stack

- **Language:** C (C99)
- **Toolchain:** any standard C compiler (`gcc` / `clang`); no build system or third-party dependencies

## Getting Started

Each `.c` file is a standalone program. Compile and run whichever one you want:

```bash
# Clone the repo
git clone https://github.com/nickthelegend/DS.git
cd DS

# Compile a single program (examples)
gcc SingleLinkedList/SingleLinkedList.c -o sll && ./sll
gcc Queues/Queues.c                     -o queue && ./queue
gcc BinaryTree/BinaryTree.c             -o bst && ./bst
gcc TreeTraversal/TreeTraversalRecursive.c -o tt && ./tt
gcc GraphTraversal/BFSNonRecursive.c    -o bfs && ./bfs
gcc MergeSort/MergeSort.c               -o msort && ./msort
gcc HeapSort/HeapSort.c                 -o hsort && ./hsort
```

On Windows with MinGW, swap the output name for `program.exe`.

## Project Structure

```
DS/
├── BinaryTree/          # Binary search tree: insert, search, in-order traversal
├── SingleLinkedList/    # Singly linked list operations
├── Queues/              # Linked-list queue with an interactive menu
├── TreeTraversal/       # In/pre/post-order traversals (recursive & non-recursive)
├── GraphTraversal/      # BFS & DFS (recursive & non-recursive) over an adjacency matrix
├── MergeSort/           # Merge sort
└── HeapSort/            # Heap sort
```

---

Built by [nickthelegend](https://github.com/nickthelegend) · [nickthelegend.tech](https://nickthelegend.tech)
