[Link to the problem](https://leetcode.com/problems/group-anagrams/)

* Take a map of vector. <br>
* Traverse the array and count the number of character of the current string in the count vector. <br>
* If the vector already exists, we push the string to the index of the answer pre-stored in the map. <br>
* Else, we increment the current index and push the string there. Also, we store the vector in the map with the new index. <br>

Runtime: 64 ms, faster than 32.23%<br>
Memory Usage: 23.9 MB, less than 15.92%<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/49.png)

</details>