#include <bits/stdc++.h> 
using namespace std; 
  

struct Node { 
    int data; 
    struct Node* next; 
}; 
  
struct Node* Reverse(struct Node* head, int k) 
{ 
    
    stack<Node*> mystack; 
    struct Node* current = head; 
    struct Node* prev = NULL; 
  
    while (current != NULL) { 
  
        
        int count = 0; 
        while (current != NULL && count < k) { 
            mystack.push(current); 
            current = current->next; 
            count++; 
        } 
  
        
        while (mystack.size() > 0) { 
  
            
            if (prev == NULL) { 
                prev = mystack.top(); 
                head = prev; 
                mystack.pop(); 
            } else { 
                prev->next = mystack.top(); 
                prev = prev->next; 
                mystack.pop(); 
            } 
        } 
    } 
  
 
    prev->next = NULL; 
  
    return head; 
} 
  

void push(struct Node** head_ref, int new_data) 
{ 
  
    struct Node* new_node =  
          (struct Node*)malloc(sizeof(struct Node)); 
  
   
    new_node->data = new_data; 
  
  
    new_node->next = (*head_ref); 
  
   
    (*head_ref) = new_node; 
} 
  

void printList(struct Node* node) 
{ 
    while (node != NULL) { 
        cout<< node->data<<" "; 
        node = node->next; 
    } 
} 
  

int main() 
{ 
    
   struct Node* head = NULL; 
  int n;
  cout<<"Enter the no. of nodes:";
  cin>>n;
  while(n){
  int x;
  cin>>x;
  push(&head,x);
  n--;
  }
   int k;
   cout<<"Enter the interval where the linked list should be reversed:";
   cin>>k;
  
   head = Reverse(head, 3); 
    cout<<"Reversed Linked list:"<<endl; 
    printList(head); 
  
    return 0; 
} 
