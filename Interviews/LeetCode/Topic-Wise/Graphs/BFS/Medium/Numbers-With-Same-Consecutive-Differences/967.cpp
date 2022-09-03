int power(int x) {
    int a = 1;
    while (x--) a *= 10;
    return a;
}

vector<int> numsSameConsecDiff(int n, int k) {
    queue<int> q;
    n--;
    for (int i = 1; i <= 9; i++) {
        q.push(i * power(n));
    }

    while (!q.empty()) {
        n--;
        if (n < 0) break;
        int sz = q.size();
        for (int i = 1; i <= sz; i++) {
            int curNum = q.front();
            q.pop();
            int curDigit = (curNum / power(n + 1)) % 10;
            int leftDigit = (curDigit - k >= 0 ? curDigit - k : -1);
            int rightDigit = (curDigit + k <= 9 ? curDigit + k : -1);

            int newNum1 = -1, newNum2 = -1;
            if (leftDigit != -1) {
                newNum1 = curNum + leftDigit * power(n);
                q.push(newNum1);
            }
            if (rightDigit != -1 and rightDigit != leftDigit) {
                newNum2 = curNum + rightDigit * power(n);
                q.push(newNum2);
            }
        }
    }

    vector<int> v;
    while (!q.empty()) {
        v.push_back(q.front());
        q.pop();
    }
    return v;
}