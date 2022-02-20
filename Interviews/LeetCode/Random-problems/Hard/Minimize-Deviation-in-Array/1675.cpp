int minimumDeviation(vector<int> &nums) {
    int minElement = 1000000009, ans = 1000000009;
    priority_queue<int> pq;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] & 1) {
            nums[i] <<= 1;
        }
        minElement = min(nums[i], minElement);
        pq.push(nums[i]);
    }

    while (pq.top() % 2 == 0) {
        ans = min(ans, abs(pq.top() - minElement));
        minElement = min(pq.top() / 2, minElement);
        pq.push(pq.top() / 2);
        pq.pop();
    }

    return min(ans, abs(pq.top() - minElement));
}