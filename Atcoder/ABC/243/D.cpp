#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include <D:/archishmanghos/Practice/Online_Judges/archiDebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int N, X;
string S;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("error.txt", "w", stderr);
	#endif

	cin >> N >> X >> S;
	stack<char> st;

	for(int i = 0; i < N; i++){
		if(S[i] == 'U'){
			if(st.size() and st.top() != 'U'){
				st.pop();
			}else{
				st.push('U');
			}
		}else{
			st.push(S[i]);
		}
	}

	string final = "";
	while(!st.empty()){
		final += st.top();
		st.pop();
	}

	reverse(final.begin(), final.end());
	for(int i = 0; i < final.size(); i++){
		if(final[i] == 'U' and X > 1){
			X >>= 1;
		}else if(final[i] == 'L'){
			X <<= 1;
		}else{
			X <<= 1;
			X += 1;
		}
	}
 
	cout << X;

    return 0;
}