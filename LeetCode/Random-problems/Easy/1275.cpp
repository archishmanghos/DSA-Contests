char A[5][5];
bool checkIfWon()
{
    for(int i = 1; i <= 3; i++)
    {
        bool allSame = true;
        char c = 'X';
        for(int j = 1; j <= 3; j++)
            allSame &= (A[i][j] == c);

        if(allSame)
            return true;

        allSame = true;
        c = 'O';
        for(int j = 1; j <= 3; j++)
            allSame &= (A[i][j] == c);

        if(allSame)
            return true;
    }

    for(int i = 1; i <= 3; i++)
    {
        bool allSame = true;
        char c = 'X';
        for(int j = 1; j <= 3; j++)
            allSame &= (A[j][i] == c);

        if(allSame)
            return true;

        allSame = true;
        c = 'O';
        for(int j = 1; j <= 3; j++)
            allSame &= (A[j][i] == c);

        if(allSame)
            return true;
    }

    bool allSame = true;
    char c = 'X';
    for(int i = 1; i <= 3; i++)
        allSame &= (A[i][i] == c);

    if(allSame)
        return true;

    allSame = true;
    c = 'O';
    for(int i = 1; i <= 3; i++)
        allSame &= (A[i][i] == c);

    if(allSame)
        return true;

    allSame = true;
    c = 'X';
    for(int i = 1; i <= 3; i++)
        allSame &= (A[i][4 - i] == c);

    if(allSame)
        return true;

    allSame = true;
    c = 'O';
    for(int i = 1; i <= 3; i++)
        allSame &= (A[i][4 - i] == c);

    if(allSame)
        return true;

    return false;

}
string tictactoe(vector<vector<int>> &moves)
{
    for(int i = 0; i < moves.size(); i++)
    {
        if(i % 2 == 0)
        {
            A[moves[i][0] + 1][moves[i][1] + 1] = 'X';
            if(checkIfWon())
                return "A";
        }
        else
        {
            A[moves[i][0] + 1][moves[i][1] + 1] = 'O';
            if(checkIfWon())
                return "B";
        }
    }

    if(moves.size() == 9)
        return "Draw";
    return "Pending";
}