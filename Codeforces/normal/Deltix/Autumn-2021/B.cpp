#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

int N, Q, pos;
string S;
char c;

bool presenceOfSubstring(int position, char x)
{
	if(x == 'a')
	{
		if(position + 2 < N)
			if(S[position + 1] == 'b' && S[position + 2] == 'c')
				return true;
		return false;
	}
	else if(x == 'b')
	{
		if(position - 1 >= 0 && position + 1 < N)
			if(S[position - 1] == 'a' && S[position + 1] == 'c')
				return true;
		return false;
	}
	else
	{
		if(position - 2 >= 0)
			if(S[position - 2] == 'a' && S[position - 1] == 'b')
				return true;
		return false;
	}
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> Q >> S;
    int totalSubstring = 0;
    for(int i = 0; i <= (N - 3); i++)
    	totalSubstring += (S[i] == 'a' && S[i + 1] == 'b' && S[i + 2] == 'c');

    while(Q--)
    {
    	cin >> pos >> c;
    	pos -= 1;
    	totalSubstring -= presenceOfSubstring(pos, S[pos]) == true;
    	S[pos] = c;
    	totalSubstring += presenceOfSubstring(pos, S[pos]) == true;
    	cout << totalSubstring << '\n';
    }

    return 0;
}