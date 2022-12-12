class Solution {
   public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }

        int prepre = 1, pre = 2;
        for (int i = 3; i <= n; i++) {
            int cur = pre + prepre;
            prepre = pre;
            pre = cur;
        }

        return pre;
    }
};