int romanToInt(string s) {
    unordered_map<char, int> ump;
    ump['M'] = 1000, ump['D'] = 500, ump['C'] = 100, ump['L'] = 50, ump['X'] = 10, ump['V'] = 5, ump['I'] = 1;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (i < s.size() - 1) {
            string t = s.substr(i, 2);
            i += 1;
            if (t == "IV") ans += 4;
            else if (t == "IX") ans += 9;
            else if (t == "XL") ans += 40;
            else if (t == "XC") ans += 90;
            else if (t == "CD") ans += 400;
            else if (t == "CM") ans += 900;
            else {
                i -= 1;
                ans += ump[s[i]];
            }
        } else {
            ans += ump[s[i]];
        }
    }
    return ans;
}