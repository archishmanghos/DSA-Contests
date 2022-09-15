int minSubset(vector<int> &Arr, int N) {
    long long sum = 0, ans = 0;
    sort(Arr.begin(), Arr.end());
    for (int i : Arr) sum += i;
    sum = (sum / 2) + 1;
    for (int i = N - 1; i >= 0; i--) {
        if (sum <= 0) return int(ans);
        ans += 1;
        sum -= Arr[i];
    }

    return int(ans);
}