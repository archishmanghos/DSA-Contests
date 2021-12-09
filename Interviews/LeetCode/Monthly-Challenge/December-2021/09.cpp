bool dp(int index, vector<int> &a, int &n)
{
    if(index >= n || index < 0)
        return false;
    if(a[index] == 0)
        return true;
    if(a[index] < 0)
        return false;
    a[index] = -a[index];
    bool ans = dp(index + a[index], a, n) | dp(index - a[index], a, n);
    return ans;
}
bool canReach(vector<int> &arr, int start)
{
    int n = arr.size();
    return dp(start, arr, n);
}