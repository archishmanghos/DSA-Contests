int solve(int N, int y, vector<int> A) {
      unordered_map<int, int> mp;
      for(int i = 0; i < N; i++) mp[A[i]] += 1;
      int ans = 0;
      for(auto i : mp) ans = max(ans, i.second);
      return ans;
}