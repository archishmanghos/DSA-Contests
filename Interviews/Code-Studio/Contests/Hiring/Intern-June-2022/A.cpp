string confusedNinja(string s) {
    vector<int> cnt(26, 0);
    for(char c : s) cnt[c - 'a'] += 1;

    string ans = "";
	string s1 = "one", s2 = "zero";
	int one = 100000;
	for(char c : s1) one = min(one, cnt[c - 'a']);
	for(int i = 1; i <= one; i++) ans += '1';

	int zero = 100000;
	for(char c : s2) zero = min(zero, cnt[c - 'a']);
	for(int i = 1; i <= zero; i++) ans += '0';

	return ans;
}