#include<iostream>
#include<queue>
using namespace std;

int n, m, a, b, visited[101][101];
string arr[101];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int main(void) {
   
   for(int i=0;i<=100;i++){
      for(int j=0;j<=100;j++){
         visited[i][j]=-1;   
      }
   }
   cin>>n>>m;
   for(int i=0;i<n;i++){
      cin>>arr[i];
   }
   visited[0][0]=0;
   queue<pair<int,int>> q;
   q.push({0,0});
   
   while(!q.empty()){
      int cx = q.front().first;
      int cy = q.front().second;
      q.pop();
      
      if(cx == m-1 && cy==n-1){
         cout<<visited[n-1][m-1] + 1;
         break;
      }
      
      for(int i=0;i<4;i++){
         int nx = cx + dx[i];
         int ny = cy + dy[i];
         
         if(nx<0 || ny<0 || nx>=m || ny>=n || visited[ny][nx]!=-1 || arr[ny][nx]=='0') continue;
         
         q.push({nx,ny});
         visited[ny][nx] = visited[cy][cx] + 1;
      }
   }
   
   return 0;
}