#include <iostream>
#include <queue>
using namespace std;

struct State{
    int lv;
    int hp;
    int mhp;
    int round;
};

int L, HP, MHP, MDMG;
int effect[20][3];
queue<State> line;
int ans = 0;
int check[16][301][401] = {};

void update(State s){
    State tmp;
    //atk
    tmp.lv = s.lv;
    tmp.round = s.round+1;
    tmp.mhp = s.mhp-effect[tmp.lv][1];
    if(tmp.mhp<=0) ans = tmp.round;
    tmp.hp = s.hp - MDMG;
    if(tmp.hp>0 && !check[tmp.lv][tmp.hp][tmp.mhp]){
        check[tmp.lv][tmp.hp][tmp.mhp] = 1;
        line.push(tmp);
    }
    //heal
    tmp.lv = s.lv;
    tmp.round = s.round+1;
    tmp.mhp = s.mhp;
    tmp.hp = s.hp + effect[tmp.lv][2] - MDMG;
    if(tmp.hp>0 && !check[tmp.lv][tmp.hp][tmp.mhp]){
        check[tmp.lv][tmp.hp][tmp.mhp] = 1;
        line.push(tmp);
    }
    //lv up
    tmp.lv = s.lv+(s.lv<L);
    tmp.round = s.round+1;
    tmp.mhp = s.mhp;
    tmp.hp = s.hp - MDMG;
    if(tmp.hp>0 && !check[tmp.lv][tmp.hp][tmp.mhp]){
        check[tmp.lv][tmp.hp][tmp.mhp] = 1;
        line.push(tmp);
    }
}

int main(){
    cin >> L >> HP >> MHP >> MDMG;
    for(int i=1;i<=L;i++) cin >> effect[i][1] >> effect[i][2];
    State init = {1, HP, MHP, 0};
    line.push(init);
    while(!ans&&!line.empty()){
        State tmp = line.front();
        //cout<<tmp.lv<<" "<<tmp.hp<<" "<<tmp.mhp<<" "<<tmp.round<<"\n";
        line.pop();
        update(tmp);
    }
    if(!ans&&line.empty()) ans = -1;
    cout << ans;
    return 0;
}   