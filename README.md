# dijkstra algorithm
# How it works (short):

Set the distance to the start node as 0, all others as ∞

Always pick the unvisited node with the smallest distance

Relax its edges (update neighbors’ distances if a shorter path is found)

Mark the node as visited

Repeat until all nodes are processed (or the target is reached)

# Key points:

Works only with non-negative weights

Uses a priority queue for efficiency

Time complexity:

O((V + E) log V) with adjacency list + heap

O(V²) with adjacency matrix
