#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T;

bool canBeHeight(int height, vector<int> &A, vector<int> &B, int &N){
    for(int i = N; i >= 3; i--){

        if(A[i] < height){
            return false;
        }

        int canMoveD = min(B[i], (A[i] - height)) / 3;
        A[i - 1] += canMoveD;
        A[i - 2] += 2 * canMoveD;

    }

    if(A[1] < height or A[2] < height){
        return false;
    }

    return true;
}

void solve()
{
    int N;
    cin >> N;
    vector<int> A(N + 2);
    int low = INF, high = -INF;
    vector<int> B(N + 2);

    for(int i = 1; i <= N; i++){
    	cin >> A[i];
        B[i] = A[i];
        low = min(low, A[i]);
        high = max(high, A[i]);
    }

    while(low < (high - 1)){
        int height = low + (high - low) / 2;
        bool canBe = canBeHeight(height, A, B, N);
        if(canBe){
            low = height;
        }else{
            high = height - 1;
        }
        for(int i = 1; i <= N; i++){
            A[i] = B[i];
        }
    }

    if(canBeHeight(high, A, B, N)){
        cout << high << '\n';
    }else{
        cout << low << '\n';
    }
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