class Solution:
    def twoOddNum(self, Arr, N):
        xorr, bit, bucket1, bucket2 = 0, 37, 0, 0
        Arr = [int(i) for i in Arr]
        for i in Arr:
            xorr ^= i

        for i in range(37, -1, -1):
            if ((xorr >> i) & 1):
                bit = i
                break

        for i in Arr:
            if ((i >> bit) & 1):
                bucket1 ^= i
            else:
                bucket2 ^= i
        ans = [bucket1, bucket2]
        if bucket1 < bucket2:
            temp = ans[0]
            ans[0] = ans[-1]
            ans[-1] = temp
        return ans
