vector<long long> sumOfThree(long long num) {
    vector<long long> ans;
    if (num % 3 != 0) {
        return ans;
    }

    num /= 3;
    ans.push_back((long long) -1 + num);
    ans.push_back((long long) 0 + num);
    ans.push_back((long long) 1 + num);
    return ans;
}