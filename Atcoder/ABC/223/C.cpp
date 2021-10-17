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

int N;
vector<pair<double, double>> A(mxN);

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	    freopen("error.txt", "w", stderr);
	#endif

	cin >> N;
	for(int i = 1; i <= N; i++)
		cin >> A[i].first >> A[i].second;

	int left = 1, right = N;
	double leftDistance = 0, rightDistance = 0;
	for(int i = 1; i <= N; i++)
		rightDistance += A[i].first;

	while(left < right)
	{
		double distL = A[left].first;
		double speedL = A[left].second;
		double distR = A[right].first;
		double speedR = A[right].second;

		double timeL = ((double)distL / (double)speedL);
		double timeR = ((double)distR / (double)speedR);

		debug(A[left].first)
		debug(A[right].first);
		debug(leftDistance)
		debug(rightDistance)
		debug(timeL)
		debug(timeR)
		debug(left)
		debug(right)

		if(distL * speedR == distR *speedL)
		{
			leftDistance += 1.0 * distL;
			rightDistance -= 1.0 * distR;
			left += 1;
			right -= 1;
		}
		else if(distL * speedR < distR *speedL)
		{
			leftDistance += 1.0 * distL;
			double minused = 1.0 * ((double)(distL *speedR) / (double)speedL);
			rightDistance -= minused;
			A[right].first -= minused;
			left += 1;
		}
		else
		{
			double minused = 1.0 * ((double)(distR *speedL) / (double)speedR);
			leftDistance += minused;
			rightDistance -= 1.0 * distR;
			A[left].first -= minused;
			right -= 1;
		}

		
		debug("\n")
	}

	debug(leftDistance)
	debug(rightDistance)
	double ans = (leftDistance + rightDistance) / 2.0;
	cout << fixed << setprecision(9) << ans;

    return 0;
}