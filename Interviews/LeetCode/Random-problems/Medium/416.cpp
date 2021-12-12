int cache[205][20005];
bool dp(int index, int sum, vector<int> &nums, int &n)
{
    if(index >= n)
        return false;
    if(sum == 0)
        return true;
    if(cache[index][sum] != -1)
        return cache[index][sum];
    if(nums[index] <= sum)
    {
        sum -= nums[index];
        bool ans1 = dp(index + 1, sum, nums, n);
        sum += nums[index];
        bool ans2 = dp(index + 1, sum, nums, n);
        return cache[index][sum] = (ans1 | ans2);
    }
    else
        return cache[index][sum] = dp(index + 1, sum, nums, n);
}
bool canPartition(vector<int> &nums)
{
    int sum = 0;
    for(int i : nums)
        sum += i;
    if(sum % 2 == 0)
    {
        memset(cache, -1, sizeof(cache));
        sum /= 2;
        int n = nums.size();
        return dp(0, sum, nums, n);
    }
    else
        return false;
}