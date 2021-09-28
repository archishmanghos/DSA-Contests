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

int T, N, A[mxN];

void solve()
{
    cin >> N;
    for(int i = 1; i <= N; i++)
    	cin >> A[i];

    set<pair<int, int>> s;
    for(int i = 1; i <= N; i++)
    	s.insert({A[i], i});
    vector<pair<pair<int, int>, int>> ans;

    while(1)
    {
    	if(s.size() <= 1)
    		break;

    	pair<int, int> frontElement = *s.begin();
    	auto backk = s.rbegin();
    	pair<int, int> backElement = *backk;
    	pair<int, int> backMinusOneElement;
    	if(s.size() > 2)
    	{
    		backk--;
    	 	backMinusOneElement = *backk;
    	}
    	else
    		backMinusOneElement = {0, 0};

    	s.erase(frontElement);
    	s.erase(backElement);

    	int maxxMinus1, maxxMinus2;
    	if(backElement.first == 0)
    		maxxMinus1 = backElement.first;
    	else
    	 maxxMinus1 = backElement.first - max((int)0, (backMinusOneElement.first - 1));
    	maxxMinus2 = frontElement.first;
    	int minn = min(maxxMinus1, maxxMinus2);

    	ans.push_back({{frontElement.second, backElement.second}, minn});
    	if(backElement.first - minn > 0)
    	{
    		backElement.first -= minn;
    		s.insert(backElement);
    	}
    	if(frontElement.first - minn > 0)
    	{
    		frontElement.first -= minn;
    		s.insert(frontElement);
    	}
    }

    int ansSize = 0;
    for(auto it : ans)
    	ansSize += it.second;

    cout << ansSize << '\n';
    for(auto it : ans)
    {
    	for(int i = 1; i <= it.second; i++)
    		cout << it.first.first << ' ' << it.first.second << '\n';
    }
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