#include <cstdio>
#include <cstring>
#include <stdio.h>
#include <math.h>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

// type and functions defs
#define sci(n) scanf("%d",&n)
#define scl(n) scanf("%lld",&n)
#define scf(n) scanf("%f",&n)
#define scd(n) scanf("%lf",&n)
#define scs(s) scanf("%s",&s)
#define sc1(a) scanf("%lld",&a)             // Take one ll inputs
#define sc2(a,b) scanf("%lld %lld",&a,&b)   // Take two ll inputs
#define pf1(a) printf("%lld\n",a)           // Print one ll output
#define pf2(a,b) printf("%lld %lld\n",a,b)  // Print two ll outputs
#define PB push_back
#define PI acos(-1.0)
#define EPS 1e-10
#define MX 10000007
#define MOD 10000007
#define SQR(x) ((x)*(x))
#define ORDER(x) sort(x.begin(), x.end())
#define MAXV 2000                           // For come and go problem
#define MAXR 10010                          // For racing problem
typedef long long ll;                       // typedef for ll
typedef double DB;
typedef double LD;
typedef pair<int, int> II;
typedef vector<int> VI;
typedef vector<II> VII;

#define  DFS_WHITE -1
#define  DFS_BLACK 1

vector<VI> graph;
VI dfs_num;
void readGraph(){
    string edge;
    int node1, node2;
    getline(cin, edge);

    while (getline(cin, edge)){
        if (edge.size() == 0) break;
        node1 = edge[0] - 65;
        node2 = edge[1] - 65;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1); // mutual connectivity
    }
}

void dfs(int node){
    dfs_num[node] = DFS_BLACK; // visited
    for (int c=0;c<graph[node].size();c++){
        if (dfs_num[graph[node][c]]== DFS_WHITE){ // unvisited
            dfs(graph[node][c]);
        }
    }
}

int main(){
    string nodes;
    int casos, CC, flag = 0; // CC = # of SCC
    scanf("%d", &casos); // # of vertices
    for (int x=0;x<casos;x++){
        cin >> nodes;
        graph.assign(nodes[0]-64, VI()); // graph[nodes[0]-64] = empty VI
        dfs_num.assign(nodes[0]-64, DFS_WHITE); // unvisited
    }
    readGraph();
    CC = 0;
    for (int z=0;z<dfs_num.size();z++){
        if (dfs_num[z] == DFS_WHITE){
            dfs(z);
            CC++;
        }
    }
    if (flag == 0) flag++;
    else printf("\n");
    printf("%d\n", CC);
    return 0;
}