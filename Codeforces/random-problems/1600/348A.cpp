#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int N, A[mxN];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> A[i];

    sort(A + 1, A + N + 1, greater<int>());
    int matchesToBeSupervised = A[1];

    for(int i = N; i >= 3; i--)
    {
        int remove = min(A[2] - A[i], matchesToBeSupervised);
        matchesToBeSupervised -= remove;
        A[i] += remove;
    }

    int ans = max(A[1], A[2] + (matchesToBeSupervised + N - 2) / (N - 1));

    cout << ans;

    return 0;
}