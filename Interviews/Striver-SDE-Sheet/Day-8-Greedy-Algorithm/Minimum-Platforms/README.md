[Link to Striver's SDE Sheet](https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/)

[Link to problem on GFG](https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#)


<details><summary>Sub Optimal Solution1</summary>

Optimal Solution: TC = `O(N ^ 2)`, SC = `O(1)`

* This is the basic brute solution. <br>
* We run 2 nested for loops, each loop starting from a train. <br>
* For every train i, we check if the j-th train merges with the timing of the i-th train. If it does merge, we increase the platform count by 1. <br>
* We take the maximum of the platform count for every train which is the answer. <br>


Total Time Taken: `Gets TLEd or may even give Wrong Answer.`

<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/GFG/Minimum-Platforms-A.png)

</details>

</details>


<details><summary>Sub Optimal Solution2</summary>

Optimal Solution: TC = `O(NlogN + NlogN)`, SC = `O(N + N)`

* In this solution, we put the timings of each train in a vector of pair. <br>
* We then sort the timings in ascending order of arrival time. <br>
* We take a minimum heap. If the heap is empty or the current top element of the heap is greater than or equal to the current arrival time, we push the departure time to the heap. Else, we pop the top element and push the departure time. <br>
* Finally the size of the heap is our answer. <br>


Total Time Taken: `0.06 / 1.38`.

<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/GFG/Minimum-Platforms-B.png)

</details>

</details>


<details><summary>Optimal Solution</summary>

Optimal Solution: TC = `O(2 x NlogN + 2 x N)`, SC = `O(1)`

* This solution is based on the observation that we need not keep track of the arrival and departure times dependently. That is we can maintain them independently. <br>
* For this, we sort the arrival times and departure times separately. <br>
* We maintain 2 pointers, one pointing to the arrival array and another for the departure array. <br>
* We check if the current arrival time is less than or equal to the current departure time, if it is, we increase the platform count and increment the arrival pointer, else we decrease the platform count and increase the departure pointer. <br>
* At each step, we take the maximum of the current platform count. <br>
* The maximum over all iterations is our answer. <br>


Total Time Taken: `0.04 / 1.38`

<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/GFG/Minimum-Platforms-C.png)

</details>

</details>
