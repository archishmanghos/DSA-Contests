[Link to Striver's SDE Sheet](https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/)

[Link to problem on GFG](https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1#)


<details><summary>Sub-Optimal Solution 1</summary>

Sub-Optimal Solution 1: TC = `O(N ^ 2)`, SC = `O(1)`

* We can traverse for all subarrays and account the length of those subarrays whose sum turn out to be 0. <br>
* Traversing for sum of all subarrays will take O(N ^ 2) times and constant space. <br>
	

Runtime: 175 TCs passed but TLEd on others.

<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/GFG/Largest-subarray-with-0-sum-A.png)

</details>

</details>



<details><summary>Optimal Solution</summary>

Optimal Solution: TC ≈ `O(N)`, SC = `O(N)`

* There is an observation to notice. <br>
* Suppose we are traversing the array and maintaining the sum. <br>
* If we already encountered a sum which we have encountered before, we can tell that every element which occured between the previous occurence and the current index, have been cancelled out. That is why the sum has been repeated as the sum of every element between these 2 points have resulted to 0. <br>
* Hence, the distance between the current occurence and the first occurence of the sum is a candidate for longest subarray. <br>
* The maximum over all such distances is the answer to the problem.
* This can be solved in linear time by maintaining a hashmap which whill contain the first occurence of the sum. <br>


Runtime: `0.63 / 3.21`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/GFG/Largest-subarray-with-0-sum-B.png)

</details>

</details>
