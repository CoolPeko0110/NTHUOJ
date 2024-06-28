#include<stdio.h>
int len;
char s[105][105];
int flag=0;
void find(int x, int y, int step){
    if(x-2>=0&&y-1>=0){
        int a=x-2, b=y-1;
        if(s[a][b]=='C'&&step==1) find(a, b, step+1);
        if(s[a][b]=='P'&&step==2) find(a, b, step+1);
        if(s[a][b]=='C'&&step==3) find(a, b, step+1);
        if(s[a][b]=='A'&&step==4) find(a, b, step+1);
        if(s[a][b]=='S'&&step==5) find(a, b, step+1);
        if(s[a][b]=='I'&&step==6) find(a, b, step+1);
        if(s[a][b]=='A'&&step==7) find(a, b, step+1);
        if(s[a][b]=='S'&&step==8) find(a, b, step+1);
        if(s[a][b]=='G'&&step==9) flag=1;
    }
    if(x-1>=0&&y-2>=0){
        int a=x-1, b=y-2;
        if(s[a][b]=='C'&&step==1) find(a, b, step+1);
        if(s[a][b]=='P'&&step==2) find(a, b, step+1);
        if(s[a][b]=='C'&&step==3) find(a, b, step+1);
        if(s[a][b]=='A'&&step==4) find(a, b, step+1);
        if(s[a][b]=='S'&&step==5) find(a, b, step+1);
        if(s[a][b]=='I'&&step==6) find(a, b, step+1);
        if(s[a][b]=='A'&&step==7) find(a, b, step+1);
        if(s[a][b]=='S'&&step==8) find(a, b, step+1);
        if(s[a][b]=='G'&&step==9) flag=1;
    }
    if(x+2<len&&y-1>=0){
        int a=x+2, b=y-1;
        if(s[a][b]=='C'&&step==1) find(a, b, step+1);
        if(s[a][b]=='P'&&step==2) find(a, b, step+1);
        if(s[a][b]=='C'&&step==3) find(a, b, step+1);
        if(s[a][b]=='A'&&step==4) find(a, b, step+1);
        if(s[a][b]=='S'&&step==5) find(a, b, step+1);
        if(s[a][b]=='I'&&step==6) find(a, b, step+1);
        if(s[a][b]=='A'&&step==7) find(a, b, step+1);
        if(s[a][b]=='S'&&step==8) find(a, b, step+1);
        if(s[a][b]=='G'&&step==9) flag=1;
    }
    if(x-2>=0&&y+1<len){
        int a=x-2, b=y+1;
        if(s[a][b]=='C'&&step==1) find(a, b, step+1);
        if(s[a][b]=='P'&&step==2) find(a, b, step+1);
        if(s[a][b]=='C'&&step==3) find(a, b, step+1);
        if(s[a][b]=='A'&&step==4) find(a, b, step+1);
        if(s[a][b]=='S'&&step==5) find(a, b, step+1);
        if(s[a][b]=='I'&&step==6) find(a, b, step+1);
        if(s[a][b]=='A'&&step==7) find(a, b, step+1);
        if(s[a][b]=='S'&&step==8) find(a, b, step+1);
        if(s[a][b]=='G'&&step==9) flag=1;
    }
    if(x-1>=0&&y+2<len){
        int a=x-1, b=y+2;
        if(s[a][b]=='C'&&step==1) find(a, b, step+1);
        if(s[a][b]=='P'&&step==2) find(a, b, step+1);
        if(s[a][b]=='C'&&step==3) find(a, b, step+1);
        if(s[a][b]=='A'&&step==4) find(a, b, step+1);
        if(s[a][b]=='S'&&step==5) find(a, b, step+1);
        if(s[a][b]=='I'&&step==6) find(a, b, step+1);
        if(s[a][b]=='A'&&step==7) find(a, b, step+1);
        if(s[a][b]=='S'&&step==8) find(a, b, step+1);
        if(s[a][b]=='G'&&step==9) flag=1;
    }
    if(x+1<len&&y-2>=0){
        int a=x+1, b=y-2;
        if(s[a][b]=='C'&&step==1) find(a, b, step+1);
        if(s[a][b]=='P'&&step==2) find(a, b, step+1);
        if(s[a][b]=='C'&&step==3) find(a, b, step+1);
        if(s[a][b]=='A'&&step==4) find(a, b, step+1);
        if(s[a][b]=='S'&&step==5) find(a, b, step+1);
        if(s[a][b]=='I'&&step==6) find(a, b, step+1);
        if(s[a][b]=='A'&&step==7) find(a, b, step+1);
        if(s[a][b]=='S'&&step==8) find(a, b, step+1);
        if(s[a][b]=='G'&&step==9) flag=1;
    }
    if(x+2<len&&y+1<len){
        int a=x+2, b=y+1;
        if(s[a][b]=='C'&&step==1) find(a, b, step+1);
        if(s[a][b]=='P'&&step==2) find(a, b, step+1);
        if(s[a][b]=='C'&&step==3) find(a, b, step+1);
        if(s[a][b]=='A'&&step==4) find(a, b, step+1);
        if(s[a][b]=='S'&&step==5) find(a, b, step+1);
        if(s[a][b]=='I'&&step==6) find(a, b, step+1);
        if(s[a][b]=='A'&&step==7) find(a, b, step+1);
        if(s[a][b]=='S'&&step==8) find(a, b, step+1);
        if(s[a][b]=='G'&&step==9) flag=1;
    }
    if(x+1<len&&y+2<len){
        int a=x+1, b=y+2;
        if(s[a][b]=='C'&&step==1) find(a, b, step+1);
        if(s[a][b]=='P'&&step==2) find(a, b, step+1);
        if(s[a][b]=='C'&&step==3) find(a, b, step+1);
        if(s[a][b]=='A'&&step==4) find(a, b, step+1);
        if(s[a][b]=='S'&&step==5) find(a, b, step+1);
        if(s[a][b]=='I'&&step==6) find(a, b, step+1);
        if(s[a][b]=='A'&&step==7) find(a, b, step+1);
        if(s[a][b]=='S'&&step==8) find(a, b, step+1);
        if(s[a][b]=='G'&&step==9) flag=1;
    }
}
int main(){
    scanf("%d", &len);
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            scanf(" %c", &s[j][i]);
        }
    }
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            if(s[j][i]=='I'){
                if(!flag) find(j, i, 1);
            }
        }
    }
    printf(flag?"YES\n":"NO\n");
    return 0;
}