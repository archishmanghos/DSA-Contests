vector<int> reverse(vector<int> &nums, int start){
    int end = nums.size() - 1;
    while(start < end){
        swap(nums[start], nums[end]);
        start += 1, end -= 1;
    }
    
    return nums;
}

void nextPermutation(vector<int> &nums){
    int n = nums.size(), breakPoint = -1;
    for(int i = n - 2; i >= 0; i--){
        if(nums[i] < nums[i + 1]){
            breakPoint = i;
            break;
        }
    }
    
    if(breakPoint == -1){
        nums = reverse(nums, 0);
    }else{
        for(int i = n - 1; i > breakPoint; i--){
            if(nums[i] > nums[breakPoint]){
                swap(nums[i], nums[breakPoint]);
                break;
            }
        }
        
        nums = reverse(nums, breakPoint + 1);
    }
}