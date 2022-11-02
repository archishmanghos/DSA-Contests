class Solution:
    def largestArea(self, n, m, k, enemy) -> int:
        if k == 0: return n * m
        r, c = [], []
        for i in enemy:
            r.append(i[0])
            c.append(i[1])
        r.sort()
        c.sort()
        maxr, maxc = max(n - r[k - 1], r[0] - 1), max(m - c[k - 1], c[0] - 1)
        for i in range(1, k):
            maxr = max(maxr, r[i] - r[i - 1] - 1)
            maxc = max(maxc, c[i] - c[i - 1] - 1)
        
        return maxr * maxc