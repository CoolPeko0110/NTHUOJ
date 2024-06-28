#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

typedef struct Node{
    char c;
    struct Node *next;
}Node;

Node *M[1024];
int idx=0;

void Insert(){
    string expr;
    cin>>expr;
    M[idx] = new Node;
    Node *temp = M[idx];
    for(int i=0;i<expr.size();i++){
        Node *now = new Node;
        now->c = expr[i];
        now->next = NULL;
        temp->next = now;
        temp = temp->next;
    }
    idx++;
}

void Shift(){
    int ids; char c;
    cin>>ids>>c;
    Node *temp = M[ids];
    Node *tp = temp->next;
    temp->next = tp->next;
    free(tp);
    while(temp->next){
        temp = temp->next;
    }
    Node *now = new Node;
    now->c = c;
    now->next = NULL;
    temp->next = now;
}

void Reverse(){
    int ids; cin>>ids;
    char sl[50];
    Node *temp = M[ids]->next;
    Node *tp = temp;
    int i=0;
    for(;temp;i++){
        sl[i] = temp->c;
        temp = temp->next;
    }
    for(i=i-1;i>=0;i--){
        tp->c = sl[i];
        tp = tp->next;
    }
}

void Print(){
    for(int i=0;i<idx;i++){
        Node *temp = M[i]->next;
        while(temp){
            cout<<temp->c<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
}

void Transpose(){
    char m[500][500]={};
    int len;
    for(int i=0;i<idx;i++){
        len = 0;
        Node *temp = M[i]->next;
        while(temp){
            m[i][len] = temp->c;
            len++;
            temp=temp->next;
        }
    }
    for(int i=0;i<len;i++){
        for(int j=0;j<idx;j++){
            cout<<m[j][i]<<" ";
        }
        cout<<endl;
    }
}

void freenode(){
    for(int i=0;i<idx;i++){
        Node *temp = M[i];
        Node *tp = temp->next;
        while(tp){
            temp->next = tp->next;
            free(tp);
            tp = temp->next;
        }
        free(temp);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string command;
    while(cin>>command){
        switch(command[0]){
            case 'I':
                Insert();
                break;
            case 'S':
                Shift();
                break;
            case 'R':
                Reverse();
                break;
            case 'P':
                Print();
                break;
            case 'T':
                Transpose();
                break;
        }
    }
    freenode();
    return 0;
}