
import java.util.*;
public class Bruteforce {
	
	


	public static void main(String[] args) {
		
		int i,n,j,ct=0;
		
		Scanner sc = new Scanner(System.in);
		//Random rand = new Random();
		System.out.println("Enter n: ");
		n=sc.nextInt();
		int a[] = new int[n];
		for(i=0;i<n;i++)
			a[i]=sc.nextInt();
		System.out.println("Array is: ");
		for(i=0;i<n;i++)
			System.out.print(a[i] + "\t");
		System.out.println();
		for(i=0;i<n-1;i++)
		{
			for(j=1;j<n;j++)
			{
				if(a[i]>a[j] && i<j)
				{
					ct++;
				}
					
			}
			
	}
		System.out.println(ct);
		sc.close();
}
}

