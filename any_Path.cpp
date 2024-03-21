#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>

using namespace std;


int v;
vector<list<int>> graph;
unordered_set<int> visited;

void addEdge(int src , int dest  , bool bi_dir = true){

        graph[src].push_back(dest);

        if(bi_dir){
            graph[dest].push_back(src);
        }
}

void display(){

    for(int i = 0 ; i<graph.size();i++){
        cout<<i<<"->";
        for(auto ele : graph[i]){
            cout<<ele<<" , ";
        }
        cout<<"\n";
    }
}

bool dfs(int curr , int end){

    if(curr == end) return true;
    visited.insert(curr);

    for(auto neighbour : graph[curr]){
        if(not visited.count(neighbour) ){
            bool result = dfs(neighbour, end);
            if(result) return true;
        }
    }
    return false;
}

bool anyPath(int src , int dest){
    return dfs(src,dest);
}
int main(){
    cin>>v;
    graph.resize(v, list<int>());
    int e;
    cin>>e;
    visited.clear();
    while(e--){
        int s,d;
        cin>>s>>d;
        addEdge(s,d,false);
    }
    display();
    

    int x,y;
    cin>>x>>y;
    bool ans = anyPath(x,y);
    cout<<ans;
}

