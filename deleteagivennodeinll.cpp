/*
Given a Singly Linked List, write a function to delete a given node. Your function must follow following constraints:
1) It must accept a pointer to the start node as the first parameter and node to be deleted as the second parameter i.e., a pointer to head node is not global.
2) It should not return a pointer to the head node.
3) It should not accept pointer to pointer to the head node.
You may assume that the Linked List never becomes empty.
*/
#include <bits/stdc++.h> 
using namespace std; 
  
/* structure of a linked list node */
class Node  
{  
    public: 
    int data;  
    Node *next;  
};  
  
void deleteNode(Node *head, Node *n)  
{  
    // When node to be deleted is head node  
    if(head == n)  
    {  
        if(head->next == NULL)  
        {  
            cout << "There is only one node." << 
                    " The list can't be made empty ";  
            return;  
        }  
  
        /* Copy the data of next node to head */
        head->data = head->next->data;  
  
        // store address of next node  
        n = head->next;  
  
        // Remove the link of next node  
        head->next = head->next->next;  
  
        // free memory  
        free(n);  
  
        return;  
    }  
  
  
    // When not first node, follow  
    // the normal deletion process  
  
    // find the previous node  
    Node *prev = head;  
    while(prev->next != NULL && prev->next != n)  
        prev = prev->next;  
  
    // Check if node really exists in Linked List  
    if(prev->next == NULL)  
    {  
        cout << "\nGiven node is not present in Linked List";  
        return;  
    }  
  
    // Remove node from Linked List  
    prev->next = prev->next->next;  
  
    // Free memory  
    free(n);  
  
    return;  
}  
  
/* Utility function to insert a node at the beginning */
void push(Node **head_ref, int new_data)  
{  
    Node *new_node = new Node(); 
    new_node->data = new_data;  
    new_node->next = *head_ref;  
    *head_ref = new_node;  
}  
  
/* Utility function to print a linked list */
void printList(Node *head)  
{  
    while(head!=NULL)  
    {  
        cout<<head->data<<" ";  
        head=head->next;  
    }  
    cout<<endl; 
}  
  
/* Driver code */
int main()  
{  
    Node *head = NULL;  
  
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
  
    cout<<"Given Linked List: ";  
    printList(head);  
  
    /* Let us delete the node with value 10 */
    cout<<"\nDeleting node "<< head->next->next->data<<" ";  
    deleteNode(head, head->next->next);  
  
    cout<<"\nModified Linked List: ";  
    printList(head);  
  
    /* Let us delete the first node */
    cout<<"\nDeleting first node ";  
    deleteNode(head, head);  
  
    cout<<"\nModified Linked List: ";  
    printList(head);  
    return 0;  
}  
