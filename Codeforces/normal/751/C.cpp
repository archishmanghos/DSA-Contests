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

int T, N, A[mxN];

string integertobinary(int x)
{
	string ans = "";
	while(x > 0)
	{
	    ans += (x % 2) + '0';
	    x >>= 1;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

string addPaddingOfZeroes(string x, int length)
{
    int n = x.size();
    if(n == length)
        return x;

    for(int i = 1; i <= (length - n); i++)
        x = '0' + x;

    return x;
}

void solve()
{
    cin >> N;
    int maxx = -INF;
    for(int i = 1; i <= N; i++)
    {
    	cin >> A[i];
    	maxx = max(maxx, A[i]);
    }

    string maxxed = integertobinary(maxx);
    int maxxBits = maxxed.size();
    set<int> checkDiv;
    vector<int> cnt(maxxBits, 0);
    for(int i = 1; i <= N; i++)
    {
    	string binary = integertobinary(A[i]);
    	binary = addPaddingOfZeroes(binary, maxxBits);
    	debug(binary)
    	int k = maxxBits - 1;
    	for(int j = 0; j < binary.size(); j++)
    		cnt[k--] += (binary[j] == '1');
    }

    for(int i = 0; i < maxxBits; i++)
    {
    	if(cnt[i])
    		checkDiv.insert(cnt[i]);
    }

    if(checkDiv.size() == 0)
    {
    	for(int i = 1; i <= N; i++)
    		cout << i << ' ';
    	cout << '\n';
    	return;
    }
    
    set<int> ans;
	int upto = *checkDiv.begin();
	for(int i = 1; i <= upto; i++)
	{
		bool ok = true;
		for(int j : checkDiv)
			ok &= (j % i == 0);
		if(ok)
			ans.insert(i);
	}

    for(int i : ans)
    	cout << i << ' ';
    cout << '\n';
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