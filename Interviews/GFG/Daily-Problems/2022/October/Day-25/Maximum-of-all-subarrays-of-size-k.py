from collections import deque
class Solution:
    def max_of_subarrays (self, arr, n, k):
        dq, ans = deque(),[]
        for i in range(n):
            while len(dq) and arr[i] > arr[dq[-1]]: dq.pop()
            dq.append(i)
            while len(dq) and dq[0] < (i - k + 1): dq.popleft()
            if i >= k - 1: ans.append(arr[dq[0]]);
        
        return ans