#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int idx;
    char thing;
    struct Node *next;
}Node;

typedef struct COLL{
    char thing;
    struct COLL *prev, *next;
}COLL;

typedef struct ITEM{
    char thing;
    struct ITEM *prev, *next;
}ITEM;

int width, height, T;
char map[1024][1024];
Node *M[1024];
Node *back[1024];
ITEM *inventory;
COLL *backpack;
int coin=0;
int nowY;
int virusflag=0;

void construct(int width, int height);
void dig(int y);
void shovel();
void use();
void pig();
void print();
void virus();
void button();

void construct(int width, int height){
    for(int j=0;j<height;j++){
        for(int i=1;i<=width;i++){
            scanf(" %c", &map[i][j]);
            if(map[i][j]!='_'){
                Node *now = (Node*)malloc(sizeof(Node));
                now->idx = i;
                now->thing = map[i][j];
                now->next = NULL;
                back[j]->next = now;
                back[j] = now;
            }
        }
    }
}

void dig(int y){
    nowY = y;
    if(M[y]->next){
        if(map[M[y]->next->idx][y]=='D'){
            COLL *nowG = (COLL*)malloc(sizeof(COLL));
            nowG->thing = 'D';
            backpack->prev->next = nowG;
            nowG->prev = backpack->prev;
            nowG->next = backpack;
            backpack->prev = nowG;
        }
        else if(map[M[y]->next->idx][y]=='G'){
            COLL *nowG = (COLL*)malloc(sizeof(COLL));
            nowG->thing = 'G';
            backpack->prev->next = nowG;
            nowG->prev = backpack->prev;
            nowG->next = backpack;
            backpack->prev = nowG;
        }
        else if(map[M[y]->next->idx][y]=='S'){
            ITEM *nowS = (ITEM*)malloc(sizeof(ITEM));
            nowS->thing = 'S';
            inventory->prev->next = nowS;
            nowS->prev = inventory->prev;
            nowS->next = inventory;
            inventory->prev = nowS;
        }
        else if(map[M[y]->next->idx][y]=='X'){
            ITEM *nowX = (ITEM*)malloc(sizeof(ITEM));
            nowX->thing = 'X';
            inventory->prev->next = nowX;
            nowX->prev = inventory->prev;
            nowX->next = inventory;
            inventory->prev = nowX;
        }
        else if(map[M[y]->next->idx][y]=='C'){
            coin = 1;
        }
        else if(map[M[y]->next->idx][y]=='P'){
            pig();
        }
        else if(map[M[y]->next->idx][y]=='V'){
            virus();
        }
        map[M[y]->next->idx][y] = '_';
        M[y]->next = M[y]->next->next;
    }
}

void shovel(){
    dig(nowY);
    dig(nowY);
}

void use(){
    if(inventory->prev!=inventory){
        if(inventory->prev->thing=='S'){
            shovel();
        }
        else if(inventory->prev->thing=='X'){
            button();
        }
        if(inventory->prev->prev==inventory){
            ITEM *temp = inventory->prev;
            inventory->prev = inventory;
            inventory->next = inventory;
            free(temp);
        }
        else{
            inventory->prev->prev->next = inventory;
            ITEM *temp = inventory->prev;
            inventory->prev = inventory->prev->prev;
            free(temp);
        }
    }
}

void pig(){
    if(coin){
        printf("Ding!\n");
        coin = 0;
        return;
    }
    COLL *temp = backpack->next, *tmp = temp->next;
    while(temp!=backpack){
        tmp = temp->next;
        if(temp->thing=='G'){
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            free(temp);
        }
        temp = tmp;
    }
}

void print(){
    printf("Backpack:");
    COLL *temp = backpack->next;
    while(temp!=backpack){
        printf(" %c", temp->thing);
        temp = temp->next;
    }
    printf("\n");
    ITEM *tmp =inventory->next;
    printf("Inventory:");
    while(tmp!=inventory){
        printf(" %c", tmp->thing);
        tmp = tmp->next;
    }
    printf("\n");
    int max=0;
    for(int i=1;i<height;i++){
        if(back[i]->idx>max) max = back[i]->idx;
    }
    printf("Map:\n");
    if(!max){
        printf("\n");
        return;
    }
    else{
        for(int j=0;j<height;j++){
            for(int i=1;i<=max;i++)
                printf("%c ", map[i][j]);
            printf("\n");
        }
    }
}

void virus(){
    printf("Game Over!\n");
    virusflag=1;
}

void button(){
    int max=width+1;
    for(int j=0;j<height;j++){
        if(j%2){
            map[max][j] = 'G';
        }
        else{
            map[max][j] = 'D';
        }
        Node *now = (Node*)malloc(sizeof(Node));
        now->idx = max;
        now->thing = map[max][j];
        now->next = NULL;
        back[j]->next = now;
        back[j] = now;
    }
}

int main(){
    for(int j=0;j<1024;j++){
        for(int i=0;i<1024;i++){
            map[i][j] = '_';
        }
        M[j] = (Node*)malloc(sizeof(Node));
        M[j]->idx = 0;
        M[j]->next = NULL;
        back[j] = M[j];
    }

    inventory = (ITEM*)malloc(sizeof(ITEM));
    inventory->next = inventory;
    inventory->prev = inventory;
    backpack = (COLL*)malloc(sizeof(COLL));
    backpack->next = backpack;
    backpack->prev = backpack;

    scanf("%d %d %d", &width, &height, &T);
    construct(width, height);
    while(T--&&!virusflag){
        char command[15]={0};
        scanf(" %s", command);
        if(command[0]=='D'){
            int y; scanf("%d", &y);
            dig(y);
        }
        else if(command[0]=='U'){
            use();
        }
    }
    print();
    return 0;
}