Optimal Solution: TC = O(Vertices x Edges), SC = O(Vertices)

The problem is a direct implementation of [Bellman-Ford Algorithm](https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm). <br>
Bellman-Ford Algorithm is used to find Single-Source Shortest Path between 2 nodes, even if a graph has negative edge weights. <br>
If a graph contains negative-edge weights, it might also contain negative weight cycles. <br>
The *Bellman-Ford Algorithm* can detect such cycles. <br>
If after doing (V - 1) [relaxations](https://en.wikipedia.org/wiki/Relaxation_(approximation), where V is the number of vertices, the graph can be further relaxed, it means that the graph contains a negative weight cycle. <br>
Thus, if there is V-th relaxation, we return 1, else we return 0. <br>

Total Time Taken: `0.82/2.8` 