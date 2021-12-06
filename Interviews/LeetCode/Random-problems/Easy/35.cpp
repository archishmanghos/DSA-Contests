int searchInsert(vector<int> &nums, int target)
{
    int lb = 0, ub = nums.size() - 1;
    while(lb < ub)
    {
        int mid = lb + (ub - lb) / 2;
        if(nums[mid] < target)
            lb = mid + 1;
        else
            ub = mid;
    }
    if(target > nums[ub])
        return ub + 1;
    return ub;
}