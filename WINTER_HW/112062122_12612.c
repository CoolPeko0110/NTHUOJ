#include<stdio.h>
int main(){
    char str[10005];
    scanf("%s", str);
    char temp[10005];
    int n;
    scanf("%d", &n);
    while(n--){
        int l, r, d;
        scanf("%d %d %d", &l, &r, &d);
        d=d%(r-l+1);
        for(int i=0;i<d;i++){
            temp[i]=str[r-d+i];
        }
        for(int i=r-d-1;i>=l-1;i--){
            str[i+d]=str[i];
        }
        for(int i=0;i<d;i++){
            str[l-1+i]=temp[i];
        }
    }
    printf("%s\n", str);
}