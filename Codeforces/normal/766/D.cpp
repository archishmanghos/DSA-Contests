#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 1e6 + 5;
const int INF = 1e18 + 7;

int N, A[mxN];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    vector<bool> present(mxN, 0);
    int maxx = -INF, ans = 0;

    for(int i = 1; i <= N; i++)
    {
        cin >> A[i];
        present[A[i]] = true;
        maxx = max(maxx, A[i]);
    }

    for(int i = 1; i <= maxx; i++)
    {
        if(!present[i])
        {
            int gcdd = -1;
            for(int j = 2; i * j <= maxx; j++)
            {
                int newNum = i * j;
                if(present[newNum])
                {
                    if(gcdd == -1)
                        gcdd = newNum;
                    else
                        gcdd = __gcd(gcdd, newNum);
                }
            }
            if(gcdd == i)
                ans += 1;
        }
    }

    cout << ans;

    return 0;
}