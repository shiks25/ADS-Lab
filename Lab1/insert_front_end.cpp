#include <bits/stdc++.h>
using namespace std;

class Node  
{  
    public: 
    int data;  
    Node* next;
};  
Node* XOR (Node *a, Node *b)  
{  
    return (Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));  
}  
void insertfront(Node **head, int data)  
{  
  
    Node *new_node = new Node();  
    new_node->data = data;  
  
    new_node->next = *head;  
  
   if (*head!= NULL)  
    {  
       
        (*head)->next = XOR(new_node, (*head)->next);  
    }  
  
  *head=new_node;

}  


void insertend(Node **head,int data){
    Node *new_node=new Node();
    new_node->data=data;
    if(*head == NULL){
        new_node->next=*head;
        *head=new_node;
    }
    else{
    Node *curr=*head;
    Node *prev=NULL;
    Node *nxt;
    
    while(XOR(prev,curr->next)!=NULL){
        nxt=XOR(prev,curr->next);
        prev=curr;
        curr=nxt;
    }
    
   new_node->next=curr;
   curr->next=XOR(prev,new_node);
   
    }
}
    

void printL(Node *head)  
{  
    Node *curr = head;  
    Node *prev = NULL;  
    Node *next;  
  
    cout << "The nodes in the Linked List are: \n";  
  
    while (curr != NULL)  
    {  
         
        cout<<curr->data<<" ";  
  
        
        next = XOR (prev, curr->next);  
  
        prev = curr;  
        curr = next;  
    }  
}  
int main()
{
    Node *head = NULL; 
    int n;
  cout<<"--Insert in the beginning--"<<endl;
  cout<<"Enter the number of elements:"<<endl;
  cin>>n;
 cout<<"Enter the elements"<<endl;
  while(n){
  int x;
  cin>>x;
  insertfront(&head, x); 
   n--;
  }
    printL(head);
    cout<<endl;
    
    cout<<"--Insert in the end--"<<endl;
  cout<<"Enter the number of elements:"<<endl;
  cin>>n;
 cout<<"Enter the elements"<<endl;
  while(n){
  int x;
  cin>>x;
  insertend(&head, x); 
   n--;
  }
    printL(head);
    return 0;
}
