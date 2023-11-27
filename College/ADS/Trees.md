- Tree has a special node called the root 
- The rest of the nodes can be partitioned into **n** disjoint sets ( sets that do not have common elements ) where each set can represent a tree.

### Tree Terminology
**Height of a node** : No of nodes in the longest path to a leaf from that node.

![[Pasted image 20230919174902.png]]

**Depth of a node** : No of nodes in the path from root to that node
![[Pasted image 20230919174958.png]]

**Height of the tree** : No of nodes in the longest path from root node to leaf node
It is also equal to h = L$_{max}$ + 1 ( L$_{max}$ = Maximum level of the tree)
In the above image the height of the tree is 4 ( 3 + 1 ; L$_{max}$ = 3 )

**Degree of node** : Number of children for the node
**Degree of Tree** : Max degree of node in the tree

![[Pasted image 20230919180123.png]]

### Representation of the Trees

##### List Representation

-> (A() )
-> (A( B() ) )
-> (A( B( ( F,G,H ) ) ) )
-> (A( B( ( F,G,H ), C ) ) )
....
-> **(A( B( ( F,G,H ), C, D( I ), E( J, K(L) ) ) ) )**

##### Linked List representation
![[Pasted image 20230919180511.png]]

![[Pasted image 20230919180628.png]]
![[Pasted image 20230919180623.png]]


- The max number of nodes in a binary tree of height h is 2^h -1
- if t0 is the number of terminal nodes and t2 is the number of nodes of degree 2
- then t0 = t1+1


Height of a complete tree is ceil(log2(n+1))

2 - Tree
A binary tree T is said to be 2-Tree or an extended binary tree if each node N has either 0 or 2 children


If a binary tree has n nodes then the number of pointers used in its linked representation is 2 * n
The number of null pointers used in linked list representation of a binary tree with n nodes is n+1


Things to revise
----------------------------
- Derive tree from Preorder and Postorder
- Post order traversal using stack


