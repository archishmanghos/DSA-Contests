class Solution:
    def numberOfSubsequences(self, S, W):
        i, ans = 0, 0

        temp = list(S)
        while i < len(temp):
            k = 0
            for j in range(i, len(temp)):
                if W[k] == temp[j]:
                    if k == 0:
                        i = j + 1
                    k += 1
                    temp[j] = '-1'
                if k == len(W):
                    break
            if k == len(W):
                ans += 1
            else:
                break

        return ans
