#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void generate(string s,vector<string> &v,int n,int count1,int count2) {
        
        if(s.size()==2*n) {
            v.push_back(s);
            return ;
        }
        
        if(count1<n) {
            s.push_back('(');
            generate(s,v,n,count1+1,count2);
            s.pop_back();
        }
        
        if(count2<n && count2<count1) {
            s.push_back(')');
            generate(s,v,n,count1,count2+1);
            s.pop_back();
        }
        
    }
    
    vector<string> AllParenthesis(int n) 
    {
        string s;
        vector<string> v;
        generate(s,v,n,0,0);
        
        return v;
        
    }