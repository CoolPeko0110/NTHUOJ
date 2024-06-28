#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Pokemon{
    int poke;
    int level;
    int attack;
    int health;
    Pokemon *next, *prev;
};

class Arena{
    public:
        Arena();
        ~Arena();
        void insert(int poke, int attack, int health, string stance);
        void deletenode();
        void shuffle(char clock, int time);
        void check(int time);
        void reverse(int group);
        void print();
    private:
        Pokemon *cur;
        int size;
};

Arena::Arena(){
    cur = nullptr;
    size = 0;
}

Arena::~Arena(){

}

void Arena::insert(int poke, int attack, int health, string stance){
    Pokemon *brand = new Pokemon;
    brand->poke = poke;
    brand->level = 1;
    brand->attack = attack;
    brand->health = health;
    if(!cur){
        cur = brand;
        cur->next = cur;
        cur->prev = cur;
        size++;
        return;
    }
    if(stance == "Evolve"){
        if(cur->prev == cur){
            brand->next = cur;
            brand->prev = cur;
            cur->next = brand;
            cur->prev = brand;
            size++;
        }
        else{
            cur->prev->next = brand;
            brand->prev = cur->prev;
            cur->prev = brand;
            brand->next = cur;
            size++;
            if(brand->prev->level<3 && brand->next->level<3 && brand->prev->poke == brand->poke && brand->next->poke == brand->poke){
                cur->attack = max(brand->prev->attack, max(cur->attack, brand->attack));
                cur->health = max(brand->prev->health, max(cur->health, brand->health));
                cur->level = max(brand->prev->level, max(cur->level, brand->level))+1;
                cur->prev->prev->prev->next = cur;
                cur->prev = cur->prev->prev->prev;
                delete brand->prev;
                delete brand;
                size -= 2;
            }
        }
    }
    else if(stance == "Attack"){
        if(cur->prev == cur){
            brand->next = cur;
            brand->prev = cur;
            cur->next = brand;
            cur->prev = brand;
            size++;
            if(brand->attack>=cur->health){
                delete cur;
                cur = brand;
                cur->next = cur;
                cur->prev = cur;
                size--;
            }
            else{
                cur->health -= brand->attack;
            }
        }
        else{
            cur->prev->next = brand;
            brand->prev = cur->prev;
            cur->prev = brand;
            brand->next = cur;
            size++;
            if(brand->attack>=brand->prev->health){
                Pokemon *tmp = brand->prev;
                brand->prev->prev->next = brand;
                brand->prev = brand->prev->prev;
                delete tmp;
                size--;
            }
            else{
                brand->prev->health -= brand->attack;
            }
            if(brand->attack>=brand->next->health){
                Pokemon *tmp = brand->next;
                brand->next->next->prev = brand;
                brand->next = brand->next->next;
                cur = brand;
                delete tmp;
                size--;
            }
            else{
                brand->next->health -= brand->attack;
            }
        }
    }
    else if(stance == "Neutral"){
        if(cur->prev == cur){
            brand->next = cur;
            brand->prev = cur;
            cur->next = brand;
            cur->prev = brand;
            size++;
        }
        else{
            cur->prev->next = brand;
            brand->prev = cur->prev;
            cur->prev = brand;
            brand->next = cur;
            size++;
        }
    }
}

void Arena::deletenode(){
    if(cur->prev == cur){
        delete cur;
        cur = nullptr;
    }
    else{
        Pokemon *temp = cur;
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        cur = cur->next;
        delete temp;
    }
    size--;
}

void Arena::shuffle(char clock, int time){
    time %= size;
    if(!time || cur->prev == cur) return;
    Pokemon *temp = cur;
    if(clock == 'c'){
        for(int i=0;i<time;i++){
            temp = temp->next;
        }
    }
    else{
        for(int i=0;i<time;i++){
            temp = temp->prev;
        }
    }
    if(temp == cur) return;
    int l = cur->level, p = cur->poke, a = cur->attack, h = cur->health;
    cur->level = temp->level; cur->poke = temp->poke; cur->attack = temp->attack; cur->health = temp->health;
    temp->level = l; temp->poke = p; temp->attack = a; temp->health = h;
    cur = temp;
}

void Arena::check(int time){
    Pokemon *end, *dummy = nullptr;
    if(time >= size){
        dummy = new Pokemon;
        dummy->poke = -1;
        dummy->prev = cur->prev;
        dummy->next = cur;
        cur->prev->next = dummy;
        cur->prev = dummy;
        end = dummy;
    }
    else{
        end = cur;
        for(int i=0;i<time;i++){
            end = end->next;
        }
    }
    Pokemon *standard = cur, *temp;
    while(standard != end){
        temp = standard->next;
        int count = 0;
        while(temp != end){
            if(temp->poke == standard->poke){
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                Pokemon *tmp = temp->next;
                delete temp;
                size--;
                count++;
                temp = tmp;
            }
            else temp = temp->next;
        }
        if(count){
            if(standard == cur){
                standard->prev->next = standard->next;
                standard->next->prev = standard->prev;
                cur = standard->next;
                delete standard;
                size--;
                standard = cur;
            }
            else{
                standard->prev->next = standard->next;
                standard->next->prev = standard->prev;
                Pokemon *tmp = standard->next;
                delete standard;
                size--;
                standard = tmp;
            }
        }
        else standard = standard->next;
    }
    if(dummy){
        if(dummy == cur){
            delete dummy;
            cur = nullptr;
        }
        else{
            dummy->prev->next = dummy->next;
            dummy->next->prev = dummy->prev;
            delete dummy;
        }
    }
}

void Arena::reverse(int group){
    if(group>=size){
        Pokemon *left = cur, *right = cur->prev;
        int time = size/2;
        while(time--){
            int level = left->level, attack = left->attack, health = left->health, poke = left->poke;
            left->level = right->level; left->attack = right->attack; left->health = right->health; left->poke = right->poke;
            right->level = level; right->attack = attack; right->health = health; right->poke = poke;
            left = left->next;
            right = right->prev;
        }
        return;
    }
    Pokemon *end = cur->prev, *groupstart = cur, *groupend = cur;
    while(groupend != end){
        groupend = groupstart;
        for(int i=0;i<group-1;i++){
            if(groupend == end) break;
            groupend = groupend->next;
        }
        Pokemon *left = groupstart, *right = groupend;
        while(right->next != left && left != right){
            int level = left->level, attack = left->attack, health = left->health, poke = left->poke;
            left->level = right->level; left->attack = right->attack; left->health = right->health; left->poke = right->poke;
            right->level = level; right->attack = attack; right->health = health; right->poke = poke;
            left = left->next;
            right = right->prev;
        }
        groupstart = groupend->next;
    }
}

void Arena::print(){
    if(!cur){
        cout<<"no Poke Poke ;-;\n";
        return;
    }
    Pokemon *end = cur->prev, *temp = cur;
    while(temp!=end){
        cout<<"ID: "<<temp->poke<<" HP: "<<temp->health<<" LVL: "<<temp->level<<"\n";
        temp = temp->next;
    }
    cout<<"ID: "<<end->poke<<" HP: "<<end->health<<" LVL: "<<end->level<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin>>T;
    Arena list;
    while(T--){
        string command; cin>>command;
        if(command == "Insert"){
            int poke, attack, health;
            string stance;
            cin>>poke>>attack>>health>>stance;
            list.insert(poke, attack, health, stance);
        }
        else if(command == "Delete"){
            list.deletenode();
        }
        else if(command == "Shuffle"){
            char clock; int time;
            cin>>clock>>time;
            list.shuffle(clock, time);
        }
        else if(command == "Check"){
            int time;
            cin>>time;
            list.check(time);
        }
        else if(command == "Reverse"){
            int group;
            cin>>group;
            list.reverse(group);
        }
    }
    list.print();
    return 0;
}