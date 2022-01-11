#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

string S, T;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> S >> T;
    int move1 = (T[0] - 'a') - (S[0] - 'a');
    int move2 = (T[1] - '0') - (S[1] - '0');

    cout << max(abs(move1), abs(move2)) << '\n';
    if(move1 > 0 and move2 > 0)
    {
    	int minMove = min(move1, move2);
    	for(int i = 1; i <= minMove; i++)
    		cout << "RU" << '\n';
    	move1 -= minMove;
    	move2 -= minMove;

    	if(move1)
    	{
    		for(int i = 1; i <= move1; i++)
    			cout << "R" << '\n';
    	}
    	else
    	{
    		for(int i = 1; i <= move2; i++)
    			cout << "U" << '\n';
    	}
    }
    else if(move1 > 0 and move2 < 0)
    {
    	int minMove = min(move1, abs(move2));
    	for(int i = 1; i <= minMove; i++)
    		cout << "RD" << '\n';
    	move1 -= minMove;
    	move2 += minMove;

    	if(move1)
    	{
    		for(int i = 1; i <= move1; i++)
    			cout << "R" << '\n';
    	}
    	else
    	{
    		for(int i = 1; i <= abs(move2); i++)
    			cout << "D" << '\n';
    	}
    }
    else if(move1 < 0 and move2 > 0)
    {
    	int minMove = min(abs(move1), move2);
    	for(int i = 1; i <= minMove; i++)
    		cout << "LU" << '\n';
    	move1 += minMove;
    	move2 -= minMove;

    	if(move1)
    	{
    		for(int i = 1; i <= abs(move1); i++)
    			cout << "L" << '\n';
    	}
    	else
    	{
    		for(int i = 1; i <= move2; i++)
    			cout << "U" << '\n';
    	}
    }
    else if(move1 < 0 and move2 < 0)
    {
    	int minMove = min(abs(move1), abs(move2));
    	for(int i = 1; i <= minMove; i++)
    		cout << "LD" << '\n';
    	move1 += minMove;
    	move2 += minMove;

    	if(move1)
    	{
    		for(int i = 1; i <= abs(move1); i++)
    			cout << "L" << '\n';
    	}
    	else
    	{
    		for(int i = 1; i <= abs(move2); i++)
    			cout << "D" << '\n';
    	}
    }
    else if(move1 == 0)
    {
    	if(move2 < 0)
    	{
    		for(int i = 1; i <= abs(move2); i++)
    			cout << "D" << '\n';
    	}
    	else if(move2 > 0)
    	{
    		for(int i = 1; i <= move2; i++)
    			cout << "U" << '\n';
    	}
    }
    else if(move2 == 0)
    {
    	if(move1 < 0)
    	{
    		for(int i = 1; i <= abs(move1); i++)
    			cout << "L" << '\n';
    	}
    	else if(move1 > 0)
    	{
    		for(int i = 1; i <= move1; i++)
    			cout << "R" << '\n';
    	}
    }

    return 0;
}