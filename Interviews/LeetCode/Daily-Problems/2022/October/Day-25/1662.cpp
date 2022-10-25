class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i = 0, ii = 0, j = 0, jj = 0;
        while (1) {
            if (ii == word1[i].size()) ii = 0, i += 1;
            if (jj == word2[j].size()) jj = 0, j += 1;

            if (i == word1.size() or j == word2.size()) break;
            if (word1[i][ii] != word2[j][jj]) return false;
            ii += 1, jj += 1;
        }

        return i == word1.size() and j == word2.size();
    }
};