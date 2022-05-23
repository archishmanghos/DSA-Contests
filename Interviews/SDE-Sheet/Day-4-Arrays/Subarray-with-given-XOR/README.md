[Link to Striver's SDE Sheet](https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/)

[Link to problem on Interview Bit](https://www.interviewbit.com/problems/subarray-with-given-xor/)


<details><summary>Sub-Optimal Solution 1</summary>

Sub-Optimal Solution 1: TC = `O(N ^ 2)`, SC = `O(1)`

* We can traverse for all subarrays and account the number of subarrays whose xor turn out to be 0. <br>
* Traversing for xor of all subarrays will take O(N ^ 2) times and constant space. <br>
	

Runtime: TLE on large testcases.

<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Interviewbit/Subarray-with-given-XOR-A.png)

</details>

</details>



<details><summary>Optimal Solution</summary>

Optimal Solution: TC ≈ `O(NlogN)`, SC = `O(N)`

* If [A ^ B = C], we can say [A = B ^ C]. This can be proved by an easy mathematical induction. We have [A ^ B = C], If we XOR B on both sides of the equation, we get [A ^ B ^ B = C ^ B]. Simplifying, we get [A = C ^ B], since [B ^ B = 0]. <br>
* Now, we need to find out if the [current xor ^ given value] has occurred before and if it has occurred before, how many times has it occurred. This will give our answer. <br>
* So, we take a hashmap and record the count of xors from 1 till the current element. We check if the [current xor ^ given value] exists in the hashmap or not. If it exists, we take the count. We also initialise count of 0 as 1, so when the [current xor = given value], we get the xor as 0 and increment the answer by 1. <br>
* The count over all such occurences is the answer. <br>


Runtime: `433 ms`<br>
Memory Usage: `8252 KB`<br>

<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Interviewbit/Subarray-with-given-XOR-B.png)

</details>

</details>
