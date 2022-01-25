#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mxN = 1e9 + 7;
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

int T;
string N;
vector<string> preCalculate;

string integertostring(int x)
{
    string ans = "";
    while (x > 0)
    {
        ans += (x % 10) + '0';
        x /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

void solve()
{
    cin >> N;

    int ans = N.size() + 1;
    for(string i : preCalculate)
    {
    	int changes = 0, k = 0;
    	for(int j = 0; j < N.size(); j++)
    	{
    		if(N[j] == i[k])
    		{
    			k += 1;
    			continue;
    		}
    		changes += 1;
    	}

    	int newSizeOfN = N.size() - changes;
    	changes += i.size() - newSizeOfN;

    	ans = min(ans, changes);
    }

    cout << ans << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x = 1;
   	while(x < INF)
   	{
   		string y = integertostring(x);
   		preCalculate.push_back(y);
   		x <<= 1;
   	}

    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif

    cin >> T;
    while (T--)
        solve();

    return 0;
}