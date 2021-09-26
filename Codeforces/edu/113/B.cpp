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

int T, N;
string S;

void solve()
{
    cin >> N >> S;
    int two = 0, one = 0;

    for(char c : S)
    {
    	one += c == '0';
    	two += c == '2';
    }

    if(two == 0)
    {
    	cout << "YES" << '\n';
    	for(int i = 1; i <= N; i++)
    	{
    		for(int j = 1; j <= N; j++)
    		{
    			if(i == j)
    				cout << 'X';
    			else
    				cout << '=';
    		}
    		cout << '\n';
    	}
    }
    else if(two > 2)
    {
    	cout << "YES" << '\n';
    	char ans[N + 5][N + 5];
    	for(int i = 1; i <= N; i++)
    	{
    		for(int j = 1; j <= N; j++)
    		{
    			if(i == j)
    				ans[i][j] = 'X';
    			else
    				ans[i][j] = '0';
    		}
    	}
    	for(int i = 1; i <= N; i++)
    	{
    		int cnt = 0;
    		for(int j = 1; j <= N; j++)
    		{
    			if(ans[i][j] == '0')
    			{
    				if(S[i - 1] == '1' && S[j - 1] == '2')
    				{
    					ans[i][j] = '+';
    					ans[j][i] = '-';
    				}
    				else if(S[i - 1] == '1' && S[j - 1] == '1')
    				{
    					ans[i][j] = '=';
    					ans[j][i] = '=';
    				}
    				else if(S[i - 1] == '2' && S[j - 1] == '1')
    				{
    					ans[i][j] = '-';
    					ans[j][i] = '+';
    				}
    				else if(S[i - 1] == '2' && S[j - 1] == '2')
    				{
    					if(cnt == 0)
    					{
    						ans[i][j] = '+';
    						ans[j][i] = '-';
    						cnt += 1;
    					}
    					else
    					{
    						ans[i][j] = '-';
    						ans[j][i] = '+';
    					}
    				}
    			}
    		}
    	}

    	for(int i = 1; i <= N; i++)
    	{
    		for(int j = 1; j <= N; j++)
    			cout << ans[i][j];
    		cout << '\n';
    	}
    }
    else
    	cout << "NO" << '\n';
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