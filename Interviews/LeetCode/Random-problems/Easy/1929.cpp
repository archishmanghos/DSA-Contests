vector<int> getConcatenation(vector<int> &nums)
{
    int N = nums.size();
    for(int i = 0; i < N; i++)
        nums.push_back(nums[i]);
    return nums;
}

/*

Analysis:

Time Complexity: O(nums.size())
Space Complexity: O(1)

Easy, just push to the original vector instead of a new one to avoid more space.

*/