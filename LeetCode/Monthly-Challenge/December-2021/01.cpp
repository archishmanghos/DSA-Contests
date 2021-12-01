int rob(vector<int> &nums)
{
    int ans1 = 0, ans2 = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        if(i & 1)
            ans1 = max(ans1 + nums[i], ans2);
        else
            ans2 = max(ans2 + nums[i], ans1);
    }
    return max(ans1, ans2);
}