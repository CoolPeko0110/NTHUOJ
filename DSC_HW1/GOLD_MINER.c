#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    char c;
    struct Node *next;
    struct Node *prev;
}Node;

Node *headofbag, *backofbag, *headoftool, *backoftool;
char mine[1005][1005]={0};
int level[1005]={0};
char command[4]={0};
int col;
int W, L, N;

void enqueue(char val, Node *back){
    Node *new=(Node*)malloc(sizeof(Node));
    new->c=val;
    new->next=NULL;
    back->prev->next=new;
    back->prev=new;
}

void dequeue(Node *head, Node *back){
    Node *temp=head->next;
    head->next=temp->next;
    if(temp==back->prev) back->prev=head;
    free(temp);
}

int isempty(Node *head){
    if(head->next==NULL) return 1;
    else return 0;
}

int find_highest();
void dig(int col);
void bomb(int x, int y);
void flashlight();
void magnet();
void lucky_clover(int x);
void pig();

int find_highest(){
    int max=0;
    for(int i=0;i<W;i++) if(level[i]>max) max=level[i];
    return max;
}

void dig(int col){
    switch(mine[col][level[col]]){
        case 'G':
            mine[col][level[col]]='_';
            enqueue('G', backofbag);
            break;
        case 'D':
            mine[col][level[col]]='_';
            enqueue('D', backofbag);
            break;
        case 'B':
            bomb(col, level[col]);
            break;
        case 'F':
            mine[col][level[col]]='_';
            enqueue('F', backoftool);
            break;
        case 'M':
            mine[col][level[col]]='_';
            enqueue('M', backoftool);
            break;
        case 'C':
            mine[col][level[col]]='_';
            lucky_clover(col);
            break;
        case 'P':
            mine[col][level[col]]='_';
            pig();
            break;
        default:
            mine[col][level[col]]='_';
            break;
        }
        while(mine[col][level[col]]=='_'&&level[col]>0) level[col]--;
}

void bomb(int x, int y){
    for(int j=y+1;j>=y-1;j--){
        for(int i=x-1;i<=x+1;i++){
            if(i>=0&&j>=1&&mine[i][j]!='_'){
                mine[i][j]='_';
                if(level[i]==j) level[i]--;
                while(mine[i][level[i]]=='_'&&level[i]>0) level[i]--;
            }
        }
    }
}

void flashlight(){
    int lv=find_highest();
    if(!lv) lv++;
    printf("MINE LEVEL:%d\n", lv);
    for(int i=0;i<W;i++) printf("%c ", mine[i][lv]);
    printf("\n");
}

void magnet(){
    for(int i=0;i<W;i++) dig(i);
}

void lucky_clover(int x){
    if(!isempty(headofbag)){
        int lv=find_highest()+1;
        char ch=backofbag->prev->c;
        for(int j=lv;j<lv+3;j++){
            for(int i=x-2;i<=x+2;i++){
                if(i>=0&&i<W){
                    mine[i][j]=ch;
                    level[i]=j;
                }
            }
        }
    }
}

void pig(){
    if(!isempty(headofbag)){
        Node *temp=headofbag->next;
        Node *tmp=headofbag;
        while(temp){
            if(temp->c=='D') tmp=temp;
            temp=temp->next;
        }
        while(tmp->next){
            Node *tp=tmp->next;
            tmp->next=tmp->next->next;
            free(tp);
        }
        backofbag->prev=tmp;
    }
}

void printfinal(){
    printf("FINAL BAG:\n");
    if(!isempty(headofbag)){
        Node *temp=headofbag->next;
        while(temp){
            printf("%c ", temp->c);
            temp=temp->next;
        }
    }
    printf("\n");
    printf("FINAL MAP:\n");
    int lv=find_highest();
    if(!lv) return;
    for(int j=lv;j>=1;j--){
        for(int i=0;i<W;i++){
            printf("%c ", mine[i][j]);
        }
        printf("\n");
    }
}

int main(){
    headofbag=(Node*)malloc(sizeof(Node));
    headofbag->next=NULL;
    backofbag=(Node*)malloc(sizeof(Node));
    backofbag->prev=headofbag;
    headoftool=(Node*)malloc(sizeof(Node));
    headoftool->next=NULL;
    backoftool=(Node*)malloc(sizeof(Node));
    backoftool->prev=headoftool;
    scanf("%d %d %d", &W, &L, &N);
    getchar();
    for(int j=0;j<1005;j++){
        for(int i=0;i<1005;i++){
            mine[i][j]='_';
        }
    }
    for(int j=L;j>=1;j--){
        for(int i=0;i<W;i++){
            mine[i][j]=getchar();
            if(mine[i][j]!='_'){
                if(!level[i]) level[i]=j;
            }
            getchar();
        }
    }
    while(N--){
        scanf(" %s", command);
        if(command[0]=='D'){
            scanf("%d", &col);
            dig(col);
        }
        else if(command[0]=='U'){
            if(!isempty(headoftool)){
                Node *temp=headoftool->next;
                switch(temp->c){
                    case 'F':
                        flashlight();
                        break;
                    case 'M':
                        magnet();
                        break;
                    default:
                        break;
                }
                dequeue(headoftool, backoftool);
            }
        }
    }
    printfinal();
    return 0;
}