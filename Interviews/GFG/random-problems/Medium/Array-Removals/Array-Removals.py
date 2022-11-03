class Solution:
	def removals (self,arr, n, k):
		arr.sort()
		i, j, ans = 0, 0, 1
		while j < len(arr):
		    if arr[j] - arr[i] <= k:
		        ans = max(ans, j - i + 1)
		        j += 1
		    else:
		        while arr[j] - arr[i] > k:
		            i += 1
		
		return len(arr) - ans