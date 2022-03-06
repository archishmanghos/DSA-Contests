vector <string> cellsInRange(string s) {
    vector <string> ans;
    string t = s.substr(0, 2);
    int upto = s[s.size() - 1] - '0';
    char upto1 = s[s.size() - 2];

    char start = t[1] - '0';
    char start1 = t[0];

    for (char i = start1; i <= upto1; i++) {
        for (int j = start; j <= upto; j++) {
            string x = "";
            x += i;
            x += (j + '0');
            ans.push_back(x);
        }
    }
    return ans;
}