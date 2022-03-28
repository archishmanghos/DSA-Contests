Optimal Solution: TC = `O(N)`, SC = `O(N)`

We make a trie class or struct, which contains:<br>
> A reference trie for 26 characters. <br>
> A boolean flag which is initially set to false. <br>
> A function `containsKey` which returns if the reference trie for this node is NULL or not. <br>
> A function `createKey` which creates a reference trie for this node. <br>
> A function `getReferenceTrie` which returns the reference trie for this node. <br>
> A function `setEnd` which sets the flag of this node to `true`.<br>
>
 The implementation of each function is as follows: <br>
 > Trie(): 
 >> Constructor function. We create and instantiate the root node here. <br>
 >>
 > insert(word):
 >> We create a dummy node which holds the value of the root. <br>
 >> We traverse the word character by character. <br>
 >> If the current dummy root does not contain a reference trie, we create a new root of this character by using `createKey` function. We then set dummy root to its reference trie using `getReferenceTrie` function. <br>
 >> Finally after the whole traversal, we set the flag of the last referenced trie to `true` using `setEnd` function. <br>
 >>
 > search(word):
 >> The crux of the previous function remains the same. <br>
 >> We start by creating the dummy root and traversing the word next. <br>
 >> If the current dummy root does not contain a reference trie, we simply return `false`, because clearly no node has been created using this character and hence, the word cannot exist. <br>
 >> We set the dummy to its referenced trie and move on. <br>
 >> After the whole traversal, we check if the flag of the current referenced trie is `true` or not. If its true, then a word does exist, else not. <br>
 >>
 > startsWith(prefix):
 >> Same implementation as the `search()` function, except we don't have to check the flag after the traversal is over. This is because, the word does not have to end to qualify as a prefix. <br>
 >>
 >
 This is the basic implementation. <br>
 If still unclear, would suggest to [watch this video](https://www.youtube.com/watch?v=dBGUmUQhjaM).<br>

 Runtime: `73 ms`, faster than `71.56%`<br>
 Memory Usage: `45 MB`, less than `48.03%`
