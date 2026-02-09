# Dijkstra’s Algorithm – C Implementation

## Overview
This program implements **Dijkstra’s algorithm** to find the **shortest path from a source node to all other nodes** in a weighted graph.  
The graph is represented using an **adjacency matrix** and assumes **non-negative edge weights**.

## Algorithm Description
Dijkstra’s algorithm works by:
1. Initializing the distance of the source vertex to `0` and all others to infinity.
2. Repeatedly selecting the unvisited vertex with the smallest known distance.
3. Updating the distances of its adjacent vertices.
4. Marking the selected vertex as visited.
5. Continuing until all vertices are visited.

## Input
- Number of vertices `n`
- `n x n` adjacency matrix  
  - `0` indicates no edge
  - Positive values indicate edge weights
- Source vertex index

## Output
- The shortest distance from the source vertex to every other vertex

## Time and Space Complexity
- **Time Complexity:** `O(V²)`
- **Space Complexity:** `O(V²)` (adjacency matrix)

## Limitations
- Does not support negative edge weights
- Uses adjacency matrix (not optimal for very large sparse graphs)

## Compilation and Execution
```bash
gcc dijkstra.c -o dijkstra
./dijkstra
