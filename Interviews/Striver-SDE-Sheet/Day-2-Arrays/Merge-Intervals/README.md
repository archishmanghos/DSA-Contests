[Link to Striver's SDE Sheet](https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/)

[Link to problem on Leetcode](https://leetcode.com/problems/merge-intervals/)


<details><summary>Hints</summary>

* What can you incur from the current element's starting point and the previous element's ending point? Can you merge them? If yes, on what condition?

</details>


<details><summary>Full Solution</summary>

Optimal Solution: TC = `O(NlogN + N)`, SC = `O(1)`

* Sort the whole vector. <br>
* Take 2 variables, start and end denoting the new interval's start and ending point. <br>
* When in the current element, inspect if this interval can be merged with the current interval. This can be done only if the start point of the interval is less than the ending point of the new interval. 
* If the start is less, take the maximum of current end point and this interval's end point. <br>
* If the start is greater, create a new interval by initialising start and end to the current interval's points. <br>
* Continue and keep pushing intervals in the answer vector. <br>

</details>


Runtime: `34 ms`, faster than `93.94%`<br>
Memory Usage: `18.9 MB`, less than `85.56%`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/56.png)

</details>