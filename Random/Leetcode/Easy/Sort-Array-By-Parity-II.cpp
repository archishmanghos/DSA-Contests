vector<int> sortArrayByParityII(vector<int> &nums)
{
    vector<int> even, odd;
    for(auto it : nums)
    {
        if(it % 2 == 0)
            even.push_back(it);
        else
            odd.push_back(it);
    }

    int i = 0, j = 0;
    vector<int> ans;
    for(int k = 0; k < nums.size(); k++)
    {
        if(k & 1)
            ans.push_back(odd[j++]);
        else
            ans.push_back(even[i++]);
    }
    return ans;
}

/*

Time-Complexity: O(N)
Space-Complexity: O(2*N)

Implementation

*/