class Solution {
public:
    string maxSum(string w, char x[], int b[], int n) {
        long sum = 0, maxSum = 0;
        string ans = "", s = "";
        for (int i = 0; i < w.size(); i++) {
            int val = (int)w[i];
            for (int j = 0; j < n; j++) {
                if (x[j] == w[i]) {
                    val = b[j];
                    break;
                }
            }

            sum += val;
            s += w[i];
            if (sum < 0) {
                sum = 0;
                s = "";
            }
            if (sum > maxSum) {
                maxSum = sum;
                ans = s;
            }
        }

        if (ans.size() == 0) {
            char lowChar;
            long minn = -1e9;
            for (int i = 0; i < n; i++) {
                if (b[i] > minn) {
                    minn = b[i];
                    lowChar = x[i];
                }
            }

            ans += lowChar;
        }

        return ans;
    }
};