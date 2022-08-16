#include <bits/stdc++.h>
using namespace std;
bool isSafe(int v,bool graph[101][101],int color[101],int c,int V){
    for(int i=0;i<V;i++){
      if(graph[v][i] and c==color[i]) return false;
    }
    return true;
}
bool wrapper(bool graph[101][101],int m,int color[101],int v,int V){
  if(v==V) return true;
  for(int c=1;c<=m;c++){
    if(isSafe(v,graph,color,c,V){
      color[v] = c;
      if(wrapper(graph,m,color,v + 1,V)){
        return true;
      }
      color[v] = 0;
    }
  }
       return false;
}
bool graphColoring(bool graph[101][101], int m, int n) {
    int *color = new int[n];
    for (int i = 0; i < n; i++) color[i] = 0;

    // checking if colours can be assigned.
    if (graphColoringUtil(graph, m, color, 0, n) == false) {
        return false;
    }

    return true;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  
