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
string S1, S2;

void solve() {
	cin >> N >> S1 >> S2;

	bool ans = true;
	string temp1 = "", temp2 = "";
	for(char c : S1) if(c != 'b') temp1 += c;
	for(char c : S2) if(c != 'b') temp2 += c;

	if(temp1 != temp2) ans = false;

	vector<int> pos1, pos2;
	for(int i = 0; i < N; i++){
		if(S1[i] == 'a') pos1.push_back(i);
		if(S2[i] == 'a') pos2.push_back(i);
	}

	if(pos1.size() != pos2.size()) ans = false;
	else for(int i = 0; i < pos1.size(); i++) if(pos1[i] > pos2[i]) ans = false;

	pos1.clear(), pos2.clear();
	for(int i = 0; i < N; i++){
		if(S1[i] == 'c') pos1.push_back(i);
		if(S2[i] == 'c') pos2.push_back(i);
	}

	if(pos1.size() != pos2.size()) ans = false;
	else for(int i = 0; i < pos1.size(); i++) if(pos1[i] < pos2[i]) ans = false;

	cout << (ans ? "YES" : "NO") << '\n';
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