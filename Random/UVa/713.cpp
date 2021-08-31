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

int T;
string A, B;

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
    cin >> A >> B;
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());

    string ans = "";

    int maxLength = max((int)A.size(), (int)B.size());
    A = addPaddingOfZeroes(A, maxLength);
    B = addPaddingOfZeroes(B, maxLength);

    int carry = 0;
    for(int i = maxLength - 1; i >= 0; i--)
    {
        int a = A[i] - '0';
        int b = B[i] - '0';
        int add = a + b + carry;

        if(i > 0)
        {
            
            if(add > 9)
            {
                carry = 1;
                add = add % 10;
            }
            else
                carry = 0;
            char c = add + '0';
            ans += c;
        }
        else
        {
            if(add > 9)
            {
                carry = 1;
                add = add % 10;
                char c1 = carry + '0';
                char c2 = add + '0';

                ans += c2;
                ans += c1;
            }
            else
            {
                char c = add + '0';
                ans += c;
            }
        }
    }

    bool printZero = false;
    for(int i = 0; i < ans.size(); i++)
    {
        if(ans[i] != '0')
            printZero = true;

        if(ans[i] == '0' && printZero)
            cout << ans[i];
        else if(ans[i] != '0')
            cout << ans[i];
    }

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