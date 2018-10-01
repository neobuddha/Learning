#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
typedef struct ListNode 
{
      int val;
      struct ListNode *next;
} ListNode;


int getIntegerValue(struct ListNode *head)
{
    int retValue = 0;
    int multiFactor = 1;
    while(head)
    {
        retValue = (head->val * multiFactor) + retValue;
        multiFactor *= 10;
        
        head=head->next;
    }    
    
    return retValue;
}

struct ListNode* createNode(int value)
{
    struct ListNode* node = (struct ListNode*) malloc(sizeof(struct ListNode));
    
    if(node)
    {
        node->val = value;
        node->next = NULL;
    }
    
    return node;
}

struct ListNode* insertNode(struct ListNode** head, int value)
{
    struct ListNode* node = NULL;
    
    if (*head == NULL)
    {
        *head = createNode(value);
        return *head;
    }
        
    node = createNode(value);
    
    if(node)
    {
        node->next = *head;
        *head = node;
    }
    
    return *head;
}

struct ListNode*  convertToReverseLinkList(struct ListNode** head, int value)
{    
    int insertValue = value % 10;
    value = value / 10;

    if (value)
    {
        convertToReverseLinkList(head, value);
    }
    
    *head = insertNode(head, insertValue);
    
    return *head;
    
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry = 0;
    int valueForInsertion = 0;
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;

    int val1 = 0;
    int val2 = 0;
    int sum = 0;
        
    while ((l1 != NULL) || (l2 != NULL))
    {
        if(l1) {
            val1 = l1->val;
            l1 = l1->next;
        }
        else
        {
            val1 = 0;
        }
        
        if(l2) {
            val2 = l2->val;
            l2 = l2->next;
        }
        else
        {
            val2 = 0;
        }
        
        sum = carry + val1 + val2;
        
        carry = sum / 10;

        insertNodeAtPosition(&head, &tail, sum % 10, 0);
    }
    
    if (carry)
        insertNodeAtPosition(&head, &tail, carry, 0);
        
    return head;
    
}

struct ListNode* reverseList (struct ListNode** head)
{
    struct ListNode* tmpNode = NULL;
    struct ListNode* prevNode = NULL;
    struct ListNode* curPtr = *head;

    while (curPtr)
    {
        tmpNode = curPtr;
        curPtr = curPtr->next;
        tmpNode->next = prevNode;
        prevNode = tmpNode;
        
    }
    
    *head = prevNode;
    
    return (*head);
}

/* Insert Node at the begining */
struct ListNode* insertNodeAtHead(struct ListNode** head, int value)
{
    struct ListNode* node = NULL;
    
    if (*head == NULL)
    {
        *head = createNode(value);
        return *head;
    }
        
    node = createNode(value);
    
    if(node)
    {
        node->next = *head;
        *head = node;
    }
    
    return *head;
}

/* Insert Node at either head or tail */
void insertNodeAtPosition(struct ListNode **head, struct ListNode **tail, int value, int position)
{
    struct ListNode* node = NULL;
    
    if (*head == NULL)
    {
        *head = createNode(value);
        *tail = *head;
    }
    else
    {
        node = createNode(value);
    
        if(node)
        {
            /* if position is head,*/
            if(position) 
            {
                node->next = *head;
                *head = node;
            }
            else
            {
                (*tail)->next = node;
                *tail = node;
            }
        }
    }
}

struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    
    struct ListNode* tmpNode = NULL;
    struct ListNode* prevNode = NULL;
    struct ListNode* endFirstSegNode = NULL;
    struct ListNode* endMidSegNode = NULL;
    struct ListNode* curPtr = head;

    while (--m)
    {
        endFirstSegNode = curPtr;
        curPtr = curPtr->next;   
        endMidSegNode = curPtr;
    }
    
    endMidSegNode = curPtr;
    int loopLength = (n-m -1);
    
    while (loopLength-- && curPtr)
    {
        tmpNode = curPtr;
        
        curPtr = curPtr->next;
        tmpNode->next = prevNode;
        prevNode = tmpNode;
    }
    
    if(endFirstSegNode)
        endFirstSegNode->next = prevNode;
    else
        head = prevNode;
    
    if(endMidSegNode)
        endMidSegNode->next = curPtr;
        
    return (head);
    
}

int main()
{

    return 0;
}