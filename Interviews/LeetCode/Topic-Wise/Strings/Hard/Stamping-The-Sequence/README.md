<!-- [Link to Striver's SDE Sheet]() -->

[Link to problem on Leetcode](https://leetcode.com/problems/stamping-the-sequence/)



<!-- <details><summary>Sub-Optimal Solution</summary>

Sub-Optimal Solution: TC = , SC =  

*


Runtime: , faster than <br>
Memory Usage: , less than <br>

<details><summary>Clean Code</summary>

![]()

</details>

</details> -->



<details><summary>Optimal Solution</summary>

Optimal Solution: TC = `O(N ^ 2)`, SC = `O(N)` 

- Imagine we stamped the sequence with moves m1, m2, ⋯. Now, from the final position target, we will make those moves in reverse order.

- Let's call the ith window, a subarray of target of length stamp.length that starts at i. Each move at position i is possible if the ith window matches the stamp. After, every character in the window becomes a wildcard that can match any character in the stamp.

- For example, say we have stamp = "abca" and target = "aabcaca". Working backwards, we will reverse stamp at window 1 to get "a????ca", then reverse stamp at window 3 to get "a??????", and finally reverse stamp at position 0 to get "???????".

- Let's keep track of every window. We want to know how many cells initially match the stamp (our "made" list), and which ones don't (our "todo" list). Any windows that are ready (ie. have no todo list), get enqueued.

- Specifically, we enqueue the positions of each character. (To save time, we enqueue by character, not by window.) This represents that the character is ready to turn into a "?" in our working target string.

- Now, how to process characters in our queue? For each character, let's look at all the windows that intersect it, and update their todo lists. If any todo lists become empty in this manner (window.todo is empty), then we enqueue the characters in window.made that we haven't processed yet.

[Editorial Credits](https://leetcode.com/problems/stamping-the-sequence/solution/)

Runtime: `1348 ms`, faster than `5.74%`<br>
Memory Usage: `37.1 MB`, less than `31.15%`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/936.png)

</details>

</details>