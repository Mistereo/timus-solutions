import java.io.*;
import java.util.*;
public class C {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int n = in.nextInt();
		int k = 0;
		int nk = n;
		String s = in.next();
		k=s.length();
		if(n%k!=0){
			int x = 1;
			while (n-k*x>0) {
				nk*=(n-k*x);
				x++;
			}
		} else {
			int x = 1;
			while (n-k*x>0) {
				nk*=(n-k*x);
				x++;
			}
		}
		out.print(nk);
		out.flush();
	}
}