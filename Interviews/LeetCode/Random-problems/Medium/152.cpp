int maxProduct(vector<int> &nums)
{
    int n = nums.size();
    int minn = nums[0], maxx = nums[0], ans = nums[0];
    for(int i = 1; i < n; i++)
    {
        int minn1 = min(nums[i], min(minn * nums[i], maxx * nums[i]));
        int maxx1 = max(nums[i], max(maxx * nums[i], minn * nums[i]));

        ans = max(ans, maxx1);
        maxx = maxx1;
        minn = minn1;
    }
    return ans;
}