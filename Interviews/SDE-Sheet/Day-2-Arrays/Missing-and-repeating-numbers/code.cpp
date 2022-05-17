pair<int, int> missingAndRepeating(vector<int> &arr, int n){
	int xorVal = 0;
	for(int i : arr){
		xorVal ^= i;
	}
	for(int i = 1; i <= n; i++){
		xorVal ^= i;
	}

	int setBitPos = 0;
	for(int i = 0; i < n; i++){
		if((xorVal & (1 << i))){
			setBitPos = i;
			break;
		}
	}

	int bucket1 = 0, bucket2 = 0;
	for(int i : arr){
		if((i & (1 << setBitPos)) != 0){
			bucket1 ^= i;
		}else{
			bucket2 ^= i;
		}
	}
	
	for(int i = 1; i <= n; i++){
		if((i & (1 << setBitPos)) != 0){
			bucket1 ^= i;
		}else{
			bucket2 ^= i;
		}
	}
	
	bool okBucket1 = false, okBucket2 = false;
	for(int i : arr){
		okBucket1 |= i == bucket1, okBucket2 |= i == bucket2;
	}
	
	pair<int, int> ans = {(okBucket1 ? bucket2 : bucket1), (okBucket1 ? bucket1 : bucket2)};
	return ans;
}
