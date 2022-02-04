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
    string S1 = "";
    char prev = '0';

    for(int i = 0; i < N; i++)
    {
    	if(S[i] != prev)
    	{
    		S1 += S[i];
    		prev = S[i];
    	}
    }

    S = S1;
    N = S.size();
    int ans = 0;
    if(N > 1)
    {
    	if(S[0] == 'F')
    	{
    		string start = (S[1] == 'X' ? "left" : "right");
    		for(int i = 1; i < N; i++)
    		{
    			if(S[i] == 'X' && start == "right")
    			{
    				ans += 1;
    				start = "left";
    			}
    			else if(S[i] == 'O' && start == "left")
    			{
    				ans += 1;
    				start = "right";
    			}
    		}
    	}
    	else
    	{
    		string start = (S[0] == 'X' ? "left" : "right");
    		for(int i = 1; i < N; i++)
    		{
    			if(S[i] == 'X' && start == "right")
    			{
    				ans += 1;
    				start = "left";
    			}
    			else if(S[i] == 'O' && start == "left")
    			{
    				ans += 1;
    				start = "right";
    			}
    		}
    	}
    }
    
    cout << ans << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif

    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}