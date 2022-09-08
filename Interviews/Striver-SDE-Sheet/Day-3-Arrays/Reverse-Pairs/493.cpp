void merge(int low, int mid, int high, vector<int> &nums){
    vector<int> temp;
    int i = low, j = mid + 1;
    while(i <= mid or j <= high){
        if(i > mid) temp.push_back(nums[j++]);
        else if(j > high) temp.push_back(nums[i++]);
        else{
            if(nums[i] < nums[j]) temp.push_back(nums[i++]);
            else temp.push_back(nums[j++]);
        }
    }
    
    for(int i = low; i <= high; i++) nums[i] = temp[i - low];
}

int countInversion(int low, int mid, int high, vector<int> &nums){
    int ans = 0, j = mid + 1;
    for(int i = low; i <= mid; i++){
        while(j <= high and nums[i] > 2LL * nums[j]) j++;
        ans += j - (mid + 1);
    }
    
    return ans;
}

void mergeSort(int low, int high, int &ans, vector<int> &nums){
    if(low >= high) return;
    int mid = low + (high - low) / 2;
    mergeSort(low, mid, ans, nums);
    mergeSort(mid + 1, high, ans, nums);
    ans += countInversion(low, mid, high, nums);
    merge(low, mid, high, nums);
}

int reversePairs(vector<int> &nums){
    int ans = 0;
    mergeSort(0, nums.size() - 1, ans, nums);
    return ans;
}