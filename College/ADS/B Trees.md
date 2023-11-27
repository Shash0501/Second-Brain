A B tree is a self - balancing M way search tree data structure that allows searches, access, insertions and deletions in logarithmic time
**Properties**
- It is perfectly balanced, every leaf node is at the same depth 
- Every node, except the root is at least half full i.e. contains M/2 or more values

The time complexity for insertion, deletion and seach operations takes O(logn) time where n is the number of keys stored in the tree
The space complexity for a B Tree is O(n) where n is the number of keys in the tree

![[Pasted image 20231112175556.png]]

![[Pasted image 20231112175604.png]]