Optimal Solution: TC = `O(QlogQ + NlogN + Q + N)` ≈ `O(max(QlogQ, NlogN))` <br>

We construct a trie as usual and create a function to maximise the XOR, which takes bits alternatively if exist. <br>
We store the queries as offline queries and sort them according to value of A[i]. <br>
We also sort the original array. <br>
Now we start inserting into the trie upto which will not exceed the current querie's A[i]. <br>
Then we calculate the maximum XOR upto that point. <br>

Runtime: `226ms`