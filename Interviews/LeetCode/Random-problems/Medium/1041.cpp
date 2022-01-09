bool isRobotBounded(string instructions)
{
    string newInstructions = instructions;
    newInstructions += instructions;
    newInstructions += instructions;
    newInstructions += instructions;

    int n = newInstructions.size();
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int j = 0;
    int curX = 0, curY = 0;

    for(int i = 0; i < n; i++)
    {
        if(newInstructions[i] == 'G')
        {
            curX += dx[j];
            curY += dy[j];
        }
        else if(newInstructions[i] == 'L')
            j = (j + 3) % 4;
        else
            j = (j + 1) % 4;
    }

    return (curX == 0 and curY == 0);
}