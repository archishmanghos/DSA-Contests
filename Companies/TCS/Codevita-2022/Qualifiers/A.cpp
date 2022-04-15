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

string S, K;

string addPaddingOfSpaces(string x, int length){
    int n = x.size();
    if(n == length){
    	return x;
    }

    for(int i = 1; i <= (length - n); i++){
    	x = x + ' ';
    }

    return x;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("error.txt", "w", stderr);
	#endif

	getline(cin, S);
	cin >> K;
	int N = S.size();

	if(N <= 16){
		S = addPaddingOfSpaces(S, 16);
	}else{
		S = addPaddingOfSpaces(S, 32);
	}
	K = addPaddingOfSpaces(K, 16);

	string S1 = "", S2 = "";
	for(int i = 0; i < 16; i++){
		S1 += S[i];
	}
	if(N > 16){
		for(int i = 16; i < 32; i++){
			S2 += S[i];
		}
	}

	int N1 = S1.size(), N2 = S2.size(), k = 0;
	vector<vector<int>> ME(4, vector<int>(4)), MK(4, vector<int>(4)), rotatedMK(4, vector<int>(4));
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			ME[i][j] = (int)(S1[k++]);
		}
	}

	k = 0;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			MK[i][j] = (int)(K[k++]);
		}
	}

	rotatedMK[0][0] = MK[1][0];
	rotatedMK[0][1] = MK[0][0];
	rotatedMK[0][2] = MK[0][1];
	rotatedMK[0][3] = MK[0][2];

	rotatedMK[1][0] = MK[2][0];
	rotatedMK[1][1] = MK[1][2];
	rotatedMK[1][2] = MK[2][2];
	rotatedMK[1][3] = MK[0][3];

	rotatedMK[2][0] = MK[3][0];
	rotatedMK[2][1] = MK[1][1];
	rotatedMK[2][2] = MK[2][1];
	rotatedMK[2][3] = MK[1][3];

	rotatedMK[3][0] = MK[3][1];
	rotatedMK[3][1] = MK[3][2];
	rotatedMK[3][2] = MK[3][3];
	rotatedMK[3][3] = MK[2][3];

	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			ME[i][j] ^= rotatedMK[i][j];
			ME[i][j] ^= MK[i][j];
			ME[i][j] ^= 4;
		}
	}

	string ans = "";
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			ans += (char)(ME[i][j]);
		}
	}

	if(N2 > 0){
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				ME[i][j] = 0;
			}
		}

		k = 0;
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				ME[i][j] = (int)(S2[k++]);
			}
		}

		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				ME[i][j] ^= rotatedMK[i][j];
				ME[i][j] ^= MK[i][j];
				ME[i][j] ^= 4;
			}
		}

		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				ans += (char)(ME[i][j]);
			}
		}
	}

	cout << ans << '\n';

    return 0;
}