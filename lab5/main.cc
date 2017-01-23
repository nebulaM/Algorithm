#include <iostream>
#include <sstream>
#include <cassert>
#include "Minheap.h"
#include "Unit.h"

void run_me_first(void){ // any test code of your own, runs before unit tests 
    // whatever you like 
}

/* ******** DO NOT CHANGE BEYOND HERE ******** */ 

// no more Mr Nice Guy - Unit tests also check your tree printing 

/* ******************************************** */ 

int input1[] = { 8, 3, 5, 6, 2, 9, 1, 7, 4, 0 };

// After constructing minheap with input1, you get this array 
//             { 0, 2, 1, 4, 3, 9, 5, 7, 6, 8 };

int drain1[] = { 0, 2, 1, 4, 3, 9, 5, 7, 6, 8, // after construction 
                 1, 2, 5, 4, 3, 9, 8, 7, 6, 0, // after 1 delete_min()
                 2, 3, 5, 4, 6, 9, 8, 7, 0, 0, // after 2
                 3, 4, 5, 7, 6, 9, 8, 0, 0, 0, // after 3 
                 4, 6, 5, 7, 8, 9, 0, 0, 0, 0, // after 4  
                 5, 6, 9, 7, 8, 0, 0, 0, 0, 0, // after 5
                 6, 7, 9, 8, 0, 0, 0, 0, 0, 0, // after 6
                 7, 8, 9, 0, 0, 0, 0, 0, 0, 0, // after 7  
                 8, 9, 0, 0, 0, 0, 0, 0, 0, 0, // after 8 
                 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, // after 9 
                 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };  // after 10 (empty) 

int build1[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, // after 1 insert 
                 3, 8, 0, 0, 0, 0, 0, 0, 0, 0, // after 2
                 3, 8, 5, 0, 0, 0, 0, 0, 0, 0, // after 3
                 3, 6, 5, 8, 0, 0, 0, 0, 0, 0, // after 4
                 2, 3, 5, 8, 6, 0, 0, 0, 0, 0, // after 5 
                 2, 3, 5, 8, 6, 9, 0, 0, 0, 0, // after 6
                 1, 3, 2, 8, 6, 9, 5, 0, 0, 0, // after 7
                 1, 3, 2, 7, 6, 9, 5, 8, 0, 0, // after 8
                 1, 3, 2, 4, 6, 9, 5, 8, 7, 0, // after 9
                 0, 1, 2, 4, 3, 9, 5, 8, 7, 6}; // after 10

// Turn your head counter clockwise to see the nearly complete tree below on the left. 
// Each element is preceded by (1 + 3*level) spaces. 
// Root is at 0, but the first thing that prints is the rightmost element.
// 
//       5      at level=2 and index=6 its value is 5,      
//    1         at level=1 and index=2 this value is 1       
//       9      which are the numbers in the tree1 array below,
// 0            (the level, index and value for each element in the tree)
//       3
//          8
//    2
//          6
//       4
//          7
//
int tree1[] = { 2, 6, 5,   1, 2, 1,   2, 5, 9,   0, 0, 0,   2, 4, 3, 
                3, 9, 8,   1, 1, 2,   3, 8, 6,   2, 3, 4,   3, 7, 7, 
    // after 1 delete_min  
                2, 6, 8,   1, 2, 5,   2, 5, 9,   0, 0, 1,   2, 4, 3, 
                1, 1, 2,   3, 8, 6,   2, 3, 4,   3, 7, 7,   0, 0, 0,
    // after 2 delete_min  
                2, 6, 8,   1, 2, 5,   2, 5, 9,   0, 0, 2,   2, 4, 6,
                1, 1, 3,   2, 3, 4,   3, 7, 7,   0, 0, 0,   0, 0, 0,
    // after 3 delete_min  
                2, 6, 8,   1, 2, 5,   2, 5, 9,   0, 0, 3,   2, 4, 6, 
                1, 1, 4,   2, 3, 7,   0, 0, 0,   0, 0, 0,   0, 0, 0,
    // after 4 delete_min  
                1, 2, 5,   2, 5, 9,   0, 0, 4,   2, 4, 8,   1, 1, 6, 
                2, 3, 7,   0, 0, 0,   0, 0, 0,   0, 0, 0,   0, 0, 0,
    // after 5 delete_min  
                1, 2, 9,   0, 0, 5,   2, 4, 8,   1, 1, 6,   2, 3, 7, 
                0, 0, 0,   0, 0, 0,   0, 0, 0,   0, 0, 0,   0, 0, 0,
    // after 6 delete_min  
                1, 2, 9,   0, 0, 6,   1, 1, 7,   2, 3, 8,   0, 0, 0, 
                0, 0, 0,   0, 0, 0,   0, 0, 0,   0, 0, 0,   0, 0, 0,
    // after 7 delete_min  
                1, 2, 9,   0, 0, 7,   1, 1, 8,   0, 0, 0,   0, 0, 0, 
                0, 0, 0,   0, 0, 0,   0, 0, 0,   0, 0, 0,   0, 0, 0,
    // after 8 delete_min  
                0, 0, 8,   1, 1, 9,   0, 0, 0,   0, 0, 0,   0, 0, 0, 
                0, 0, 0,   0, 0, 0,   0, 0, 0,   0, 0, 0,   0, 0, 0,
    // after 9 delete_min  
                0, 0, 9,   0, 0, 0,   0, 0, 0,   0, 0, 0,   0, 0, 0, 
                0, 0, 0,   0, 0, 0,   0, 0, 0,   0, 0, 0,   0, 0, 0,
    // after 10 delete_min (empty)   
                0, 0, 0,   0, 0, 0,   0, 0, 0,   0, 0, 0,   0, 0, 0, 
                0, 0, 0,   0, 0, 0,   0, 0, 0,   0, 0, 0,   0, 0, 0 }; 



int input2[] = { 15, 17, 13, 11, 12, 12, 11, 9, 7, 8 };
int morph2[] = { 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                15, 17, 0, 0, 0, 0, 0, 0, 0, 0, 
                13, 17, 15, 0, 0, 0, 0, 0, 0, 0, 
                11, 13, 15, 17, 0, 0, 0, 0, 0, 0, 
                11, 12, 15, 17, 13, 0, 0, 0, 0, 0, 
                11, 12, 12, 17, 13, 15, 0, 0, 0, 0, 
                11, 12, 11, 17, 13, 15, 12, 0, 0, 0, 
                9, 11, 11, 12, 13, 15, 12, 17, 0, 0, 
                7, 9, 11, 11, 13, 15, 12, 17, 12, 0, 
                7, 8, 11, 11, 9, 15, 12, 17, 12, 13 };

// visited vector stores paramater values (level, ix and element itself) as each "node" is visited 
std::vector<int> visited; 
// Visitor class is defined in Minheap.h (so visit_tree() method knows what one is) 
class VectorVisitor : public Visitor {
    void visit(int* _heap, int ix, int level) {
        visited.push_back( level ); 
        visited.push_back( ix ); 
        visited.push_back( _heap[ix] ); 
    }
};

void print_array(int* src, int size){
    for (int ii = 0; ii < size; ++ii) {
        std::cout << src[ii] << " ";
    }
    std::cout << std::endl; 
}
void prepare_vector(std::vector<int>& vv, int* src, int offset, int size) { 
    vv.clear();
    for (int ii=0; ii < size; ii++) { 
        vv.push_back( src[ offset + ii ] ) ; 
    }
    assert( vv.size() == (size_t) size ); 
}
void print_vector(std::vector<int>& vv) { 
    int vSize = vv.size();
    std::cout << "{ "; 
    for (int ii=0; ii < vSize; ii++) { 
        std::cout << vv[ii] << ((ii+1 < vSize) ? ", " : " ");  
    }
    std::cout << "}; "; 
}
void remove_trailing_zeroes(std::vector<int>& vv, int from_index) { 
    for (int jj = from_index; jj < (int) vv.size(); ++ jj) { 
        if (vv[jj] != 0) return; // no-op if not all 0 
    }
    for (int jj = vv.size(); jj > from_index; -- jj) {
        vv.pop_back();
    }
}
int check_heap_property( Minheap* minheap ){ 
    int* copy1 = minheap->get_heap();
    int hSize = minheap->get_size(); 
    int result = 0;
    for (int ii=1; ii < hSize; ++ii) {
        int parent = (ii - 1) /2;
        if (copy1[parent] > copy1[ii]) result += 1; 
    }
    delete[] copy1; 
    return result; 
}

int main() {
    run_me_first(); 
    
    Unit unit; 
    VectorVisitor vectorVisitor; 

    std::vector<int> expected; 
    std::vector<int> actual; 
    
    const int CAPACITY1 = sizeof(input1) / sizeof(int);
    std::cout << "input1: "; 
    print_array( input1, CAPACITY1 ); 
    Minheap* heap1 = new Minheap(input1, CAPACITY1);
    std::cout << "heap1: " << std::endl;
    heap1->print_tree();
    heap1->print_array();
    std::cout << std::endl;
    assert( CAPACITY1 * (CAPACITY1 + 1) == (sizeof(drain1) / sizeof(int) ) ); 
    assert( sizeof(drain1) == sizeof(build1)); 
    
    // heap after construction 
    int heap1_size = heap1->get_size(); 
    unit.assertEquals("heap1: size after construction", CAPACITY1, heap1_size );
    unit.assertEquals("heap1: capacity after construction", CAPACITY1, heap1->get_capacity() );
    prepare_vector( actual, heap1->get_heap(), 0, CAPACITY1 ); 
    prepare_vector( expected, drain1, 0, CAPACITY1 ); 
    unit.assertEquals("heap1: expected and actual lengths", expected.size(), actual.size() );
    unit.assertvectorEquals("heap1: array after construction", expected, actual );
    int num_Parent_GT_child = check_heap_property( heap1 ); 
    unit.assertEquals("heap1: heap property after construction", 0, num_Parent_GT_child);
    // tree after construction 
    assert( sizeof(tree1) / sizeof(int) == (CAPACITY1 * 3)*(CAPACITY1 + 1)); 
    prepare_vector(expected, tree1, 0, CAPACITY1 * 3);     
    visited.clear(); 
    heap1->visit_tree( vectorVisitor);
    unit.assertEquals("heap1: expected.size() multiple of 3 (internal error)", 0, (expected.size() % 3));
    unit.assertEquals("heap1: visited.size() multiple of 3 (internal error)", 0, (visited.size() % 3));
    unit.assertEquals("heap1: num tree nodes after construction", (expected.size() / 3), (visited.size() / 3));
    unit.assertEquals("heap1: expected and visited lengths", expected.size(), visited.size() );
    unit.assertvectorEquals("heap1: tree after construction", expected, visited );
    
    // delete everything
    const int MIN_VALUE = heap1->delete_min(); 
    int prev = MIN_VALUE;
    heap1_size --; 
    for (int ii=1; ii <CAPACITY1; ++ii) { 
        // capacity and size after delete_min 
        std::stringstream smt;
        smt << "heap1: size after " << CAPACITY1 - heap1_size << " delete_mins";
        unit.assertEquals(smt.str(), heap1_size, heap1->get_size() );
        std::stringstream cmt;
        cmt << "heap1: capacity after " << CAPACITY1 - heap1_size << " delete_mins";
        unit.assertEquals(cmt.str(), CAPACITY1, heap1->get_capacity() );
        // content and order of array after delete_min 
        prepare_vector( actual, heap1->get_heap(), 0, CAPACITY1 ); 
        prepare_vector( expected, drain1, CAPACITY1*(CAPACITY1 - heap1_size), CAPACITY1 ); 
        unit.assertEquals("heap1: expected and actual sizes", expected.size(), actual.size() );
        std::stringstream fmt;
        fmt << "heap1: array after " << CAPACITY1 - heap1_size << " delete_mins";
        unit.assertvectorEquals( fmt.str(), expected, actual );
        // tree after delete_min 
        visited.clear(); 
        heap1->visit_tree( vectorVisitor);
        prepare_vector( expected, tree1, 3 * CAPACITY1 * (CAPACITY1 - heap1_size), 3 * heap1_size); 
        unit.assertEquals("heap1: expected and visited sizes", expected.size(), visited.size() );
        std::stringstream tmt;
        tmt << "heap1: tree after " << CAPACITY1 - heap1_size << " delete_mins";
        unit.assertvectorEquals( tmt.str(), expected, visited );
        // heap property after delete_min         
        num_Parent_GT_child = check_heap_property( heap1 ); 
        unit.assertEquals("invalid heap after delete_min", 0, num_Parent_GT_child);
        int curr = heap1->delete_min();
        unit.assert_LE("heap1: sequence of delete_min values", prev, curr );
        // next element 
        prev = curr; 
        heap1_size --; 
    }
    const int MAX_VALUE = prev; 
    unit.assertEquals("heap1: emptied, test size", 0, heap1_size );
    unit.assertEquals("heap1: emptied, size", 0, heap1->get_size() );
    unit.assertEquals("heap1: emptied, capacity", CAPACITY1, heap1->get_capacity() );
    prepare_vector( actual, heap1->get_heap(), 0, CAPACITY1 ); 
    prepare_vector( expected, drain1, CAPACITY1*CAPACITY1, CAPACITY1 ); 
    unit.assertEquals("heap1: emptied, expected and actual sizes", expected.size(), actual.size() );
    unit.assertvectorEquals("heap1: emptied, array", expected, actual );
    expected.clear();
    visited.clear(); 
    heap1->visit_tree( vectorVisitor);
    unit.assertEquals("heap1: emptied, expected and visited tree nodes", expected.size(), visited.size() );
    unit.assertvectorEquals("heap1: emptied, tree", expected, visited );
    
    int heap2_size = 0; 
    Minheap* heap2 = new Minheap(); 
    unit.assertEquals("heap2: size", 0, heap2->get_size() );
    unit.assertEquals("heap2: capacity", DEFAULT_CAPACITY, heap2->get_capacity() );
    // insert everything from input1 onto heap2 
    for (int ii=0; ii < CAPACITY1; ++ii) {
        heap2->insert( input1[ii] ); 
        heap2_size ++; 
        std::stringstream smt;
        smt << "heap2: size after " << heap2_size << " inserts";
        unit.assertEquals(smt.str(), heap2_size, heap2->get_size() );
        unit.assertEquals("heap2: capacity", DEFAULT_CAPACITY, heap2->get_capacity() );
        num_Parent_GT_child = check_heap_property( heap2 ); 
        unit.assertEquals("heap2: invalid heap after insert", 0, num_Parent_GT_child);
        // testing with a relatively large vector, but keep error messages human readable 
        prepare_vector( expected, build1, CAPACITY1 * (ii+1), CAPACITY1 ); 
        // there are 256 elements here, but only the first 10 (CAPACITY1) should ever be non-zero 
        prepare_vector( actual, heap2->get_heap(), 0, DEFAULT_CAPACITY );
        // trailing elements of actual SHOULD all be 0 (i.e. actual[CAPACITY1] .. actual[DEFAULT_CAPACITY - 1] all zero)
        remove_trailing_zeroes( actual, CAPACITY1 ); 
        unit.assertEquals("heap2: expected and actual sizes", expected.size(), actual.size() );
        std::stringstream fmt;
        fmt << "heap2: array after " << heap2_size << " inserts";
        unit.assertvectorEquals(fmt.str(), expected, actual );
    }

    unit.assertEquals("heap2: size after all initial inserts", CAPACITY1, heap2->get_size() );
    prepare_vector( expected, build1, CAPACITY1 * CAPACITY1, CAPACITY1 );     
    // insert many copies of largest value 
    for (int ii=0; ii < (2 * heap2_size); ++ii) {         
        expected.push_back( MAX_VALUE ); 
        // insert() should call swap_up() which should do nothing 
        heap2->insert( MAX_VALUE ); 
        prepare_vector( actual, heap2->get_heap(), 0, DEFAULT_CAPACITY ); 
        remove_trailing_zeroes( actual, expected.size() ); 
        unit.assertEquals("heap2: adding MAX, expected and actual sizes", expected.size(), actual.size() );
        std::stringstream fmt;
        fmt << "heap2: array after " << ii+1 << " inserts of MAX";
        unit.assertvectorEquals(fmt.str(), expected, actual );
    } 
    unit.assertEquals("heap2: size after MAX duplicates inserted", heap2_size * 3, heap2->get_size() );
    num_Parent_GT_child = check_heap_property( heap2 ); 
    unit.assertEquals("heap2: invalid heap after duplicates", 0, num_Parent_GT_child);
    heap2->remove_matching( MAX_VALUE ); 
    heap2_size --; 
    unit.assertEquals("heap2: size after remove_matching MAX", heap2_size, heap2->get_size() );
    
    prepare_vector( expected, heap2->get_heap(), 0, heap2_size ); 
    // remove something that isn't there 
    heap2->remove_matching( MAX_VALUE ); 
    unit.assertEquals("heap2: size after remove_matching (no match)", heap2_size, heap2->get_size() );
    prepare_vector( actual, heap2->get_heap(), 0, heap2_size ); 
    unit.assertvectorEquals("heap2: remove_matching (no match) arrays", expected, actual );
    num_Parent_GT_child = check_heap_property( heap2 ); 
    unit.assertEquals("heap2: invalid heap after remove_matching", 0, num_Parent_GT_child);
    // finally, put the MAX value back in 
    heap2->insert( MAX_VALUE ); 
    heap2_size ++; 
            
    // insert many copies of smallest value 
    for (int ii=heap2_size; ii < DEFAULT_CAPACITY; ++ii) {         
        heap2->insert( MIN_VALUE ); 
    } 
    unit.assertEquals("heap2: size, after adding MIN duplicates", DEFAULT_CAPACITY, heap2->get_size() );
    unit.assertEquals("heap2: delete_min, after adding MIN duplicates", heap2->delete_min(), MIN_VALUE );
    unit.assertEquals("heap2: size, room for 1 more", DEFAULT_CAPACITY - 1, heap2->get_size() );
    heap2->insert( MIN_VALUE ); 
    unit.assertEquals("heap2: was at capacity, reduced, now at capacity again", DEFAULT_CAPACITY, heap2->get_size() );
    heap2->remove_matching( MIN_VALUE ); 
    unit.assertEquals("heap2: size, after remove MIN duplicates", heap2_size - 1, heap2->get_size() );
    heap2->insert( MIN_VALUE ); 
    
    // remove them all again (to be sure no values lost) 
    for (int ii=0; ii<heap2_size; ii++) { 
        std::stringstream fmt;
        fmt << "heap2: delete_min " << ii << " (should have same value)";
        unit.assertEquals( fmt.str(), ii, heap2->delete_min() );
    }        
    
    expected.clear();
    actual.clear();
    const int size2 = sizeof(input2) / sizeof(int);
    assert( size2 * size2 == (sizeof(morph2) / sizeof(int) ) ); 
    unit.assertEquals("heap1 capacity", size2, CAPACITY1 );
    for (int ii=0; ii < size2; ++ii) { 
        heap1->insert( input2[ii] ); 
        std::stringstream fmt;
        fmt << "heap1 size after " << ii+1 << " inserts";
        unit.assertEquals( fmt.str(), ii+1, heap1->get_size() );
        std::stringstream vmt;
        vmt << "heap1 structure after " << ii+1 << " inserts";
        prepare_vector( actual, heap1->get_heap(), 0, size2 ); 
        prepare_vector( expected, morph2, ii*size2, size2 ); 
        unit.assertvectorEquals( vmt.str(), expected, actual );
    }
    unit.assertEquals("heap1 size = capacity ", heap1->get_size(), CAPACITY1 );

    unit.printResults(); 
    
    delete heap1;
    delete heap2;

    return 0;
}
