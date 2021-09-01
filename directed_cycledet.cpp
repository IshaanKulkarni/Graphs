// C++ program to detect cycles in a directed graph: We use the fact that topological sort can only be generated for DAG. 

#include<bits/stdc++.h>
using namespace std;
vector<int>v[100000];
int indegree[100000]={0};

bool isCycle(int n){
    queue<int>q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    int count=0;
    while(!q.empty()){
        int current=q.front();
        q.pop();
        count++;
        for(auto x:v[current]){
            indegree[x]--;
            if(indegree[x]==0){
                q.push(x);
            }
        }
    }

    if(count==n){
        return false;
    }
    return true;
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

    bool q=isCycle(n);
    if(q==true){
        cout<<"Given is a cyclic directed graph!"<<endl;
    }
    else{
        cout<<"Given is an acyclic directed graph!"<<endl;
    }
}