import java.io.PrintWriter;
import java.util.Scanner;

public class D {
	public static int gcd(int a, int b)
	{
	   if (b==0) return a;
	   return gcd(b,a%b);
	}
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int n=in.nextInt();
		int m=in.nextInt();
		int count=1;
		n--;
		m--;
		count=gcd(m,n);
		if (count != 1){
			m/=count;
			n/=count;
		}
		out.println((m+n-1)*count);
		out.flush();
	}
}
