[Link to Striver's SDE Sheet](https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/)

[Link to problem on Leetcode](https://leetcode.com/problems/majority-element/)


<details><summary>Hints</summary>

* Read [Boyer–Moore majority vote algorithm](https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm). <br>

</details>


<details><summary>Sub-Optimal Solution</summary>

Sub-Optimal Solution: TC = `O(N)` / `O(NlogN)` (Depending on use of Freq Array or HashMap), SC = `O(N)`

* Use a hashmap to store the occurences of the elements. <br>
* If an element is reached whose frequency is already = (N / 2), we return this element as the majority element. <br>

Runtime: `25 ms`, faster than `55.66%`<br>
Memory Usage: `19.5 MB`, less than `92.68%`<br>

<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/169-A.png)

</details>

</details>


<details><summary>Optimal Solution</summary>

Optimal Solution: TC = `O(N)`, SC = `O(1)`

* This problem can be solved by Moore's Voting Algorithm. <br>
* The intuition is that, since the majority occurs `> (N / 2)` times, hence it will get cancelled out by the minority elements and there will still be some majority element remaining. <br>
* Thus we maintain a counter and a variable which will eventually contain our majority element. <br>
* If the counter is 0, we assign the variable to the current element, signifying this is our current majority element. Counter pointing to 0 also signifies start of a new segment.<br>
* If the current element is equal to the current majority element, we increment the counter by 1, else we decrement the counter by 1. <br>

Runtime: `16 ms`, faster than `92.03%`<br>
Memory Usage: `19.5 MB`, less than `59.93%`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/169-B.png)

</details>

</details>