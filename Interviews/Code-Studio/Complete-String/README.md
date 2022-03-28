Optimal Solution: TC = O(N x length of string)

We start by creating the node of Trie using more or less the same variables and functions. <br>
We them create a class Trie which consists of 2 functions:<br>
> insert(word): <br>
>> It is the same as an ordinary trie. <br>
>>
> ifComplete(word): <br>
>> This function checks if the word is complete or not. <br>
>> The word is traversed character by character and checked if the corresponding trie is valid or not. If valid, we check if it's flag is true or not. Bot conditions need to be met to continued, else we return false. <br>
>>
>
The rest is coming back to the completeString() function, inserting all the words of the vector and checking for each word if is complete or not and returning the largest and lexicographically smallest string. <br>

Runtime: 191ms