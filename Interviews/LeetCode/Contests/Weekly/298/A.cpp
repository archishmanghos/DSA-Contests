string greatestLetter(string s) {
    vector<int> cnt(100, 0);
    for(char c : s) cnt[c - 'A'] += 1;

    string ans = "";
    for(int i = 90; i >= 65; i--){
        if(cnt[i - 65] and cnt[(i + 32) - 65]) {
            ans += (char)i;
            break;
        }
    }

    return ans;
}