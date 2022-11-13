class Solution:
    def reverseWords(self, s: str) -> str:
        words, word = [], ""
        for c in s:
            if c != ' ':
                word += c
            else:
                if len(word):
                    words.append(word)
                    word = ""
        if len(word):
            words.append(word)
        ans = ""
        for idx, c in enumerate(reversed(words)):
            ans += c
            if idx < len(words) - 1:
                ans += ' '

        return ans
