#include <bits/stdc++.h>

// #ifndef ONLINE_JUDGE

// #include <D:/archishmanghos/Practice/Online_Judges/archiDebug.h>

// #else
// #define debug(x)
// #endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int N, M, R;
string toFind;
vector<deque<string>> v(55);

// void print(){
// 	vector<deque<string>> a = v;
// 	for(int i = 0; i < N; i++){
// 		while(!a[i].empty()){
// 			cout << a[i].front() << ' ';
// 			a[i].pop_front();
// 		}
// 		cout << '\n';
// 	}
// }

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	// #ifndef ONLINE_JUDGE
	//     freopen("error.txt", "w", stderr);
	// #endif

	cin >> N >> M;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			string X;
			cin >> X;
			v[i].push_back(X);
		}
	}

	cin >> R >> toFind;
	R %= (N *M);
	while(R > 0){
		int nowRotate = min(R, M);
		for(int i = 0; i < N; i++){
			int j = (i + 1) % N;
			if(i % 2 == 0){
				int k = 0;
				while(k < nowRotate){
					string x = v[i].back();
					v[i].pop_back();
					if(j % 2 == 0){
						v[j].push_front(x);
					}else{
						v[j].push_back(x);
					}
					k += 1;
				}
			}else{
				int k = 0;
				while(k < nowRotate){
					string x = v[i].front();
					v[i].pop_front();
					if(j % 2 == 0){
						v[j].push_front(x);
					}else{
						v[j].push_back(x);
					}
					k += 1;
				}
			}
		}
		R -= nowRotate;
	}

	pair<int, int> ans = {-1, -1};
	for(int i = 0; i < N; i++){
		int j = 0;
		while(!v[i].empty()){
			cout << v[i].front() << ' ';
			if(v[i].front() == toFind){
				ans = {i, j};
			}
			j += 1;
			v[i].pop_front();
		}
		cout << '\n';
	}

	if(ans.first == -1){
		cout << "Not Available";
	}else{
		cout << '[' << ans.first << ", " << ans.second << ']';
	}

    return 0;
}