class Solution:
    def endOfRoad (self, x, y, r, c, visited) -> bool:
        if x < 0 or x >= R or y < 0 or y >= C: return True
        if visited[x][y]: return True
        return False
        
	def reverseSpiral (self, R, C, a):
		start, ans = [0, 0], [None for i in range(R * C)]
		i, curDir = 0, 0 # 0 for right, 1 for down, 2 for left and 3 for up
        dx, dy = [0, 1, 0, -1], [1, 0, -1, 0]
        visited = [[0 for i in range(C)] for j in range(R)]
        
        while True:
            ans[i] = a[start[0]][start[1]]
            i += 1
            visited[start[0]][start[1]] = 1
            if self.endOfRoad(start[0] + dx[curDir], start[1] + dy[curDir], R, C, visited):
                curDir = (curDir + 1) % 4;
            start[0] += dx[curDir];
            start[1] += dy[curDir];
            
            if self.endOfRoad(start[0], start[1], R, C, visited):
                break
        
        ans.reverse()
        return ans