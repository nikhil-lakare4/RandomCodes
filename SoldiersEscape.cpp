#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

struct soldier{
    int x, y;
};

int main(){
    int l, w, n;
    queue<int> Q; //for bfs
    cin >> l >> w >> n;
    soldier s[n];
    int G[n+2][n+2]; //2 extra vertices for north wall and south wall
    for(int i = 0; i < n+2; i++){
        for(int j = 0; j < n+2; j++){
            G[i][j] = 0;
        }
    }
    for(int i = 0; i < n; i++){
        cin >> s[i].x >> s[i].y;
    }
    for(int i = 0; i < n; i++){
      	//if vertex overlaps with north wall
    	if(s[i].y+100>= w){  
    		G[0][i+1] = 1;
    		G[i+1][0] = 1;
    	}
      	//if vertex overlaps with south wall
    	if(s[i].y-100 <= 0){
    		G[n+2-1][i+1] = 1;
    		G[i+1][n+2-1] = 1;
    	}
        for(int j = 1; j < n; j++){
          	//two vertices overlaps with their ranges if distance between them is at most 200
            int d = sqrt(pow((s[i].x - s[j].x), 2)+pow((s[i].y - s[j].y), 2));
            if(d <= 200){
            	G[i+1][j+1] = 1;
            	G[j+1][i+1] = 1;
            }
        }
    }
//    for(int i = 0; i < n+2; i++){
//    	for(int j = 0; j < n+2; j++){
//    		cout << G[i][j] << " ";
//    	}
//    	cout << endl << endl;
//    }
    int visited[n+2];
    for(int i = 0; i < n+2; i++){
        visited[i] = 0;
    }
    //BFS to find out whether north wall vertex is connected to south wall vertex
    Q.push(0);
    visited[0] = 1;
    while(!Q.empty()){
        int top = Q.front();
        Q.pop();
        for (int i = 0; i < n+2; ++i){
            if(G[top][i] != 0 && (!visited[i])){
                Q.push(i);
                visited[i] = 1;
            }
        }
    }
//    for(int i = 0; i < n+2; i++){
//    	cout << visited[i] << " ";
//    }
//    cout << endl;
    if(visited[n+2-1] == 1)
        cout << 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}
