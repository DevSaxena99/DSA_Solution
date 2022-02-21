#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int getLevelDiff(Node *root)
    {   
        int i,j;
        struct Node *p;
        vector<vector<int>> v;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            int a;
            vector<int> t;
            a=q.size();
            while(a--) {
                p=q.front();
                q.pop();
                t.push_back(p->data);
                if(p->left) {
                    q.push(p->left);
                }
                if(p->right) {
                    q.push(p->right);
                }
            }
            v.push_back(t);
        }
        
        int count1=0,count2=0;
        for(i=0;i<v.size();i++) {
            if(i%2==0) {
                count1=count1+accumulate(v[i].begin(),v[i].end(),0);
            }
            else {
                count2=count2+accumulate(v[i].begin(),v[i].end(),0);
            }
        }
        
        return count1-count2;
       
    }