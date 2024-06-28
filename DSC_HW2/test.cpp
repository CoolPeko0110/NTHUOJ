#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

struct Node{
    int val;
    int damage;
    int health;
    int lv;
    Node *prev, *next;
};

class Arena{
    public:
        Arena();
        ~Arena();
        void Insert(int val, int damage, int health, string stance);
        void Delete();
        void Shuffle(char clock, int step);
        void Check(int step);
        void Reverse(int group);
        void Print();
    private:
        Node *cur;
        int size;
};

Arena::Arena(){
    cur = NULL;
    size = 0;
}

Arena::~Arena(){

}

void Arena::Insert(int val, int damage, int health, string stance){
    Node *now = new Node;
    now->val = val;
    now->damage = damage;
    now->health = health;
    now->lv = 1;
    if(!cur){
        size++;
        cur = now;
        cur->prev = cur;
        cur->next = cur;
        return;
    }
    now->next = cur;
    now->prev = cur->prev;
    size++;
    if(stance == "Neutral"){
        cur->prev->next = now;
        cur->prev = now;
        return;
    }
    if(stance == "Evolve"){
        if(now->prev == now->next){
            cur->prev->next = now;
            cur->prev = now;
            return;
        }
        else if(now->prev->val == now->val && now->prev->lv < 3 && now->next->val == now->val && now->next->lv < 3){
            cur->damage = max(now->prev->damage, max(now->damage, now->next->damage));
            cur->health = max(now->prev->health, max(now->health, now->next->health));
            cur->lv = max(now->prev->lv, max(now->lv, now->next->lv)) + 1;
            Node *tp1 = now, *tp2 = cur->prev;
            cur->prev = cur->prev->prev;
            cur->prev->next = cur;
            delete tp1;
            delete tp2;
            size -= 2;
            return;
        }
        else{
            cur->prev->next = now;
            cur->prev = now;
            return;
        }
    }
    if(stance == "Attack"){
        if(now->prev == now->next){
            if(now->damage >= now->next->health){
                now->next = now;
                now->prev = now;
                delete cur;
                size--;
                cur = now;
            }
            else{
                now->next->health -= now->damage;
                now->prev->next = now;
                now->next->prev = now;
            }
        }
        else{
            if(now->damage >= now->next->health){
                Node *temp = now->next;
                now->next = now->next->next;
                now->next->prev = now;
                delete temp;
                size--;
                cur = now;
            }
            else{
                now->next->health -= now->damage;
                now->prev->next = now;
                now->next->prev = now;
            }
            if(now->damage >= now->prev->health){
                Node *temp = now->prev;
                now->prev = now->prev->prev;
                now->prev->next = now;
                delete temp;
                size--;
            }
            else{
                now->prev->health -= now->damage;
                now->prev->next = now;
                now->next->prev = now;
            }
        }
    }
}

void Arena::Delete(){
    size--;
    if(cur->next == cur){
        delete cur;
        cur = NULL;
    }
    else{
        cur->next->prev = cur->prev;
        cur->next->prev->next = cur->next;
        Node *temp = cur;
        cur = cur->next;
        delete temp;
    }
}

void Arena::Shuffle(char clock, int step){
    step %= size;
    Node *temp = cur;
    switch(clock){
        case 'c':
            for(int i=0;i<step;i++){
                cur = cur->next;
            }
            break;
        case 'a':
            for(int i=0;i<step;i++){
                cur = cur->prev;
            }
            break;
    }
    int lv = cur->lv, dam = cur->damage, heal = cur->health, val = cur->val;
    cur->lv = temp->lv; cur->damage = temp->damage; cur->health = temp->health; cur->val = temp->val;
    temp->lv = lv; temp->damage = dam; temp->health = heal; temp->val = val;
}

void Arena::Check(int step){
    int count[10005] = {};
    Node *temp = cur;
    for(int i=0;i<step;i++){
        count[temp->val]++;
        temp = temp->next;
    }
    temp = cur;
    for(int i=0;i<step;i++){
        if(count[temp->val]>1){
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            Node *tmp = temp->next;
            if(temp == cur){
                cur = cur->next;
            }
            delete temp;
            size--;
            temp = tmp; 
        }
        else temp = temp->next;
    }
}

void Arena::Reverse(int group){
    if(group == 1) return;
    if(group>=size){
        Node *left = cur;
        Node *right = cur->prev;
        int times = size/2;
        while(times--){
            int lv = left->lv, dam = left->damage, heal = left->health, val = left->val;
            left->lv = right->lv; left->damage = right->damage; left->health = right->health; left->val = right->val;
            right->lv = lv; right->damage = dam; right->health = heal; right->val = val;
            right = right->prev;
            left = left->next;
        }
    }
    else{
        Node *left = cur, *right = cur, *rightmost;
        int times = size/group+!(size%group==0);
        while(times--){
            right = left;
            for(int i=1;i<group;i++){
                if(right == cur->prev) break;
                right = right->next;
                rightmost = right;
            }
            while(right != left && right->next != left){
                int lv = left->lv, dam = left->damage, heal = left->health, val = left->val;
                left->lv = right->lv; left->damage = right->damage; left->health = right->health; left->val = right->val;
                right->lv = lv; right->damage = dam; right->health = heal; right->val = val;
                right = right->prev;
                left = left->next;
            }
            left = rightmost->next;
        }
    }
}

void Arena::Print(){
    //cout<<size<<endl;
    if(!cur){
        cout<<"no Poke Poke ;-;\n";
        return;
    }
    Node *temp = cur;
    while(temp!=cur->prev){
        cout<<"ID: "<<temp->val<<" HP: "<<temp->health<<" LVL: "<<temp->lv<<endl;
        temp = temp->next;
    }
    cout<<"ID: "<<temp->val<<" HP: "<<temp->health<<" LVL: "<<temp->lv<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin>>T;
    Arena list;
    while(T--){
        string command; cin>>command;
        if(command == "Insert"){
            int val, dam, heal; string stance;
            cin>>val>>dam>>heal>>stance;
            list.Insert(val, dam, heal, stance);
        }
        else if(command == "Delete"){
            list.Delete();
        }
        else if(command == "Shuffle"){
            char clock; int step;
            cin>>clock>>step;
            list.Shuffle(clock, step);
        }
        else if(command == "Check"){
            int step;
            cin>>step;
            list.Check(step);
        }
        else if(command == "Reverse"){
            int group;
            cin>>group;
            list.Reverse(group);
        }
        //list.Print();
    }
    list.Print();
    return 0;
}