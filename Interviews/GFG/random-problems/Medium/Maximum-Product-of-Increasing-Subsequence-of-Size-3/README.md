Optimal Solution: TC = O(NlogN), SC = O(N)

Since, we are asked to find a increasing subsequence of size 3 with maximum product, we will take advantage of the size here.<br>
We traverse for the second element in the array. <br>
We use a set to keep track of all the elements that have been traversed before the current element. These all are candidates for our first element. <br>
Now we need to maximise the first element as well as make sure, it is less than the second element. <br>
> For that, we maintain a set. <br>
> We find the lower bound of the current element in the set, which is smallest element >= current element. <br>
> Hence, it's clear, the element before the lower bound element is the largest possible element that is smaller than the current element. <br>
> We have found our first element successfully. <br>
>
Now, for the third element, we need to find the maximum element to the right of the current element that is also greater than the current element. <br>
> For that, we use a suffix maximum array. <br>
> We traverse from behind and store the maximum at each index in an array. <br>
> For our third element, we just take the [i + 1]th array value, considering we are standing at position i.
>
Thus we found all 3 values for the current position. <br>
We now check if the product is greater than our current stored product, if it is, we replace the current stored elements with these elements. <br>
Finally, if nothing satisfied an increasing subsequence, we return -1. <br>

Total Time Taken: `1.6/3.5`