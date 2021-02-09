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
     int p,d = 0;
     char ch;
     scanf("%d %d", &p, &d); // count
     getchar();
     int district, voteA, voteB;
     VII vote_count(d, make_pair(0,0));
     int total_vote = 0;
     while(p--){
        scanf("%d %d %d", &district, &voteA, &voteB);
        vote_count[district-1].first += voteA;
        vote_count[district-1].second += voteB;
        total_vote += voteA + voteB;
        getchar();
     }
     int waste_A, waste_B;
     int total_wasteA, total_wasteB;
     for (int i=0;i<d;i++){
         int standard = (vote_count[i].first + vote_count[i].second) / 2 + 1;
         if (vote_count[i].first > vote_count[i].second){
             waste_A = vote_count[i].first - standard;
             waste_B = vote_count[i].second;
             printf("A %d %d\n", waste_A, waste_B);
         } else {
             waste_A = vote_count[i].first;
             waste_B = vote_count[i].second - standard;
             printf("B %d %d\n", waste_A, waste_B);
         } // what if there's a tie????
        total_wasteA += waste_A;
        total_wasteB += waste_B;
     }
    printf("%.10f\n", abs(total_wasteA - total_wasteB) / total_vote);
    return 0;
 }