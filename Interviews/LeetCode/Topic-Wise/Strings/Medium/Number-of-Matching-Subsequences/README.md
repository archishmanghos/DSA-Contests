<!-- [Link to Striver's SDE Sheet]() -->

[Link to problem on Leetcode](https://leetcode.com/problems/number-of-matching-subsequences/)



<details><summary>My Solution</summary>

Optimal Solution: TC = `O(size(S) + size(words) x size(words[i]) x log(size(words)))`, SC = `O(size(words))`

- Take a adjacency list and list out for each character from 'a' to 'z', the indices in the given word. 
- Traverse through the given array and for each word, find the corresponding character in s using binary search. If the character does not exist, return false.
- Count all such occurences which return true.


Runtime: `280 ms`, faster than `69.94%`<br>
Memory Usage: `63.8 MB`, less than `38.32%`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/792.png)

</details>

</details>