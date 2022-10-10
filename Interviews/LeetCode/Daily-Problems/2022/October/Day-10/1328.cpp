class Solution {
public:
    string breakPalindrome(string palindrome) {
        bool done = false;
        string ans = palindrome;
        int i = 0, j = palindrome.size() - 1;
        while (i < j) {
            if (ans[i] != 'a') {
                ans[i] = 'a';
                done = true;
                break;
            }
            i += 1, j -= 1;
        }

        if (!done) {
            if (palindrome.size() > 1) {
                ans.back() = 'b';
            } else {
                ans = "";
            }
        }

        return ans;
    }
};