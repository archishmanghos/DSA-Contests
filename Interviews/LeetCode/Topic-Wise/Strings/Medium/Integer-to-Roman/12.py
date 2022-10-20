class Solution:
    def intToRoman(self, num: int) -> str:
        numerals, roman = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"], ""
        i, j, k, l = 0, 1000, 400, 100
        while i < 14:
            digitsReqd = int(num // j)
            for z in range(digitsReqd): roman += numerals[i]
            num %= j
            if i > 0 and i % 4 == 3:
                j -= (k - l)
                k, l = k / 10, l / 10
            else:
                j -= k if (i & 1) else l
            i += 1
        
        return roman