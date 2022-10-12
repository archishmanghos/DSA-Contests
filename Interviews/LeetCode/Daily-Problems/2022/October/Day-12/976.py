class Solution:
    def check(self, a, b, c) -> bool:
        if a + b > c and a + c > b and b + c > a:
            return True
        return False
        
    def largestPerimeter(self, nums: List[int]) -> int:
        nums.sort()
        for i in range(len(nums) - 1, 1, -1):
            if self.check(nums[i], nums[i - 1], nums[i - 2]):
                return nums[i] + nums[i - 1] + nums[i - 2]
        
        return 0