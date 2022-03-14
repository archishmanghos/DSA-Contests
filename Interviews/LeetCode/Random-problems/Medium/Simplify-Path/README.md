My solution: TC ~ `O(N)`, SC  = `O(N)`

> This is a simple casework problem but the cases are huge and tricky.<br>
> We use a stack to record previous character and traverse the string from the start. <br>
> Lets analyse the cases one by one. <br>
>> *Case 1*: The stack is empty -> We just push the current element. <br>
>> *Case 2*: The top of the stack is '/' and the current element is also '/' -> We ignore the current element. <br>
>> *Case 3*: The top of the stack is '.' and the current element is '/' -> We check if the element under top is '/' or not -> If '/', we pop the top, else we push the current element onto the stack. <br>
>> *Case 4*: The top of the stack is '/' and the current element is '.' and this is either the last element in the string or the next element is a '/' -> We dont push the element and continue. <br>
>> *Case 5*: The top of the stack is '.' and the current element is '.' and this is either the last element in the string or the next element is a '/' -> We check if the element under the top element is a '/' or not -> If slash, we don't push anything onto the stack and check how many slashes have already been covered in the stack, if there are more than 1, we go 1 directory up, else we just pop till the last slash. If not slash, we just push the current element and continue. <br>
>> *Case 6*: We just push the current element. <br>
> We come out after traversing and check if the stack size is more than 1 -> If it is more than one, we check if the top element is '/' -> If it is '/', we pop it, else we continue. <br>
> The final stack content is our answer in the reversed order. <br>

Runtime: `12 ms`, faster than `31.79%`<br>
Memory Usage: `8.5 MB`, less than `73.41%`