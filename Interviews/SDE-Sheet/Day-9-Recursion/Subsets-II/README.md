[Link to Striver's SDE Sheet](https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/)

[Link to problem on Leetcode](https://leetcode.com/problems/subsets-ii/)



<details><summary>Sub-Optimal Solution</summary>

Sub-Optimal Solution: TC = `O(2 ^ N * (klogX) + 2 ^ N)` (klogX is average time to put a subset in a set), SC = `O(2 ^ N * K)` (storing every subset of average length K).

* This is the same as recursive logic for subset sums, except that we store the subset inside a set. <br>
* The set rejects a duplicte subset and hence after the recursive calls are over, we can just copy back the contents of the set into a vector and return the same. <br>
* This method employs another data-structure which should be avoided in an optimal format. <br>
	

Runtime: `20 ms`, faster than `7.21%`<br>
Memory Usage: `17.6 MB`, less than `8.51%`<br>

<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/90-A.png)

</details>

</details>



<details><summary>Optimal Solution</summary>

Optimal Solution: TC = `O(2 ^ N * K)`, SC = `O(2 ^ N * K)`, where K is the average size of a subset. 

* This recursive call is based on the fact that at every recursion call level, we generate a subset of size `s + 1`, where s is the current size of the subset. <br>
* We traverse for all indices from current index till the end of the given array and pick an element which has not been picked before. Duplicates are avoided by sorting the array and checking if the picked element is not equal to the previous element. <br>
* We continue this till we have reached the end of the array. <br>
* Finally, we will have unique subsets only as we avoided the duplicate elements at each step.<br>


Runtime: `5 ms`, faster than `52.29%`<br>
Memory Usage: `7.9 MB`, less than `49.37%`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/90-B.png)

</details>

</details>