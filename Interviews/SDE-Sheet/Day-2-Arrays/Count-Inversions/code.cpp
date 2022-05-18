long long merge(int low, int mid, int high, long long *arr, int &n){
	vector<long long> a;
	int i = low, j = mid + 1;
	long long inversions = 0;
	while(i <= mid or j <= high){
		if(i > mid){
			a.push_back(arr[j++]);
		}else if(j > high){
			a.push_back(arr[i++]);
		}else{
			if(arr[i] <= arr[j]){
				a.push_back(arr[i++]);
			}else{
				inversions += mid - i + 1;
				a.push_back(arr[j++]);
			}
		}
	}

	for(int i = low; i <= high; i++){
		arr[i] = a[i - low];
	}
	
	return inversions;
}

void mergeSort(int low, int high, long long &ans, long long *arr, int &n){
	if(low >= high){
		return;
	}
	
	int mid = low + (high - low) / 2;
	mergeSort(low, mid, ans, arr, n);
	mergeSort(mid + 1, high, ans, arr, n);
	ans += merge(low, mid, high, arr, n);
}

long long getInversions(long long *arr, int n){
    long long ans = 0;
	mergeSort(0, n - 1, ans, arr, n);
	return ans;
}