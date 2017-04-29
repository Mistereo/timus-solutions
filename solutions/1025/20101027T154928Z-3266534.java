import java.io.*;
import java.util.*;

public class C {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int n = in.nextInt();
		int[] a = new int[n];
		int result = 0;
		for (int i=0; i<n; i++)
			a[i] = in.nextInt();
		Arrays.sort(a);
		for(int i=0; i<(n/2)+1; i++) {
			result+=(a[i]/2)+1;
		}
		out.println(result);
		out.flush();
	}
}