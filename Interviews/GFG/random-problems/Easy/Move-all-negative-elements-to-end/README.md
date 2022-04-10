Given Optimal Solution: TC = `O(N)`, SC = `O(N)`

Since, we can use another DS to get our answer, we use another vector. <br>
We put all the elements of our array into the vector.<br>
Now, we traverse the vector and if there is a negative element, we push that to the vector. <br>
We traverse the vector. If there exists a negative element before the n-th index, we don't add it in our array. Else, we change the array element to our current vector element. <br>

Total Time Taken: `0.38/1.72`