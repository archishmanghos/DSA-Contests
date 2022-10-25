class Solution:
    def arrayStringsAreEqual(self, word1: List[str], word2: List[str]) -> bool:
        i, ii, j, jj = 0, 0, 0, 0
        while 1:
            if ii == len(word1[i]): ii, i = 0, i + 1
            if jj == len(word2[j]): jj, j = 0, j + 1
            if i == len(word1) or j == len(word2): break
            if word1[i][ii] != word2[j][jj]: return False
            ii, jj = ii + 1, jj + 1
        
        return True if i == len(word1) and j == len(word2) else False