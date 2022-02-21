#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void check(vector<vector<int>> &grid,pair<int,int> &d,int i,int j,int size) {
        
        grid[i][j]=0;
        
        if(c!=0) {
            return ;
        }
        
        if(d.first==i && d.second==j) {
            c++;
            return;
        }
        
        if(j<size-1 && ( grid[i][j+1]==3 || grid[i][j+1]==2 ) ) {
            check(grid,d,i,j+1,size);
        }
        
        if(j>0 && (grid[i][j-1]==3 || grid[i][j-1]==2) ) {
            check(grid,d,i,j-1,size);
        }
        
        if( i<size-1 && ( grid[i+1][j]==3 || grid[i+1][j]==2 ) ) {
            check(grid,d,i+1,j,size);
        }
        
        if( i>0 && ( grid[i-1][j]==3 || grid[i-1][j]==2 ) ) {
            check(grid,d,i-1,j,size);
        }
        
    }
    
    
    bool is_Possible(vector<vector<int>>& grid) 
    {
        pair<int,int> s,d;
        int i,j;
        for(i=0;i<grid.size();i++) {
            for(j=0;j<grid.size();j++) {
                if(grid[i][j]==1) {
                    s={i,j};
                }
                if(grid[i][j]==2) {
                    d={i,j};
                }
            }
        }
        
        c=0;
        
        check(grid,d,s.first,s.second,grid.size());
        
        if(c>0) {
            return 1;
        }
        
        return 0;
        
    }