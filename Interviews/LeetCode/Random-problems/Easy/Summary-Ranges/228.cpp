string integerToString(long long n) {
    string ans = "";
    while (n > 0) {
        ans += ((n % 10) + '0');
        n /= 10;
    }
    if (ans.size() == 0) {
        ans += '0';
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

vector <string> summaryRanges(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector <string> ans;

    if (nums.size() == 0) {
        return ans;
    }

    long long start = nums[0], end = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == end + 1) {
            end = nums[i];
        } else {
            string s = "";
            if (start == end) {
                if (start < 0) {
                    s += '-';
                    start = abs(start);
                }
                s += integerToString(start);

            } else {
                if (start < 0) {
                    s += '-';
                    start = abs(start);
                }
                s += integerToString(start);
                s += "->";
                if (end < 0) {
                    s += '-';
                    end = abs(end);
                }
                s += integerToString(end);
            }
            ans.push_back(s);
            start = end = nums[i];
        }
    }

    string s = "";
    if (start == end) {
        if (start < 0) {
            s += '-';
            start = abs(start);
        }
        s += integerToString(start);

    } else {
        if (start < 0) {
            s += '-';
            start = abs(start);
        }
        s += integerToString(start);
        s += "->";
        if (end < 0) {
            s += '-';
            end = abs(end);
        }
        s += integerToString(end);
    }
    ans.push_back(s);

    return ans;
}