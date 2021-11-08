#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

#ifndef ONLINE_JUDGE
#define debugarr(x,i,j) cerr << #x <<" "; _print(x,i,j); cerr << endl;
#else
#define debugarr(x)
#endif

void _print(int t){cerr << t;}
void _print(string t){cerr << t;}
void _print(bool t){cerr << t;}
void _print(char t){cerr << t;}
void _print(long double t){cerr << t;}
void _print(double t){cerr << t;}
void _print(unsigned long long t){cerr << t;}
template <class T> void _print(T arr[], int i, int j){cerr << "[ " ;for ( int k = i; k <= j; k++) cerr << arr[k] << ", " ;cerr << "]\n";}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p){cerr << "{";_print(p.ff);cerr << ",";_print(p.ss);cerr << "}";}
template <class T> void _print(vector <T> v){cerr << "[ ";for (T i : v){_print(i);cerr << " ";}cerr << "]";}
template <class T> void _print(set <T> v){cerr << "[ ";for (T i : v){_print(i);cerr << " ";}cerr << "]";}
template <class T> void _print(multiset <T> v){cerr << "[ ";for (T i : v){_print(i);cerr << " ";}cerr << "]";}
template <class T, class V> void _print(map <T, V> v){cerr << "[ ";for (auto i : v){_print(i);cerr << " ";}cerr << "]";}

int T, N, A[mxN], B[mxN];

void solve()
{
    cin >> N;
    int sum1 = 0, sum2 = 0;
    for(int i = 1; i <= N; i++)
    {
    	cin >> A[i];
    	sum1 += A[i];
    }
    for(int i = 1; i <= N; i++)
    {
    	cin >> B[i];
    	sum2 += B[i];
    }

    if(sum1 != sum2)
    {
    	cout << -1 << '\n';
    	return;
    }

    vector<pair<int, int>> ans;
    while(1)
    {
    	bool allEqual = true;
    	for(int i = 1; i <= N; i++)
    		allEqual &= A[i] == B[i];
    	if(allEqual)
    	{
    		cout << ans.size() << '\n';
    		for(auto it : ans)
    			cout << it.first << ' ' << it.second << '\n';
    		return;
    	}

    	int pos;
    	for(int i = 1; i <= N; i++)
    	{
    		if(A[i] != B[i])
    		{
    			pos = i;
    			break;
    		}
    	}

    	if(A[pos] < B[pos])
    	{
    		while(A[pos] < B[pos])
    		{
    			for(int i = 1; i <= N; i++)
    			{
    				if(A[i] > B[i])
    				{
    					A[i] -= 1;
    					A[pos] += 1;
    					ans.push_back({i, pos});
    					if(A[pos] == B[pos])
    						break;
    				}
    			}
    		}
    	}
    	else
    	{
    		while(A[pos] > B[pos])
    		{
    			for(int j = 1; j <= N; j++)
    			{
    				if(A[j] < B[j])
    				{
    					A[j] += 1;
    					A[pos] -= 1;
    					ans.push_back({pos, j});
    					if(A[pos] == B[pos])
    						break;
    				}
    			}
    		}
    	}
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif

    cin >> T;
    while (T--)
        solve();

    return 0;
}