import java.util.*;
public class Graph
{
    int V;
    LinkedList<Integer> adj[];
    Graph(int v)
    {
        V=v;
        adj=new LinkedList[v];
        for(int i=0;i<v;i++)
            adj[i]=new LinkedList();
    }
    void addEdge(int v,int w)
    {
        adj[v].add(w);
    }
}
