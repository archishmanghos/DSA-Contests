#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

string S1, S2;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> S1 >> S2;
    int black = 0;
    for(char c : S1)
    	black += c == '#';
    for(char c : S2)
    	black += c == '#';

    if(black > 2)
    	cout << "Yes";
    else if(black < 2)
    	cout << "No";
    else
    	cout << ((S1[1] == S2[0] &&S1[1] == '#') || (S1[0] == S2[1] &&S1[0] == '#') ? "No" : "Yes");

    return 0;
}