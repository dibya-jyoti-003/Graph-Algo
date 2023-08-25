#include<iostream>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);init_code();
#include<bits/stdc++.h>
#define ll long long 
#define read(x) int x;cin>>x;
#define vi vector<int>
#define vvi vector<vi>
#define sort(arr) sort(arr.begin(),arr.end());
using namespace std;
void init_code(){
    #ifndef ONLINE_JUDGE
    freopen("inputf.txt","r",stdin);
    freopen("outputf.txt","w",stdout);
    #endif
}
void bfs(vvi& list,vi& vis,int start,int n){
    for (int i=start; i+1 != start;i++){
        if (!vis[i]){
            queue<int> q;
            q.push(i);
            vis[i] =true;
            while (!q.empty()){
                int f= q.front();
                cout <<f<<" ";
                q.pop();
                for (auto k:list[f]){if (!vis[k]){q.push(k);vis[k] = true;}}
            }
        }
        if (i>n)i=1;
    }
}
void print(vvi& list){
    for (auto i:list){
        for (auto j:i)cout <<j<<" ";
        cout <<endl;
    }
}
int main(){
    fast;
    int n,m;cin>>n>>m;
    vvi list(n+1);
    for (int i=0;i<m;i++){
        int p,q;cin >>p>>q;
        list[p].push_back(q);
        list[q].push_back(p);
    }
    vi vis(n+1,0);
    read(start);
    bfs(list,vis,start,n);
    return 0;
}