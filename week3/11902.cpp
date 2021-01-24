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

// KEY IDEA: The principle is that if the traversal situation after 
// removing a certain point is the same as that of point 0, 
// it means that the situation can be reached without passing through the point, 
// and there are other paths. Only different situations are considered unique paths.

int g[110][110]; // g[i][j] denotes if vertex i and j are connected through an edge
int visit[110][110]; // visit[i][j], blocking i, can reach j or not (1/0)
int book[110];
int n;

 void dfs(int x){
     book[x] = 1;
     for (int i=0;i<n;i++){
         if (book[i] == 0 && g[x][i] == 1) 
            dfs(i);
     }
 }

 int main(){
     int t,c = 1;
     scanf("%d", &t); // # of cases
     while(t--){
        scanf("%d", &n); // # of vertices
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                scanf("%d", &g[i][j]);
        for (int i=0;i<n;i++){
            memset(book, 0, sizeof(book)); // copies a single character for a specified number of time to an object.
            book[i] = -1; // temporarily remove this point
            dfs(0);
            book[i] = 0; // set the value 0 back
            for (int j=0;j<n;j++){
                visit[i][j] = book[j];
            }
        }
        for (int i=1;i<n;i++){
            for (int j=0;j<n;j++){
                visit[i][j] ^= visit[0][j]; // XOR, only when two values are different can we conclude that i is j's denominator
            }
        }
        printf("case %d:\n", c++);
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                printf("%c", visit[i][j]);
            }
        }
     }
 }