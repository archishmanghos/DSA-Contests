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

int N, M, X, Q;
char A[50][50];
string S;

bool checkEuclidean(pair<int, int> x, pair<int, int> y)
{
	int dist1 = abs(x.first - y.first);
	int dist2 = abs(x.second - y.second);

	int dist = dist1 * dist1 + dist2 * dist2;
	return (dist <= (X *X));
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("error.txt", "w", stderr);
	#endif

	cin >> N >> M >> X;
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= M; j++)
			cin >> A[i][j];

	vector<vector<pair<int, int>>> position(30);
	vector<pair<int, int>> allPosOfS;

	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= M; j++)
		{
			if(A[i][j] != 'S')
				position[A[i][j] - 'a'].push_back({i, j});
			else
				allPosOfS.push_back({i, j});
		}
	}

	cin >> Q >> S;
	int ans = 0;
	int ifPossible[30];
	memset(ifPossible, -1, sizeof(ifPossible));

	for(int i = 0; i < Q; i++)
	{
		char toCheck = tolower(S[i]);

		if(position[toCheck-'a'].size() != 0)
		{
			if(toCheck == S[i])
				continue;
			else
			{
				if(allPosOfS.size() == 0)
				{
					cout << -1;
					return 0;
				}

				if(ifPossible[toCheck - 'a'] == -1)
				{
					bool everyOneFar = true;
					for(auto it1 : position[toCheck - 'a'])
					{
						for(auto it : allPosOfS)
						{
							if(checkEuclidean(it1,it))
								everyOneFar = false;
						}
					}
					ifPossible[toCheck - 'a'] = (everyOneFar ? 1 : 0);
				}
			
				ans += ifPossible[toCheck - 'a'] == 1;
			}
		}
		else
		{
			cout << -1;
			return 0;
		}
	}

	cout << ans;
    return 0;
}