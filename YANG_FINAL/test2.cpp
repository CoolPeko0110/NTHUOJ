#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;
int main(){
	//ios::sync_with_stdio ( false ); cin.tie(0); cout.tie(0);
    int T; cin>>T;
    while(T--){
        map<vector<int>, int> D;
        queue<vector<int>> Q;   
        int x;
        int flag = 1;
        vector<int> st, ed;
        for ( int i=0; i<9; ++i ){
            cin >> x;
            st.emplace_back(x);
        }
        for ( int i=0; i<9; ++i ){
            x = (i+1)%9;
            ed.emplace_back(x);
        }
        D[st] = 1;
        Q.push(st);
        
        while ( !Q.empty() ){
            vector<int> x = Q.front();
            int pos = 0, curd = D[x];
            if(curd>14){flag = 0; break;}
            Q.pop();
            while ( x[pos] ) pos++;
            if ( pos >= 3 ) {
                swap(x[pos], x[pos-3]);
                if ( !D[x] ) {D[x] = curd+1; Q.push(x);}
                if ( x == ed ) break;
                swap(x[pos], x[pos-3]);
            }
            if ( pos <= 5 ) {
                swap(x[pos], x[pos+3]);
                if ( !D[x] ) {D[x] = curd+1; Q.push(x);}
                if ( x == ed ) break;
                swap(x[pos], x[pos+3]);
            }
            if ( pos%3 ) {
                swap(x[pos], x[pos-1]);
                if ( !D[x] ) {D[x] = curd+1; Q.push(x);}
                if ( x == ed ) break;
                swap(x[pos], x[pos-1]);
            }
            if ( pos%3!=2 ) {
                swap(x[pos], x[pos+1]);
                if ( !D[x] ) {D[x] = curd+1; Q.push(x);}
                if ( x == ed ) break;
                swap(x[pos], x[pos+1]);
            }
        }
        if(!flag) cout<<"You'd better skip this game.\n";
        else cout<<"You can solve it within "<<D[ed]-1<<" steps.\n";
    }
	return 0;
}