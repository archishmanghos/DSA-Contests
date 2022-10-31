class Solution:
    def check (self, r, c, n, m, matrix) -> bool:
        content = matrix[r][c]
        while r < n and c < m:
            if content != matrix[r][c]: return False
            r, c = r + 1, c + 1
        return True
    
    def isToeplitzMatrix (self, matrix: List[List[int]]) -> bool:
        dx, dy, cell, n, m, i = [-1, 0], [0, 1], [0, 0], len(matrix), len(matrix[0]), 0
        cell[0] = n - 1
        
        while cell[1] < m:
            if not self.check (cell[0], cell[1], n, m, matrix): return False
            if cell[0] == 0 and cell[1] == 0: i += 1
            cell[0], cell[1] = cell[0] + dx[i], cell[1] + dy[i]
        
        return True