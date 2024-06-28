#include<stdio.h>
int main(){
    int num;
    scanf("%d", &num);
    while(num--){
        int n;
        int count=0;
        int f, g;
        scanf("%d", &n);
        if(n%400==0||(n%4==0&&n%100!=0)) f=1;
        else f=0;
        int flag=0;
        while(!flag){
            n++;
            if(n%400==0||(n%4==0&&n%100!=0)){
                count=(count+366%7)%7;
                g=1;
            }
            else{
                count=(count+365%7)%7;
                g=0;
            }
            if(count==0&&f-g==0) flag=1;
        }
        printf("%d\n", n);
    }
    return 0;
}