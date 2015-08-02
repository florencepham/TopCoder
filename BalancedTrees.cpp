// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
// Define the height of a binary tree to be the number of nodes in
// the longest path from the root to a leaf.  
// The empty tree is considered to have height 0.
// A node is k-balanced if 
// its left and right subtrees differ in height by at most k.  A tree is
// k-balanced if all of its nodes are k-balanced.  The empty tree
// is considered to be k-balanced.
// 
// 
// 
// For example, the tree below has height 4.
// 
// 
//            o
//           / \
//          o   o
//         / \
//        o   o
//           /
//          o
// 
// This tree is 2-balanced but not 1-balanced, because the left subtree of the 
// root has height 3 and the right subtree of the root has height 1.
// 
// 
// Your task is to write a method that takes
// a balance factor k and a number of nodes n and returns the maximum
// height of a k-balanced tree with n nodes.
// 
// 
// 
// DEFINITION
// Class:BalancedTrees
// Method:maxHeight
// Parameters:int, int
// Returns:int
// Method signature:int maxHeight(int k, int n)
// 
// 
// CONSTRAINTS
// -k is between 1 and 100, inclusive.
// -n is between 1 and 1000000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 1
// 7
// 
// Returns: 4
// 
// A tree that achieves the maximum height for 7 nodes and balance factor 1 is
// 
//            o
//           / \
//          o   o
//         / \   \
//        o   o   o
//       /
//      o
// 
// 
// 
// 1)
// 2
// 40
// 
// Returns: 9
// 
// 2)
// 10
// 5
// 
// Returns: 5
// 
// With k=10, a tree of size 5 can be completely linear (eg, every right subtree 
// is empty) without violating the balance factor.
// 
// 
// END CUT HERE
#line 86 "BalancedTrees.cpp"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath> 
#include <map> 
#include <queue> 
#include <stack> 

using namespace std; 

class BalancedTrees {
	public:
	int maxHeight(int k, int n) {
		
	}
};
