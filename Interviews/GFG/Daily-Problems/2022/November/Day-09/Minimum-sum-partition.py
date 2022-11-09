class Solution:
    def dp(self, index, cursum, arr, totSum, cache) -> int:
        if index == 0:
            sum1 = cursum + arr[index]
            sum2 = totSum - cursum
            return min(abs(sum1 - (totSum - sum1)), abs(cursum - sum2))
        if cache[index][cursum] != -1:
            return cache[index][cursum]
        ans = min(self.dp(index - 1, cursum, arr, totSum, cache),
                  self.dp(index - 1, cursum + arr[index], arr, totSum, cache))
        cache[index][cursum] = ans
        return ans

    def minDifference(self, arr, n):
        totSum = 0
        for i in arr:
            totSum += i
        cache = [[-1 for i in range(totSum + 1)] for j in range(n)]
        return self.dp(n - 1, 0, arr, totSum, cache)
