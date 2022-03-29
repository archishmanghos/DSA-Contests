long long int calculate(int a[], int n)
{
    long long ans = 0;
    vector<int> cnt(100005, 0);
    for(int i = 0; i < n; i++){
        cnt[a[i]] += 1;
        ans += cnt[a[i]] - 1;
    }
    return ans;
}