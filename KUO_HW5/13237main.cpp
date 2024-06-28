#include "function.h"

void Crossing::solve(){
    list<list<State>> line;
    State init = {_items[0], _items[1], _items[2], 0, 0, 0, 1};
    line.push_back({init});
    while(!line.empty()){
        list<State> temp;
        temp = line.front();
        line.pop_front();
        for(auto r:temp) _explored.insert(r);
        set<State> next = extend(temp.back());
        for(auto r:next){
            temp.push_back(r);
            if(found(r)) _solutions.insert(temp);
            else line.push_back(temp);
            temp.pop_back();
        }
        _explored.clear();
    }
}
// extend to other possible states from a certain state
set<State> Crossing::extend(State s){
    set<State> ret;
    if(valid(Go(s, 1, 0, 0)) && _explored.find(Go(s, 1, 0, 0))==_explored.end()) ret.insert(Go(s, 1, 0, 0));
    if(valid(Go(s, 0, 1, 0)) && _explored.find(Go(s, 0, 1, 0))==_explored.end()) ret.insert(Go(s, 0, 1, 0));
    if(valid(Go(s, 0, 0, 1)) && _explored.find(Go(s, 0, 0, 1))==_explored.end()) ret.insert(Go(s, 0, 0, 1));
    if(valid(Go(s, 0, 0, 0)) && _explored.find(Go(s, 0, 0, 0))==_explored.end()) ret.insert(Go(s, 0, 0, 0));
    return ret;
}
// may use s[6] to indicate the direction of move
State Crossing::Go(State s, int wolf, int goat, int cabbage){
    State ret;
    if(s[6] == 1) ret = {s[0]-wolf, s[1]-goat, s[2]-cabbage, s[3]+wolf, s[4]+goat, s[5]+cabbage, -1};
    else ret = {s[0]+wolf, s[1]+goat, s[2]+cabbage, s[3]-wolf, s[4]-goat, s[5]-cabbage, 1};
    return ret;
}
// check the validity of a state
bool Crossing::valid(State s){
    if(s[6] == 1){
        if((s[3]<=s[4] || s[4]==0) && (s[4]<=s[5] || s[5]==0) && s[3]>=0 && s[4] >=0 && s[5] >=0) return true;
        return false;
    }
    else{
        if((s[0]<=s[1] || s[1]==0) && (s[1]<=s[2] || s[2]==0) && s[0]>=0 && s[1] >=0 && s[2] >=0) return true;
        return false;
    }
}
// check if all people are at the right bank
bool Crossing::found(State s){
    if((!s[0]&&!s[1]&&!s[2]&&s[6] == -1) || (!s[3]&&!s[4]&&!s[5]&&s[6] == 1)) return true;
    return false;
}