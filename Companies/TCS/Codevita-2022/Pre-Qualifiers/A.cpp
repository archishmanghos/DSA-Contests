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

bool checkPrime(int n){
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0){
			return false;
		}
	}

	return true;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	// #ifndef ONLINE_JUDGE
	//     freopen("error.txt", "w", stderr);
	// #endif

	vector<int> A;
	int X, N = 0;
	while(cin >> X){
		A.push_back(X);
		N += 1;
	}

	sort(A.begin(), A.end(), greater<int>());
	int minn = A.back();
	A.pop_back();
	N -= 1;

	if(minn > 1){
		for(int i = 0; i < N; i++){
			if(A[i] != 1 and A[i] % minn == 0){
				cout << "None";
				return 0;
			}
		}
	}

	int lcmm = A[0];
	for(int i = 1; i < N; i++){
		lcmm = (A[i] * lcmm) / (__gcd(A[i], lcmm));
	}

	if(lcmm % 2 == 0 and minn % 2 == 0){
		cout << "None";
		return 0;
	}

	if(__gcd(lcmm, minn) > 1){
		cout << "None";
	}else{
		while(!checkPrime(lcmm + minn)){
			lcmm += lcmm;
		}
		cout << lcmm + minn;
	}

    return 0;
}