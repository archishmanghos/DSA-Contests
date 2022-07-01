int waysToSplitArray(vector<int>& nums) {
    long sumLeft = 0, sumRight = 0;
    for(int i : nums) sumRight += i;

    int ans = 0;
	for(int i = 0; i < nums.size() - 1; i++){
		sumLeft += nums[i];
		sumRight -= nums[i];
		ans += sumLeft >= sumRight;
	}

	return ans;
}