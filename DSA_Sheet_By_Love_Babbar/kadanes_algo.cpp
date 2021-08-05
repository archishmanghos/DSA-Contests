#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(int arr[], int n){
        
        int sumTillNow=0,ans=0,maxx=-100000000;
        for(int i=0; i<n; i++)
        {
            sumTillNow+=arr[i];
            maxx=max(arr[i],maxx);
            ans=max(ans,sumTillNow);
            sumTillNow=max((int)0,sumTillNow);
        }
        if(maxx<0)
            return maxx;
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends