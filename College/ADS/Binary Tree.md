It is a Tree T such that
- T is empty (Null tree or Empty Tree)
- T with a maximum of two children for each parent

#### Observations in a binary Tree
- Max number of nodes on a level i is 2$^i$  
- Max number of nodes in a binary tree is 2$^{h-1}$ (h = height of binary tree) 
- For any non empty BT, if t$_0$ is the number of terminal nodes and t$_2$ is the number of nodes of degree 2 then t$_0$ = t$_2$ + 1

#### Different types of binary tree
##### Full Binary Tree
It is a special kind of a binary tree that has either zero children or two children. It means that all the nodes in that binary tree should either have two child nodes of its parent node or the parent node is itself the leaf node or the external node.
![[Pasted image 20230919183946.png]]


##### Complete Binary Tree
A complete binary tree is another specific type of binary tree where all the tree levels are filled entirely with nodes, except the lowest level of the tree.

![[Pasted image 20230919184050.png]]

##### **Perfect Binary Tree**

A binary tree is said to be ‘perfect’ if all the internal nodes have strictly two children, and every external or leaf node is at the same level or same depth within a tree
![[Pasted image 20230919184203.png]]

##### Balanced Binary Tree
A binary tree is said to be ‘balanced’ if the tree height is O(logN), where ‘N’ is the number of nodes. In a balanced binary tree, the height of the left and the right subtrees of each node should vary by at most one.

![[Pasted image 20230919184244.png]]


##### **Degenerate Binary Tree** 

A binary tree is said to be a degenerate binary tree or pathological binary tree if every internal node has only a single child.

![[Pasted image 20230919184306.png]]

##### Skewed Binary Tree
* A binary tree which is dominated solely by left child nodes or right child nodes 

![[Pasted image 20230919184940.png]]

##### Properties of Complete Binary Tree
![[Pasted image 20230919184616.png]]

- If the parent node had a number i 
	- Left child has number 2i ( 2i<=n )
		- if 2i > n then i has no left child
	- Right child has the number 2i + 1 ( 2i + 1 <= n)
		- if 2i + 1 > n then i has no right child
- If child node has number i 
	- Parent node has the number floor(i/2)



#### Representation of Binary trees

##### Array Representation
![[Pasted image 20230919185141.png]]

![[Pasted image 20230919185903.png]]


#### Properties of Binary Tree
**Lemma 1** : For a binary Tree, the maximum number of nodes on level l is 2$^l$
**Lemma 2** : The maximum number of nodes possible in a binary tree with height h is 2$^h-1$
**Lemma 3** : Minimum number of nodes present in a binary tree if heigh h is h
**Lemma 4** : For a non empty binary tree, if n is the number of nodes and e is the number of edges then n = e + 1
**Lemma 5** : For any non-empty binary tree T, if n$_0$ is the number of leaf nodes and n$_2$ is the number of nodes with degree 2 then n$_0$ = n$_2$ + 1
**Lemma 6** : Height of the complete binary tree with n number of nodes is ceil(log$_2$(n+1))


#### Traversals of Binary Tree

##### Preorder (NLR)
##### Inorder (LNR)
##### Postorder (LRN)



