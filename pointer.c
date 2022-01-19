// DO NOT INCLUDE ANY OTHER LIBRARIES/FILES
#include "pointer.h"

// In this assignment, you can assume that function parameters are valid and the memory is managed by the caller

// Compares the price of obj1 with obj2
// Returns a negative number if the price of obj1 is less than the price of obj2
// Returns a positive number if the price of obj1 is greater than the price of obj2
// Returns 0 if the price of obj1 is equal to the price of obj2
int compare_by_price(Object* obj1, Object* obj2)
{
    // IMPLEMENT THIS
    if(object_price(obj1) < object_price(obj2)){
        return(-1);
    }else if(object_price(obj1) > object_price(obj2)){
        return(1);
    }else{
        return(0);
    }
}

// Compares the quantity of obj1 with obj2
// Returns a negative number if the quantity of obj1 is less than the quantity of obj2
// Returns a positive number if the quantity of obj1 is greater than the quantity of obj2
// Returns 0 if the quantity of obj1 is equal to the quantity of obj2
int compare_by_quantity(Object* obj1, Object* obj2)
{
    // IMPLEMENT THIS
    if(object_quantity(obj1) < object_quantity(obj2)){
        return(-1);
    }else if(object_quantity(obj1) > object_quantity(obj2)){
        return(1);
    }else{
        return(0);
    }
}

// Initializes a StaticPriceObject with the given quantity, name, and price
// Memory for the name string is managed by the caller and assumed to be valid for the duration of the object's lifespan
void static_price_object_construct(StaticPriceObject* obj, unsigned int quantity, const char* name, double price)
{
    // IMPLEMENT THIS
    //Used pointer.h to initialize staticPriceObjects
    object_quantity(obj) = quantity;
    object_name(obj) = name;
    object_price(obj) = price;
}

// Initializes a DynamicPriceObject with the given quantity, name, base price, and price scaling factor
// Memory for the name string is managed by the caller and assumed to be valid for the duration of the object's lifespan
void dynamic_price_object_construct(DynamicPriceObject* obj, unsigned int quantity, const char* name, double base, double factor)
{
    // IMPLEMENT THIS
    object_quantity(obj) = quantity;
    object_name(obj) = name;
    obj->base = base;
    obj->factor = factor;
}

// Returns the price of a StaticPriceObject or ERR_OUT_OF_STOCK if it is out of stock
double static_price(StaticPriceObject* obj)
{
    // IMPLEMENT THIS
    if(object_price(obj) != NULL){
        return(object_price(obj));
    }else{
        return("ERR_OUT_OF_STOCK");
    }
}

// Returns the price of a DynamicPriceObject or ERR_OUT_OF_STOCK if it is out of stock
// The dynamic price is calculated as the base price multiplied by (the quantity raised to the power of the scaling factor)
double dynamic_price(DynamicPriceObject* obj)
{
    // IMPLEMENT THIS
    if(object_price(obj) != NULL){
        return(object_price(obj));
    }else{
        return("ERR_OUT_OF_STOCK");
    }
}

// Returns the bulk price of purchasing multiple (indicated by quantity parameter) StaticPriceObject at a discount where the first item is regular price and the additional items are scaled by the BULK_DISCOUNT factor
// Return ERR_OUT_OF_STOCK if there is insufficient quantity available
double static_bulk_price(StaticPriceObject* obj, unsigned int quantity)
{
    // IMPLEMENT THIS
    return 0;
}

// Returns the bulk price of purchasing multiple (indicated by quantity parameter) DynamicPriceObject at a discount where the first item is regular price and the additional items are scaled by the BULK_DISCOUNT factor
// This uses the same dynamic price equation from the dynamic_price function, and note that the price changes for each item that is bought
// For example, if 3 items are requested, each of them will have a different price, and this function calculates the total price of all 3 items
// Return ERR_OUT_OF_STOCK if there is insufficient quantity available
double dynamic_bulk_price(DynamicPriceObject* obj, unsigned int quantity)
{
    // IMPLEMENT THIS
    return 0;
}

//
// Iterator functions
//

// Initializes an iterator to the beginning of a list
void iterator_begin(LinkedListIterator* iter, LinkedListNode** head)
{
    // IMPLEMENT THIS
    struct LinkedListIterator* currentNode = iter->curr;
    currentNode = *head;
}

// Updates an iterator to move to the next element in the list if possible
void iterator_next(LinkedListIterator* iter)
{
    // IMPLEMENT THIS
    while(iter->curr != NULL){
        iter->curr = iter->next;
    }
}

// Returns true if iterator is at the end of the list or false otherwise
// The end of the list is the position after the last node in the list
bool iterator_at_end(LinkedListIterator* iter)
{
    // IMPLEMENT THIS
    if(iter->next == NULL){
        return(true);
    }else{
        return(false);
    }
}

// Returns the current object that the iterator references or NULL if the iterator is at the end of the list
Object* iterator_get_object(LinkedListIterator* iter)
{
    // IMPLEMENT THIS
    if(iter->next != NULL){
        return(iter->curr);
    }else{
        return(NULL);
    }
}

// Removes the current node referenced by the iterator
// The iterator is valid after call and references the next object
// Returns removed node
LinkedListNode* iterator_remove(LinkedListIterator* iter)
{
    // IMPLEMENT THIS
    //Define current node, plus a temp node

    struct LinkedListIterator* currentNode = iter->curr;
    struct LinkedListIterator* tempNode = NULL;

    //check if current node is empty, if not, get value of current 
    if(currentNode != NULL){
        tempNode = currentNode;
        free(currentNode);
        currentNode = iter->prev_next;
        return(temp);
    }else{
        return NULL;
    }
}

// Inserts node after the current node referenced by the iterator
// The iterator is valid after call and references the same object as before
// Returns ERR_INSERT_AFTER_END error if iterator at the end of the list or 0 otherwise
int iterator_insert_after(LinkedListIterator* iter, LinkedListNode* node)
{
    // IMPLEMENT THIS
    //Define current node
    struct LinkedListIterator* currentNode = iter->curr;
    struct LinkedListNode* newNode = node;
    //check if current node is at the end, else insert new Node
    if(currentNode->next == NULL){
        return("ERR_INSERT_AFTER_END");
    }else{
        newNode->next = currentNode->next;
        currentNode->next = newNode;
        return(0)
    }
}

// Inserts node before the current node referenced by the iterator
// The iterator is valid after call and references the same object as before
void iterator_insert_before(LinkedListIterator* iter, LinkedListNode* node)
{
    // IMPLEMENT THIS
    //Define current node
    struct LinkedListIterator* currentNode = iter->curr;
    struct LinkedListNode* newNode = node;

    while(currentNode->next != NULL){
        currentNode = currentNode->next;
    }
    newNode = node;
    newNode->next = currentNode->next;
    currentNode->next = newNode;
}
//
// List functions
//

// Returns the maximum, minimum, and average price of the linked list
void max_min_avg_price(LinkedListNode** head, double* max, double* min, double* avg)
{
    // IMPLEMENT THIS
}

// Executes the func function for each node in the list
// The function takes in an input data and returns an output data, which is used as input to the next call to the function
// The initial input data is provided as a parameter to foreach, and foreach returns the final output data
// For example, if there are three nodes, foreach should behave like: return func(node3, func(node2, func(node1, data)))
Data foreach(LinkedListNode** head, foreach_fn func, Data data)
{
    // IMPLEMENT THIS
    return data;
}

// Returns the length of the list
int length(LinkedListNode** head)
{
    // IMPLEMENT THIS
    int count = 0;
    struct LinkedListNode* currentNode = head;
    while(currentNode != NULL){
        currentNode = currentNode->next;
        count += 1;
    }
    return (count);
}

//
// Mergesort
//

// Assuming list1 and list2 are sorted lists, merge list2 into list1 while keeping it sorted
// That is, when the function returns, list1 will have all the nodes in sorted order and list2 will be empty
// The sort order is determined by the compare function
// Default convention for compare functions on objects A and B:
//   Negative return values indicate A should be earlier than B in the list
//   Positive return values indicate A should be later than B in the list
//   Zero return values indicate A and B are equal
// A stable sort is not required for this implementation, so equal objects can be in either order
void merge(LinkedListNode** list1_head, LinkedListNode** list2_head, compare_fn compare)
{
    // IMPLEMENT THIS
}

// Split the list head in half and place half in the split list
// For example, if head has 8 nodes, then split will move 4 of them to split_head
void split(LinkedListNode** head, LinkedListNode** split_head)
{
    // IMPLEMENT THIS
    struct LinkedListNode* fstHalf = head;
    struct LinkedListNode* secHalf = split_head;

    int length = length(head);
}

// Implement the mergesort algorithm to sort the list
// The sort order is determined by the compare function
// Default convention for compare functions on objects A and B:
//   Negative return values indicate A should be earlier than B in the list
//   Positive return values indicate A should be later than B in the list
//   Zero return values indicate A and B are equal
// A stable sort is not required for this implementation, so equal objects can be in either order
void mergesort(LinkedListNode** head, compare_fn compare)
{
    // IMPLEMENT THIS
    
}
