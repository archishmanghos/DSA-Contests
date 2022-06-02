int samePlace(int n, vector < int > arr) {
   vector<int> a = arr;
   sort(a.begin(), a.end());
   int ans = 0;
   for(int i = 0; i < n; i++) ans += a[i] == arr[i];
   return ans;
}