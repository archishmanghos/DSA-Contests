string integerToString(int num){
	if(num == 0) return "0";
	string ans = "";
	while(num > 0){
		ans += ((num % 10) + '0');
		num /= 10;
	}

	reverse(ans.begin(), ans.end());
	return ans;
}

long stringToInteger(string s){
	long ans = 0, j = 1;
	reverse(s.begin(), s.end());
	for(int i = 0; i < s.size(); i++){
		ans += (s[i] - '0') * j;
		j *= 10;
	}

	return ans;
}

int divisorSubstrings(int num, int k) {
    string n = integerToString(num);
    int ans = 0;
    for(int i = 0; i <= (n.size() - k); i++){
    	string nowS = n.substr(i, k);
    	long nowSInt = stringToInteger(nowS);
    	if(nowSInt > 0 and	num % nowSInt == 0) ans += 1;
    }

    return ans;
}