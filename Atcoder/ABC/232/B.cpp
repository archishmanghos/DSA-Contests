#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

string S, T;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> S >> T;
    set<int> s;
    for(int i = 0; i < S.size(); i++)
    {
    	int reach = (T[i] - 'a') - (S[i] - 'a');
    	if(reach < 0)
    		reach = 26 + reach;
    	s.insert(reach);
    }

    if((int)s.size() == 1)
    	cout << "Yes";
    else
    	cout << "No";

    return 0;
}