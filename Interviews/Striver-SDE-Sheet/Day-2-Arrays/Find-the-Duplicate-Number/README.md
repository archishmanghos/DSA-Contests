[Link to Striver's SDE Sheet](https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/)

[Link to problem on Leetcode](https://leetcode.com/problems/find-the-duplicate-number/)


<details><summary>Hints</summary>

* Think of finding a cycle in a linked list using tortoise method. <br>

</details>


<details><summary>Full Solution</summary>

Optimal Solution: TC = `O(N)`, SC = `O(1)`

* We can think the array with duplicate as a linked list with a cycle, where the entry point of the cycle is the duplicate element. <br>
* Use 2 pointers, 1 slow and another fast, the slow one moving 1 index at a time and the faster one, 2 indices at a time. <br>
* Continue running the slow and fast pointers till they meet. <br>
* After they meet, re-initialise the fast pointer to the initial value or the base addressed element of the array. <br>
* Continue the loop till both pointers meet again, but this time make the fast pointer behave like the slow pointer, i.e increment the fast as well as slow pointer by 1. <br>
* When they meet, they meet on the duplicate element. <br>

</details>


Runtime: `115 ms`, faster than `87.20%`<br>
Memory Usage: `61.3 MB`, less than `62.04%`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/287.png)

</details>