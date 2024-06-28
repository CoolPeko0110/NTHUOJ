#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXEXPR 256
#define NUMSYM 6

char expr[MAXEXPR];  // string to store the input expression.
int pos;             // current position of parsing, from end to start

typedef enum {ID_A, ID_B, ID_C, ID_D, OP_AND, OP_OR} TokenSet;
char sym[NUMSYM];

typedef struct _Node {
    TokenSet data;
    struct _Node *left, *right;
} BTNode;

BTNode* EXPR();
BTNode* FACTOR();
BTNode* makeNode(char c);
void freeTree(BTNode *root);
void printPrefix(BTNode *root);

BTNode* EXPR(){
    BTNode *node=NULL, *right=FACTOR();
    char c=expr[pos];
    if(pos<0||c=='(') return right;
    node=makeNode(c);
    node->right=right;
    pos--;
    node->left=EXPR();
    return node;
}//
BTNode* FACTOR(){
    BTNode *node=NULL, *right=NULL;
    char c=expr[pos];
    pos--;
    if(c==')'){
        node=EXPR();
        pos--;
    }
    else{
        node=makeNode(c);
    }
    return node;
}
BTNode* makeNode(char c){
    BTNode *new=(BTNode*)malloc(sizeof(BTNode));
    if(c=='A') new->data=ID_A;
    else if(c=='B') new->data=ID_B;
    else if(c=='C') new->data=ID_C;
    else if(c=='D') new->data=ID_D;
    else if(c=='&') new->data=OP_AND;
    else if(c=='|') new->data=OP_OR;
    new->left=NULL;
    new->right=NULL;
    return new;
}
void freeTree(BTNode *root);
void printPrefix(BTNode *root);

int main(void){
    sym[0]='A';
    sym[1]='B';
    sym[2]='C';
    sym[3]='D';
    sym[4]='&';
    sym[5]='|';
    while (scanf("%s", expr)!=EOF)
    {
        pos = strlen(expr) - 1;
        BTNode *root = EXPR();
        printPrefix(root);
        printf("\n");
        freeTree(root);
    }

    return 0;
}

/* print a tree by pre-order. */
void printPrefix(BTNode *root){
    if (root != NULL) {
        printf("%c",sym[root->data]);
        printPrefix(root->left);
        printPrefix(root->right);
    }
}

/* clean a tree.*/
void freeTree(BTNode *root){
    if (root!=NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

