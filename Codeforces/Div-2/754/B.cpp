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

bool isSorted(string X)
{
	string Y = X;
	sort(Y.begin(), Y.end());
	bool ans = true;
	for(int i = 0; i < N; i++)
		ans &= X[i] == Y[i];
	return ans;
}

void solve()
{
    cin >> N >> S;
    vector<vector<int>> ans;

    while(!isSorted(S))
    {
    	int i = 0, j = N - 1;
    	for(int k = N - 1; k >= 0; k--)
    	{
    		if(S[k] == '0')
    		{
    			j = k;
    			break;
    		}
    	}
    	for(int k = 0; k < N; k++)
    	{
    		if(S[k] == '1')
    		{
    			i = k;
    			break;
    		}
    	}

    	vector<int> indices;
    	while(i < j)
    	{
    		if(S[i] == '0')
    		{
    			i += 1;
    			continue;
    		}
    		if(S[j] == '1')
    		{
    			j -= 1;
    			continue;
    		}

    		indices.push_back(i);
    		indices.push_back(j);
    		i += 1;
    		j -= 1;
    	}

    	sort(indices.begin(), indices.end());
    	int k = 0, l = indices.size() - 1;
    	while(k < l)
    	{
    		swap(S[indices[k]], S[indices[l]]);
    		k += 1;
    		l -= 1;
    	}
    	ans.push_back(indices);
    }

    cout << ans.size() << '\n';
    for(auto it : ans)
    {
    	cout << it.size() << ' ';
    	for(int i : it)
    		cout << i + 1 << ' ';
    	cout << '\n';
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