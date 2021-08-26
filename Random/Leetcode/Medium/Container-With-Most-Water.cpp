int maxArea(vector<int> &height)
{
    int i = 0, j = height.size() - 1;
    
    int ans = -1;
    
    while(i < j)
    {
        ans = max(ans, min(height[i], height[j]) * (j - i));
        if(height[i] >= height[j])
            j -= 1;
        else
            i += 1;
    }

    return ans;
}

/*

Analysis:

Time Compleity: O(height.size())
Space Complexity: O(1)

2-pointer approach, observing one of the heights of both ends will get rejected is the key

*/