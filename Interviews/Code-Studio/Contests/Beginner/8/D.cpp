long long int maximumProfit(int n, int k, vector<int> a){
	sort(a.begin(), a.end());
	long long ans = 0;
	for(int i = n - 1; i > n - 1 - k; i--) ans += a[i];
	
	return ans;
}