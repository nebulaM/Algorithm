#Lab 4 Binary Search Tree

Binary search tree basics: [Link1](https://www.youtube.com/watch?v=KQ4BA5tGkMU) [Link2](https://www.youtube.com/watch?v=sf_9w653xdE)

Modify bst.cc to pass tests.
```sh
make
./bst
```
You can also write your own testing/debugging code and run that instead. 

To do that, put your code in runMain() and supply your test keys as command line arguments
```sh
./bst 5 3 2 1 6 8 4 7 9
```
Use recursive functions to complete the following functions
```c++
 int numNodes( Node* root );
 
 int numLeaves( Node* root );
 
 int height( Node* x );
 
 int depth( Node* x , Node* root ');
 
 void in_order( Node*& rootNode, int level, Visitor& v );
 
 void pre_order( Node*& rootNode, int level, Visitor& v );
 
 void post_order( Node*& rootNode, int level, Visitor& v );
 
 bool delete_node(Node*& root, KType key);
```

Watch the first 5 minutes of [this video](https://www.youtube.com/watch?v=sqVefIEttT0)

Regarding his code: it's considered “better” to deal with the base case first, i.e.
```c++
if (! root) return 0; // should be the first line
```
Consider this corresponding example from a previous lab: to count the nodes in a linked_list
```c++
int count_nodes(Node* head){
 if (! head) return 0; // BASE CASE
 return 1 + count_nodes(head->next);
}
```
The above is more concise, looks cleaner, and is easier to read and understand than something like
```c++
int count_nodes(Node* head){
 if (head != NULL){
 return 1 + count_nodes(head->next);
 }
 else {
 return 0;
 }
}
```
And [this video](https://www.youtube.com/watch?v=wcIRPqTR3Kc) is helpful for deleting a tree node.

One final question to ask yourself: 

which function(s) would have to change if the Nodes were part of a binary tree that wasn't also a binary search tree?

Hint: which function(s) relied on the fact that the keys in the left-child and its descendants were less than the key in the node, or that the keys in the right-child and its descendants were greater that it? 
