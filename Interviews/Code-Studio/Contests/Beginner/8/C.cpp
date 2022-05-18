int MaxLevels(int n, int f, vector<int> &A){
    int sum = 0, start = 0, end = 0, ans = 0;
	for(int i = 0; i < n; i++){
		sum += A[i];
		end += 1;
		while(sum > f){
			sum -= A[start];
			start += 1;
		}
		
		ans = max(ans, end - start);
	}
	
	return ans;
}