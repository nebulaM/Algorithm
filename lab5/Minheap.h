#ifndef _MINHEAP_H_
#define _MINHEAP_H_
#include <iostream>
#include <cassert>
#include <vector>

#define DEFAULT_CAPACITY 256

class Visitor { public:
    virtual ~Visitor() { };
    virtual void visit(int* _heap, int ix, int level) = 0;
};
class PrintVisitor : public Visitor {
    void visit(int* _heap, int ix, int level) {
        for (int ii=0; ii<level; ++ii) std::cout << " ";
        std::cout << _heap[ix] << std::endl;
    }
};

class Minheap {
public:
    Minheap();
    Minheap(int capacity);
    Minheap(int* elements, int num_elements);
    ~Minheap();

    /* add element to the heap */
    void insert(int element);
    /* remove the top element and return its value */
    int delete_min();
    /* remove all elements with value equal to value-to-remove */
    void remove_matching(int value_to_remove);

    /* prints the heap array */
    void print_array();
    /* print the heap as a tree */
    void print_tree();

    /* returns the number of elements currently in the heap */
    int get_size();
    /* returns the maximum number of elements that can be in the heap */
    int get_capacity();
    /* returns the heap as a new array (of capacity = _capacity) */
    int* get_heap();

    /* returns true IFF _size == 0 */
    bool isEmpty();

    /* visit the elements in the heap as a tree */
    void visit_tree(Visitor& visit);

private:
    int _capacity;
    int _size;
    int* _heap;

    void heapify();
    void swap_down(int ix);
    void swap_up(int ix);

    void print_tree(int ix, int level);
    void visit_tree(int ix, int level, Visitor& visitor); /** for Unit tests */

    int percolateUp(int hole,int val);
    int percolateDown(int hole,int val);

};

#endif /* _MINHEAP_H_ */
