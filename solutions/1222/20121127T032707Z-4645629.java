import javax.script.ScriptException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;


public class Main {

    public static void main(String[] args) throws ScriptException {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);

		int n = in.nextInt();

		BigInteger[] dp = new BigInteger[n+1];
		dp[0] = BigInteger.ZERO;
		for(int i=1; i<=n; i++) {
			dp[i] = BigInteger.valueOf((long)i);
			for(int j=2; j<27 && j<i; j++) {
				BigInteger t = dp[i-j].multiply(BigInteger.valueOf((long)j));
				if (t.compareTo(dp[i]) == 1) {
					dp[i] = t;
				}
			}
		}

		out.println(dp[n]);
		out.flush();
    }
}
