/*
Given a singly linked list, find middle of the linked list. For example, if given linked list is 1->2->3->4->5 then output should be 3. 
If there are even nodes, then there would be two middle nodes, we need to print second middle element. For example, if given linked list 
is 1->2->3->4->5->6 then output should be 4.
*/
#include<bits/stdc++.h>  
using namespace std;  
  
// Struct  
struct Node  
{  
    int data;  
    struct Node* next;  
};  
  
/* Function to get the middle of the linked list*/
void printMiddle(struct Node *head)  
{  
    struct Node *slow_ptr = head;  
    struct Node *fast_ptr = head;  
  
    if (head!=NULL)  
    {  
        while (fast_ptr != NULL && fast_ptr->next != NULL)  
        {  
            fast_ptr = fast_ptr->next->next;  
            slow_ptr = slow_ptr->next;  
        }  
        printf("The middle element is [%d]\n\n", slow_ptr->data);  
    }  
}  
  
// Function to add a new node  
void push(struct Node** head_ref, int new_data)  
{  
    /* allocate node */
    struct Node* new_node = new Node;  
  
    /* put in the data */
    new_node->data = new_data;  
  
    /* link the old list off the new node */
    new_node->next = (*head_ref);  
  
    /* move the head to point to the new node */
    (*head_ref) = new_node;  
}  
  
// A utility function to print a given linked list  
void printList(struct Node *ptr)  
{  
    while (ptr != NULL)  
    {  
        printf("%d->", ptr->data);  
        ptr = ptr->next;  
    }  
    printf("NULL\n");  
}  
  
// Driver Code 
int main()  
{ 
    
    //cin_tie(false)
    ios_base::sync_with_stdio(false);
    struct Node* head = NULL;  
      
    // Iterate and add element  
    for (int i=5; i>0; i--)  
    {  
        push(&head, i);  
        printList(head);  
        printMiddle(head);  
    }  
  
    return 0;  
}  
