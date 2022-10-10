from typing import List
class Solution:
    def dfs(self, r, c, n, m, grid, visited):
        if r < 0 or r >= n or c < 0 or c >= m: return
        if grid[r][c] == 0 or visited[r][c]: return
        visited[r][c] = 1
        dx, dy = [-1, 1, 0, 0], [0, 0, -1, 1]
        for i in range(4):
            self.dfs(r + dx[i], c + dy[i], n, m, grid, visited)
        
    def numOfIslands(self, n: int, m : int, operators : List[List[int]]) -> List[int]:
        k, grid = len(operators), [[0 for col in range(m)] for row in range(n)]
        ans = [0 for i in range(k)]
        
        for i in range(k):
            islands, r, c = 0, operators[i][0], operators[i][1]
            grid[r][c] = 1
            visited = [[0 for col in range(m)] for row in range(n)]
            for j in range(n):
                for k in range(m):
                    if not visited[j][k] and grid[j][k] == 1:
                        islands += 1
                        self.dfs(j, k, n, m, grid, visited)
            ans[i] = islands
        
        return ans
