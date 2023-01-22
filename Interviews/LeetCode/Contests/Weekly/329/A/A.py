class Solution:
    def alternateDigitSum(self, n: int) -> int:
        newN = str(n)
        answer = 0
        cur = 1
        
        for c in newN:
            if cur:
                answer += ord(c) - 48
            else:
                answer -= ord(c) - 48
            cur ^= 1
        
        return answer