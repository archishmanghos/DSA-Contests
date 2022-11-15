class Solution {
   public:
    int longestPerfectPiece(int arr[], int N) {
        multiset<int> ms;
        int ans = 0, j = 0;
        for (int i = 0; i < N; i++) {
            ms.insert(arr[i]);
            while (*ms.rbegin() - (*ms.begin()) > 1) {
                ms.erase(arr[j]);
                j += 1;
            }
            ans = max(ans, i - j + 1);
        }

        return ans;
    }
};