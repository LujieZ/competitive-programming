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

map<string, string> m;
vector<string> final_combi;

vector<string> helper(string message){
    if (message == ""){
        vector<string> combi;
        return combi;
    }
    string final_word;
    int max_num_vowels = 0;
    int num_vowels;
    vector<string> max_combi;
    vector<string> prev_combi;
    for (int l = 1; l<=sizeof(message); l++){
        string sub_message = message.substr(0, l);
        num_vowels = 0;
        if (m.find(sub_message) != m.end()){ // key present in the map
            if (l==sizeof(message)){
                prev_combi = helper("");
            } else {
                prev_combi = helper(message.substr(l));
            }

            for (int i = 0; i<= sizeof(prev_combi); i++){
                num_vowels += sizeof(m[prev_combi[i]]) - sizeof(prev_combi[i]);
            }
            num_vowels = sizeof(m[sub_message]) - sizeof(sub_message);
            if (num_vowels > max_num_vowels){
                final_word = sub_message;
                max_num_vowels = num_vowels;
                max_combi = prev_combi;
            }
        }; 
    }
    max_combi.push_back(final_word); // push the word w/o vowels to max_combi
    return max_combi;
}

int main(){
    int count = 0;
    scanf("%d", &count); // count
    getchar();
    char s[50], t[50]; // t is the word without vowels
    int c, d = 0;
    while (count --){
        scanf("%s", &s);
        for(c = 0; s[c] != '\0'; c++) {
            // check for If not a vowel
            if (!(s[c] == 'A' || s[c] == 'E' || s[c] == 'I' || s[c] == 'O' || s[c] == 'U')){
                t[d] = s[c];
                d++;
            }
        }
        t[d] = '\0';
        m.insert(t,s);
        getchar();
    }
    string ss;
    scanf("%s", &ss);
    vector<string> combi = helper(ss);
    for (int j=0;j<sizeof(combi);j++){
        printf("%s ", m[combi[j]]);
    }
    return 0;
}
