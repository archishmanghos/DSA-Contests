class Solution:
    def reverseVowels(self, s: str) -> str:
        vo, vowel, ans = "", "AEIOUaeiou", list(s)
        for c in s:
            if c in vowel:
                vo += c
        j = len(vo) - 1
        for idx, i in enumerate(ans):
            if i in vowel:
                ans[idx] = vo[j]
                j -= 1

        return "".join(ans)
