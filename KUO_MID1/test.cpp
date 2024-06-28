/*
#include<iostream>
#include<string>
using namespace std;
int t;
int parent[100005]={};
int n=0;
string tree;
int ri[100005]={};
void maketree(int idx, int father){
    if(n==t) return;
    n++;
    int count=0;
    while(tree[idx]<='9'&&tree[idx]>='0'){
        count = count*10 + (tree[idx]-'0');
        idx++;
    }
    parent[count]=father;
    while(tree[idx]=='('||tree[idx]==')'){
        if(tree[idx]==')'){
            ri[count]++;
            if(ri[count]==2) count = parent[count];
        }
        idx++;
    }
    maketree(idx, count);
}
int main(){
    cin >> t >> tree;
    int T;
    cin >> T;
    maketree(0, 0);
    while(T--){
        int len;
        int road[105]={};
        cin >> len;
        for(int i=0;i<len;i++){
            cin >> road[i];
        }
        int flag=1;
        for(int i=1;road[i];i++){
            if(parent[road[i]]!=road[i-1]) flag=0;
        }
        if(flag) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
*/
/*
#include<iostream>
#include<string>
using namespace std;
int arr[10005]={};
int len;
int comparison=0, swa=0;
void bubble(){
    int sw;
    for(int i=0;i<len;len--){
        sw=0;
        for(int j=i+1;j<len;j++){
            if(arr[j]<arr[j-1]){
                int temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
                sw++;
            }
            comparison++;
        }
        if(!sw) return;
        swa+=sw;
    }
}
int main(){
    cin>>len;
    for(int i=0;i<len;i++){
        cin>>arr[i];
    }
    bubble();
    cout<<comparison<<" "<<swa<<endl;
    return 0;
}
*/
/*
#include<iostream>
#include<string>
using namespace std;
typedef struct Node{
    int val;
    struct Node *prev, *next;
}Node;
int main(){
    int testcase;
    cin>>testcase;
    while(testcase--){
        Node *head = new Node;
        head->val = 0;
        head->next = head;
        head->prev = head;
        int n;
        cin>>n;
        Node *now = head;
        for(int i=1;i<=n;i++){
            char c;
            cin>>c;
            Node *cur = new Node;
            cur->val = i;
            if(c=='L'){
                cur->next = now;
                cur->prev = now->prev;
                cur->prev->next = cur;
                cur->next->prev = cur;
                if(now==head) head=cur;
            }
            else{
                cur->prev = now;
                cur->next = now->next;
                cur->next->prev = cur;
                cur->prev->next = cur;
            }
            now = cur;
        }
        head->prev->next=NULL;
        while(head){
            cout<<head->val<<" ";
            Node *tp = head;
            head = head->next;
            delete tp;
        }
        cout<<"\n";
    }
    return 0;
}
*/
/*
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
long long arr[10005]={};
int len;
void bubble(){
    int le = len;
    for(int i=0;i<le;le--){
        for(int j=i+1;j<le;j++){
            if(arr[j]<arr[j-1]){
                int temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
            }
        }
    }
}
int main(){
    cin>>len;
    for(int i=0;i<len;i++){
        cin>>arr[i];
    }
    bubble();
    long long sum=0;
    for(int i=1;i<len;i++){
        arr[i]+=arr[i-1];
        arr[i-1]=0;
        sum+=arr[i];
        int j=i+1;
        while(arr[j]<arr[j-1]&&j<len){
            long long temp=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
            j++;
        }
    }
    cout<<sum;
    return 0;
}
*/
/*
#include <iostream>
#include <string>

typedef struct _Card{
    int num;
    struct _Card *nxt, *prv;
} Card;

Card* Construct(int n){
    Card *head = new Card;
    Card *temp = head;
    for(int i=1;i<=n;i++){
        int number;
        std::cin>>number;
        Card *now = new Card;
        now->num = number;
        now->nxt =NULL;
        temp->nxt = now;
        temp = now;
    }
    return head;
}

void cut(int a, int b, Card* head){
    Card *temp = head, *mid, *H, *T;
    while(a--){
        temp = temp->nxt;
    }
    mid = temp;
    H = temp->nxt;
    while(b--){
        temp = temp->nxt;
    }
    T = temp;
    mid->nxt = T->nxt;
    T->nxt = head->nxt;
    head->nxt = H;
}

void add(int idx, int num, Card* head){
    Card *temp = head;
    while(idx--){
        temp = temp->nxt;
    }
    Card *now = new Card;
    now->num = num;
    now->nxt = temp->nxt;
    temp->nxt = now;
}

void print(Card* head){
    Card *temp = head->nxt;
    while(temp){
        std::cout<<temp->num<<std::endl;
        temp = temp->nxt;
    }
}

using namespace std;

void Destruct(Card* head){
    Card* cur = head,*tmp;
    while(cur){
        tmp = cur->nxt;
        delete cur;
        cur = tmp;
    }
    return ;
}

int main(){

    string command;
    int n, m;

    cin >> n >> m;
    Card* head = Construct(n);

    int a, b, idx, num;
    while(m--){
        cin >> command;
        if(command == "CUT"){
            cin >> a >> b;
            cut(a,b,head);
        }
        else{
            cin >> idx >> num;
            add(idx,num,head);
        }
    }
    print(head);
    Destruct(head);
    return 0;
}
*/
/*
#include <iostream>
#include <string>

int solve(std::string &text){
    typedef struct Node{
        int idx;
        struct Node *next;
    }Node;
    Node *alp[26];
    Node *back[26];
    int number[26]={};
    for(int i=0;i<26;i++){
        alp[i] = new Node;
        alp[i]->next = NULL;
        back[i] = alp[i];
    }
    for(int i=0;i<text.size();i++){
        Node *now = new Node;
        now->idx = i;
        now->next = NULL;
        back[text[i]-'a']->next = now;
        back[text[i]-'a'] = now;
        number[text[i]-'a']++;
    }

    int cnt1, cnt2, max, res=1;
    for(int i=0;i<26;i++){
        cnt1 = 1, cnt2 = 0, max = 0;
        if(!alp[i]->next||!alp[i]->next->next) continue;
        Node *bac = alp[i]->next, *fro = bac->next;
        while(fro){
            if(fro->idx==bac->idx+1) cnt1++;
            else{
                cnt2 = fro->idx==bac->idx+2 ? cnt1 : 0;
                cnt1 = 1; 
            }
            max = cnt1+cnt2>max ? cnt1+cnt2 : max;
            fro = fro->next;
            bac = bac->next;
        }
        res = max+(number[i]>max)>res ? max+(number[i]>max) : res ;
    }
    return res;
}

using namespace std;

int main() {
    string text;
    cin >> text;

    cout << solve(text) << endl;

    return 0;
}
*/
#include<iostream>
using namespace std;
#define ll long long
#define N 200005
typedef struct Node{
    int idx;
    ll weight;
    struct Node *next;
}Node;

int n;
int oloo[N];
Node *road[N];
int been[N];
ll ans;

void prepare(){
    ans = 0;
    for(int i=0;i<n;i++){
        oloo[i] = 0;
        road[i] = new Node;
        road[i]->next = NULL;
        been[i] = 0;
    }
}

void addnode(int a, int b, ll w){
    Node *now = new Node;
    now->idx = b;
    now->weight = w;
    now->next = road[a]->next;
    road[a]->next = now;
}

ll dfs(int now, ll weight){
    been[now] = 1;
    ll num = oloo[now];
    if(!road[now]->next->next&&been[road[now]->next->idx]){
        ans+=(num>0?num:-num)*weight;
        return num;
    }
    Node *temp = road[now]->next;
    while(temp){
        if(!been[temp->idx]){
            num += dfs(temp->idx, temp->weight);
        }
        temp = temp->next;
    }
    ans += (num>0?num:-num)*weight;
    return num;
}

void freenode(){
    for(int i=0;i<n;i++){
        Node *temp = road[i];
        while(temp->next){
            Node *tp = temp->next;
            temp->next = temp->next->next;
            free(tp);
        }
        free(temp);
    }
}

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--){
        ll sum = 0;
        cin>>n;
        prepare();
        for(int i=0;i<n;i++){
            cin>>oloo[i];
            sum += oloo[i];
        }
        if(sum%n){
            for(int i=0;i<n-1;i++){
                int a, b;
                ll w;
                cin>>a>>b>>w;
            }
            freenode();
            printf("-1\n");
            continue;
        }
        for(int i=0;i<n-1;i++){
            int a, b;
            ll w;
            cin>>a>>b>>w;
            addnode(a, b, w);
            addnode(b, a, w);
        }
        ll avg = sum/n;
        for(int i=0;i<n;i++){
            oloo[i] -= avg;
        }
        dfs(0, 0);
        cout<<ans<<endl;
        freenode();
    }
    return 0;
}