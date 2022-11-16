class Solution:
    def guessNumber(self, n: int) -> int:
        lo, hi = 1, n
        while lo <= hi:
            mid = lo + (hi - lo) // 2
            slope = guess(mid)
            if slope == 0:
                return mid
            elif slope == -1:
                hi = mid - 1
            else:
                lo = mid + 1
        return lo
