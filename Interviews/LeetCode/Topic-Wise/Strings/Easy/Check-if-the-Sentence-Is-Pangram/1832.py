class Solution:
    def checkIfPangram(self, sentence: str) -> bool:
        cnt = [0 for i in range(26)]
        for c in sentence:
            cnt[ord(c) - 97] |= 1
        for i in cnt:
            if not i:
                return False
        
        return True