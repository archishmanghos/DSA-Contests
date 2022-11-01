class Solution:
    def median (self, matrix, R, C):
        a = []
    	for i in range(R):
    	    for j in range(C):
    	        a.append(matrix[i][j])
    	a.sort()
    	return a[(R * C) // 2]