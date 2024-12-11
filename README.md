Inorder Successor of Node in BST (Please refer to the docx version of README for better understanding)


The inorder successor of a node p is the node q that comes just after p in the binary tree's inorder traversal.

Given the root node of a binary search tree and the node p, find the inorder successor of node p. If it does not exist, return null.

inorder-successor-bst
Testing
Input Format
The first line contains an integer T denoting the number of test cases.

For each test case, the input has 2 lines:

The first line contains an integer n denoting the number of nodes in the tree (including the NULL nodes).
The second line contains n space-separated integers that will form the binary tree. The integers follow level order traversal of the tree where -1 indicates a NULL node.
The third line contains an integer denoting the 0-based index of p in the above list.
Output Format
For each test case, the output contains an integer with the value of the inorder successor. In case the successor doesn't exist the value is -1.

Sample Input
4
9
2 1 3 -1 -1 -1 5 4 7
2
7
6 3 21 -1 -1 -1 89
1
12
8 3 9 -1 4 -1 10 -1 -1 -1 12 11
11
4
28 14 -1 11
0
Expected Output
4
6
12
-1