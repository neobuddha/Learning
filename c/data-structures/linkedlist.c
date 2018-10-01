#include <stdio.h>
#include <stdlib.h>

typedef struct MyLinkedList{
    int data;
    struct MyLinkedList *next;
} MyLinkedList;

/** Initialize your data structure here. */
MyLinkedList* myLinkedListCreate() {

    MyLinkedList* head = NULL;
    
    #if 0
    MyLinkedList* head = (MyLinkedList *) malloc(sizeof(MyLinkedList));
    
    if(!head) {
        /* Memory allocation failed */
        printf("\n Error: Unable to allocate memory. Returning ...");
    } 
    else {
        head->data = 0;
        head->next = NULL;
    }
    #endif
    
    return head;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    int i = 0;
    
    if(obj) 
    {    
        while(obj)
        { 
            if(i < index)
                obj = obj->next;
            else
                return (obj->data); 
        }
    }
    
    return -1;     
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList* node = NULL;

    if(val < 1 || val > 1000)
    {
        printf("\nError: Invalid Value range. Please use value between 1 to 1000. Current value: %d \n", val);
        return;
    }
    
    node = (MyLinkedList *) malloc(sizeof(MyLinkedList));
    
    if(!node) {
        /* Memory allocation failed */
        printf("\n Error: Unable to allocate memory. Returning ...");
    } 
    else {
        node->data = val;
        node->next = NULL;
        
        if(obj)
            node->next = obj;            
    }
    
    obj = node;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList* node = NULL;

    if(val < 1 || val > 1000)
    {
        printf("\nError: Invalid Value range. Please use value between 1 to 1000. Current value: %d \n", val);
        return;
    }    
    
    node = (MyLinkedList *) malloc(sizeof(MyLinkedList));
    
    if(!node) {
        /* Memory allocation failed */
        printf("\n Error: Unable to allocate memory. Returning ...");
        return;
    } 
    else {
        node->data = val;
        node->next = NULL;
    }
    
    if(obj)
    {
        while (obj->next != NULL)
            obj = obj->next;
    
        obj->next = node;
    }
    else
        obj = node;
    
    return;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    
    int position = 0;
    
    MyLinkedList* node = NULL;
    MyLinkedList* tmp = obj;
    

    if(val < 1 || val > 1000)
    {
        printf("\nError: Invalid Value range. Please use value between 1 to 1000. Current value: %d \n", val);
        return;
    }
    
    node = (MyLinkedList *) malloc(sizeof(MyLinkedList));  
    
    if(!node) {
        /* Memory allocation failed */
        printf("\n Error: Unable to allocate memory. Returning ...");
        return;
    } 
    else {
        node->data = val;
        node->next = NULL;
    }
    
    for (position = 0; position < index - 1; position++) 
    {
        if(tmp->next)
        {
            tmp = tmp->next;
        }
        else
        {
            printf("\n Lesser elements in list that required position. returning ...\n");
            return;
        }
    }

    node->next = tmp->next;
    tmp->next = node;
    
    return;
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {

    MyLinkedList *endPtr;
    
    if(!obj)
    {
        printf("\n Empty list. Returning... \n");
        return;
    }
    
    for (int i = 0; i < index -1; i++)
    {
        if (obj->next)
        {
            obj = obj->next;
        }
        else 
        {
             printf("\n Not enough elements in list. Returning... \n");
            return;       
        }
    }
    
    endPtr = obj->next;
    
    if (endPtr) 
    {
        obj->next = endPtr->next;
        endPtr->next = NULL;
        free(endPtr);
    }
    
    return;
}


void myLinkedListFree(MyLinkedList* obj) {
    MyLinkedList* tmp = obj;
    
    while(obj->next)
    {
        tmp = obj;
        obj = obj->next;
        free(tmp);
    }
    
    return;
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * struct MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 * myLinkedListAddAtHead(obj, val);
 * myLinkedListAddAtTail(obj, val);
 * myLinkedListAddAtIndex(obj, index, val);
 * myLinkedListDeleteAtIndex(obj, index);
 * myLinkedListFree(obj);
 */

int main()
{
	struct MyLinkedList* obj = myLinkedListCreate();
	myLinkedListAddAtHead(obj, 1);
	myLinkedListAddAtTail(obj, 3);
	myLinkedListAddAtIndex(obj, 1, 2);
	myLinkedListDeleteAtIndex(obj, 1);
	myLinkedListFree(obj);
	return 0;
}
