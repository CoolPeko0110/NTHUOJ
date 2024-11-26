#include <iostream>
#include <deque>
using namespace std;

struct Node{int x, y;};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, D; cin >> N >> D;

    Node point[N+1];

    int minimum = INT32_MAX;
    deque<Node> coordinate;
    for(int i=0;i<N;++i){
        cin >> point[i].x >> point[i].y;
        while(!coordinate.empty() && point[i].x <= coordinate.back().x) coordinate.pop_back();//Remove the point that has x larger than the current point's x. because we move up to find appropriate point for this point, that point we want to remove will not be optimal answer for us. (the length will definitely longer than the added point) 
        coordinate.push_back(point[i]);
        while(!coordinate.empty() && point[i].x - coordinate.front().x >= D){
            minimum = min(minimum, point[i].y - coordinate.front().y);
            coordinate.pop_front(); //has find the optimal answer for this point => remove it 
        }
    }

    coordinate.clear();
    for(int i=N-1;i>=0;--i){
        while(!coordinate.empty() && point[i].x <= coordinate.back().x) coordinate.pop_back(); 
        coordinate.push_back(point[i]);
        while(!coordinate.empty() && point[i].x - coordinate.front().x >= D){
            minimum = min(minimum, coordinate.front().y - point[i].y);
            coordinate.pop_front();
        }
    }
	switch(minimum){
		case INT32_MAX: cout << "-1\n";
			break;
		default: cout << minimum << "\n";
			break;
	}
    return 0;
}