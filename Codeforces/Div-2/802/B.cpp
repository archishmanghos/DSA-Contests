#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include </home/archishmanghosh/archishmanghos/practice/archidebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, N;
string S;

string findDiff(string str1, string str2)
{
    string str = "";
    int n1 = str1.length(), n2 = str2.length();
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
 
    int carry = 0;
    for (int i = 0; i < n2; i++) {
        int sub
            = ((str1[i] - '0') - (str2[i] - '0') - carry);
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
 
        str.push_back(sub + '0');
    }
    for (int i = n2; i < n1; i++) {
        int sub = ((str1[i] - '0') - carry);
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
 
        str.push_back(sub + '0');
    }

    reverse(str.begin(), str.end());
 
    return str;
}

// https://www.geeksforgeeks.org/difference-of-two-large-numbers/

void solve() {
	cin >> N >> S;
	string toBeAdded = S;
	int i = 0, j = N - 1;
	while(i < j){
		if(S[i] != S[j]) toBeAdded[i] = toBeAdded[j] = max(S[i], S[j]);
		i += 1, j -= 1;
	}
	
	if(toBeAdded[0] == S[0]){
		char nextDigit = (toBeAdded[0] == '9' ? '1' : toBeAdded[0] + 1);
		string prevAdd = toBeAdded;
		toBeAdded.clear();
		if(nextDigit == '1') {
			for(int i = 0; i <= N; i++) toBeAdded += '1';
		}else{
			toBeAdded = prevAdd;
			toBeAdded[0] = toBeAdded[N - 1] = nextDigit;
		}

		string ans = findDiff(toBeAdded, S);
		cout << (ans[0] == '0' ? ans.substr(1) : ans) << '\n';
		return;
	}

	string ans = "";
	for(int i = 0; i < N; i++) ans += ((toBeAdded[i] - S[i]) + '0');

	cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif

    cin >> T;
    while (T--)
        solve();

    return 0;
}