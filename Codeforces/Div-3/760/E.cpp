#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, N, B[mxN];

void solve()
{
    cin >> N;
    for(int i = 1; i <= N; i++)
    	cin >> B[i];

    // a + 4b + 3c + 2d = B[1] .... eqn(1)
    // 2a + b + 4c + 3d = B[2] .... eqn(2)
    // 3a + 2b + c + 4d = B[3] .... eqn(3)
    // 4a + 3b + 2c + d = B[4] .... eqn(4)
    // ----------------------- (Adding all)
    // 10a + 10b + 10c + 10d = Sum of B[i] from i= 1 to 4
    // a + b + c + d = (Sum of B[i] from i= 1 to 4) / 10
    // Sum of A[i] from i= 1 to N = (Sum of B[i] from i= 1 to N) / N * (N + 1) / 2

    int sum = 0;
    for(int i = 1; i <= N; i++)
    	sum += B[i];

    int divide = (N * (N + 1) / 2);
    int sumOfAis;

    if(sum % divide)
    {
    	cout << "NO" << '\n';
    	return;
    }

    sumOfAis = sum / divide;

    // Subtracting eqn(2) from eqn(1)
    // -a + 3b - c -d = B[2] - B[1]
    // 3b - (a + c + d) = B[2] - B[1]
    // 3b - (sumOfAis - b) = B[2] - B[1]
    // 4b - sumOfAis = B[2] - B[1]
    // b = (B[2] - B[1] + sumOfAis) / 4

    // Subtracting eqn(3) from eqn(2)
    // -a - b + 3c -d = B[3] - B[2]
    // 3c - (a + b + d) = B[3] - B[2]
    // 3c - (sumOfAis - c) = B[3] - B[2]
    // 4c - sumOfAis = B[3] - B[2]
    // c = (B[3] - B[2] + sumOfAis) / 4

    // Generalising
    // Subtracting eqn(i+1) from eqn(i) for every i= 1 to N-1
    // A[i+1] = (B[i+1] - B[i] + sumOfAis) / N
    // A[i] = sumOfAis - (sum of A[i] from i= 2 to N)

    int A[N + 2];
    for(int i = 1; i < N; i++)
    {
    	int x = (B[i] - B[i + 1] + sumOfAis);
    	if(x > 0 && x % N == 0)
    		A[i + 1] = x / N;
    	else
    	{
    		cout << "NO" << '\n';
    		return;
    	}
    }

    sum = 0;
    for(int i = 2; i <= N; i++)
    	sum += A[i];
    A[1] = sumOfAis - sum;

    if(A[1] <= 0)
    {
    	cout << "NO" << '\n';
    	return;
    }

    cout << "YES" << '\n';
    for(int i = 1; i <= N; i++)
    	cout << A[i] << ' ';
    cout << '\n';
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