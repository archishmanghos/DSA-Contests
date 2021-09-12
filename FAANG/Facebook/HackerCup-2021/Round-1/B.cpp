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

int T, N, M, A, B;

void solve()
{
    cin >> N >> M >> A >> B;

    if((N + M - 1) <= A && (N + M - 1) <= B)
    {
    	cout << "Possible" << '\n';
    	int ans[N + 5][M + 5];
    	memset(ans, -1, sizeof(ans));

    	for(int i = 2; i <= M; i++)
    		ans[1][i] = 1;
    	for(int i = 2; i <= N; i++)
    		ans[i][M] = 1;

    	if(M > 2)
    	{
    		for(int i = 2; i < M; i++)
    			ans[N][i] = 1;
    	}

    	A -= (N + M - 2);
    	B -= (N + M - 2);

    	ans[1][1] = A;
    	ans[N][1] = B;

    	for(int i = 1; i <= N; i++)
    	{
    		for(int j = 1; j <= M; j++)
    			cout << (ans[i][j] != -1 ? ans[i][j] : 1000) << ' ';
    		cout << '\n';
    	}
    }
    else
    	cout << "Impossible" << '\n';
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