class Solution {
   public:
    string baseEquiv(int n, int m) {
        for (int i = 2; i < 33; i++) {
            int x = log2(n) / log2(i);
            if (x + 1 == m)
                return "Yes";
        }

        return "No";
    }
};