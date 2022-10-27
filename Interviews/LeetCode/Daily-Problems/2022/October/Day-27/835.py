class Solution:
    def largestOverlap (self, img1: List[List[int]], img2: List[List[int]]) -> int:
        n, pa, pb, ump, ans = len(img1), [], [], {}, 0
        for i in range(n * n):
            if img1[i // n][i % n] == 1: pa.append((i // n) * 100 + (i % n))
            if img2[i // n][i % n] == 1: pb.append((i // n) * 100 + (i % n))
        
        for i in pa: 
            for j in pb: 
                ump[i - j] = ump.get(i - j, 0) + 1
        for value in ump.values(): ans = max(ans, value)
        
        return ans