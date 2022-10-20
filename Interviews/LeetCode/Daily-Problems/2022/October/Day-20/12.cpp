class Solution {
public:
    string intToRoman(int num) {
        vector<string> numerals = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string roman = "";
        for (int i = 0, j = 1000, k = 400, l = 100; i < 14; i++) {
            int digitsReqd = num / j;
            while (digitsReqd--) {
                roman += numerals[i];
            }
            num %= j;
            if (i > 0 and i % 4 == 3) {
                j -= (k - l);
                k /= 10, l /= 10;
            } else {
                j -= (i & 1) ? k : l;
            }
        }

        return roman;
    }
};