#include<iostream>
#include<string>
using namespace std;
typedef struct Node{
    string name;
    struct Node *next;
}Node;

short ord[20][3]={{1, 1, 1}, {1, 0, 1}, {1, 1, 2}, {1, 0, 2}, {1, 1, 3},
                  {1, 0, 3}, {1, 1, 4}, {1, 0, 4}, {1, 1, 5}, {1, 0, 5}, 
                  {0, 1, 1}, {0, 0, 1}, {0, 1, 2}, {0, 0, 2}, {0, 1, 3},
                  {0, 0, 3}, {0, 1, 4}, {0, 0, 4}, {0, 1, 5}, {0, 0, 5}};
Node *order[3][3][6];
Node *back[3][3][6];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for(short i=0;i<20;++i){
        order[ord[i][0]][ord[i][1]][ord[i][2]] = new Node;
    }
    int T;
    cin>>T;
    while(T--){
        for(short i=0;i<20;++i){
            order[ord[i][0]][ord[i][1]][ord[i][2]]->next = NULL;
            back[ord[i][0]][ord[i][1]][ord[i][2]] = order[ord[i][0]][ord[i][1]][ord[i][2]];
        }
        int n;
        cin>>n;
        string name; short a, b, c;
        for(int i=0;i<n;++i){
            cin>>name>>a>>b>>c;
            Node *now = new Node;
    		now->name = name;
    		now->next = NULL;
    		back[c][b][a]->next = now;
    		back[c][b][a] = now;
        }
        bool flag=1;
        short idx = 0;
        Node *temp = order[ord[idx][0]][ord[idx][1]][ord[idx][2]]->next; 
        while(!temp){
            ++idx;
            temp = order[ord[idx][0]][ord[idx][1]][ord[idx][2]]->next; 
        }
        for(int i=0;i<n;++i){
            cin>>name>>a>>b>>c;
            if(!flag) continue;
            else{
                if(temp->name!=name){
                    flag = 0; 
                    continue;
                }
                else if(i<n-1){
                    temp = temp->next;
                    while(!temp){
                        ++idx;
                        temp = order[ord[idx][0]][ord[idx][1]][ord[idx][2]]->next; 
                    }
                }
            }
        }
        if(flag) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
