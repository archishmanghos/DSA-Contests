long long smallestNumber(long long num) {
    if (num > 0) {
        string n1 = integertostring(num);
        sort(n1.begin(), n1.end());

        int minn = 10, pos = -1;
        for (int i = 0; i < n1.size(); i++) {
            char c = n1[i];
            if (c != '0') {
                if ((c - '0') < minn) {
                    minn = (c - '0');
                    pos = i;
                }
            }
        }

        swap(n1[pos], n1[0]);
        long long ans = stringtointeger(n1);
        return ans;
    } else if (num < 0) {
        string n1 = integertostring(abs(num));
        sort(n1.begin(), n1.end());
        reverse(n1.begin(), n1.end());
        long long ans = stringtointeger(n1);
        return -ans;
    } else {
        return (long long) 0;
    }
}