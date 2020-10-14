#include <bits/stdc++.h> 
using namespace std; 
    
    
 class Disjoint
{ 
      
    vector<int> parent;
    
    public: 
    int count;
    Disjoint(int n) 
    { 
        parent.resize(n);
        createSet(n); 
        count=0;
    } 
  
    void createSet(int n) 
    { 
        for (int i = 0; i < n; i++) 
            parent[i] = i; 
    } 
    
    int find(int x) 
    { 
        if(parent[x] != x)
		return parent[x] = find(parent[x]);;
		
        return x;
    } 

    void Union(int x, int y) 
    { 
        int xRep = find(x); 
        int yRep = find(y); 
  
        if(xRep != yRep){
		parent[xRep] = yRep;
		count--;
	}
        
    } 
    
    void setCount(int n){
		count = n;
	}

 
}; 


int countIslands(vector<vector<int>>mat) 
{ 
    int m = mat.size(); 
    int n = mat[0].size(); 
    int count=0;
    for(int i=0; i<m; i++){
	for(int j=0; j<n; j++){
		if(mat[i][j])
			count++;
		}
	}
  
    Disjoint *d= new Disjoint(n * m); 
    d->setCount(count);
    
    for (int i = 0; i < m; i++) 
    { 
        for (int j= 0; j < n; j++) 
        { 
          
          if(mat[i][j]){
		  
            if(i>0 && mat[i-1][j]){
                d->Union(n*i+j, n*(i-1)+j);
	        }
	    if(i<m-1 && mat[i+1][j]){
		d->Union(n*i+j, n*(i+1)+j);
		}
	    if(j>0 && mat[i][j-1]){
		d->Union(n*i+j, n*i+j-1);
		}
            if(j<n-1 && mat[i][j+1]){
		d->Union(n*i+j, n*i+j+1);
		}
	     if(i>0 && j>0 && mat[i-1][j-1]){
		d->Union(n*i+j, n*(i-1)+j-1);
		}
	     if(i<m-1 && j<n-1 && mat[i+1][j+1]){
		d->Union(n*i+j, n*(i+1)+j+1);
		}
	     if(i>0 && j<n-1 && mat[i-1][j+1]){
		d->Union(n*i+j, n*(i-1)+j+1);
		}
	     if(i<m-1 && j>0 && mat[i+1][j-1]){
		d->Union(n*i+j, n*(i+1)+j-1);
		}
           } 
        }
    } 
    
    return d->count;
    
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
