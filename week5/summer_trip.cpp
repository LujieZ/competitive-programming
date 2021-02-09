#include <algorithm> 
#include <cstdio>
#include <cstring>
#include <stdio.h>
#include <math.h>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <sstream>
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
    string s;
    getline(cin, s);
    int n = s.size();
    int count = 0;
    int i;
    bool flag;
    for (int a=0;a<n-1;a++){
        i = a+1;
        flag = true;
        map<char, int> m;
        m.insert({s[a], 1});
        while (i<n && flag){
            if (s[a] == s[i]){
                flag = false;
            }
            if (m.find(s[i]) == m.end()){
                m.insert({s[i], 1});
                count++;
            }
            ++i;
        }
    }
    printf("%d", count);
    return 0;
}