int largestRectangleArea(vector<int> &heights)
{
    stack<pair<int, int>> st;
    st.push({-1, -1});
    int ans = 0, N = heights.size();

    for(int i = 0; i < N; i++)
    {
        if(heights[i] >= st.top().first)
        {
            st.push({heights[i], i});
        }
        else
        {
            while(heights[i] < st.top().first)
            {
                int height = st.top().first;
                st.pop();
                int width = i - st.top().second - 1;
                ans = max(ans, height * width);
            }
            st.push({heights[i], i});
        }
    }

    while(st.size() > 1)
    {
        int height = st.top().first;
        st.pop();
        int width = N - st.top().second - 1;
        ans = max(ans, height * width);
    }

    return ans;
}