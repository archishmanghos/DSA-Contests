int findMaxConsecutiveOnes(vector<int> &nums)
{
    int ans = 0, cnt = 1;
    for(int i = 1; i < nums.size(); i++)
    {
        if(nums[i] == nums[i - 1])
            cnt += 1;
        else
        {
            if(nums[i] == 0)
                ans = max(ans, cnt);
            cnt = 1;
        }
    }
    if(nums[nums.size() - 1] == 1)
        ans = max(ans, cnt);

    return ans;
}

/*

Time-Complexity: O(N)
Space-Complexity: O(1)

Easy Greedy Solution

*/