<!-- [Link to Striver's SDE Sheet]() -->

[Link to problem on Leetcode](https://leetcode.com/problems/find-and-replace-pattern/)



<details><summary>Sub-Optimal Solution</summary>

Sub-Optimal Solution: TC = `O(NM)`, SC = `O(26 x 2)` 

- For each word in the list do the following:
- Declare a vector of size 26 to map the characters and initialise to -1.
- Maintain a set to check for unique characters.
- Traverse the word and check if the i-th character of pattern has been mapped or not.
- If not mapped, check if the set already contains the to be mapped character. If it doesn't map the character and if it does, break out of the loop because this will never match.
- If mapped, check if the mapped character matches with the current character. If it doesn't break out of the loop, else continue further traversals.


Runtime: `2 ms`, faster than `91.01%`<br>
Memory Usage: `8.3 MB`, less than `77.06%`<br>

<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/890-A.png)

</details>

</details>



<details><summary>Optimal Solution</summary>

Optimal Solution: TC = `O(NM)`, SC = `O(26)`

- We normalise the pattern first.
- Normalising means changing the word such that each character is replaced by order of occurence.
- For example, for "sspqc", s occurs first, hence gets replaced by 'a' (for all s), p occurs next and is replaced by 'b', q is next and is replaced by 'c' and finally c by 'd'. So the normalised string for "sspqc" will be "aabcd".
- Next, we traverse the words array and check if the normalised version of the word is equal to the normalised pattern, if it is, we can push this to our answer.


Runtime: `0 ms`, faster than `100.00%`<br>
Memory Usage: `8.1 MB`, less than `83.72%`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/890-B.png)

</details>

</details>