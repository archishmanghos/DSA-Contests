int maxProfit(vector<int> &prices) {
    int minn = 100000, ans = 0;
    for (int i = 0; i < prices.size(); i++) {
        minn = min(minn, prices[i]);
        ans = max(ans, prices[i] - minn);
    }
    return ans;
}