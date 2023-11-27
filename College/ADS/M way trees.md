- Can have more than two children
- A multiway tree of order M is a tree where children can have m children
- The nodes in an m way tree will be made up of key fields (m-1 key) and pointers to children

Max elements in an m way tree = `m^(h) - 1`

Mway trees have shorter height compared to binary trees hence less traversal overhead

### Conditions for an M-Way search Tree

- Keys in each node are in ascending order
- The keys in the first i children are smaller than the ith key 
- The keys in the last m-i children are larger than the ith key

### Insertion in M way trees
- Insert keys in node till key count == m-1
- If node full, insert key to the left sub tree node where key k_new < key_parent
- If node full, insert key to the left sub tree node where key k_new > key_parent
- insertion in the node can be done anyway just that the ascending order should be preferred
	- so if m=3, then a node can have two keys
	- lets say the keys are 14 32 145 etc
	- So the first node would look like | 14 | -> || 14 | 32 ||
	- But lets say the order was 32, 14 then it would look something like this
	- | 32 | -> || 14 | 32 || - You will insert 14 before 32 at the correct position

### Deletion in M way search trees
- **Case 1** - Deletion of trees with no subtree
	- Simply delete the node
- **Case 2** - Deletion of key with left subtree
	- Replace the largest value from the left subtree with value to be deleted. Delete largest value from left subtree
- **Case 3 - Deletion of key with right subtree
	- Replace the smallest value from the right subtree with value to be deleted. Delete smallest value from right subtree
- Case 4 - Deletion of a key with both left and right tree 
	- Replace smallest value for RST or replace largest value from LST with the key to be deleted. Then delete this replaced value