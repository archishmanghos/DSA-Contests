vector<vector<int>> ans;
void rec(vector<int> &nums, map<int, int> visited, vector<int> v)
{
    if(v.size() == nums.size())
    {
        ans.push_back(v);
        return;
    }
    for(int i = 0; i < nums.size(); i++)
    {
        if(!visited[nums[i]])
        {
            v.push_back(nums[i]);
            visited[nums[i]] = 1;
            rec(nums, visited, v);
            v.pop_back();
            visited[nums[i]] = 0;
        }
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<int> v;
    ans.clear();
    map<int, int> visited;
    rec(nums, visited, v);
    return ans;
}

/*

Analysis:
Time-Complexity: O(N!)
Space-Complexity: O(N*N!)

Easy Recursive approach. C++ has an STL for this, but I guess that's not accepted in an interview.

*/