int maxSumTwoNoOverlap(vector<int> &nums, int firstLen, int secondLen) {

    if (firstLen < secondLen) {
        swap(firstLen, secondLen);
    }
    int n = nums.size();

    int curSumLen1 = 0;
    for (int i = 0; i < firstLen; i++) {
        curSumLen1 += nums[i];
    }

    int ans = 0;
    for (int i = 0; i < (n - firstLen + 1); i++) {
        if (i >= 1) {
            curSumLen1 += nums[i + firstLen - 1];
            curSumLen1 -= nums[i - 1];
        }

        int maxSumLen2 = 0;
        if (i >= secondLen) {
            for (int j = 0; j < secondLen; j++) {
                maxSumLen2 += nums[j];
            }
            int curSumLen2 = maxSumLen2;
            for (int j = secondLen; j < i; j++) {
                curSumLen2 += nums[j];
                curSumLen2 -= nums[j - secondLen];
                maxSumLen2 = max(maxSumLen2, curSumLen2);
            }
        }

        if (i + firstLen + secondLen <= n) {
            int curSumLen2 = 0;
            for (int j = i + firstLen; j < i + firstLen + secondLen; j++) {
                curSumLen2 += nums[j];
            }
            maxSumLen2 = max(maxSumLen2, curSumLen2);

            for (int j = i + firstLen + secondLen; j < n; j++) {
                curSumLen2 += nums[j];
                curSumLen2 -= nums[j - secondLen];
                maxSumLen2 = max(maxSumLen2, curSumLen2);
            }
        }
        ans = max(ans, (curSumLen1 + maxSumLen2));
    }

    return ans;
}