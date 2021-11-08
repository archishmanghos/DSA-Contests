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

void solve()
{
    cin >> N;
    for(int i = 1; i <= N; i++)
    	cin >> A[i];

    if(N == 1)
    {
    	cout << 0 << '\n';
    	return;
    }

    vector<int> even, odd;
    for(int i = 1; i <= N; i++)
    {
    	if(A[i] & 1)
    		odd.push_back(i);
    	else
    		even.push_back(i);
    }

    int evenSize = even.size();
    int oddSize = odd.size();
    if(even.size() == 0 || odd.size() == 0 || abs(evenSize - oddSize) > 1)
    {
    	cout << -1 << '\n';
    	return;
    }

    int ans = 0;
    if(N & 1)
    {
    	int i = 0, j = 0, doneUptill = 0;
    	bool oddIsForEven = false, oddIsForOdd = false;
    	if(even.size() > odd.size())
    	{
    		i += 1;
    		doneUptill = even[0];
    		ans += even[0] - 1;
    		oddIsForEven = true;
    	}
    	else
    	{
    		j += 1;
    		doneUptill = odd[0];
    		ans += odd[0] - 1;
    		oddIsForOdd = true;
    	}
    	debug(doneUptill)
    	debug(oddIsForEven)
    	debug(i)
    	debug(j)
    	int k = 2;
    	while((i + j + 2) <= N)
    	{
    		if(k & 1)
    		{
    			if(oddIsForEven)
    			{
    				if(doneUptill < even[i])
    				{
    					doneUptill = even[i];
    					ans += even[i] - k;
    				}
    				i += 1;
    			}
    			else
    			{
    				if(doneUptill < odd[j])
    				{
    					doneUptill = odd[j];
    					ans += odd[j] - k;
    				}
    				j += 1;
    			}
    		}
    		else
    		{
    			if(oddIsForEven)
    			{
    				if(doneUptill < odd[j])
    				{
    					doneUptill = odd[j];
    					ans += odd[j] - k;
    				}
    				j += 1;
    			}
    			else
    			{
    				if(doneUptill < even[i])
    				{
    					doneUptill = even[i];
    					ans += even[i] - k;
    				}
    				i += 1;
    			}
    		}
    		k += 1;
    	}
    }
    else
    {
    	int ans1 = 0, i = 1, j = 0, doneUptill = 0;
    	bool oddIsForEven = true, oddIsForOdd = false;

		doneUptill = even[0];
		ans1 += even[0] - 1;

    	int k = 2;
    	while((i + j + 2) <= N)
    	{
    		if(k & 1)
    		{
    			if(oddIsForEven)
    			{
    				if(doneUptill < even[i])
    				{
    					doneUptill = even[i];
    					ans1 += even[i] - k;
    				}
    				i += 1;
    			}
    			else
    			{
    				if(doneUptill < odd[j])
    				{
    					doneUptill = odd[j];
    					ans1 += odd[j] - k;
    				}
    				j += 1;
    			}
    		}
    		else
    		{
    			if(oddIsForEven)
    			{
    				if(doneUptill < odd[j])
    				{
    					doneUptill = odd[j];
    					ans1 += odd[j] - k;
    				}
    				j += 1;
    			}
    			else
    			{
    				if(doneUptill < even[i])
    				{
    					doneUptill = even[i];
    					ans1 += even[i] - k;
    				}
    				i += 1;
    			}
    		}
    		k += 1;
    	}

    	int ans2 = 0; 
    	i = 0, j = 1, doneUptill = 0;
    	oddIsForEven = false, oddIsForOdd = true;

		doneUptill = odd[0];
		ans2 += odd[0] - 1;

    	k = 2;

    	while((i + j + 2) <= N)
    	{
    		if(k & 1)
    		{
    			if(oddIsForEven)
    			{
    				if(doneUptill < even[i])
    				{
    					doneUptill = even[i];
    					ans2 += even[i] - k;
    				}
    				i += 1;
    			}
    			else
    			{
    				if(doneUptill < odd[j])
    				{
    					doneUptill = odd[j];
    					ans2 += odd[j] - k;
    				}
    				j += 1;
    			}
    		}
    		else
    		{
    			if(oddIsForEven)
    			{
    				if(doneUptill < odd[j])
    				{
    					doneUptill = odd[j];
    					ans2 += odd[j] - k;
    				}
    				j += 1;
    			}
    			else
    			{
    				if(doneUptill < even[i])
    				{
    					doneUptill = even[i];
    					ans2 += even[i] - k;
    				}
    				i += 1;
    			}
    		}
    		k += 1;
    		debug(k)
    		debug(ans2)
    	}

    	ans = min(ans1, ans2);
    }
    
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
    while (T--)
        solve();

    return 0;
}