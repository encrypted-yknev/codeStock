// C program to delete nodes which have a greater value on 
// right side
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* structure of a linked list node */
struct Node
{
	int data;
	struct Node *next;
};

/* prototype for utility functions */
void reverseList(struct Node **headref);
void delLesserNodes(struct Node **head_ref);
struct Node * delLesserNodesUtil(struct Node **head_ref,int *max_val);


/* Deletes nodes which have a node with greater value node
on left side */

void delLesserNodes(struct Node **head_ref) {
    int max_val=INT_MIN;
    struct Node *head = *head_ref;
    if(head && head->next)    {
        struct Node *ptr=NULL;
        ptr=delLesserNodesUtil(head_ref,&max_val);
        if(ptr->data < max_val) {
            *head_ref=ptr->next;
            free(ptr);
        }
    }
}
struct Node * delLesserNodesUtil(struct Node **head_ref,int *max_val)
{
    struct Node *cur_ptr = *head_ref;
	if(cur_ptr)   {
	    struct Node *ptr = delLesserNodesUtil(&cur_ptr->next,max_val);
	    if(cur_ptr->data > *max_val)    {
	        *max_val=cur_ptr->data;
	        if(ptr) {
	            cur_ptr->next=ptr->next;
	            free(ptr);
	        }
	    }
	}
	return cur_ptr;
}

/* Deletes nodes which have greater value node(s) on left side */


/* Utility function to insert a node at the begining */
void push(struct Node **head_ref, int new_data)
{
	struct Node *new_node =
			(struct Node *)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = *head_ref;
	*head_ref = new_node;
}

/* Utility function to reverse a linked list */
void reverseList(struct Node **headref)
{
	struct Node *current = *headref;
	struct Node *prev = NULL;
	struct Node *next;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*headref = prev;
}

/* Utility function to print a linked list */
void printList(struct Node *head)
{
	while (head != NULL)
	{
		printf("%d ", head->data);
		head=head->next;
	}
	printf("\n");
}

/* Driver program to test above functions */
int main()
{
	struct Node *head = NULL;

	/* Create following linked list
	12->15->10->11->5->6->2->3 */
	push(&head,3);
	push(&head,2);
	push(&head,6);
	push(&head,5);
	push(&head,11);
	push(&head,10);
	push(&head,15);
	push(&head,12);

	printf("Given Linked List \n");
	printList(head);
    
	delLesserNodes(&head);
    
        
	printf("Modified Linked List \n");
	printList(head);

	return 0;
}
