class Solution {
public:
   int findSum(int A[], int N) {
      long maxx = -1e18, minn = 1e18;
      for (int i = 0; i < N; i++) {
         maxx = max(maxx, 1L * A[i]);
         minn = min(minn, 1L * A[i]);
      }

      return int(maxx + minn);
   }

};