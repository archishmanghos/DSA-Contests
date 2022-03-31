Optimal Solution: TC = `O(NlogSum)`, SC = `O(1)`

We can apply binary search in this problem. <br>
Set the lower bound as maximum element of the array and higher bound as the sum of the array. <br>
Now we start the binary search and find the mid value. <br>
We check if the array can be split into subarrays such that the answer is less than the value of mid. Two cases arise: <br> 
> If we can achieve the value of mid as answer, we set high to [mid - 1]. <br>
> Else, we set low to [mid + 1]. <br>
>

The final value of mid is our answer. <br>

Runtime: `0 ms`, faster than `100.00%` <br>
Memory Usage: `7.3 MB`, less than `43.47%`