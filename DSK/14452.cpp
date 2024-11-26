#include <iostream>
#include <string>
using namespace std;

struct Node{
    char c;
    struct Node *prev;
    struct Node *next;
};

Node *start;
Node *tail;
int Size;
int amount[26] = {};

void Insert_tail(string in){
    Node *temp = tail->prev;
    for(int i=0;i<in.size();i++){
        Node *newNode = new Node;
        newNode->c = in[i];
        tail->prev = newNode;
        newNode->next = tail;
        newNode->prev = temp;
        temp->next = newNode;
        temp = newNode;
        Size++;
    }
}

void Insert_at(string in, int at){
    if(!Size){
        Insert_tail(in);
        return;
    }
    at = at % Size;
    if(at == 0){
        Insert_tail(in);
        return;
    }
    Node *temp;
    temp = start;
    for(int i=0;i<at;i++) temp = temp->next;
    Node *temptail = temp->next;
    for(int i=0;i<in.size();i++){
        Node *newNode = new Node;
        newNode->c = in[i];
        temptail->prev = newNode;
        newNode->next = temptail;
        newNode->prev = temp;
        temp->next = newNode;
        temp = newNode;
        Size++;
    }
}

void Pop_back(){
    if(!Size) return;
    Node *temp = tail->prev;
    temp->prev->next = tail;
    tail->prev = temp->prev;
    delete temp;
    Size--;
}

void Pop_at(int at){
    if(!Size) return;
    Node *temp;
    at = at % Size;
    if(at == 0) Pop_back();
    else{
        temp = start;
        for(int i=0;i<at;i++) temp = temp->next;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        Size--;
    }
}

void Print(){
    Node *temp = start->next;
    while(temp != tail){
        cout << temp->c;
        temp = temp->next;
    }
    cout <<"\n";
}

void Eliminate(){
    int align = 0;
    int tag = 0;
    Node *left, *right;

    align = 1;
    left = start->next;
    right = left->next;
    while(right != tail && right != start){
        if(left->c == right->c){
            align++;
            right = right->next;
            if(right == tail){
                if(align >= 3){
                    left->prev->next = tail;
                    tail->prev = left->prev;
                    Size -= align;
                    tag = 1;
                }
            }
        }
        else{
            if(align >= 3){
                left->prev->next = right;
                right->prev = left->prev;
                left = right;
                right = right->next;
                Size -= align;
                align = 1;
                tag = 1;
            }
            else{
                left = right;
                right = right->next;
                align = 1;
            }
        }
    }
    if(tag) Eliminate();
    else return;
}

int main(){
    ios_base::sync_with_stdio(false);
    std::cin.tie(0); cout.tie(0);
    Size = 0;
    start = new Node;
    tail = new Node;
    start->next = tail;
    start->prev = tail;
    tail->next = start;
    tail->prev = start;
    int n; std::cin >> n;
    while(n--){
        string command;
        std::cin >> command;
        if(command == "Insert_at"){
            string str;
            int P;
            std::cin >> str >> P;
            Insert_at(str, P);
            Eliminate();
        }
        else if(command == "Pop_at"){
            int P;
            std::cin >> P;
            Pop_at(P);
            Eliminate();
        }
        else{
            Print();
        }
    }
    Node *tmp = start;
    while(tmp != tail){
        Node *tp = tmp;
        tmp = tmp->next;
        delete tp;
    }
    delete tail;
    return 0;
}
