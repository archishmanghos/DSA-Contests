class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        xorval, j, setBit, bucket1, bucket2, n = 0, 1, 0, 0, 0, len(nums)
        
        for i in nums:
            xorval ^= i ^ j
            j += 1
            
        for i in range(15):
            if (xorval >> i) & 1:
                setBit = i
                break
                
        j = 1
        for i in nums:
            if (i >> setBit) & 1: bucket1 ^= i
            else: bucket2 ^= i
            if (j >> setBit) & 1: bucket1 ^= j
            else: bucket2 ^= j
            j += 1
        
        for i in nums:
            if i == bucket1:
                return [bucket1, bucket2]
        
        return [bucket2, bucket1]