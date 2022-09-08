[Link to Striver's SDE Sheet](https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/)

[Link to problem on Leetcode](https://leetcode.com/problems/longest-consecutive-sequence/)


<details><summary>Hints</summary>

* Can you make up a `O(NlogN)` approach? <br>
* How can you improve the time to a linear using a standard DS? <br>

</details>


<details><summary>Sub-Optimal Solution 1</summary>

Sub-Optimal Solution 1: TC = `O(NlogN)`, SC = `O(1)`

* We sort the array first. <br>
* Now, if numbers occur consecutively, we can keep track linearly of the consecutive elements. <br>
* We keep a counter, if the current element is same as previous element, we don't increase the counter, since this is not a new element, if the current element is 1 greater than the previous element, we increase the counter, else we take the maximum of our maximum variable and the counter and reinitialise the counter to 1. <br>
	

Runtime: `91 ms`, faster than `73.97%`<br>
Memory Usage: `33.7 MB`, less than `23.13%`<br>

<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/128-A.png)

</details>

</details>



<details><summary>Optimal Solution</summary>

Optimal Solution: TC ≈ `O(N + N + N)`, SC = `O(N)`

* This solution involves using a hashset. <br>
* We first put all elements in a hashset. This will take linear time assuming there are no collisions. <br>
* Then we iterate over the elements again and check if the [current element - 1] exists in the hashset or not. This will also take constant time considering there are no collisions in the hashset. <br>
* If there exists the [current element - 1], we don't do anoything since there are still elements that can be the minimum element of the consecutive sequence. <br>
* If there doesn't exist [current element - 1], we start a loop and take all elements starting from current element till there exists an element in the hashset. The length of this loop will be a candidate for maximum length sequence. <br>
* The maximum of all these lengths is our answer. <br>


Runtime: `618 ms`, faster than `27.02%`<br>
Memory Usage: `49.8 MB`, less than `7.98%`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/128-B.png)

</details>

</details>