int maximumNumber(int num) {
    string ans = "";
    while (num > 0) {
        ans += (num % 10) + '0';
        num /= 10;
    }

    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] == '7') {
            ans[i] = '9';
            break;
        }
    }

    int finalAns = 0, j = 1;
    while (ans.size()) {
        finalAns += (ans.back() - '0') * j;
        j *= 10;
        ans.pop_back();
    }

    return finalAns;
}