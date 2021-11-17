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

int N;
pair<int, int> queen, king, target;
int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[8] = {0, 0, 1, -1, 1, -1, -1, 1};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("error.txt", "w", stderr);
	#endif

	cin >> N;
	cin >> queen.first >> queen.second;
	cin >> king.first >> king.second;
	cin >> target.first >> target.second;

	bool visited[N + 1][N + 1], ans = false;
	memset(visited, false, sizeof(visited));

	queue<pair<int, int>> q;
	q.push(king);

	while(!q.empty())
	{
		pair<int, int> curSquare = q.front();
		q.pop();
		if(curSquare.first < 1 || curSquare.first > N)
			continue;
		if(curSquare.second < 1 || curSquare.second > N)
			continue;
		if(visited[curSquare.first][curSquare.second])
			continue;
		visited[curSquare.first][curSquare.second] = true;

		if(curSquare == target)
		{
			ans = true;
			break;
		}
		
		if(curSquare.first == queen.first || curSquare.second == queen.second)
			continue;
		if(curSquare.first - curSquare.second == queen.first - queen.second)
			continue;
		if(curSquare.first + curSquare.second == queen.first + queen.second)
			continue;

		for(int i = 0; i < 8; i++)
			q.push({curSquare.first + dx[i], curSquare.second + dy[i]});
	}

	cout << (ans ? "YES" : "NO") << '\n';

    return 0;
}