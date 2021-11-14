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
string S;

void solve()
{
    cin >> N >> S;
    vector<int> red, blue, yellow;

    for(int i = 0; i < N; i++)
    {
    	if(S[i] == 'U')
    	{
    		red.push_back(-1);
    		yellow.push_back(-1);
    		blue.push_back(-1);
    	}
    	else if(S[i] == 'R')
    	{
    		red.push_back(1);
    		yellow.push_back(-1);
    		blue.push_back(-1);
    	}
    	else if(S[i] == 'B')
    	{
    		red.push_back(-1);
    		yellow.push_back(-1);
    		blue.push_back(1);
    	}
    	else if(S[i] == 'Y')
    	{
    		red.push_back(-1);
    		yellow.push_back(1);
    		blue.push_back(-1);
    	}
    	else if(S[i] == 'O')
    	{
    		red.push_back(1);
    		yellow.push_back(1);
    		blue.push_back(-1);
    	}
    	else if(S[i] == 'P')
    	{
    		red.push_back(1);
    		yellow.push_back(-1);
    		blue.push_back(1);
    	}
    	else if(S[i] == 'G')
    	{
    		red.push_back(-1);
    		yellow.push_back(1);
    		blue.push_back(1);
    	}
    	else if(S[i] == 'A')
    	{
    		red.push_back(1);
    		yellow.push_back(1);
    		blue.push_back(1);
    	}
    }

    int ans = 0, cnt = 0, pre = -1;
    for(int i = 0; i < red.size(); i++)
    {
    	if(red[i] == 1)
    	{
    		if(red[i] != pre)
    			cnt += 1;
    	}
    	pre = red[i];
    }
    ans += cnt;

    cnt = 0, pre = -1;
    for(int i = 0; i < yellow.size(); i++)
    {
    	if(yellow[i] == 1)
    	{
    		if(yellow[i] != pre)
    			cnt += 1;
    	}
    	pre = yellow[i];
    }
    ans += cnt;

    cnt = 0, pre = -1;
    for(int i = 0; i < blue.size(); i++)
    {
    	if(blue[i] == 1)
    	{
    		if(blue[i] != pre)
    			cnt += 1;
    	}
    	pre = blue[i];
    }
    ans += cnt;

    cout << ans << '\n';
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