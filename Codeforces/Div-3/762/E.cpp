#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, N, A[mxN];

void solve()
{
    cin >> N;
    vector<int> cnt(N + 2, 0);
    for(int i = 1; i <= N; i++)
    {
    	cin >> A[i];
    	cnt[A[i]] += 1;
    }

    priority_queue<pair<int, int>> pq;
    int add = 0;
    bool print = true;
    for(int i = 0; i <= N; i++)
    {
        if(cnt[i])
        {
            if(print && (i == 0 || cnt[i - 1]))
                cout << cnt[i] + add << ' ';
            else
            {
                cout << -1 << ' ';
                print = false;
            }
            int extra = cnt[i] - 1;
            if(extra)
                pq.push({i, extra});
        }
        else
        {
            if(print && (i == 0 || cnt[i - 1]))
            {
                cout << add << ' ';
                if(!pq.empty())
                {
                    pair<int, int> last = pq.top();
                    pq.pop();
                    int extra = last.second;
                    cnt[i] += 1;
                    extra -= 1;
                    add += (i - last.first);
                    if(extra)
                        pq.push({last.first, extra});
                }
            }
            else
            {
                cout << -1 << ' ';
                print = false;
            }
        }
    }
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