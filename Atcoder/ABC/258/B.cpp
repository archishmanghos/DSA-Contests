#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include </home/archishmanghosh/archishmanghos/practice/archidebug.h>

#else
#define debug(x)
#endif

#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e5 + 7;

int N;
char A[15][15];

string getPath(pair<int, int> curCell, pair<int, int> p){
	string curString = "";
	curString += A[curCell.first][curCell.second];
	for(int k = 1; k <= N - 1; k++){
		curCell.first += p.first, curCell.second += p.second;
		if(curCell.first < 1) curCell.first = N;
		if(curCell.first > N) curCell.first = 1;
		if(curCell.second < 1) curCell.second = N;
		if(curCell.second > N) curCell.second = 1;
		curString += A[curCell.first][curCell.second];
	}

	return curString;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif

    cin >> N;
    char maxSquare = '0';
    for(int i = 1; i <= N; i++){
    	for(int j = 1; j <= N; j++) {
    		cin >> A[i][j];
    		maxSquare = max(maxSquare, A[i][j]);
    	}
    }

    string ans = "0";
    for(int i = 1; i <= N; i++){
    	for(int j = 1; j <= N; j++){
    		if(A[i][j] == maxSquare){
    			pair<int, int> curCell = {i, j};
    			pair<int, int> left = {0, -1}, right = {0, 1}, up = {-1, 0}, down = {1, 0}, leftUp = {-1, -1}, rightUp = {-1, 1}, leftDown = {1, -1}, rightDown = {1, 1};
    			ans = max(ans, getPath(curCell, left));
    			ans = max(ans, getPath(curCell, right));
    			ans = max(ans, getPath(curCell, up));
    			ans = max(ans, getPath(curCell, down));

    			ans = max(ans, getPath(curCell, leftUp));
    			ans = max(ans, getPath(curCell, rightUp));
    			ans = max(ans, getPath(curCell, leftDown));
    			ans = max(ans, getPath(curCell, rightDown));
    		}
    	}
    }

    cout << ans;

    return 0;
}