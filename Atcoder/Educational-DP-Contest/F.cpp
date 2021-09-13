#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mxN = 3e3 + 5;
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

string S, T, answer;
int cache[mxN][mxN];

int dp(int i, int j)
{
    if(i == S.size() || j == T.size())
        return 0;
    if(cache[i][j] != -1)
        return cache[i][j];

    int ans = -INF;
    if(S[i] == T[j])
        ans = max(ans, 1 + dp(i + 1, j + 1));
    else
        ans = max(ans, max(dp(i, j + 1), dp(i + 1, j)));

    return cache[i][j] = ans;
}

void printLCS(int i, int j)
{
    if(i == S.size() || j == T.size())
        return;

    if(S[i] == T[j])
    {
        answer += S[i];
        return printLCS(i + 1, j + 1);
    }
    else
    {
        if(cache[i][j] == cache[i + 1][j])
            return printLCS(i + 1, j);
        return printLCS(i, j + 1);
    }

    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif

    cin >> S >> T;
    memset(cache, -1, sizeof(cache));
    answer = "";

    int longestLength = dp(0, 0);
    printLCS(0, 0);
    cout << answer;

    return 0;
}

//