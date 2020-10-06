#include <bits/stdc++.h> 
using namespace std; 
  

class Node 
{ 
public: 
    int key; 
    Node **forward; 
    Node(int, int); 
}; 
  
Node::Node(int key, int level) 
{ 
    this->key = key; 
    forward = new Node*[level+1]; 
    memset(forward, 0, sizeof(Node*)*(level+1)); 
}; 
  
class SkipList 
{ 
   
    int MAXLVL; 
    float P; 
    int level; 
    Node *head; 
    public: 
        SkipList(int, float); 
        int randomLevel(); 
        Node* createNode(int, int); 
        void insert(int); 
        void deleteNode(int); 
        void search(int); 
        void display(); 
}; 
  
SkipList::SkipList(int MAXLVL, float P) 
{ 
    this->MAXLVL = MAXLVL; 
    this->P = P; 
    level = 0; 
    head = new Node(-1, MAXLVL); 
}; 

int SkipList::randomLevel() 
{ 
    float r = (float)rand()/RAND_MAX; 
    int lvl = 0; 
    while(r < P && lvl < MAXLVL) 
    { 
        lvl++; 
        r = (float)rand()/RAND_MAX; 
    } 
    return lvl; 
}; 
  

Node* SkipList::createNode(int key, int level) 
{ 
    Node *n = new Node(key, level); 
    return n; 
}; 
  

void SkipList::insert(int key) 
{ 
    Node *curr = head; 
    Node *update[MAXLVL+1]; 
    memset(update, 0, sizeof(Node*)*(MAXLVL+1)); 
    for(int i = level; i >= 0; i--) 
    { 
        while(curr->forward[i] != NULL && curr->forward[i]->key < key){
            curr = curr->forward[i]; 
            }
        update[i] = curr; 
    } 
  
    curr = curr->forward[0]; 
  
   if (curr == NULL || curr->key != key) 
    { 
       
        int rlevel = randomLevel(); 
  
        if(rlevel > level) 
        { 
            for(int i=level+1;i<rlevel+1;i++) {
                update[i] = head; 
                }
                level = rlevel; 
                
        } 
  
     Node* n = createNode(key, rlevel); 
     for(int i=0;i<=rlevel;i++) 
        { 
            n->forward[i] = update[i]->forward[i]; 
            update[i]->forward[i] = n; 
        } 
      
    } 
}; 
  

void SkipList::deleteNode(int key) 
{ 
    Node *curr = head; 
    Node *update[MAXLVL+1]; 
    memset(update, 0, sizeof(Node*)*(MAXLVL+1)); 

    for(int i = level; i >= 0; i--) 
    { 
        while(curr->forward[i] != NULL  && curr->forward[i]->key < key) {
            curr = curr->forward[i]; 
            }
        update[i] = curr; 
    } 
    curr= curr->forward[0]; 
    if(curr != NULL and curr->key == key) 
    {
        for(int i=0;i<=level;i++) 
        { 
            if(update[i]->forward[i] != curr)  break; 
            update[i]->forward[i] = curr->forward[i]; 
        }
     while(level>0 && head->forward[level] == 0) 
            level--; 
         
    } 
}; 
  
void SkipList::search(int key) 
{ 
    Node *curr = head; 
    for(int i = level; i >= 0; i--) 
    { 
        while(curr->forward[i] && curr->forward[i]->key < key) 
            curr = curr->forward[i]; 
  
    } 
    curr = curr->forward[0]; 
    if(curr && curr->key == key)  
        cout<<key<<" Found!"<<endl; 
    else{
		cout<<key<<" Not found"<<endl;
	}
}; 
  
void SkipList::display() 
{ 
    cout<<"Elements in the list are:"<<endl; 
    for(int i=0;i<=level;i++) 
    { 
        Node *node = head->forward[i]; 
        cout<<"Level "<<i<<": "; 
        while(node != NULL) 
        { 
            cout<<node->key<<" "; 
            node = node->forward[i]; 
        } 
        cout<<endl; 
    } 
}; 
  
int main() 
{ 
    srand((unsigned)time(0));
    SkipList list(3, 0.5);
    list.insert(3); 
    list.insert(6); 
    list.insert(7); 
    list.insert(9); 
    list.insert(20); 
    list.display(); 
    cout<<"Enter the element to be inserted :"<<endl;
	  int key;
	  cin>>key;
	  list.insert(key);
	  list.display();
	  cout<<"Enter the element to be deleted :"<<endl;
	  cin>>key;
	  list.deleteNode(key);
	  list.display();
	  cout<<"Enter the element to be searched :"<<endl;
	  cin>>key;
	  list.search(key);
	  return 0;
  
}
