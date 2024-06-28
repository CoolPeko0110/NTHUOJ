#include<iostream>
#include<string>
using namespace std;

struct Node{
    int ID;
    int lv;
    Node *prev, *next;
};

class Arena{
    public:
        Arena(int n);
        ~Arena();
        void Insert(int idx, int ID, int lv);
        void Remove(int idx, int ID);
        void Rotate(int idx, int times);
        void Reorder(int idx);
        void Reverse(int idx, int left, int right);
        void Merge(int end, int from);
        void Print();
    private:
        Node *head[15];
        Node *back[15];
        int size[15];
        int n;
};

Arena::Arena(int n){
    for(int i=0;i<n;i++){
        head[i] = new Node;
        head[i]->next = NULL;
        head[i]->prev = NULL;
        back[i] = head[i];
        size[i] = 0;
    }
    this->n = n;
}

Arena::~Arena(){

}

void Arena::Insert(int idx, int ID, int lv){
    Node *now = new Node;
    now->ID = ID;
    now->lv = lv;
    now->next = NULL;
    back[idx]->next = now;
    now->prev = back[idx];
    back[idx] = now;
    size[idx]++;
}

void Arena::Remove(int idx, int ID){
    Node *temp = head[idx]->next;
    while(temp){
        if(temp->ID == ID){
            if(temp == back[idx]){
                back[idx] = temp->prev;
                temp->prev->next = NULL;
                Node *tmp = temp;
                temp = temp->next;
                free(tmp);
                size[idx]--;
                return;
            }
            else{
                temp->next->prev = temp->prev;
                temp->prev->next = temp->next;
                Node *tmp = temp;
                temp = temp->next;
                free(tmp);
                size[idx]--;
            }
        }
        else{
            temp = temp->next;
        }
    }
}

void Arena::Rotate(int idx, int times){
    times %= size[idx];
    if(!times) return;
    Node *left = back[idx], *right = back[idx];
    for(int i=1;i<times;i++){
        left = left->prev;
    }
    right->next = head[idx]->next;
    head[idx]->next->prev = right;
    left->prev->next = NULL;
    back[idx] = left->prev;
    left->prev = head[idx];
    head[idx]->next = left;
}

void Arena::Reorder(int idx){
    int IDeven[10005] = {}, IDodd[10005] = {};
    int lvodd[10005] = {}, lveven[10005] = {};
    int iodd = 0, ieven = 0;
    Node *temp = head[idx]->next;
    while(temp){
        if(temp->ID%2){
            IDodd[iodd] = temp->ID;
            lvodd[iodd] = temp->lv;
            iodd++;
        }
        else{
            IDeven[ieven] = temp->ID;
            lveven[ieven] = temp->lv;
            ieven++;
        }
        temp = temp->next;
    }
    temp = head[idx]->next;
    for(int i=0;i<iodd;i++){
        temp->ID = IDodd[i];
        temp->lv = lvodd[i];
        temp = temp->next;
    }
    for(int i=0;i<ieven;i++){
        temp->ID = IDeven[i];
        temp->lv = lveven[i];
        temp = temp->next;
    }
}

void Arena::Reverse(int idx, int left, int right){
    int ID[10005] = {}, lv[10005] = {};
    Node *l = head[idx]->next, *r = head[idx]->next;
    for(int i=0;i<left;i++){
        l = l->next;
    }
    for(int i=0;i<right;i++){
        r = r->next;
    }
    Node *temp = l;
    int i;
    for(i=0;temp && temp!=r->next;i++){
        ID[i] = temp->ID;
        lv[i] = temp->lv;
        temp = temp->next;
    }
    temp = r;
    for(int j=0;j<i;j++){
        temp->ID = ID[j];
        temp->lv = lv[j];
        temp = temp->prev;
    }
}

void Arena::Merge(int end, int from){
    Node *temp1 = head[end]->next, *temp2 = head[from]->next;
    int ID[10005] = {}, lv[10005] = {};
    int i = 0;
    while(temp1 || temp2){
        if(!temp1){
            ID[i] = temp2->ID;
            lv[i] = temp2->lv;
            i++;
            temp2 = temp2->next;
            continue;
        }
        else if(!temp2){
            ID[i] = temp1->ID;
            lv[i] = temp1->lv;
            i++;
            temp1 = temp1->next;
            continue;
        }
        if(temp2->lv < temp1->lv){
            ID[i] = temp2->ID;
            lv[i] = temp2->lv;
            i++;
            temp2 = temp2->next;
        }
        else if(temp2->lv == temp1->lv){
            if(temp2->ID < temp1->ID){
                ID[i] = temp2->ID;
                lv[i] = temp2->lv;
                i++;
                temp2 = temp2->next;
            }
            else{
                ID[i] = temp1->ID;
                lv[i] = temp1->lv;
                i++;
                temp1 = temp1->next;
            }
        }
        else{
            ID[i] = temp1->ID;
            lv[i] = temp1->lv;
            i++;
            temp1 = temp1->next;
        }
    }
    back[end]->next = head[from]->next;
    head[from]->next->prev = back[end];
    back[end] = back[from];
    head[from]->next = NULL;
    back[from] = head[from];
    size[end] += size[from];
    size[from] = 0;
    Node *temp = head[end]->next;
    for(int j=0;j<i;j++){
        temp->ID = ID[j];
        temp->lv = lv[j];
        temp = temp->next;
    }
}

void Arena::Print(){
    for(int i=0;i<n;i++){
        cout<<"List "<<i<<endl;
        Node *temp = head[i]->next;
        if(!temp){
            cout<<"Empty"<<endl;
        }
        while(temp){
            cout<<"ID: "<<temp->ID<<" Level: "<<temp->lv<<endl;
            temp = temp->next;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin>>n;
    Arena list(n);
    int T; cin>>T;
    while(T--){
        string command; cin>>command;
        if(command == "Insert"){
            int pos, idx, lv;
            cin>>pos>>idx>>lv;
            list.Insert(pos, idx, lv);
        }
        else if(command == "Remove"){
            int from, idx;
            cin>>from>>idx;
            list.Remove(from, idx);
        }
        else if(command == "Rotate"){
            int idx, times;
            cin>>idx>>times;
            list.Rotate(idx, times);
        }
        else if(command == "Reorder"){
            int idx;
            cin>>idx;
            list.Reorder(idx);
        }
        else if(command == "Reverse"){
            int idx, left, right;
            cin>>idx>>left>>right;
            list.Reverse(idx, left, right);
        }
        else if(command == "MergeListsPreserveOrder"){
            int end, from;
            cin>>end>>from;
            list.Merge(end, from);
        }
        list.Print();
    }
    list.Print();
    return 0;
}

/*
3 16
Insert 0 2 1
Insert 0 1 5
Insert 1 3 1
Insert 1 3 4
Insert 1 2 3
MergeListsPreserveOrder 0 1
Reorder 0
Reverse 0 1 3
*/