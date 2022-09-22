string reverseWords(string s) {
    s += ' ';
    string ans = "", temp = "";
    for (char c : s) {
        if (c == ' ') {
            if (temp.size() > 0) {
                int i = 0, j = temp.size() - 1;
                while (i < j) {
                    swap(temp[i++], temp[j--]);
                }
                ans += temp;
                ans += ' ';
            }
            temp = "";
        } else {
            temp += c;
        }
    }

    if (ans.back() == ' ') ans.pop_back();
    return ans;
}