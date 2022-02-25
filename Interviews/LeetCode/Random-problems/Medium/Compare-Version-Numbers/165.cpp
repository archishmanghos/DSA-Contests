int stringToInteger(string s) {
    int ans = 0, j = 1, startPos = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] > '0') {
            startPos = i;
            break;
        }
    }
    for (int i = s.size() - 1; i >= startPos; i--) {
        ans += (s[i] - '0') * j;
        j *= 10;
    }
    return ans;
}

int compareVersion(string version1, string version2) {
    int i = 0, j = 0, N1 = version1.size(), N2 = version2.size();
    while (true) {
        string s1 = "", s2 = "";
        while (i < N1 and version1[i] != '.') {
            s1 += version1[i];
            i += 1;
        }
        i += 1;

        while (j < N2 and version2[j] != '.') {
            s2 += version2[j];
            j += 1;
        }
        j += 1;

        if (s1.size() == 0 and s2.size() == 0) {
            break;
        }

        int comp1 = stringToInteger(s1);
        int comp2 = stringToInteger(s2);

        if (comp1 != comp2) {
            return (comp1 < comp2 ? -1 : 1);
        }
    }

    return 0;
}