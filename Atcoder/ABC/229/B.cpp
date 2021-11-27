#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

string A, B;

string addPaddingOfZeroes(string x, int length)
{
    int n = x.size();
    if(n == length)
        return x;

    for(int i = 1; i <= (length - n); i++)
        x = '0' + x;

    return x;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> A >> B;
    int N1 = A.size(), N2 = B.size();
    int maxx = max(N1, N2);
    A = addPaddingOfZeroes(A, maxx);
    B = addPaddingOfZeroes(B, maxx);
    N1 = N2 = maxx;

    for(int i = N1 - 1; i >= 0; i--)
    {
    	int add = (A[i] - '0') + (B[i] - '0');
    	if(add > 9)
    	{
    		cout << "Hard";
    		return 0;
    	}
    }

    cout << "Easy";
    return 0;
}