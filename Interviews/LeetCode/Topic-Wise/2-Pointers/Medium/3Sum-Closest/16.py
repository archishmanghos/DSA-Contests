class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        ans, diff, n = -1, 1e9, len(nums)
        nums.sort()
        for i in range(n - 2):
            j, k = i + 1, n - 1
            while j < k:
                x = nums[i] + nums[j] + nums[k]
                if x == target: return x
                if abs(x - target) < diff:
                    diff = abs(x - target)
                    ans = x
                if x < target: j += 1
                else: k -= 1
        
        return ans