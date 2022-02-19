vector<long long> maximumEvenSplit(long long finalSum) {
    long long n = -1;
    vector<long long> ans;

    if (finalSum % 2) {
        return ans;
    }

    for (long long i = 1; i <= 1000000; i++) {
        if ((i * (i + 1)) <= finalSum) {
            n = i;
        } else {
            break;
        }
    }

    long long firstSum = n * (n + 1);
    long long remSum = finalSum - firstSum;
    if (remSum <= n * 2) {
        long long sum = 0;
        for (long long i = 1; i < n; i++) {
            ans.push_back(i * 2);
            sum += i * 2;
        }
        ans.push_back(finalSum - sum);
    } else {
        long long sum = 0;
        for (long long i = 1; i <= n; i++) {
            ans.push_back(i * 2);
            sum += i * 2;
        }
        ans.push_back(finalSum - sum);
    }

    return ans;
}