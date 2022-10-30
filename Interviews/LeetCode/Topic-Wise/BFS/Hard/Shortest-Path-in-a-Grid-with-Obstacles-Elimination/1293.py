from queue import Queue
class Solution:
    def shortestPath(self, grid: List[List[int]], k: int) -> int:
        n, m, q, v = len(grid), len(grid[0]), Queue(), [0, 0, 0, k]
        vis = [[-1 for i in range(m)] for j in range(n)]
        q.put(v)
        
        while q.qsize() > 0:
            i = q.get()
            r, c, stepsTaken, stepsLeft = i[0], i[1], i[2], i[3]
            if vis[r][c] != -1 and vis[r][c] >= stepsLeft: continue
            vis[r][c] = stepsLeft
            if r == n - 1 and c == m - 1: return stepsTaken
            
            dx, dy = [0, 1, 0, -1], [1, 0, -1, 0]
            for j in range(4):
                nr, nc = r + dx[j], c + dy[j]
                if nr >= 0 and nr < n and nc >= 0 and nc < m:
                    if grid[nr][nc]:
                        if stepsLeft:
                            v = [nr, nc, stepsTaken + 1, stepsLeft - 1]
                            q.put(v)
                    else:
                        v = [nr, nc, stepsTaken + 1, stepsLeft]
                        q.put(v)
        
        return -1