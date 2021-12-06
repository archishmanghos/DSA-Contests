int minCostToMoveChips(vector<int> &position)
{
    int odd = 0, even = 0;
    for(int i : position)
    {
        odd += (i % 2 == 1);
        even += (i % 2 == 0);
    }
    return min(odd, even);
}