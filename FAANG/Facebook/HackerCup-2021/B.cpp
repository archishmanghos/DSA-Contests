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
template <class T, class V> void _print(pair <T, V> p){cerr << "{";_print(p.first);cerr << ",";_print(p.second);cerr << "}";}
template <class T> void _print(vector <T> v){cerr << "[ ";for (T i : v){_print(i);cerr << " ";}cerr << "]";}
template <class T> void _print(set <T> v){cerr << "[ ";for (T i : v){_print(i);cerr << " ";}cerr << "]";}
template <class T> void _print(multiset <T> v){cerr << "[ ";for (T i : v){_print(i);cerr << " ";}cerr << "]";}
template <class T, class V> void _print(map <T, V> v){cerr << "[ ";for (auto i : v){_print(i);cerr << " ";}cerr << "]";}

int T, N;
char A[100][100];

void solve()
{
    cin >> N;
    for(int i = 1; i <= N; i++)
    	for(int j = 1; j <= N; j++)
    		cin >> A[i][j];

    int ans = INF;
    for(int i = 1; i <= N; i++)
    {
    	int cnt[2] = {0};
    	for(int j = 1; j <= N; j++)
    	{
    		cnt[0] += A[i][j] == 'O';
    		cnt[1] += A[i][j] == 'X';
    	}

    	if(cnt[0] == 0)
    		ans = min(ans, N - cnt[1]);

    	cnt[0] = cnt[1] = 0;

    	for(int j = 1; j <= N; j++)
    	{
    		cnt[0] += A[j][i] == 'O';
    		cnt[1] += A[j][i] == 'X';
    	}

    	if(cnt[0] == 0)
    		ans = min(ans, N - cnt[1]);
    }

    if(ans == INF)
    {
    	cout << "Impossible" << '\n';
    	return;
    }
    
    cout << ans << ' ';

    int cntAns = 0;
    if(ans == 1)
    {
	    set<pair<int, int>> points;
	    for(int i = 1; i <= N; i++)
	    {
	    	int cnt[2] = {0};
	    	pair<int, int> point;

	    	for(int j = 1; j <= N; j++)
	    	{
	    		cnt[0] += A[i][j] == 'O';
	    		cnt[1] += A[i][j] == 'X';
	    		if(A[i][j] == '.')
	    			point = {i, j};
	    	}

	    	if(cnt[0] == 0 && (N - cnt[1] == ans))
	    		points.insert(point);

	    	debug(points)

	    	cnt[0] = cnt[1] = 0;

	    	for(int j = 1; j <= N; j++)
	    	{
	    		cnt[0] += A[j][i] == 'O';
	    		cnt[1] += A[j][i] == 'X';
	    		if(A[i][j] == '.')
	    			point = {j, i};
	    	}

	    	if(cnt[0] == 0 && (N - cnt[1] == ans))
	    		points.insert(point);
	    }

	    cntAns += (int)points.size();
    }
    else
    {
    	for(int i = 1; i <= N; i++)
	    {
	    	int cnt[2] = {0};

	    	for(int j = 1; j <= N; j++)
	    	{
	    		cnt[0] += A[i][j] == 'O';
	    		cnt[1] += A[i][j] == 'X';
	    	}

	    	if(cnt[0] == 0)
	    		cntAns += (ans == N - cnt[1]);

	    	cnt[0] = cnt[1] = 0;

	    	for(int j = 1; j <= N; j++)
	    	{
	    		cnt[0] += A[j][i] == 'O';
	    		cnt[1] += A[j][i] == 'X';
	    	}

	    	if(cnt[0] == 0)
	    		cntAns += (ans == N - cnt[1]);
	    }
    }
    

    cout << cntAns << '\n';
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