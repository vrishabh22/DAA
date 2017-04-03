import java.io.*;
import java.util.*;

public class editdistance_dp
{
    static int memo[][]=new int[100][100];
   
    static String s1,s2;
    static int n,m;
    public static void main(String []args)throws IOException
    {
        BufferedReader stdin=new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter 2 strings: ");
        s1=stdin.readLine();
        s2=stdin.readLine();
        n=s1.length();
        m=s2.length();
        editdistance_dp obj=new editdistance_dp();
        int i,j;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                memo[i][j]=-1;
            }
        }
        int mincost=obj.c(0,0);
        System.out.println("Minimum cost is "+mincost+"\n");   
        obj.print(0,0);
           
       
    }
    void print(int i,int j)
    {
            if(i==n)
            {
                while(j<m)
                {
                    System.out.println("_ "+s2.charAt(j)+" 1");
                    j++;
                }
                return;
            }       
           
            if(j==m)
            {
                while(i<n)
                {
                    System.out.println(s1.charAt(i)+" _ 1");
                    i++;
                }
                return;
            }
            if(s1.charAt(i)==s2.charAt(j))
            {
                System.out.println(s1.charAt(i)+" "+s2.charAt(j)+" 0");
                print(i+1,j+1);
                return;
            }
            if(memo[i][j]==diff(i,j)+memo[i+1][j+1])
            {
                System.out.println(s1.charAt(i)+" "+s2.charAt(j)+" 1");
                print(i+1,j+1);
            }   
            else if(memo[i][j]==1+memo[i+1][j])
            {
                System.out.println(s1.charAt(i)+" _ 1");
                print(i+1,j);
            }
            else
            {
                System.out.println("_ "+s2.charAt(j)+" 1");
                print(i,j+1);
            }   
    }
   
   
    int c(int i,int j)
    {
        if(i==n)
            return (m-j);
        if(j==m)
            return (n-i);
        if(memo[i][j]!=-1)
            return memo[i][j];
        else
        {   
            memo[i][j]=(min(diff(i,j)+c(i+1,j+1),c(i+1,j)+1,c(i,j+1)+1));
            return memo[i][j];
        }
       
    }
    int diff(int a,int b)
    {
        if(s1.charAt(a)==s2.charAt(b))
            return 0;
        else
            return 1;
    }
   
    int min(int a,int b,int c)
    {
        if(a<b&&a<c)
            return a;
        else if(b<a&&b<c)
            return b;
        else if(c<a&&c<b)
            return c;
        else if (a==b&&a<c)
            return a;
        else if (a==b&&a>c)
            return c;
        else if (b==c&&b<a)
            return b;
        else if (b==c&&b>a)
            return a;   
        else if (a==c&&a<b)
            return a;   
        else if (a==c&&a>b)
            return b;   
        else if((a==b) && (a==c))
            return a;   
        System.out.println("Error");
        return 0;
    }
}    
