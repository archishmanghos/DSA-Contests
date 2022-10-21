class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        lastIndex = {}
        for i in range(len(nums)):
            if nums[i] in lastIndex:
                if i - lastIndex[nums[i]] <= k: return True
            lastIndex[nums[i]] = i
        
        return False