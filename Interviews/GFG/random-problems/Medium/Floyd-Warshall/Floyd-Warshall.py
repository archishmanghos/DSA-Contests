class Solution:
    def shortest_distance(self, d):
        n = len(d)
        for k in range(n):
            for i in range(n):
                for j in range(n):
                    if d[i][k] != -1 and d[k][j] != -1:
                        if d[i][j] == -1 or d[i][j] > d[i][k] + d[k][j]:
                            d[i][j] = d[i][k] + d[k][j]
