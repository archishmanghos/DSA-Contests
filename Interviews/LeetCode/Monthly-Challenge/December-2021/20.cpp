vector<vector<int>> minimumAbsDifference(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> ans;
    int minDiff = 10000000;
    sort(arr.begin(), arr.end());
    for(int i = 1; i < n; i++)
    {
        if(abs(arr[i] - arr[i - 1]) == minDiff)
            ans.push_back({arr[i - 1], arr[i]});
        else if(abs(arr[i] - arr[i - 1]) < minDiff)
        {
            ans.clear();
            minDiff = min(minDiff, abs(arr[i] - arr[i - 1]));
            ans.push_back({arr[i - 1], arr[i]});
        }
    }
    return ans;
}