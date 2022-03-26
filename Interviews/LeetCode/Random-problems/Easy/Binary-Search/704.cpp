int search(vector<int> &nums, int target){
    int lb = 0, ub = nums.size() - 1;
    while(lb <= ub){
        int mid = lb + (ub - lb) / 2;
        if(nums[mid] == target){
            return mid;
        }
        if(target > nums[mid]){
            lb = mid + 1;
        }else{
            ub = mid - 1;
        }
    }
    return -1;
}