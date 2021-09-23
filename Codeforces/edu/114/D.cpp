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

int N, M, C, X;
vector<vector<int>> A;

class compare
{
public:
    bool operator()(const vector<int> &a, const vector<int> &b)
    {
        int strength1 = 0, j = 0, strength2 = 0;
        for(int i : a)
            strength1 += A[j++][i];
        j = 0;
        for(int i : b)
            strength2 += A[j++][i];

        return strength1 < strength2;
    }

};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("error.txt", "w", stderr);
	#endif

	cin >> N;
	for(int i = 1; i <= N; i++)
	{
		cin >> C;
		vector<int> temp;
		for(int j = 1; j <= C; j++)
		{
			cin >> X;
			temp.push_back(X);
		}
		A.push_back(temp);
	}

	set<vector<int>> banned, visited;
	cin >> M;
	for(int i = 1; i <= M; i++)
	{
		vector<int> temp;
		for(int i = 1; i <= N; i++)
		{
			cin >> X;
			temp.push_back(X - 1);
		}
		banned.insert(temp);
	}

	priority_queue<vector<int>, vector<vector<int>>, compare> pq;
	vector<int> temp;
	for(int i = 0; i < N; i++)
		temp.push_back((int)(A[i].size() - 1));

	pq.push(temp);
	int count = 0;

	while(!pq.empty() && count < M + 1)
	{
		vector<int> check = pq.top();
		if(banned.find(check) == banned.end())
		{
			for(int ans : check)
				cout << ans + 1 << ' ';
			return 0;
		}

		count += 1;
		pq.pop();
		for(int i = 0; i < N; i++)
		{
			if(check[i] > 0)
			{
				vector<int> next = check;
				next[i] -= 1;
				if(visited.find(next) == visited.end())
				{
					pq.push(next);
					visited.insert(next);
				}
			}
		}
	}

    return 0;
}