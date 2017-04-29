import java.io.*;
import java.util.*;

public class temp {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);

		int n = in.nextInt();
		boolean[][] a = new boolean[n][n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if (Math.abs(i - j) <= n / 2) {
					a[i][j] = true;
				}
			}
		String s=new String();
		//*
		int count=0;
		for (int i = 0; i < n/2; i++) {
			for (int j = 0; j < n; j++) {
				if(!a[i][j]) {
					s+=(i+1)+" "+(j+1)+"\n";
					count++;
				}
			}
		}
		//*/
		if(count==0)
			out.println(-1);
		else {
			out.println(count);
			out.println(s);
		}
		out.flush();
	}
}
