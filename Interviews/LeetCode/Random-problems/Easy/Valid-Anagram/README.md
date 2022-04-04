We can have 2 solutions, depending on what we are trading off for. <br>
<br>
Solution 1: TC = `O(NlogN)`, SC = `O(1)`

We can sort both the strings. <br>
If the strings are anagrams, they will contain the same characters in exact same amount, so after sorting, they will become same if they are anagrams. <br>

Runtime: `16 ms`, faster than `40.15%`<br>
Memory Usage: `7.3 MB`, less than `46.01%`<br>

Solution 2: TC = `O(N)`, SC = `O(N)`

We can take a hash-map or an array and increase the value for characters in string s and decrease the same for characters in string t for a particular character. <br>
Finally for every character, if the count is 0, we can conclude, that they are anagrams. <br>

Runtime: `0 ms`, faster than `100.00%`<br>
Memory Usage: `7.4 MB`, less than `46.01%`