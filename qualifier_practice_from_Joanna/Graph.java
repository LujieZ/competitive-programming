import java.math.BigInteger;
import java.util.*;

// question D

public class Graph {
    private int V;
    private int[][] adjListArray;

    public Graph(int V)
    {
        this.V = V;
        this.adjListArray = new int[V][V];
    }

    // Adds an edge to an undirected graph
    public void addEdge(int src, int dest)
    {
        this.adjListArray[src][dest] = 1;
        this.adjListArray[dest][src] = 1;
    }

    public void DFSUtil(int v, boolean[] visited)
    {
        visited[v] = true;
        for (int i=0;i<this.V;i++){
            if (!visited[i] && adjListArray[v][i]==1){
                DFSUtil(i, visited);
            }
        }
    }

    // Driver code
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        for (int i=1;i<=N;i++){
            sc.next();
            int num_intersection = sc.nextInt();
            Graph g = new Graph(num_intersection);

            int firstline[] = new int[num_intersection];
            int secondline[] = new int[num_intersection];
            for (int p=0;p<num_intersection;p++) firstline[p] = sc.nextInt();
            for (int p=0;p<num_intersection;p++) secondline[p] = sc.nextInt();

            for (int k=0;k<num_intersection;k++){
                if (firstline[k] != secondline[k]) {
                    g.addEdge(firstline[k], secondline[k]);
                }
            }
            // add graph edges

            int count = 0;
            boolean[] visited = new boolean[num_intersection];
            int v = 0;
            int flag = 1;
            while(v < num_intersection && flag == 1) {
                if (!visited[v]) {
                    if (count == 0){
                        g.DFSUtil(v, visited);
                        count++;
                    } else {
                        System.out.println(i + " NO");
                        flag = 0;
                    }
                }
                v++;
            }
            if (flag == 1) System.out.println(i + " YES");
        }
    }
}