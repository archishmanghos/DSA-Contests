class Solution {
public:
    string reverseVowels(string s) {
        string vo = "", vowel = "AEIOUaeiou", ans = s;
        for (char c: s) {
            size_t found = vowel.find(c);
            if (found != string::npos) vo += c;
        }
        
        int j = vo.size() - 1;
        for (int i = 0; i < ans.size(); i++) {
            size_t found = vowel.find(ans[i]);
            if (found != string::npos) ans[i] = vo[j--];
        }
        
        return ans;
    }
};