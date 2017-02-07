import java.util.*;
public class dfs 
{
    Scanner sc=new Scanner(System.in);
    int V,timea[],timed[],t=0,parent[],m=0,h=0;
    String treeedge[],backedge[];
    char color[];
    Graph g;
    public static void main(String args[])
    {
        dfs ob=new dfs();
        System.out.println("Enter number of vertices");
        ob.V=ob.sc.nextInt();
        ob.g=new Graph(ob.V);
        int ch=1;
        while(ch==1)
        {
            System.out.println("Enter edge start and end points");
            int v=ob.sc.nextInt();
            int w=ob.sc.nextInt();
            ob.g.addEdge(v,w);
            System.out.println("Do you want to continue adding edges 0/1");
            ch=ob.sc.nextInt();
        }
        ob.finddfs();
        ob.typetree(ob.timea,ob.timed);
    }
    void finddfs()
    {
        timea=new int[V];
        timed=new int[V];
        color=new char[V];
        parent=new int[V];
        treeedge=new String[40];
        backedge=new String[40];
        for(int i=0;i<V;i++)
        {
            color[i]='w';
            parent[i]=-1;
        }
        System.out.println("Enter source vertex");
        int p=sc.nextInt();
        dfsUtil(p,timea,timed,color);
    }
    void dfsUtil(int v,int timea[],int timed[],char color[])
    {
        t++;
        timea[v]=t;
        color[v]='g';
        System.out.print(v+" ");
        Iterator<Integer> i=g.adj[v].listIterator();
        while(i.hasNext())
        {
            int n=i.next();
            if(color[n]=='w')
            {
                parent[n]=v; //you can print parent of any vertex
                String abc=Integer.toString(v)+" -> "+Integer.toString(n);
                treeedge[m++]=abc;
                dfsUtil(n,timea,timed,color);
            }
            if(color[n]=='g')
            {
                String abc=Integer.toString(v)+" -> "+Integer.toString(n);
                backedge[h++]=abc;
            }
        }
        color[v]='b';
        t++;
        timed[v]=t;
    }
    void typetree(int timea[],int timed[])
    {
        System.out.println();
       
       
        System.out.println("Tree edges");
        for(int i=0;i<m;i++)
        {
            System.out.print(treeedge[i]+"\t");
        }
        System.out.println("\nBack edges");
        for(int i=0;i<h;i++)
        {
            System.out.print(backedge[i]+"\t");
        }
    }
}
