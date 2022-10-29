class Solution:
    def earliestFullBloom(self, plantTime: List[int], growTime: List[int]) -> int:
        indices = list (range (0, len(plantTime)))
        indices.sort (key = lambda x: -growTime[x])
        ans, cursum = 0, 0
        for i in indices:
            cursum += plantTime[i]
            ans = max(ans, cursum + growTime[i])
        
        return ans