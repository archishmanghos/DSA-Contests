#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include <D:/archishmanghos/Practice/Online_Judges/archiDebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e5 + 7;

int N, X;
map<string, int> cache;

string integertostring(int x){
    string ans = "";
    while (x > 0){
        ans += (x % 10) + '0';
        x /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}


// https://www.tutorialspoint.com/multiply-strings-in-cplusplus
string multiply(string nums1, string nums2)
{
    int n = nums1.size();
	int m = nums2.size();
	string ans(n + m, '0');
	for(int i = n - 1; i>=0; i--){
	    for(int j = m - 1; j >= 0; j--){
	        int p = (nums1[i] - '0') * (nums2[j] - '0') + (ans[i + j + 1] - '0');
	        ans[i + j + 1] = p % 10 + '0';
	        ans[i + j] += p / 10 ;
	      }
	   }
	for(int i = 0; i < m + n; i++){
	    if(ans[i] != '0')return ans.substr(i);
	}
   return "0";
}

int dp(string number){
	if(number.size() == N) return 0;
	if(cache.find(number) != cache.end()) return cache[number];
	char maxDigit = '0';
	for(char c : number) maxDigit = max(maxDigit, c);
	if(maxDigit == '1') return INF;

	int ans = INF;
	for(char c : number){
		if(c == '1' or c == '0') continue;
		string mul = "";
		mul += c;
		string newNumber = multiply(number, mul);
		ans = min(ans, dp(newNumber) + 1);
	}

	return cache[number] = ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("error.txt", "w", stderr);
	#endif

	cin >> N >> X;
	string number = integertostring(X);
	int ans = dp(number);
	cout << (ans == INF ? -1 : ans) << '\n';

    return 0;
}