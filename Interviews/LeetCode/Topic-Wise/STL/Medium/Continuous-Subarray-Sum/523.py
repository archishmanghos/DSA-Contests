class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        ump, curSum, n = {}, 0, len(nums)
        ump[0] = -1
        for i in range(n):
            curSum = (curSum + nums[i]) % k
            if curSum in ump:
                if i - ump[curSum] > 1: return True
            else:
                ump[curSum] = i
        
        return False