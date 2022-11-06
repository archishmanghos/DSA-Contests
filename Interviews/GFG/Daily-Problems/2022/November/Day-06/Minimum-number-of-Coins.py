class Solution:
    def minPartition(self, N):
        notes, ans, i = [2000, 500, 200, 100, 50, 20, 10, 5, 2, 1], [], 0

        while N:
            j = 1
            while j <= (N // notes[i]):
                ans.append(notes[i])
                j += 1
            N %= notes[i]
            i += 1

        return ans
