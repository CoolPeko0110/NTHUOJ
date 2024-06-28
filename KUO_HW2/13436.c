#include<stdio.h>
#include<stdlib.h>
int main(){
    int T;
    scanf("%d", &T);
    for(int numb=0;numb<T;numb++){
        int stack[20005]={0}, number[20005]={0}, delstack[20005]={0};
        int n, k;
        scanf("%d %d", &n, &k);
        int stnum=0;
        for(int u=0;u<n-1;u++){
            int a, b;
            scanf("%d %d", &a, &b);
            number[a]++;
            number[b]++;
            stack[++stnum]=a*100000+b;
        }
        int flag=0;
        int num=n;
        int flag2=0;
        while(k--&&num){
            if(flag2){
                num-=2*(k+1);
                if(num<0) num=0;
                break;
            }
            int delnum=0;
            int temp=stnum;
            stnum=0;
            for(int j=1;j<=temp;j++){
                if(number[stack[j]/100000]==1){
                    number[stack[j]/100000]--;
                    delstack[++delnum]=stack[j]%100000;
                }
                else if(number[stack[j]%100000]==1){
                    number[stack[j]%100000]--;
                    delstack[++delnum]=stack[j]/100000;
                }
                else{
                    stack[++stnum]=stack[j];
                }
            }
            num-=delnum;
            if(delnum==2){
                flag2=1;
                continue;
            }
            for(int j=1;j<=delnum;j++){
                number[delstack[j]]--;
                if(k&&num==1){
                    flag=1;
                    break;
                }
            }
            if(flag) break;
        }
        if(flag) printf("0\n");
        else printf("%d\n", num);
    }
    return 0;
}