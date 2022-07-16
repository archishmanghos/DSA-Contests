vector<int> reverseV(vector<int> v) {
    vector<int> ans;
    ans.push_back(v.back());
    for (int i = 0; i < v.size() - 1; i++) {
        ans.push_back(v[i]);
    }
    return ans;
}
int min_operations(int n, vector<int>&arr, vector<int>&brr) {
    reverse(arr.begin(), arr.end());
    reverse(brr.begin(), brr.end());

    int ans = n + 1;
    while (arr.size() > 1) {
        while (arr.back() != brr.back()) {
            arr = reverseV(arr);
            ans += 1;
        }
        arr.pop_back();
        brr.pop_back();
    }

    return ans;
}