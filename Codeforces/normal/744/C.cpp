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

int T, N, M, K;
char A[50][50];
bool visited[50][50];

void markAsUnVisited(vector<pair<int, int>> x)
{
	for(auto it : x)
		visited[it.first][it.second] = false;
}

void markGrid(int n, int m)
{	
	int i = n - 1, j = m - 1;
	int checkCnt = 1;

	debug(checkCnt)
	vector<pair<int, int>> newMarkings;
	if(visited[n][m] == false)
	{
		visited[n][m] = true;
		newMarkings.push_back({n, m});
	}
	while(i >= 1 && j >= 1)
	{
		if(A[i][j] != '*')
			break;
		if(visited[i][j] == false)
		{
			visited[i][j] = true;
			newMarkings.push_back({i, j});
		}
		i -= 1;
		j -= 1;
		checkCnt += 1;
	}

	debug(n)
	debug(m)
	debug(checkCnt)
	if(checkCnt <= K)
	{
		markAsUnVisited(newMarkings);
		return;
	}

	i = n - 1, j = m + 1;
	checkCnt = 1;
	if(visited[n][m] == false)
	{
		visited[n][m] = true;
		newMarkings.push_back({n, m});
	}
	while(i >= 1 && j <= M)
	{
		if(A[i][j] != '*')
			break;
		if(visited[i][j] == false)
		{
			visited[i][j] = true;
			newMarkings.push_back({i, j});
		}
		i -= 1;
		j += 1;
		checkCnt += 1;
	}

	debug(n)
	debug(m)
	debug(checkCnt)

	if(checkCnt <= K)
		markAsUnVisited(newMarkings);
}

void solve()
{
    cin >> N >> M >> K;
    for(int i = 1; i <= N; i++)
    	for(int j = 1; j <= M; j++)
    		cin >> A[i][j];

    memset(visited, false, sizeof(visited));
    for(int i = 1; i <= N; i++)
    {
    	for(int j = 1; j <= M; j++)
    	{
    		if(A[i][j] == '*')
    			markGrid(i, j);
    	}
    }

    for(int i = 1; i <= N; i++)
    {
    	for(int j = 1; j <= M; j++)
    	{
    		if(A[i][j] == '*' && !visited[i][j])
    		{
    			cout << "NO" << '\n';
    			return;
    		}
    	}
    }

    cout << "YES" << '\n';
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