import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class Untitled {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		
		int length = in.nextInt();
		int sum = in.nextInt();
		
		if (sum % 2 == 1) {
			out.print("0");
		} else {
			BigInteger[][] A = new BigInteger[length+1][sum/2+1];
			for (int i=0;i<length+1; i++) {
				for (int j=0; j<sum/2+1; j++) {
					A[i][j] = BigInteger.ZERO;
				}
			}
			for (int i=0; i<sum/2+1; i++) {
				A[0][i] = BigInteger.ZERO;
			}
			for (int i=0; i<length+1; i++) {
				A[i][0] = BigInteger.ONE;
			}
			
			for (int l=1; l<length+1; l++) {
				for (int s=1; s<sum/2+1; s++) {
					for (int i=0; i<10 && s-i >= 0; i++) {
						A[l][s] = A[l][s].add(A[l-1][s-i]);
					}
				}
			}
			
			BigInteger ans = A[length][sum/2];
			out.print(ans.multiply(ans));
		}
		out.flush();
	}
}