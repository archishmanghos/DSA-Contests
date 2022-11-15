from sortedcontainers import SortedList
class Solution:
    def longestPerfectPiece(self, arr, N):
        subarray, ans, j =  SortedList(), 0, 0
        for idx, i in enumerate(arr):
            subarray.add(i)
            while subarray[-1] - subarray[0] > 1:
                subarray.discard(arr[j])
                j += 1
            ans = max(ans, idx - j + 1)
        
        return ans