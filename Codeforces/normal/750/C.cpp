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
    set<char> toBeChanged;
    int i = 0, j = N - 1;

    while(i <= j)
    {
    	if(S[i] != S[j])
    	{
    		toBeChanged.insert(S[i]);
    		toBeChanged.insert(S[j]);
    		break;
    	}
    	i += 1;
    	j -= 1;
    }

    if(toBeChanged.size() == 0)
    {
    	cout << 0 << '\n';
    	return;
    }

    int ans = INF;
    for(char c : toBeChanged)
    {
    	int i = 0, j = N - 1, changes = 0;
    	bool cannotHappen = false;
    	while(i <= j)
    	{
    		if(S[i] != S[j])
    		{
    			if(S[i] == c)
    			{
    				changes += 1;
    				i += 1;
    			}
    			else if(S[j] == c)
    			{
    				changes += 1;
    				j -= 1;
    			}
    			else
    			{
    				cannotHappen = true;
    				break;
    			}
    		}
    		else
    		{
    			i += 1;
    			j -= 1;
    		}
    	}
    	if(!cannotHappen)
    		ans = min(ans, changes);
    	debug(ans)
    }

    cout << (ans == INF ? -1 : ans) << '\n';
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