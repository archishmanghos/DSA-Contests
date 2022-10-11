class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        ans, n = [], len(nums)
        for i in range(n):
            if len(ans) == 0 or nums[i] > ans[-1]:
                ans.append(nums[i])
            else:
                idx = bisect.bisect_left(ans, nums[i])
                ans[idx] = nums[i]
            if len(ans) > 2:
                return True
            
        return False