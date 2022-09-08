[Link to Striver's SDE Sheet](https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/)

[Link to problem on GFG](https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1)



<details><summary>Optimal Solution</summary>

Optimal Solution: TC = `O(N + NlogN + N)`, SC = `O(N)`

* The solution is based on the observation, the lesser the end timings are, the more number of meetings we can slot in. <br>
* Thus, we put the start and end times in a vector of pair and sort the vector according to the 2nd element of the pair. <br>
* We pick the elements such that the current meeting's starting time is strictly greater than the previous meeting's end time. If it's not, we simply skip this meeting.<br>
* The number of meetings we don't skip is our answer. <br>


Total Time Taken: `0.57 / 2.8`

<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/GFG/N-meetings-in-one-room.png)

</details>

</details>
