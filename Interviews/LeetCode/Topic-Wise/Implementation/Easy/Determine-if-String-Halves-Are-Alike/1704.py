class Solution:
    def isVowel(self, c):
        return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u'

    def halvesAreAlike(self, s: str) -> bool:
        cancelOut, i, j = 0, 0, len(s) - 1
        s = s.lower()
        while (i < j):
            cancelOut += 1 if self.isVowel(s[i]) else 0
            cancelOut -= 1 if self.isVowel(s[j]) else 0
            i, j = i + 1, j - 1

        return cancelOut == 0
