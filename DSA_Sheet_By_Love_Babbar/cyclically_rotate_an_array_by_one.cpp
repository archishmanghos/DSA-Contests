//Initial Template for C++

#include <stdio.h>

void rotate(int arr[], int n);

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[n] , i;
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        rotate(a, n);
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
        return 0;
}
// } Driver Code Ends


//User function Template for C++

void rotate(int arr[], int n)
{
    int x=arr[n-1];
    for(int i=n-2; i>=0; i--)
        arr[i+1]=arr[i];
    arr[0]=x;
}

/*

Analysis:
Simple solution, easy enough to AC in one go. If you can't, you better brush up some basics.

*/