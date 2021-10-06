vector<int> findDuplicates(vector<int> &nums)
{
    vector<int> ans;
    for(int i = 0; i < nums.size(); i++)
    {
        int indexToInvert = abs(nums[i]) - 1;
        if(nums[indexToInvert] < 0)
            ans.push_back(abs(nums[i]));
        nums[indexToInvert] = -nums[indexToInvert];
    }
    return ans;
}

/*

Analysis:

Time-Complexity: O(N)
Space-Complexity: O(N)

when encountering an integer change the position of integer-1 to negative. When you encounter the integer again, the position will already be negative. Little tricky but interesting.

*/