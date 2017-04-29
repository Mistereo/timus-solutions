import java.io.*;
import java.util.*;

public class Test {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);

		int n=in.nextInt();
		long x=0;
		if(n<=0){
			for(int i=n; i<=1; i++)
				x+=i;
		}
		else {
			for(int i=n; i>=1; i--)
				x+=i;
		}
		out.println(x);
		out.flush();
	}
}