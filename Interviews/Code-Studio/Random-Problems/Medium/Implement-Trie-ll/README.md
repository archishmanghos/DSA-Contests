Optimal Solution: TC = O(N), SC = O(N)

We make a trie class or struct, which contains:<br>
> A reference trie for 26 characters. <br>
> A variable `endsWith` to count the number of words ending with this character node. <br>
> A variable `countPrefix` to count the number of prefixes ending with this character node. <br>
> A function `containsKey` which returns if the reference trie for this node is NULL or not.<br>
> A function `createKey` which creates a reference trie for this node.<br>
> A function `getReferenceTrie` which returns the reference trie for this node.<br>
> A function `changeCountEnd` to increment/decrement the variable `endsWith`.<br>
> A function `changeCountPrefix` to increment/decrement the variable `countPrefix`.<br>
>
The implementation of each function is as follows:<br>
> Trie():<br>
>> Constructor function. We create and instantiate the root node here.<br>
>>
> insert(word):<br>
>> We create a dummy node which holds the value of the root.<br>
>> We traverse the word character by character.<br>
>> If the current dummy root does not contain a reference trie, we create a new root of this character by using createKey function. We then set dummy root to its reference trie using getReferenceTrie function. We also increase the `countPrefix` using the `changeCountPrefix` function<br>
>> Finally after the whole traversal, we increase the `endsWith` using the `changeCountEnd` function<br>
>>
> countWordsEqualTo(word): <br>
>> The crux of the previous function remains the same.
We start by creating the dummy root and traversing the word next. <br>
>> If the current dummy root does not contain a reference trie, we simply return 0, because clearly no node has been created using this character and hence, the word cannot exist.<br>
>> We set the dummy to its referenced trie and move on.<br>
>> After the whole traversal, we return the value of `endsWith`, because that is the number of words that end with this character node. <br>
>>
> countWordsStartingWith(word): <br>
>> Same implementation as the countWordsEqualTo() function, except we have to return tha value of  `countPrefix` after the traversal is over. This is because, we are checking for the number of prefixes here.<br>
>>
> erase(word): <br>
>> This is exactly same implementation as insert() function, except we need to decrease the value of `countPrefix` where we were increasing it and after the traversal is over, we need to decrease the value of `endsWith` instead of increasing, because we are removing an instance of this word. <br>
>>
This is the basic implementation.<br>
If still unclear, would suggest to [watch this video](https://www.youtube.com/watch?v=K5pcpkEMCN0&list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp&index=2).<br>

Runtime: `162ms`