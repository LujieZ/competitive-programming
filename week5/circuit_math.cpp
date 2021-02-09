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

int main(){
     int t,c = 0;
     char ch;
     scanf("%d", &t); // # of cases
     getchar();
     bool visit[t];
     while(t--){
        ch = getchar();
        bool boo = ch == 'T'? true : false;
        visit[c] = boo;
        c++;
        getchar();
     }
    getchar();
    // circuit description
    vector<bool> q;
    int cur = 0;
    ch = getchar();
    while (ch != ' '){
        if (isalpha(ch)){
            int ch_ind = c - 'A';
            bool ch_bool = visit[ch_ind];
            q.push_back(ch_bool);
            cur++;
        } else {
            if (ch == '*'){
                bool result = q.at(sizeof(q)-1) & q.at(sizeof(q)-2);
                q.pop_back();
                q.pop_back();
                q.push_back(result);
            }
            else if (ch == '+'){
                bool result = q.at(sizeof(q)-1) | q.at(sizeof(q)-2);
                q.pop_back();
                q.pop_back();
                q.push_back(result);
            }
            else{
                bool result = !(q.at(sizeof(q)-1));
                q.pop_back();
                q.push_back(result);
            }
        }
        ch = getchar(); // getline() instead
    }
    char result = q.back() == true? 'T':'F';
    printf("%s", result);
    return 0;
 }