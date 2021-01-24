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

// 给你一个矩阵和某些点，找到给的点所处连续的W区域的面积s（八个方向）。

char maps[111][111];
char used[111][111];

int dxy[8][2] = {-1, -1, -1, 0, -1, 1, 0, -1, 0, 1, 1, -1, 1, 0, 1, 1};

int dfs(int x, int y, int n, int m){ // n is x's boundary, m is y's boundary
    if (x < 0 || x >= n || y < 0 || y >= m) return 0; // exceed boundary
    if (maps[x][y] != 'W' || used[x][y]) return 0; // not W or visited
    used[x][y] = 1;
    int sum = 1;
    for (int i=0; i < 8;i++){
        sum += dfs(x+dxy[i][0], y+dxy[i][1], n,m);
    }
    return sum;
}

int main(){
    int T,x,y,temp;
    scanf("%d", &T); // number of cases
    getchar();
    for (int t=1;t<=T;t++){
        temp = getchar();
        while (temp != 'W' && temp != 'L') // to get rid of the empty space between num and LW's
            temp = getchar();
        int count = 0;
        while (temp == 'W' || temp == 'L'){ // LW's
            ungetc(temp, stdin);
            gets(maps[count ++]);
            temp = getchar();
        }
        int length = strlen(maps[0]);
        while (temp >= '0' && temp <= '9'){ // starting positions of W's
            ungetc(temp, stdin);
			scanf("%d%d",&x,&y);
            getchar();
			memset(used, 0, sizeof(used)); // refresh used 
			printf("%d\n",dfs(x-1, y-1, count, length));
			temp = getchar(); // scan the next line
        }
        if (t < T) printf("\n"); // start a new line
    }
    return 0;
}

