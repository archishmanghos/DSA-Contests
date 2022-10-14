class Solution:
    def xorAllNums(self, nums1: List[int], nums2: List[int]) -> int:
        sz1, sz2, xor1, xor2, ans = len(nums1), len(nums2), 0, 0, 0
        for i in nums1: xor1 ^= i
        for i in nums2: xor2 ^= i
        if sz1 & 1: ans ^= xor2
        if sz2 & 1: ans ^= xor1
        return ans