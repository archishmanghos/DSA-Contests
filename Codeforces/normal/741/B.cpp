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
    char prime[4] = {'2', '3', '5', '7'};
    int cnt[10] = {0};

    cin >> N >> S;

    for(int i = 0; i < N; i++)
    {
    	bool notPrime = false;
    	for(int j = 0; j < 4; j++)
    		notPrime |= S[i] == prime[j];

    	if(!notPrime)
    	{
    		cout << 1 << '\n';
			cout << S[i] << '\n';
			return;
    	}

    	cnt[S[i] - '0'] += 1;
    }

    if(cnt[2] > 0)
    {
    	if(S[0] != '2')
    	{
    		cout << 2 << '\n';
    		cout << S[0] <<  2 << '\n';
    		return;
    	}
    }

    if(cnt[5] > 0)
    {
    	if(S[0] != '5')
    	{
    		cout << 2 << '\n';
    		cout << S[0] << 5 << '\n';
    		return;
    	}
    }

   	if(cnt[2] > 1)
   		cout << 2 << '\n' << 22 << '\n';
   	else if(cnt[3] > 1)
   		cout << 2 << '\n' << 33 << '\n';
   	else if(cnt[5] > 1)
   		cout << 2 << '\n' << 55 << '\n';
   	else if(cnt[7] > 1)
   		cout << 2 << '\n' << 77 << '\n';
   	else if(cnt[2] > 0 && cnt[7] > 0)
   		cout << 2 << '\n' << 27 << '\n';
   	else if(cnt[5] > 0 && cnt[7] > 0)
   		cout << 2 << '\n' << 57 << '\n';
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