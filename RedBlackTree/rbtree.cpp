/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h> 
using namespace std; 
  
enum Color {R, B}; 
  
struct Node 
{ 
	int data; 
    	bool color; 
    	Node *left, *right, *parent; 
    	Node(int data) 
    	{ 
       		this->data = data; 
       		left = right = parent = NULL; 
       		this->color = R; 
    	} 
}; 

class RBTree 
{ 
	Node *root; 
	public:
    		void rotateLeft(Node *&, Node *&); 
    		void rotateRight(Node *&, Node *&); 
    		void fixViolation(Node *&, Node *&); 
    	RBTree() { root = NULL; } 
    	void insert(int &n); 
    	void printTree();
}; 

void display(Node* root, string indent, bool last) {
    if (root != NULL) {
      cout << indent;
      if (last) {
        cout << "R----";
        indent += "   ";
      } else {
        cout << "L----";
        indent += "|  ";
      }

      string sColor = root->color ? "Black" : "Red";
      cout << root->data << "(" << sColor << ")" << endl;
      display(root->left, indent, false);
      display(root->right, indent, true);
    }
  }
Node* BSTInsert(Node* root, Node *pt) 
{ 
    	if (root == NULL) 
       		return pt; 

    	if (pt->data < root->data) 
    	{ 
        	root->left  = BSTInsert(root->left, pt); 
        	root->left->parent = root; 
    	} 
    	else if (pt->data > root->data) 
    	{ 
        	root->right = BSTInsert(root->right, pt); 
        	root->right->parent = root; 
    	} 	
    	return root; 
} 

void RBTree::rotateLeft(Node *&root, Node *&pt) 
{ 
    	Node *pt_right = pt->right; 
  
    	pt->right = pt_right->left; 
  
    	if (pt->right != NULL) 
        	pt->right->parent = pt; 
  
    	pt_right->parent = pt->parent; 
  
    	if (pt->parent == NULL) 
        	root = pt_right; 
  
    	else if (pt == pt->parent->left) 
        	pt->parent->left = pt_right; 
  
    	else
        	pt->parent->right = pt_right; 
  
    	pt_right->left = pt; 
    	pt->parent = pt_right; 
} 
  
void RBTree::rotateRight(Node *&root, Node *&pt) 
{ 
    	Node *pt_left = pt->left; 
  
    	pt->left = pt_left->right; 
  
    	if (pt->left != NULL) 
        	pt->left->parent = pt; 
  
    	pt_left->parent = pt->parent; 
  
    	if (pt->parent == NULL) 
        	root = pt_left; 
  
    	else if (pt == pt->parent->left) 
        	pt->parent->left = pt_left; 
  
    	else
        	pt->parent->right = pt_left; 
  
    	pt_left->right = pt; 
    	pt->parent = pt_left; 
} 
  

void RBTree::fixViolation(Node *&root, Node *&pt) 
{ 
    	Node *parent_pt = NULL; 
    	Node *grand_parent_pt = NULL; 
  
    	while ((pt != root) && (pt->color != B) && (pt->parent->color == R)) 
    	{ 
  
        	parent_pt = pt->parent; 
        	grand_parent_pt = pt->parent->parent; 
  
        	if (parent_pt == grand_parent_pt->left) 
        	{ 
  
            		Node *uncle_pt = grand_parent_pt->right; 

            		if (uncle_pt != NULL && uncle_pt->color == R) 
            		{ 
                		grand_parent_pt->color = R; 
                		parent_pt->color = B; 
                		uncle_pt->color = B; 
                		pt = grand_parent_pt; 
            		} 
  
            		else
            		{ 
                		if (pt == parent_pt->right) 
                		{ 
                    			rotateLeft(root, parent_pt); 
                    			pt = parent_pt; 
                    			parent_pt = pt->parent; 
                		} 
  
                		rotateRight(root, grand_parent_pt); 
                		swap(parent_pt->color,grand_parent_pt->color); 
                		pt = parent_pt; 
            		} 
        	} 

        	else
        	{ 
            		Node *uncle_pt = grand_parent_pt->left; 
  
            		if ((uncle_pt != NULL) && (uncle_pt->color == R)) 
            		{ 
                		grand_parent_pt->color = R; 
                		parent_pt->color = B; 
                		uncle_pt->color = B; 
                		pt = grand_parent_pt; 
            		} 		
            		else
            		{ 
                		if (pt == parent_pt->left) 
                		{ 
                    			rotateRight(root, parent_pt); 
                    			pt = parent_pt; 
                    			parent_pt = pt->parent; 
                		} 
                		rotateLeft(root, grand_parent_pt); 
                		swap(parent_pt->color, grand_parent_pt->color); 
                		pt = parent_pt; 
            		} 
        	} 
    	} 
  
    	root->color = B; 
} 
  
void RBTree::insert(int &data) 
{ 
    	Node *pt = new Node(data);  
    	root = BSTInsert(root, pt); 
    	fixViolation(root, pt); 
} 
  

void RBTree::printTree() {
    
      display(root, "", true);
}
  
int main() 
{ 
	RBTree tree; 
	int n, key;
	cout<<"Enter the no. of elements:"<<endl;
	cin>>n;
	cout<<"Enter the elements:"<<endl;
	for(int i=0; i<n; i++)
	{
		cin>>key;
		tree.insert(key);
	}
	cout << "Levelorder Tree Traversal:"<<endl; 
	 tree.printTree();
     return 0; 
}
	
