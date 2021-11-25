#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int T, N;
vector<int> A;

void solve()
{
    cin >> N;
    deque<int> dq;
    set<int> s;
    for(int i = 1; i <= N; i++)
    {
    	int X;
    	cin >> X;
    	A.push_back(X);
    	dq.push_back(X);
    	s.insert(X);
    }

    deque<int> ans;
    while(!dq.empty())
    {
    	if(dq.front() == *s.rbegin() || dq.back() == *s.rbegin())
		{
			if(dq.front() > dq.back())
    		{
    			ans.push_back(dq.back());
    			s.erase(dq.back());
    			dq.pop_back();
    		}
    		else
    		{
    			ans.push_front(dq.front());
    			s.erase(dq.front());
    			dq.pop_front();
    		}
		}
		else
		{
			cout << -1 << '\n';
			return;
		}
    }

    while(!ans.empty())
    {
    	cout << ans.front() << ' ';
    	ans.pop_front();
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