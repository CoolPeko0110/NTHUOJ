#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

enum direction{
    UP, DOWN, LEFT, RIGHT, NA
};

int movement[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

class State{
    public:
        int puzzle[3][3];
        int nowx, nowy;
        int score;
        direction premove;
        int round;

        State(int pu[3][3], int x, int y, direction dir);
        bool operator<(const State& rhs) const;
        void setScore();
        void update(int newx, int newy, direction preMove);
};

priority_queue<State> line;

State::State(int pu[3][3], int x, int y, direction dir):round(0){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            puzzle[j][i] = pu[j][i];
        }
    }
    nowx = x;
    nowy = y;
    premove = dir;
    setScore();
}

bool State::operator<(const State& rhs) const{
    return this->score + this->round > rhs.score + rhs.round;
}

int GoalY[9] = {2, 0, 0, 0, 1, 1, 1, 2, 2};
int GoalX[9] = {2, 0, 1, 2, 0, 1, 2, 0, 1};

void State::setScore(){
    int s = 0;
    int goalx, goaly;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(!puzzle[j][i]) continue;
            goalx = GoalX[puzzle[j][i]];
            goaly = GoalY[puzzle[j][i]];
            s += abs(i-goaly) + abs(j-goalx);
            if(i==goaly){
                for(int k=j+1;k<3;k++){
                    if(puzzle[k][i] && GoalY[puzzle[k][i]]==i && puzzle[k][i]<puzzle[j][i]) s+=2;
                }
            }
            if(j==goalx){
                for(int k=i+1;k<3;k++){
                    if(puzzle[j][k] && GoalX[puzzle[j][k]]==j && puzzle[j][k]<puzzle[j][i]) s+=2;
                }
            }
        }
    }
    score = s;
}

void State::update(int newx, int newy, direction preMove){
    premove = preMove;
    puzzle[nowx][nowy] = puzzle[newx][newy];
    puzzle[newx][newy] = 0;
    nowy = newy; nowx = newx;
    round++;
    setScore();
}

int main(){
    int init[3][3], now_x, now_y;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>init[j][i];
            if(!init[j][i]){
                now_x = j;
                now_y = i;
            }
        }
    }
    line.push(State(init, now_x, now_y, NA));

    while(line.size()){
        State cur = line.top();
        if(!cur.score){
            cout<< cur.round << "\n";
            return 0;
        }
        line.pop();
        for(int i=0;i<4;i++){
            cout<<cur.round<<"\n";
            int newx = cur.nowx + movement[i][0];
            int newy = cur.nowy + movement[i][1];
            if(newx<0||newx>2||newy<0||newy>2) continue;
            if(i==UP && cur.premove == DOWN) continue;
            if(i==DOWN && cur.premove == UP) continue;
            if(i==LEFT && cur.premove == RIGHT) continue;
            if(i==RIGHT && cur.premove == LEFT) continue;

            State next = cur;
            next.update(newx, newy, (direction)i);
            line.push(next);
        }
    }
    cout<<-1<<"\n";
}