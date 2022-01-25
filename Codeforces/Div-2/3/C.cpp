#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mxN = 2e5 + 5;
const int INF = 1e18 + 7;

char square[5][5];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cross = 0, nought = 0;
    for(int i = 1; i <= 3; i++)
    {
        for(int j = 1; j <= 3; j++)
        {
            cin >> square[i][j];
            cross += square[i][j] == 'X';
            nought += square[i][j] == '0';
        }
    }

    if(cross >= nought and cross - nought <= 1)
    {
        string winner = (cross == nought ? "the second player won" : "the first player won");
        set<string> ans;
        int crossCnt = 0, noughtCnt = 0;
        for(int i = 1; i <= 3; i++)
        {
            crossCnt += square[1][i] == 'X';
            noughtCnt += square[1][i] == '0';
        }

        if(crossCnt == 3 and cross == nought)
        {
            cout << "illegal";
            return 0;
        }
        if(noughtCnt == 3 and nought < cross)
        {
            cout << "illegal";
            return 0;
        }
        if(crossCnt == 3 or noughtCnt == 3)
            ans.insert(winner);

        crossCnt = noughtCnt = 0;
        for(int i = 1; i <= 3; i++)
        {
            crossCnt += square[i][i] == 'X';
            noughtCnt += square[i][i] == '0';
        }

        if(crossCnt == 3 and cross == nought)
        {
            cout << "illegal";
            return 0;
        }
        if(noughtCnt == 3 and nought < cross)
        {
            cout << "illegal";
            return 0;
        }
        if(crossCnt == 3 or noughtCnt == 3)
            ans.insert(winner);

        crossCnt = noughtCnt = 0;
        for(int i = 1; i <= 3; i++)
        {
            crossCnt += square[i][1] == 'X';
            noughtCnt += square[i][1] == '0';
        }

        if(crossCnt == 3 and cross == nought)
        {
            cout << "illegal";
            return 0;
        }
        if(noughtCnt == 3 and nought < cross)
        {
            cout << "illegal";
            return 0;
        }
        if(crossCnt == 3 or noughtCnt == 3)
            ans.insert(winner);

        crossCnt = noughtCnt = 0;
        for(int i = 1; i <= 3; i++)
        {
            crossCnt += square[i][4 - i] == 'X';
            noughtCnt += square[i][4 - i] == '0';
        }

        if(crossCnt == 3 and cross == nought)
        {
            cout << "illegal";
            return 0;
        }
        if(noughtCnt == 3 and nought < cross)
        {
            cout << "illegal";
            return 0;
        }
        if(crossCnt == 3 or noughtCnt == 3)
            ans.insert(winner);

        crossCnt = noughtCnt = 0;
        for(int i = 1; i <= 3; i++)
        {
            crossCnt += square[i][3] == 'X';
            noughtCnt += square[i][3] == '0';
        }

        if(crossCnt == 3 and cross == nought)
        {
            cout << "illegal";
            return 0;
        }
        if(noughtCnt == 3 and nought < cross)
        {
            cout << "illegal";
            return 0;
        }
        if(crossCnt == 3 or noughtCnt == 3)
            ans.insert(winner);

        crossCnt = noughtCnt = 0;
        for(int i = 1; i <= 3; i++)
        {
            crossCnt += square[3][i] == 'X';
            noughtCnt += square[3][i] == '0';
        }

        if(crossCnt == 3 and cross == nought)
        {
            cout << "illegal";
            return 0;
        }
        if(noughtCnt == 3 and nought < cross)
        {
            cout << "illegal";
            return 0;
        }
        if(crossCnt == 3 or noughtCnt == 3)
            ans.insert(winner);

        crossCnt = noughtCnt = 0;
        for(int i = 1; i <= 3; i++)
        {
            crossCnt += square[i][2] == 'X';
            noughtCnt += square[i][2] == '0';
        }

        if(crossCnt == 3 and cross == nought)
        {
            cout << "illegal";
            return 0;
        }
        if(noughtCnt == 3 and nought < cross)
        {
            cout << "illegal";
            return 0;
        }
        if(crossCnt == 3 or noughtCnt == 3)
            ans.insert(winner);

        crossCnt = noughtCnt = 0;
        for(int i = 1; i <= 3; i++)
        {
            crossCnt += square[2][i] == 'X';
            noughtCnt += square[2][i] == '0';
        }

        if(crossCnt == 3 and cross == nought)
        {
            cout << "illegal";
            return 0;
        }
        if(noughtCnt == 3 and nought < cross)
        {
            cout << "illegal";
            return 0;
        }
        if(crossCnt == 3 or noughtCnt == 3)
            ans.insert(winner);

        if(ans.size() == 1)
        {
            cout << (*ans.begin());
            return 0;
        }
        else if(ans.size() > 1)
        {
            cout << "illegal";
            return 0;
        }

        if(cross + nought == 9)
            cout << "draw";
        else if(cross > nought)
            cout << "second";
        else
            cout << "first";
    }
    else
        cout << "illegal";

    return 0;
}