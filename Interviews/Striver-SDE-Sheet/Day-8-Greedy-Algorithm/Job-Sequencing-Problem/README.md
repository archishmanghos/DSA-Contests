[Link to Striver's SDE Sheet](https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/)

[Link to problem on GFG](https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#)



<details><summary>Optimal Solution</summary>

Optimal Solution: TC = `O(NlogN + N x Deadline_Count)`, SC = `O(N)`

* We can observe that it is optimal to perform a task at the last day always. <br>
* We take an array of deadline times initially set to -1. <br>
* We sort the given array according to the profit values in descending order. <br>
* Now, we traverse the array and check if the deadline timed array index is -1 or not, if it is we fill the array index and take the profit in our answer, else we traverse till 1st index, whenever, we encounter an empty index, we take that array index. If there are no empty indices from 1st till the deadline time, we don't take this value. <br>
* The final answer is the required answer. <br>


Total Time Taken: `1.01 / 2.31`

<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/GFG/Job-Sequencing-Problem.png)

</details>

</details>
