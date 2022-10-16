from typing import List
import queue

class Solution:
    def shortestPath(self, grid: List[List[int]], source: List[int], destination: List[int]) -> int:
        n, m = len(grid), len(grid[0])
        dist = [[1e9 for j in range(m)] for i in range(n)]
        q = queue.Queue()
        q.put(source)
        dist[source[0]][source[1]] = 0
        
        while q.qsize():
            cn = q.get()
            if cn == destination:
                return dist[destination[0]][destination[1]]
            dx, dy = [0, 0, 1, -1], [1, -1, 0, 0]
            for i in range(4):
                nr, nc = cn[0] + dx[i], cn[1] + dy[i]
                if nr < 0 or nr >= n or nc < 0 or nc >= m or grid[nr][nc] != 1:
                    continue
                if dist[nr][nc] > dist[cn[0]][cn[1]] + 1:
                    dist[nr][nc] = dist[cn[0]][cn[1]] + 1;
                    q.put([nr, nc]);
            
        return -1