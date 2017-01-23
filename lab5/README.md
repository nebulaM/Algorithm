#Lab 5 Min Heap

This lab uses another kind of binary tree called a minimum heap. (These are NOT binary search trees.)

We are implementing them using an array; the “pointers” from parent-to-child (and vice-versa) are subscript values. 

For this implementation to work, the tree MUST always be nearly-complete: every level is full, except perhaps the bottom level which might have open slots on the right.

The [Heap Visualizer](https://www.cs.usfca.edu/~galles/visualization/Heap.html) can be used to build your own examples of min heaps. 

Complete the following methods in **Minheap.cc**
```c++
print_tree(int ix, int level);
visit_tree(int ix, int level, Visitor& v);
insert(int element);
delete_min() ;
remove_matching(int value_to_remove);
```

For min heap 0 2 1 4 3 9 5 7 6 8, print_tree should output
```sh
    5
  1
    9
0
    3
      8
  2
      6
    4
      7
```