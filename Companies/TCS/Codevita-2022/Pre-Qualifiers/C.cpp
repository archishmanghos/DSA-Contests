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

int N, M;
char A[12][102];

struct mario
{
	int initialCalorie, jumpCalorie, coinsCalorie;
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	// #ifndef ONLINE_JUDGE
	//     freopen("error.txt", "w", stderr);
	// #endif

	mario user;
	cin >> user.initialCalorie >> user.jumpCalorie >> user.coinsCalorie;

	cin >> N >> M;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> A[i][j];
		}
	}

	for(int j = 0; j < M; j++){
		if(A[N - 1][j] == 'H'){
			int i = N - 1, jumpHeight = 0;
			while(i >= 0 and A[i][j] == 'H'){
				jumpHeight += 1;
				i -= 1;
			}
			int reqdCalories = jumpHeight * user.jumpCalorie;
			if(user.initialCalorie >= reqdCalories){
				user.initialCalorie -= reqdCalories;
			}else{
				cout << j - 1;
				return 0;
			}
		}else if(A[N - 1][j] != 'H'){
			int i = N - 1, jumpHeight = -1, finalJumpHeight = 0, coinsCollected = 0;
			while(i >= 0){
				jumpHeight += 1;
				if(A[i][j] == 'C'){
					finalJumpHeight = jumpHeight;
					coinsCollected += 1;
				}
				i -= 1;
			}
			if(coinsCollected){
				int coinsChange = coinsCollected * user.coinsCalorie - finalJumpHeight * user.jumpCalorie;
				if(user.initialCalorie + coinsChange < 0){
					cout << j - 1;
					return 0;
				}
				user.initialCalorie += coinsChange;
			}else{
				if(user.initialCalorie == 0){
					cout << j - 1;
					return 0;
				}
				user.initialCalorie -= 1;
			}
		}
	}

	cout << user.initialCalorie;

    return 0;
}