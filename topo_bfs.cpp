// Algorithm to implement Toposort using BFS. Also popularly known as Kahn's Algorithm.
// The visited array is prettymuch useless here as all work is being done on indegrees. We start with nodes having indegrees of 0 by pushing them into the queue.
// We visit their neighbours and decrement their indegree by one.
// If the indegree becomes 0, we push them into the queue and the process repeats till the queue is empty!
#include<bits/stdc++.h>
using namespace std;
vector<int>v[100000];
int visited[100000]={0};
int indegree[100000]={0};
void toposort(int n){
    queue<int>q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            // visited[i]=1;
            q.push(i);
        }
        while(!q.empty()){
            int current=q.front();
            q.pop();
            cout<<current<<" ";
            for(auto x:v[current]){
                indegree[x]--;
                // visited[i]=1;
                if(indegree[x]==0){
                    q.push(x);
                }
            }
     
        }
    }
} 
int main(){
    int n,e;
    cin>>n>>e;
    while(e--){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        indegree[y]++;
    }
    toposort(n);

}