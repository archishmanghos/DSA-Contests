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

int T, A, B;

int highestPowerof2(int n)
{
   int p = (int)log2(n);
   return (int)pow(2, p);
}

string integertobinary(int x)
{
	string ans = "";
	while(x > 0)
	{
		ans += (x % 2) + '0';
		x >>= 1;
	}
	if(ans.size() == 0)
		ans += '0';
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

int binarytointeger(string x)
{
	int ans=0,m=1;
	for(int i=x.size()-1; i>=0; i--)
	{
		ans+=(x[i]-'0')*m;
		m<<=1;
	}
	return ans;
}

void solve()
{
    cin >> A >> B;
    int ans = max((int)0, A - 1) + 1;

    int xorr = 0;
    int hPowerOf2 = highestPowerof2(A - 1);
    if(hPowerOf2 > 3)
    {
    	for(int i = hPowerOf2; i <= (A - 1); i++)
    		xorr ^= i;
    }
    else
    {
    	for(int i = 0; i <= (A - 1); i++)
    		xorr ^= i;
    }

    if(xorr == B)
    {
    	cout << ans << '\n';
    	return;
    }

    string bin = integertobinary(xorr);
    string req = integertobinary(B);

    int maxx = max((int)bin.size(), (int)req.size());
    bin = addPaddingOfZeroes(bin, maxx);
    req = addPaddingOfZeroes(req, maxx);

    string xorredAns = "";

    for(int i = 0; i < maxx; i++)
    {
    	if(bin[i] == '0' && req[i] == '0')
    		xorredAns += '0';
    	else if(bin[i] == '0' && req[i] == '1')
    		xorredAns += '1';
    	else if(bin[i] == '1' && req[i] == '0')
    		xorredAns += '1';
    	else
    		xorredAns += '0';
    }

    int ansXorred = binarytointeger(xorredAns);

    if(ansXorred == A)
    	cout << ans + 2 << '\n';
    else
    	cout << ans + 1 << '\n';
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