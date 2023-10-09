void dfsTopo(int v,stack<int>& st,vector<bool>& visited,vector<int> adj[]){
	    visited[v]=true;
	    
	    for(auto i: adj[v]){
	        if(!visited[i]){
	            dfsTopo(i,st,visited,adj);
	        }
	    }
	    st.push(v);
	}
	void dfs(int v,vector<bool>& visited,vector<int> graph[]){
	    visited[v]=true;
	    
	    for(auto i: graph[v]){
	        if(!visited[i]){
	            dfs(i,visited,graph);
	        }
	    }
	    
	}
	
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        stack<int> st;
        int count = 0;
        vector<bool> visited(V,false);
        
        
        //1.topo sort
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfsTopo(i,st,visited,adj);
            }
        }
        
        //2.reverse edges
        vector<int> graph[V];
        for(int i=0;i<V;i++){
            //0 -> 2, 3
            visited[i] = false;
            for(auto j: adj[i]){
                graph[j].push_back(i);
            }
        }
        
        //3.dfs acc to stack in graph
        while(!st.empty()){
            int topElem = st.top();
            st.pop();
            if(!visited[topElem]){
                dfs(topElem,visited,graph);
                count++;
            }
        }
        
        return count;
        
    }
