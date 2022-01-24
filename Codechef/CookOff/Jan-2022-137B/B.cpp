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
    vector<int> A(N + 2);
    for(int i = 1; i <= N; i++){
    	cin >> A[i];
    }

    sort(A.begin() + 1, A.begin() + N + 1);
    int sum = 0;
    for(int i = 1; i < N; i++){
    	sum += A[i];
    }

    double avg = (double)sum / (N - 1);
    avg += A[N];

    cout << fixed << setprecision(9) << avg << '\n';
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