bool validMountainArray(vector<int> &arr)
{
    bool checkInc = true;
    for(int i = 1; i < arr.size(); i++)
    {
        if(checkInc)
        {
            if(arr[i] <= arr[i - 1])
            {
                if(arr[i] == arr[i - 1])
                {
                    return false;
                }
                if(checkInc and i > 1)
                {
                    checkInc = false;
                }
                else
                {
                    return false;
                }
            }
        }
        else
        {
            if(arr[i] >= arr[i - 1])
            {
                return false;
            }
        }
    }
    return !checkInc;
}