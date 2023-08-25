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
void makeAdj(vvi& list,int m){
    // Building the adjacency list 
    for (int i=0;i<m;i++){
        int p,q;cin >>p>>q;
        list[p].push_back(q);
        list[q].push_back(p);
    }
}
void dfs(vvi& list,int start,int n, vi& vis){
    int flag =1;
    for (int i=start;flag or i<start;i++){
        if (i==n){i=0;flag=0;}
        if (!vis[i]){
            stack<int> st;st.push(i);
            while (!st.empty()){
                int temp = st.top();
                st.pop();
                if (!vis[temp]){cout << temp<<" ";vis[temp] = true;}
                for (auto j:list[temp]){if (!vis[j])st.push(j);}
            }
        }
    }
}
void print(vvi& list){
    for (auto i:list){
        for (auto j:i)cout <<j<<" ";
        cout <<endl;
    }
}
void dfsRecursive(vvi &list,int curr,vi& vis){
    vis[curr] = 1;
    cout <<curr<<" ";
    //ans.push_back(curr);
    for (auto i:list[curr]){
        if (!vis[i])dfsRecursive(list,i,vis);
    }
}
int main(){
    fast;
    int n,m;cin>>n>>m;
    vvi list(n);
    makeAdj(list,m);
    vi vis(n,0);
    //taking the starting point of traversal as input 
    read(start);
    //print(list);
    for (int i=0;i<n;i++){
        if (!vis[i])dfsRecursive(list,i,vis);
    }
    //cout <<start;
    return 0;
}