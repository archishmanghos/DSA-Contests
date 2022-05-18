Optimal Solution: TC = `O(32N + 32M)`

We make a trie where we insert every element from array 1 into the trie bit-wise from 31st till 0th. <br>
We make a function of maximising XOR in the trie, where we try to maximise the XOR for every element of array 2, by taking the opposite bit everytime we traverse through the bits. <br>
For every element of array 2, we maximise the XOR with the trie, which contains the elements of array 1. <br>
The maximum of all the maximums is our answer. <br>

Runtime: `177ms`