int subarraySum(vector<int> &nums, int k) {
    int sumTillNow = 0, ans = 0;
    unordered_map<int, int> sumOccurences;
    sumOccurences[0] = 1;
    for (int i = 0; i < nums.size(); i++) {
        sumTillNow += nums[i];
        int subarraySum = sumTillNow - k;
        if (sumOccurences.find(subarraySum) != sumOccurences.end()) {
            ans += sumOccurences[subarraySum];
        }
        sumOccurences[sumTillNow] += 1;
    }
    return ans;
}