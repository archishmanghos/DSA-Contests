There can be 2 possible solutions, depending on what we will be trading off. Here are the 2 solutions: <br>
<br>
Solution 1: TC = `O(N)`, SC = `O(N)` <br>

We can have a set, where we store all the elements of the array. <br>
We return true if the size of set is less than the original array size, else false. <br>

Runtime: `178 ms`, faster than `13.96%` <br>
Memory Usage: `54.6 MB`, less than `13.76%` <br>

Solution 2: TC = `O(NlogN)`, SC = `O(1)` <br>

We sort the given array and traverse the array. <br>
If we find any element that is equal to the previous element, we return true, else we return false. <br>

Runtime: `80 ms`, faster than `96.32%` <br>
Memory Usage: `46.7 MB`, less than `77.60%`