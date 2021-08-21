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

int N, M, A[mxN];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("error.txt", "w", stderr);
	#endif

	cin >> N >> M;
	
	unordered_map<int, int> mark, notVisit;
	int maxx = -INF;

	for(int i = 1; i <= N; i++)
	{
		cin >> A[i];
		for(int j = 2; j * j <= A[i]; j++)
		{
			if(A[i] % j == 0)
			{
				int x = A[i] / j;
				notVisit[x] = notVisit[j] = 1;
			}
		}
		mark[A[i]] = 1;
	}

	vector<int> ans;
	for(int i = 1; i <= M; i++)
	{
		if(!notVisit[i])
		{
			bool flag = true;
			if(mark[i] == 1)
			{
				flag = false;
				continue;
			}
			for(int j = 2; j * j <= i; j++)
			{
				if(i % j == 0)
				{
					int x = i / j;
					if(mark[j] || mark[x] || notVisit[j] || notVisit[x])
					{
						flag = false;
						break;
					}
				}
			}
			if(flag)
				ans.push_back(i);
		}
	}

	sort(ans.begin(), ans.end());
	if(ans.size() > 0 && ans[0] != 1)
		ans.push_back(1);
	if(ans.size() == 0)
		ans.push_back(1);
	sort(ans.begin(), ans.end());

	cout << ans.size() << '\n';
	for(auto it : ans)
		cout << it << '\n';

    return 0;
}