#include<stdio.h>
int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    char str[200005];
    for(int i=0;i<a;i++){
        scanf(" %c", &str[i]);
    }
    char g[30];
    for(int i=0;i<26;i++){
        g[i]='a'+i;
    }
    while(b--){
        char c, d;
        scanf(" %c %c", &c, &d);
        for(int i=0;i<26;i++){
            if(g[i]==c) g[i]=d;
            else if(g[i]==d) g[i]=c;
        }
    }
    for(int i=0;i<a;i++){
        printf("%c", g[str[i]-'a']);
    }
    printf("\n");
    return 0;
}