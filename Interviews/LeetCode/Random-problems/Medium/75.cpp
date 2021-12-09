void sortColors(vector<int> &nums)
{
    int low = 0, mid = 0, high = nums.size() - 1;
    while(mid <= high)
    {
        if(nums[mid] == 0)
        {
            swap(nums[mid], nums[low]);
            mid += 1;
            low += 1;
        }
        else if(nums[mid] == 1)
            mid += 1;
        else
        {
            swap(nums[mid], nums[high]);
            high -= 1;
        }
    }
}