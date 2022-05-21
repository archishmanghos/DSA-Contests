[Link to Striver's SDE Sheet](https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/)

[Link to problem on Leetcode](https://leetcode.com/problems/reverse-pairs/)


<details><summary>Hints</summary>

* Try to think of modifying the standard Merge-Sort Algorithm. <br>

</details>


<details><summary>Sub-Optimal Solution 1</summary>

Sub-Optimal Solution 1: TC = `O(N ^ 2)`, SC = `O(1)`

* The idea is simple, we just iterate over every pair of elements of the array and check with the condition. <br>
* This will require 2 loops, one for each element. <br>
	

Runtime: This doesn't pass this leetcode problem's checker for the given constraints. <br>

<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/493-A.png)

</details>

</details>



<details><summary>Optimal Solution</summary>

Optimal Solution: TC = `O(NlogN + N + N)`, SC = `O(N)`

* This problem can be solved by modifying the standard [Merge Sort Algorithm](https://en.wikipedia.org/wiki/Merge_sort). <br>
* For better understanding this, solve this [problem](https://www.codingninjas.com/codestudio/problems/count-inversions_615). <br>
* The idea is after we are done calling merge sort and before calling merge, we have 2 sorted arrays. <br>
* We can use 2 pointers to store the number of inverse pairs. <br>
* We use the 1st pointer on the 1st array and the 2nd one on the 2nd array. <br>
* Now, we move the 2nd pointer till it satisfies the given condition with the current element pointed by the 1st pointer. The point where the 2nd pointer stops signifies every element to the left of it satisfies the condition, so we increment the count by that value. <br>
* Now, we hold the 2nd pointer and increase the 1st pointer by 1. <br> 
* This time, we don't start the 2nd pointer from the start of the 2nd array, we already know, whatever number of elements satisfied the condition with the previous element of the 1st pointer will also satisfy this pointer's element since the array is sorted. Thus we move the 2nd pointer from that very position only. <br>
* This gives us a linear time complexity and we can easily keep track of the number of inversions. <br>


Runtime: `1170 ms`, faster than `21.82%`<br>
Memory Usage: `234.1 MB`, less than `40.40%`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/493-B.png)

</details>

</details>