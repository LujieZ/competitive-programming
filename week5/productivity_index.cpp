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

int probs[200000];

float helper(int i, int j, int k){
    if (i == k){
        if (j == 0) {
            return 0;
        } return pow(j, j/k);
    }
    return probs[i-1] * helper(i+1, j+1, k) + (1-probs[i-1]) * helper(i+1, j, k);
}

int main(){
    int n;
    cin >> n;   
    cin.ignore();
    string probs;
    getline(cin, probs);
    stringstream stream(probs);
    string prob_str;
    int prob;
    int i=0;
    while(getline(stream, prob_str, ' ')) {
        prob = stoi(prob_str);
        probs[++i] = prob;
    }
    std::sort(std::begin(probs), std::end(probs), greater());
    float max_prob = 0;
    for (int k=1;k<=n;k++){
        max_prob = max(max_prob, helper(0, 0, k)); 
    }
    printf("%.9f", max_prob);
    return 0;
}