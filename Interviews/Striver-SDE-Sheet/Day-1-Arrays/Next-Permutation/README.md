[Link to Striver's SDE Sheet](https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/)

[Link to problem on Leetcode](https://leetcode.com/problems/next-permutation/)

<details><summary>Hints</summary>

* Start by forming the intuition of what can be immediate greater prefix than the current permutation. <br>
* You need to find a breakpoint somewhere. <br>
* You need to start thinking from the end of the permutation. <br>
* You need to visualise peaks. <br>

</details>


<details><summary>Full Solution</summary>

Optimal Solution: TC = `O(3 x N)`, SC = `O(1)`

* Start traversing from the end of the permutation to find an index which is lesser than the previous element. This is required because we need to find a position, where we can place the next bigger element for the next permutation. <br>
* If there is no breakpoint, we have reached end of all permutaions of the array. We need to return the lowest permutation which is nothing but every element in increasing order. Reverse the permutation. <br>
* If there is a breakpoint, it means there is still some greater element left after this position. Find from the back of the array, the element that is greater than the current element. This is the element that should come at the breakpoint in the next permutation. Swap the elements at breakpoint and this index. <br>
* We have got the prefix for the next permutation. Now we need to find the lowest permutation from the next of the breakpoint index till the end of the permutation. This can be achieved by reversing or sorting the segment from the next of the breakpoint index till the end. Since, sorting takes larger complexity, we reverse the segment. <br>
* We got our next permutation. <br>

</details>


Runtime: `0 ms`, faster than `100.00%`<br>
Memory Usage: `12.2 MB`, less than `38.05%`


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/31.png)

</details>