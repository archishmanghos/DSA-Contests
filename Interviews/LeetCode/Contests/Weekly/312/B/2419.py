class Solution(object):
    def longestSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        maxx, cnt, ans, cur = max(nums), 0, 0, nums[0]
        for i in range(len(nums)):
            if nums[i] ==  cur:
                cnt += 1
            else:
                if cur == maxx:
                    ans = max(ans, cnt)
                cur, cnt = nums[i], 1
        
        if cur == maxx:
            ans = max(ans, cnt)
        
        return ans