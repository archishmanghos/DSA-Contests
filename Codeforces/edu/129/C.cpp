#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include <D:/archishmanghos/Practice/Online_Judges/archiDebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 105;
const int INF = 1e18 + 7;

int T, N, A[mxN], B[mxN], C[mxN];

void solve() {
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> A[i], C[i] = A[i];
    for(int i = 1; i <= N; i++) cin >> B[i];

    sort(C + 1, C + N + 1);
	vector<pair<int, int>> ans;
	for(int i = 1; i <= N; i++){
		if(A[i] != C[i]){
			if(i < N){
				int index = -1;
				for(int j = i + 1; j <= N; j++){
					if(A[j] == C[i] and B[j] == B[i]){
						index = j;
						break;
					}
				}

				if(index != -1){
					swap(A[i], A[index]);
					ans.push_back({i, index});
					continue;
				}

				for(int j = i + 1; j <= N; j++){
					if(A[j] == C[i] and B[j] < B[i]){
						index = j;
						break;
					}
				}	

				if(index != -1){
					swap(A[i], A[index]);
					swap(B[i], B[index]);
					ans.push_back({i, index});
					continue;
				}	

				for(int j = i + 1; j <= N; j++){
					if(A[j] == C[i]){
						index = j;
						break;
					}
				}	

				swap(A[i], A[index]);
				swap(B[i], B[index]);
				ans.push_back({i, index});
			}else{
				cout << -1 << '\n';
				return;
			}
		}
	}

	for(int i = 1; i <= N; i++) C[i] = B[i];
	sort(C + 1, C + N + 1);
	
	for(int i = 1; i <= N; i++){
		if(B[i] != C[i]){
			if(i < N){
				int index = -1;
				for(int j = i + 1; j <= N; j++){
					if(B[j] == C[i] and A[i] == A[j]){
						index = j;
						break;
					}
				}

				if(index != -1){
					swap(B[i], B[index]);
					ans.push_back({i, index});
				}else{
					cout << -1 << '\n';
					return;
				}
			}else{
				cout << -1 << '\n';
				return;
			}
		}
	}

	cout << ans.size() << '\n';
	for(auto i : ans) cout << i.first << ' ' << i.second << '\n';
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