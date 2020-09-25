#include <stdio.h>
#include <stdlib.h>

//Define Linked list
struct LinkedList { 
    int data; 
    struct LinkedList* next; 
};

//This function adds a node to the start of the list
//This is a 4 step process
void add_node_at_first(struct LinkedList** Head_ref, int newdata )
{
    //Step 1: Allocate a node
    struct LinkedList* new_list_node = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    //Step 2: Put new data
    new_list_node -> data = newdata;
    //Step 3: Next of new_list is head
    new_list_node->next = (*Head_ref);
    //Step 4: Head points to new node
    (*Head_ref) = new_list_node;
}

//This function adds a node at the end of the list
//This is a 6 step process
void add_node_at_last(struct LinkedList** Head_ref, int newdata )
{
    //Step 1: Allocate a node
    struct LinkedList* new_list_node = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    struct LinkedList *last = *Head_ref;
    //Step 2: Put new data
    new_list_node->data = newdata;
    //Step 3: Make next of last node as NULL
    new_list_node->next = NULL;
    //Step 4: If the linked list is empty, make the new node
    if(*Head_ref == NULL)
    {
        *Head_ref = new_list_node;
        return;
    }
    //Step 5: Go through last node
    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = new_list_node;  
}

//This function adds a node in the middle of list
//This is a 5 step process

void add_node_in_middle(struct LinkedList* mid_ref, int newdata )
{
    //Step 1: Check if the given node is NULL
    if(mid_ref == NULL)
    {
        printf("The previous node");
    }
    //Step 2: Allocate new node
    struct LinkedList* new_list_node = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    //Step 3: Put data in node
    new_list_node ->data = newdata;
    //Step 4: Next of new node is next of mid_ref
    new_list_node ->next = mid_ref -> next;
    //Step 5: Move the mid_ref as new_list_node
    mid_ref->next = new_list_node;
}

int main() 
{

//Start with an empty list
struct LinkedList* head = NULL;

add_node_at_first(&head, 6);
add_node_at_last(&head,4);
add_node_in_middle(&head,10);

    return 0;
}
