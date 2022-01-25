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

int T, N, M;

string integertobinary(int x)
{
    string ans="";
    while(x>0)
    {
        ans+=(x%2)+'0';
        x>>=1;
    }
    reverse(ans.begin(),ans.end());
    return ans;
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
    cin >> N >> M;
    if(M < N)
    {
        cout << 0 << '\n';
        return;
    }
    M += 1;

    string binN = integertobinary(N);
    string binM = integertobinary(M);

    int L = max((int)binN.size(), (int)binM.size());
    binN = addPaddingOfZeroes(binN, L);
    binM = addPaddingOfZeroes(binM, L);

    debug(binN)
    debug(binM)

    string ans = "";

    for(int i = 0; i < L; i++)
    {
        int ch1 = binN[i] - '0';
        int ch2 = binM[i] - '0';
        if((ch1 ^ 0) >= ch2)
        {
            ans += '0';
            if((ch1 ^ 0) > ch2)
            {
                for(int j = i + 1; j < L; j++)
                    binM[j] = '0';
            }
        }
        else
            ans += '1';
    }

    cout << binarytointeger(ans) << '\n';
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

//31-07-2021 10:53:21