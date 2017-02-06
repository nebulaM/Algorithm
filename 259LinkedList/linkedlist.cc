/*
 * File:            linkedlist.c
 * Purpose:         Implements the linked list functions whose prototypes
 *                  are declared in the linked_list.h header file
 */

/* Preprocessor directives */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

/******************************************************************
 PLEASE EDIT THIS FILE

 Comments that start with // should be replaced with code
 Comments that are surrounded by * are hints
 ******************************************************************/

/*
 Main function drives the program.  Every C program must have one
 main function.  A project will not compile without one.

 In our program, the main function does nothing.  That's because
 our program doesn't do anything.  We're just implementing a linked
 list and testing it using our unit tests.

 PRE:    NULL (no pre-conditions)
 POST:	 NULL (no side-effects)
 RETURN: IF the program exits correctly
         THEN 0 ELSE 1
 */
int main ( void )
{
    /* The system command forces the system to pause */
    system(  "pause");
    return 0;
}

/*
 Returns a pointer to a new, empty linked list of struct node.
 PRE:       NULL (no pre-conditions)
 POST:      NULL (no side-effects)
 RETURN:    A pointer to a new, empty linked list of struct node (NULL)
 */
struct node * create_linked_list()
{
    // Insert your code here
    return NULL;
}

/*
 Returns a dynamically allocated struct node that contains the specified
 struct airplane.  The node's next pointer doesn't point to anything
 e.g., it is equal to NULL.
 PARAM:     plane, a struct airplane
 PRE:       NULL (no pre-conditions)
 POST:      NULL (no side-effects)
 RETURN:    A pointer to a dynamically allocated struct node a) that contains
            the specified struct airplane, and b) whose next pointer points to NULL
 */
struct node * create_node(struct airplane plane)
{
    // Insert your code here
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->plane=plane;
    newnode->next=NULL;
    return newnode;
}

/*
 Prepends a struct node passed as a parameter to the list passed as a
 parameter, and returns a pointer to the result.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PARAM:     new_node is a pointer to a struct node
 PRE:       new_node is not null
 POST:      The specified struct node is added to the beginning of the list
            and its next pointer points to the node that used to be first
 RETURN:    A pointer to a linked list which contains all of the nodes
            of the list passed as a parameter, plus a prepended node
 */
struct node * prepend_node(struct node * list, struct node * new_node)
{
    // Insert your code here
    new_node->next=list;
    list=new_node;
    return list;
}

/*
 Deletes the first struct node in the specified list, and returns a pointer to
 the shortened list.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PRE:       NULL
 POST:      The list passed as a parameter has one fewer node, and the dynamically
            allocated memory which contained that removed node has been freed
 RETURN:    IF the list is empty
            THEN NULL
            ELSE a pointer to the shortened list
 */
struct node * delete_node(struct node * list)
{
    // Insert your code here
    if(!list){
        return list;
    }
    struct node *ptr=list;
    list=list->next;
    free(ptr);
    ptr=NULL;
    return list;
}

/*
 Returns the number of nodes in the specified linked list of struct node.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PRE:       NULL (no pre-conditions)
 POST:      NULL (no side-effects)
 RETURN:    The length of the specified list, an int
 */
int get_length(struct node * list)
{
    // Insert your code here
    if(!list){
        return 0;
    }
    int count=0;
    struct node *ptr=list;
    while(ptr)
    {
        ptr=ptr->next;
        count++;
    }
    return count;
}

/*
 Deletes an entire list.  This function iterates along a list and deallocates the
 memory containing each struct node.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PRE:       NULL (no pre-conditions)
 POST:      The memory containing all of the nodes in the list has been freed
 RETURN:    an empty list (NULL)
 */
struct node * delete_list(struct node * list)
{
    // Insert your code here
    if(!list){
        return list;
    }
    struct node * ptr;
    while(list)
    {
        ptr=list;
        list=list->next;
        free(ptr);
        ptr=NULL;
    }
    return list;
}

/*
 Prints the data stored in a node.  For the struct airplane in the node,
 prints the fields on separate lines.  For each field, prints the field name
 and the field value.  For the pointer, prints "Link = NULL\n" if the pointer points
 to null, else prints "Link points to address xxx\n", where xxx is the pointer address
 in hexademical.
 If node_to_print is NULL, prints "The node is empty\n".
 PARAM:     node_to_print is a pointer to a (possibly null) struct node
 PRE:       NULL (no pre-conditions)
 POST:      Information about node_to_print has been printed to standard output
 RETURN:    NULL
 */
void print_node(struct node * node_to_print)
{
    // Insert your code here
    if(!node_to_print->next){
        printf("Link = NULL\n");
    }
    else{
        printf("Link points to address %d\n",&(node_to_print->next));
    }
    if(!node_to_print){
        printf("The node is empty\n");
    }
    else
    {
        printf("Flight number is %d\n",node_to_print->plane.flight_number);
        printf("City origin is %s\n",node_to_print->plane.city_origin);
        printf("City destination is %s\n",node_to_print->plane.city_destination);
        printf("Priority is %d\n",node_to_print->plane.priority);
        printf("Maximum speed kph is %d\n",node_to_print->plane.maximum_speed_kph);
        printf("Cruising altitude is %d\n",node_to_print->plane.cruising_altitude);
        printf("Capacity is %d\n",node_to_print->plane.capacity);
        printf("\n");
    }
    return;
}

/*
 Prints the data stored in all nodes in the specified list to print.
 For each node, prints the data inside the node the same way that it
 is printed by print_node.  If the list is empty, a suitable message
 is printed to standard output.
 PARAM:     node_to_print is a pointer to a (possibly empty) linked list of
            struct node
 PRE:       NULL (no pre-conditions)
 POST:      Information about list_to_print has been printed to standard output
 RETURN:    NULL
 */
void print_list(struct node * list_to_print)
{
    // Insert your code here
    if(!list_to_print){
        printf("Empty list\n");
    }
    else
    {
    struct node *ptr=list_to_print;
    int i=1;
        while(ptr)
        {
            printf("Information in node %d: \n",i);
            print_node(ptr);
            i++;
            ptr=ptr->next;
        }
    }
    return;
}

/*
 Reverses a list.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PRE:       NULL (no pre-conditions)
 POST:      The order of the nodes in the list passed as a parameter has been
            reversed
 RETURN:    a list of struct node that is the reverse of the list passed as a
            parameter
 */
struct node * reverse(struct node * list)
{
    // Insert your code here
    if (!list || !list->next) {
        return list;
    }
    struct node *prev=NULL,*current=list,*next;
    while(current)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    list=prev;
    return list;
}

/*
 Removes every node from the list which contains an airplane destined for
 the city name passed in the second parameter.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PARAM:     destination_city is a pointer to a null-terminated array of char
 PRE:       NULL (no pre-conditions)
 POST:      Any struct node in the list which contains an airplane struct
            destined for the destination_city is removed from the list, and
            the memory deallocated
 RETURN:    a list of struct node that does not contain any struct node that
            has an airplane destined for the destination_city
 */
struct node * remove_from_list(struct node * list, char * destination_city)
{
    // Insert your code here
    if(!list){
        return list;
    }
    struct node *ptr=list,*to_delete,*prev=NULL;
    while(ptr)
    {
        if(strncmp(ptr->plane.city_destination,destination_city,strlen(destination_city))==0)
        {
            if (list == ptr) {
                list = list->next;
            }
            to_delete=ptr;
            ptr=ptr->next;
            free(to_delete);
            to_delete=NULL;
            //prev is not empty, there is something before the deleted node.
            if(prev){
                prev->next=ptr;
            }
        }
        //Track the current node by temp because the current node was not deleted.
        else {
            prev = ptr;
            ptr = ptr->next;
        }
    }
    return list;
}

/*
 Returns a reference to the nth node (but does not remove it ) in the
 specified list.  If the list is too short, returns NULL.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PARAM:     position is an integer
 PRE:       position > 0
 POST:      NULL (no side-effects)
 RETURN:    IF position <= length of list
            THEN a pointer to the nth node
            ELSE NULL
 */
struct node * retrieve_nth(struct node * list, int position)
{
    // Insert your code here
    int length=get_length(list);
    if(length<position)
        return NULL;
    struct node * ptr=list;
    for(int i=1;i<position;i++){
        ptr=ptr->next;
    }
    return ptr;
}

/*
 Inserts the specified node into the specified list of nodes at the specified
 position.  For example, if position = 1, this is a simple prepend_node
 operation.  If position = 3, then when this function is finished, the third
 node in the list will be the node_to_insert.  If the position = the length
 of the list + 1, then the node_to_insert is appended to the end of the list.
 If the position > 1 + length of the list, the function returns a pointer
 to the unchanged list.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PARAM:     position is an integer
 PRE:       position > 0
 PRE:       node_to_insert is NEVER a null (it is always a correct node pointer)
 POST:      NULL (no side-effects)
 RETURN:    IF position <= length of list + 1
            THEN a pointer to the list which contains the node_to_insert in the
            correct location
            ELSE a pointer to the unchanged list
 */
struct node * insert_nth(struct node * list, struct node * node_to_insert, int position)
{
    // Insert your code here
    int length=get_length(list);
    if(position>length+1)
        return list;
    else if(position==1)	//insert at the beginning
    {
        list=prepend_node(list,node_to_insert);
        return list;
    }
    else if(position==length+1)	//insert at the end
    {
        struct node *ptr=list;
        while(ptr->next){
            ptr=ptr->next;
        }
        ptr->next=node_to_insert;
        return list;
    }
    else{
        struct node *ptr=list;
        for(int i=1;i<position-1;i++){
            ptr=ptr->next;
        }
        node_to_insert->next=ptr->next;
        ptr->next=node_to_insert;
        return list;
    }
}
