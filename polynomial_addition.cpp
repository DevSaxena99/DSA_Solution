#include<iostream>
#include<bits/stdc++.h>
using namespace std;

Node* addPolynomial(Node *p1, Node *p2)
    {
        Node *head=NULL;
        head=(Node*)malloc(sizeof(Node*));
        if(p1->pow > p2->pow) {
            head->coeff=p1->coeff;
            head->pow=p1->pow;
            head->next=NULL;
            p1=p1->next;
        }
        
        else if(p1->pow < p2->pow) {
            head->coeff=p2->coeff;
            head->pow=p2->pow;
            head->next=NULL;
            p2=p2->next;    
        }
        
        else {
            head->coeff=p1->coeff+p2->coeff;
            head->pow=p1->pow;
            head->next=NULL;
            p1=p1->next;
            p2=p2->next;
        }
        
        struct Node *p=head;
        
        while(p1 && p2) {
            Node *t=NULL;
            t=(Node*)malloc(sizeof(Node*));
            
            if(p1->pow > p2->pow) {
                t->coeff=p1->coeff;
                t->pow=p1->pow;
                t->next=NULL;
                p1=p1->next;        
            }
            
            else if(p1->pow < p2->pow) {
                t->coeff=p2->coeff;
                t->pow=p2->pow;
                t->next=NULL;
                p2=p2->next;    
            }
            
            else {
                t->coeff=p1->coeff+p2->coeff;
                t->pow=p1->pow;
                t->next=NULL;
                p1=p1->next;
                p2=p2->next;    
            }
            p->next=t;
            p=t;
        }
        
        while(p1) {
            Node *t=NULL;
            t=(Node*)malloc(sizeof(Node*));
            t->coeff=p1->coeff;
            t->pow=p1->pow;
            t->next=NULL;
            p1=p1->next;
            p->next=t;
            p=t;
        }
        
        while(p2) {
            Node *t=NULL;
            t=(Node*)malloc(sizeof(Node*));
            t->coeff=p2->coeff;
            t->pow=p2->pow;
            t->next=NULL;
            p2=p2->next;
            p->next=t;
            p=t;    
        }
        
        return head;
    }