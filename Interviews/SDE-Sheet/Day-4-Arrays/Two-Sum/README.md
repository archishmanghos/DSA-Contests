[Link to Striver's SDE Sheet](https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/)

[Link to problem on Leetcode](https://leetcode.com/problems/two-sum/)


<details><summary>Hints</summary>

* Can 2 indices be represented as 2 pointers over the array? <br>

</details>


<details><summary>Sub-Optimal Solution 1</summary>

Sub-Optimal Solution 1: TC = `O(N ^ 2)`, SC = `O(1)`

* The idea is simple, we just iterate over every pair of elements of the array and check if their sum is equal to the given target value. <br>
* This will require 2 loops, one for each element. <br>
	

Runtime: `404 ms`, faster than `31.02%`<br>
Memory Usage: `10.2 MB`, less than `67.97%`<br>

<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/1-A.png)

</details>

</details>



<details><summary>Sub-Optimal Solution 2</summary>

Sub-Optimal Solution 1: TC = `O(NlogN + N)`, SC = `O(N)`

* This uses 2 pointers. <br>
* We first sort the array. <br>
* We place 2 pointers at each end. We check for the sum of the elements pointed by the pointers. <br>
* If the sum is greater than target, we decrement the pointer closer to the end since we need to decrease the sum. <br>
* If the sum is lesser than target, we increment the pointer closer to the beginning since we need to increase the sum. <br>
* We continue this till both pointers cross each other. <br>
	

Runtime: `13 ms`, faster than `77.04%`<br>
Memory Usage: `11 MB`, less than `24.00%`<br>

<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/1-B.png)

</details>

</details>



<details><summary>Optimal Solution</summary>

Optimal Solution: TC ≈ `O(N)`, SC = `O(N)`

* This solution is simpler than the above solution albeit assuming some information. We assume that there are no collisions whatsover in the hashmap that we will be using. <br>
* We take a hashmap and traverse the array. We check if [target - current element] exists in the hashmap. If it exists, we return the the value of key [target - current element] and the current index. Else, we put it in the hashmap. <br>
* Hashmap insertions take constant time on average when there are minimal collisions. In case of high collisions, the insertion time can even be linear. So this is a bit risky but rewarding. <br>


Runtime: `8 ms`, faster than `94.93%`<br>
Memory Usage: `10.9 MB`, less than `29.56%`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/1-C.png)

</details>

</details>