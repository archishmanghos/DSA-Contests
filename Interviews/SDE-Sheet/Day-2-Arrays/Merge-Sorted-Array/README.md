[Link to Striver's SDE Sheet](https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/)

[Link to problem on Leetcode](https://leetcode.com/problems/merge-sorted-array/)


<details><summary>Hints</summary>

* Think of an algorithm with O(N) Space. <br>
* Now remove that space. Can you do something with insertion sort?<br>

</details>


<details><summary>Full Solution</summary>

Optimal Solution: TC = `O(NlogN)`, SC = `O(1)`

* We take a gap of size `(N + M)`.
* We start a while loop which will end when gap becomes less than or equal to 1. <br>
* Take the ceil of `(gap / 2)` at the start. Let it be current gap. <br>
* Place 2 pointers, 1 at the start of the array and another at a distance of current gap from the start. <br>
* Traverse linearly incrementing each pointer till the 2nd pointer becomes out of bounds. <br>
* If the element pointed by the 1st pointer is greater than the 2nd, swap them. <br>
* Take the ceil of `(current gap / 2)` in the next traversal. <br>

</details>


Runtime: `0 ms`, faster than `100.00%`<br>
Memory Usage: `8.9 MB`, less than `99.28%`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/88.png)

</details>