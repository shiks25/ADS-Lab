#include<bits/stdc++.h> 
using namespace std; 

class BTreeNode 
{ 
    int *key; 
    int d;     
    BTreeNode **child; 
    int n; 
    bool leaf; 
public: 
    BTreeNode(int _d, bool _leaf); 
  
    void insertNonFull(int k); 
 
    void splitChild(int i, BTreeNode *y); 

    void traverse(); 
    friend class BTree; 
}; 
  
class BTree 
{ 
    BTreeNode *root; 
    int d;
public: 
    BTree(int _d) 
    {  root = NULL;  
    	d = _d; 
    } 

    void traverse() 
    {  if (root != NULL) 
    	root->traverse(); } 
  
    void insert(int k); 
}; 

BTreeNode::BTreeNode(int dx, bool leafx) 
{
    d = dx; 
    leaf = leafx; 

    key = new int[2*d-1]; 
    child = new BTreeNode *[2*d]; 
    n = 0; 
} 
  
void BTreeNode::traverse() 
{ 
	int i;
	for(i=0; i<n; i++)
	{
		if(leaf == false)
			child[i]->traverse();
		cout<<key[i]<<" ";
	}
	if(leaf == false)
		child[i]->traverse();
} 
  
void BTree::insert(int k) 
{ 
 
    if (root == NULL) 
    { 
 
        root = new BTreeNode(d, true); 
        root->key[0] = k; 
        root->n = 1; 
    } 
    else 
    { 
 
        if (root->n == 2*d-1) 
        { 
            BTreeNode *s = new BTreeNode(d, false); 

            s->child[0] = root; 
            s->splitChild(0, root); 
            int i = 0; 
            if (s->key[0] < k) 
                i++; 
            s->child[i]->insertNonFull(k); 
            root = s; 
        } 
        else  
            root->insertNonFull(k); 
    } 
} 

void BTreeNode::insertNonFull(int k) 
{ 
    int i = n-1; 

    if (leaf == true) 
    { 
        while (i >= 0 && key[i] > k) 
        { 
            key[i+1] = key[i]; 
            i--; 
        } 
        key[i+1] = k; 
        n++; 
    } 
    else 
    {
        while (i >= 0 && key[i] > k) 
            i--; 

        if (child[i+1]->n == 2*d-1) 
        { 
            splitChild(i+1, child[i+1]); 

            if (key[i+1] < k) 
                i++; 
        } 
        child[i+1]->insertNonFull(k); 
    } 
} 

void BTreeNode::splitChild(int i, BTreeNode *y) 
{ 

    BTreeNode *z = new BTreeNode(y->d, y->leaf); 
    z->n = d - 1; 
    for (int j = 0; j < d-1; j++) 
        z->key[j] = y->key[j+d]; 
        
    if (y->leaf == false) 
    { 
        for (int j = 0; j < d; j++) 
            z->child[j] = y->child[j+d]; 
    } 
 
    y->n = d - 1; 

    for (int j = n; j >= i+1; j--) 
        child[j+1] = child[j]; 
        
    child[i+1] = z; 

    for (int j = n-1; j >= i; j--) 
        key[j+1] = key[j]; 
 
    key[i] = y->key[d-1]; 
    n++; 
} 

int main() 
{ 
   int m,n,ch=0;
   int x;
   cout<<"Enter the order: ";
   cin>>m;
    BTree t(m); 
    cout<<"Enter the number of elements: ";
    cin>>n;
    cout<<"Enter the elements:"<<endl;
    for(int i=0;i<n;i++){
      cin>>x;
      t.insert(x);
    }
    cout << "Traversal of the constucted tree is "<<endl; 
    t.traverse(); 
    
    while(ch!=-1){
    cout<<"\nEnter 1 to insert,-1 to exit: ";
    cin>>ch;
    if(ch==1){
    cout<<"Enter the element to be inserted: ";
    cin>>x;
    t.insert(x);
    cout << "Traversal of the tree after insertion is "<<endl; 
    t.traverse(); 
    }
   }
    return 0; 
} 
