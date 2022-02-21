#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int c=0;

    void dfs(int u,vector<int> adj[],int visited[],int order[]) {
        int i;
        visited[u]=1;
        order[u]=1;
    
        for(i=0;i<adj[u].size();i++) {
            if(visited[adj[u][i]]==0 ) {
                dfs(adj[u][i],adj,visited,order);
            }
            else {
                if( order[adj[u][i]]==1 ) {
                    c++;
                    return ;
                }
            }
        }
        order[u]=0;    
    }
	
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
        int i;
        vector<int> adj[N];
        for(i=0;i<prerequisites.size();i++) {
            adj[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        
        int order[N],visited[N];
        for(i=0;i<N;i++) {
            order[i]=0;
            visited[i]=0;
        }

        for(i=0;i<N;i++) {
            if(visited[i]==0) {
                dfs(i,adj,visited,order);
            }
        }	
        
        if(c!=0) {
            return 0;
        }
        return 1;   
	}