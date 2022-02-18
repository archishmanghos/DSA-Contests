Optimal Solution: TC = O(1) for both get and put operations, SC = O(N + N)

We maintain a doubly-linked list and an unordered map.

-> Create 2 dummy nodes, head and tail. The closer the node towards the tail, the more less recently used it is.

-> When we use the get() func, we check if the node is in the hashmap, if it's not, we return -1, else, we delete the node using the address from the hashmap and insert it after the head node, since it is the most recently used now.

-> When we use the put() func, we check if the node exists in the hashmap, 

	-> if it exits, we delete and insert it at the front and change the value in the hashmap.
	-> if it doesn't, we check if the size of hashmap is equal to the capacity.

		-> If it's equal, we delete the LRU node, which is just before the tail node and insert the new Node after the head and insert the node in the hashmap.
		-> If it isn't, we simply insert the new node after the head and insert the node in the hashmap.