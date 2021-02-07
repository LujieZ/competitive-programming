// Chapter 4. Graph
// Jan 29, 2021

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <cstdio>

#include <sstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <tuple>
using namespace std;

// type and functions defs
#define sci(n) scanf("%d",&n)
#define scl(n) scanf("%lld",&n)
#define scf(n) scanf("%f",&n)
#define scd(n) scanf("%lf",&n)
#define scs(s) scanf("%s",&s)
#define sc1(a) scanf("%lld",&a)             // Take one ll inputs
#define sc2(a,b) scanf("%lld %lld",&a,&b)   // Take two ll inputs
#define pf(a) printf("%.10f\n",a)
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

// Problem A - Circuit Math
// n: Number of labels (A, B, C, D...)
// i: Number of index for label
// word, line: Instant place holder for input string
// labels: All label that are stored
// res: Current result of the circuit
int circuit_math() {
    int n;
    int i = 0;
    string word, line, labels[250];
    vector<bool> res;
    cin >> n;   // get an int input for number of labels.
    cin.ignore();
    bool assignment[n];
    getline(cin, line);
    stringstream stream(line);
    while(getline(stream, word, ' ')) {
        if(word == "T") {
            assignment[i] = true;   // ith label is true.
        } else {
            assignment[i] = false;  // ith label is false.
        }
        i++;
    }
    
    i = 0;
    getline(cin, line);
    stringstream another_stream(line);
    while(getline(another_stream, word, ' ')) {
        if(isalpha(word[0])) {
            res.push_back(assignment[i]);
            cout << assignment[i] << ' ';
            i++;
        } else {
            bool res1 = res.back();
            res.pop_back();
            if(word[0] == '*') {
                bool res2 = res.back();
                res.back() = res2 && res1;
            } else if (word[0] == '+') {
                bool res2 = res.back();
                res.back() = res2 || res1;
            } else {
                bool res2 = !res1;
                res.push_back(res2);
            }
        }
    }
    cout << res.back() << endl;
    return 0;
}

// Problem B - Diagonal Cut
// Input: M N (M x N represents the # of rectangular grids of chocolate blocks)
// Ouput: the number of blocks of the chocolate bar that are diagonally cut.
void diagonal_cut() {
    int M, N, res;
    scanf("%d %d", M, N);
    
}

// Problem C - Gerry Mandering
// P: the number of voting precincts
// D: the number of voting districts
// d: the district that the precinct is assigned
// a: vote for party A
// b: vote for party B
void gerrymandering() {
    int P, D = 1;
    double totalV = 0, aWaste = 0, bWaste = 0;
    int d, a, b;
    scanf("%d %d", &P, &D);
    int res[1000][2]{}; // Initilize all elements of the array to zero.
    int i = 0;
    while(i < P) {
        scanf("%d %d %d", &d, &a, &b);
        res[d-1][0] += a;
        res[d-1][1] += b;
        totalV += a + b;
        ++i;
    }
    int j;
    double waste0, waste1;
    for(j = 0; j < D; ++j) {
        int majority = floor((res[j][0] + res[j][1])/2) + 1;
        if (res[j][0] >= majority) {
            waste0 = res[j][0]-majority;
            waste1 = res[j][1];
            cout << "A " << waste0 << ' ' << waste1 << endl;
        } else {
            waste0 = res[j][0];
            waste1 = res[j][1]-majority;
            cout << "B " << waste0 << ' ' << waste1 << endl;
        }
        aWaste += waste0;
        bWaste += waste1;
    }
    if(!totalV) {
        cout << "0.0000000000" << endl;
    } else {
        double E = abs(aWaste - bWaste)/totalV;
        pf(E);
    }
}

// Problem D - Missing Number
// n: total number of numbers given
// num: current number that has been read
// i: currnet number that should be printed
void missing_numbers() {
    int n, num, i = 1;
    VI missing;
    scanf("%d", &n);
    while(n--) {
        scanf("%d", &num);
        while(num > i) {
            missing.push_back(i);
            ++i;
        }
        ++i;
    }
    if(missing.size()) {
        for(auto &&m : missing) {
            cout << m << endl;
        }
    } else {
        cout << "good job" << endl;
    }
}

// Problem E
void NVWLS() {

}

// Problem F
void prospecting() {
    
}

int main(int argc, const char * argv[]) {
    // circuit_math();
    gerrymandering();
    // missing_numbers();
    return 0;
}
