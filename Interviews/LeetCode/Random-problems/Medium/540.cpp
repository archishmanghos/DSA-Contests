int singleNonDuplicate(vector<int> &nums)
{
    int n = nums.size();
    int lb = 0, ub = n - 1;
    int mid = lb + (ub - lb) / 2;
    while(lb < ub - 1)
    {
        if(mid - 1 >= 0 && nums[mid] != nums[mid - 1])
        {
            if(mid + 1 < n && nums[mid] != nums[mid + 1])
                return nums[mid];
        }
        if(mid + 1 < n && nums[mid] != nums[mid + 1])
        {
            if(mid - 1 >= 0 && nums[mid] != nums[mid - 1])
                return nums[mid];
        }
        if((mid + 1) & 1)
        {
            if(mid - 1 == 0 && nums[mid] != nums[mid - 1])
                return nums[mid - 1];
            if(mid - 1 >= 0 && nums[mid] == nums[mid - 1])
                ub = mid;
            else
                lb = mid + 1;
        }
        else
        {
            if(mid + 1 == n - 1 && nums[mid] != nums[mid + 1])
                return nums[mid + 1];
            if(mid + 1 < n && nums[mid] == nums[mid + 1])
                ub = mid;
            else
                lb = mid + 1;
        }
        mid = lb + (ub - lb) / 2;
    }

    if(lb == 0 || (nums[lb] != nums[lb - 1] && nums[lb] != nums[lb + 1]))
        return nums[lb];
    return nums[ub];
}