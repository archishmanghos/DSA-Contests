[Link to Striver's SDE Sheet](https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/)

[Link to problem on Leetcode](https://leetcode.com/problems/majority-element-ii/)


<details><summary>Hints</summary>

* Read [Boyer–Moore majority vote algorithm](https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm). <br>
* Solve this [problem first](https://leetcode.com/problems/majority-element/). <br>

</details>


<details><summary>Sub-Optimal Solution 1</summary>

Sub-Optimal Solution 1: TC = `O(N)` / `O(NlogN)` (Depending on use of Freq Array or HashMap), SC = `O(N)`

* Use a hashmap to store the occurences of the elements. <br>
* Traverse the hashmap and store all elements whose frequency is greater than `(n / 3)`. <br>
	

Runtime: `19 ms`, faster than `46.64%`<br>
Memory Usage: `15.9 MB`, less than `12.85%`<br>

<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/229-B.png)

</details>

</details>


<details><summary>Sub-Optimal Solution 2 (Better Space Complexity)</summary>

Sub-Optimal Solution 2: TC = `O(NlogN)`, SC = `O(1)`

* Sort the array. This will as a result modify the original array. <br>
* Take a counter and increase if it is equal to the previous element. <br>
* If it's not equal, check if the counter exceeded (n / 3), if it did, put it in the answer vector. <br>


Runtime: `18 ms`, faster than `51.42%`<br>
Memory Usage: `15.8 MB`, less than `82.10%`<br>

<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/229-A.png)

</details>

</details>


<details><summary>Optimal Solution</summary>

Optimal Solution: TC = `O(2 x N)`, SC = `O(1)`

* This problem can be solved by some modification of the Moore's Voting Algorithm. <br>
* We take 2 variables for majority elements and 2 counters for maintaing count of the majority elements. <br>
* 2 variables are taken because there can be at-max 2 majority elements in the array. This is because, a majority element is one which occurs > `(n / 3)` times. So the least value to become a majority element is `(n / 3 + 1)`. For the sake of proof, let's say there are 3 majority elements. Adding least values for 3 majority elements is `3 x (n / 3 + 1)` which is `(n + 3)` and which is impossible. So there are at-max 2 majority elements in the array. <br>
* The algorithm remains almost same and obviously the conditions double due to 2 majority elements. Both the majority elements are initialised to a dummy value. <br>
* 5 if-else statements come into play:

> 1. If the current element is our first majority element, we increment first counter by 1. <br>
> 2. If not 1, then if the current element is our second majority element, we increment second counter by 1. <br>
> 3. If not 2, then if our first counter stands at 0, we initialise the first majority element with the current element and make the first counter 1. <br>
> 4. If not 3, then if our second counter stands at 0, we initialise the second majority element with the current element and make the second counter 1. <br>
> 5. If none of the above conditions, decrement both the counters by 1. <br>
>

* The next step involves checking if the elements contained in the 2 majority elements are indeed the majority elements. This requires another linear pass and no extra space. <br>


Runtime: `11 ms`, faster than `90.55%`<br>
Memory Usage: `15.8 MB`, less than `82.10%`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/229-C.png)

</details>

</details>