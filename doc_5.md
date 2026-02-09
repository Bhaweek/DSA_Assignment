# Undirected Graph Using Adjacency Matrix

## 1. Introduction
A graph is a collection of vertices (nodes) and edges that connect pairs of vertices.  
In an **undirected graph**, edges have no direction, meaning the connection is mutual.

---

## 2. Adjacency Matrix Representation

An **adjacency matrix** is a 2D array `adj[n][n]` used to represent a graph.

### Rules:
- `adj[i][j] = 1` → There is an edge between vertex `i` and `j`
- `adj[i][j] = 0` → No edge between vertex `i` and `j`
- For an **undirected graph**:

## 3. Breadth First Search (BFS)

### Description:
Breadth First Search (BFS) is a graph traversal technique that explores all neighboring vertices at the current level before moving to the next level.

### Characteristics:
- Uses **Queue**
- Traverses **level by level**
- Suitable for finding **shortest path in unweighted graphs**

### Steps:
1. Start from a source vertex
2. Mark it as visited
3. Insert it into a queue
4. Visit all its adjacent unvisited vertices
5. Repeat until the queue is empty

---

## 4. Depth First Search (DFS)

### Description:
Depth First Search (DFS) explores a graph by going as deep as possible along each branch before backtracking.

### Characteristics:
- Uses **Recursion** or **Stack**
- Traverses **depth-wise**
- Does not guarantee shortest path

## 5. Applications
- Network routing
- Path finding
- Cycle detection
- Connected components
- Maze solving

---

## 6. Conclusion
Using an adjacency matrix provides a simple and effective way to represent undirected graphs. BFS and DFS are fundamental traversal techniques that help explore and analyze graph structures efficiently.
