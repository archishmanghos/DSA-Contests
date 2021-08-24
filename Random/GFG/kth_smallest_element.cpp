int kthSmallest(int arr[], int l, int r, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = l; i <= r; i++)
        pq.push(arr[i]);
    
    int count = 1;
    while(!pq.empty())
    {
        if(count == k)
            return pq.top();
        pq.pop();
        count += 1;
    }
}

/*

Analysis:

Time Complexity: O(r - l + 1)
Space Complexity: O(r - l + 1)

Tried with set, although was giving TLE, idk. Priority Queue Acd. Quick sort Acd too with tc NlogN

*/