#include <stdio.h>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int main() {
    int n, m, cases = 0, x, y, tn, i;
    char cmd[105], name[105][105];
    while(scanf("%d", &n) == 1) {
        map<string, int> R; // name to index
        vector<int> g[105];
        int indeg[105] = {};
        for(i = 0; i < n; i++) {
            scanf("%s", name[i]);
            R[name[i]] = i;
        }
        scanf("%d", &m);
        while(m--) { // IMPORTANT
            scanf("%s", cmd);
            x = R[cmd];
            scanf("%s", cmd);
            y = R[cmd];
            g[x].push_back(y); // y greater than x
            indeg[y]++; // rank one higher
        }
        priority_queue<int, vector<int>, greater<int> > Q; // based on 
        for(i = 0; i < n; i++)
            if(indeg[i] == 0) // lowest rank/alcohol content
                Q.push(i);
        printf("Case #%d: Dilbert should drink beverages in this order:", ++cases);
        while(!Q.empty()) {
            tn = Q.top();
            Q.pop();
            for(vector<int>::iterator it = g[tn].begin();
                it != g[tn].end(); it++) {
                indeg[*it]--; // one rank lower
                if(indeg[*it] == 0)
                    Q.push(*it);
            }
            printf(" %s", name[tn]);
        }
        puts(".\n");
    }
    return 0;
}