#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T;

void solve()
{
    int N;
    cin >> N;
    vector<string> A(N + 2);
    set<string> S;
    map<string, int> index;
    for(int i = 1; i <= N; i++){
    	cin >> A[i];
    	S.insert(A[i]);
    	index[A[i]] = i;
    }

    bool ans = false;
    for(int i = 1; i <= N; i++){
    	if((int)A[i].size() == 3){
    		string s = A[i];
    		if(s[0] != s[1] and s[1] != s[2]){
    			string t = "";
    			t += s[2];
    			t += s[1];
    			ans |= (S.find(t) != S.end() and index[t] < i);
    			t += s[0];
    			ans |= (S.find(t) != S.end()); 

    			t = "";
    			t += s[1];
    			t += s[0];
    			ans |= (S.find(t) != S.end() and index[t] > i);
    		}
    		else if(s[0] == s[1] and s[1] != s[2]){
    			string t = "";
    			t += s[2];
    			ans |= (S.find(t) != S.end() and index[t] < i);
    			t += s[1];
    			ans |= (S.find(t) != S.end() and index[t] < i);
    			t += s[0];
    			ans |= (S.find(t) != S.end());

    			t = "";
    			t += s[1];
    			t += s[0];
    			ans |= (S.find(t) != S.end() and index[t] > i);
    		}
    		else if(s[0] == s[2] and s[0] != s[1]){
                ans = true;
    		}
    		else if(s[1] == s[2] and s[0] != s[1]){
    			string t = "";
    			t += s[2];
    			t += s[1];
    			ans |= (S.find(t) != S.end() and index[t] < i);
    			t += s[0];
    			ans |= (S.find(t) != S.end());

    			t = "";
    			t += s[1];
    			t += s[0];
    			ans |= (S.find(t) != S.end() and index[t] > i);

    			t = "";
    			t += s[0];
    			ans |= (S.find(t) != S.end() and index[t] > i);
    		}
    		else{
                ans = true;
    		}
    	}
    	else if(A[i].size() == 2){
    		string s = A[i];
    		if(s[0] != s[1]){
    			string t = "";
    			t += s[1];
    			ans |= (S.find(t) != S.end() and index[t] < i);
    			t += s[0];
    			ans |= (S.find(t) != S.end());
    			t += s[0];
    			ans |= (S.find(t) != S.end() and index[t] < i);

    			t = "";
    			t += s[0];
    			ans |= (S.find(t) != S.end() and index[t] > i);

    			t = "";
    			t += s[1];
    			t += s[1];
    			t += s[0];
    			ans |= (S.find(t) != S.end() and index[t] > i);
    		}
    		else{
                ans = true;
    		}
    	}
    	else{
            ans = true;
    	}
    }

    cout << (ans ? "YES" : "NO") << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while (T--)
        solve();

    return 0;
}