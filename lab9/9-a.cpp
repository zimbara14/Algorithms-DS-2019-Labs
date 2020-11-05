#include<bits/stdc++.h>
 
using namespace std;
 
ifstream fin("topsort.in");
ofstream fout("topsort.out");

void addEdge(vector <int> edges[], int a, int b){
    edges[a].push_back(b);
}

bool isCyclicUtil(vector<int> adj[], int v, bool visited[], bool *recStack) {
    if(visited[v] == false) { 
    
        visited[v] = true; 
        recStack[v] = true; 
  
        list<int>::iterator i; 
        for(auto i = adj[v].begin(); i != adj[v].end(); ++i) 
        { 
            if ( !visited[*i] && isCyclicUtil(adj, *i, visited, recStack) ) 
                return true; 
            else if (recStack[*i]) 
                return true; 
        } 
  
    } 
    recStack[v] = false;
    return false; 
} 

bool isCyclic(vector<int> adj[], int num) { 

    bool *visited = new bool[num]; 
    bool *recStack = new bool[num]; 
    for(int i = 1; i < num; i++) 
    { 
        visited[i] = false; 
        recStack[i] = false; 
    } 
  
    for(int i = 1; i < num; i++) 
        if (isCyclicUtil(adj, i, visited, recStack)) 
            return true; 
  
    return false; 
} 

void topologicalsortutil(vector<int> edges[], int v, bool visited[], stack<int> &Stack){
	
	visited[v] = true;
	list<int>::iterator i;
	for( auto i = edges[v].begin(); i != edges[v].end(); i++){
		if(!visited[*i])
			topologicalsortutil(edges, *i, visited, Stack);
	}
	Stack.push(v);
	
}

void topsort(vector<int> edges[], int num){
	stack<int>Stack;
	bool *visited = new bool[num]; 
    for (int i = 1; i < num; i++) 
        visited[i] = false; 
  
    for (int i = 1; i < num; i++) 
      if (visited[i] == false) 
        topologicalsortutil(edges, i, visited, Stack); 
  
    while (Stack.empty() == false) { 
        fout << Stack.top() << " ";
        Stack.pop(); 
    } 
}

int main() {
 
    int v, e;
    fin >> v >> e;
    int num = v + 1;
    vector<int> edges[num];
    int a, b;
    while(e--){
        fin >> a >> b;
        addEdge(edges, a, b);
    }
    if(isCyclic(edges, num)){
    	fout << -1;
    	return 0;
	} else {
		topsort(edges, num);
		return 0;
	}
 
    return 0;
}
