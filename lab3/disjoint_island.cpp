#include <bits/stdc++.h> 
using namespace std; 
    
    
 class Disjoint
{ 
      
    vector<int> parent;
    int n; 
      
    public: 
    Disjoint(int n) 
    { 
        parent.resize(n); 
        this->n = n; 
        makeSet(); 
    } 
  
    void createSet() 
    { 
        for (int i = 0; i < n; i++) 
            parent[i] = i; 
    } 
    
    int find(int x) 
    { 
        if (parent[x] != x) 
        { 
            return find(parent[x]); 
        } 
  
        return x; 
    } 

    void Union(int x, int y) 
    { 
        int xRep = find(x); 
        int yRep = find(y); 
  
        if (xRep == yRep) 
            return; 
           
        parent[xRoot] = yRoot; 
  
    } 
}; 

int countIslands(vector<vector<int>>m) 
{ 
    int a = m.size(); 
    int b = m[0].size(); 
    
    int *c = new int[a * b]; 
    int num = 0;
    
    Disjoint *d = new Disjoint(a * b); 
 
    for (int j = 0; j < a;j++) 
    { 
        for (int k = 0; k < b; k++) 
        { 
            
            if (m[j][k]) {
            
            int x = d->find(j * b + k); 
  
            if (c[x] == 0) 
            { 
              num++; 
              c[x]++;
            } 
            else
              {
               c[x]++; 
              }
          
            if (j + 1 < a && m[j + 1][k] == 1) 
                d->Union(j * (b) + k, (j + 1) * (b) + k); 
            if (j - 1 >= 0 && m[j - 1][k] == 1) 
                d->Union(j * (b) + k,(j - 1) * (b) + k); 
            if (k + 1 < b && m[j][k + 1] == 1) 
                d->Union(j * (b) + k,(j) * (b) + k + 1); 
            if (k - 1 >= 0 && m[j][k - 1] == 1) 
                d->Union(j * (b) + k,(j) * (b) + k - 1); 
            if (j + 1 < a && k + 1 < b && m[j + 1][k + 1] == 1) 
                d->Union(j * (b) + k,(j + 1) * (b) + k + 1); 
            if (j + 1 < a && k - 1 >= 0 && m[j + 1][k - 1] == 1) 
                d->Union(j * b + k, (j + 1) * (b) + k - 1); 
            if (j - 1 >= 0 && k + 1 < b && m[j - 1][k + 1] == 1) 
                d->Union(j * b + k,(j - 1) * b + k + 1); 
            if (j - 1 >= 0 && k - 1 >= 0 && m[j - 1][k - 1] == 1) 
                d->Union(j * b + k,(j - 1) * b + k - 1); 
           }
        } 
   } 
    return num; 
} 

int main() 
{ 
 vector<vector<int>>m;
	int x,y,val;
	cout<<"Enter the no. of rows: ";
	cin>>x;
	cout<<"Enter the no. of columns: ";
	cin>>y;
	cout<<"Enter the boolean matrix: "<<endl;
	for(int i=0;i<x; i++){
		vector<int> row;
		for(int j=0; j<y; j++){
			cin>>val;
			row.push_back(val);
		}
		m.push_back(row);
	}

	cout<<"Number of Islands: "<< countIslands(m)<<endl;
	return 0;

}
