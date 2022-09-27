long long minCost(long long arr[], long long n) {
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 0; i < n; i++) {
        pq.push(arr[i]);
    }

    long long ans = 0;
    while (pq.size() > 1) {
        long long top1 = pq.top();
        pq.pop();
        long long top2 = pq.top();
        pq.pop();
        pq.push(top1 + top2);
        ans += top1 + top2;
    }

    return ans;
}