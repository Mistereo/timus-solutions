import javax.script.ScriptException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws ScriptException {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);

		int n = in.nextInt();
		int t = in.nextInt();
		int s = in.nextInt();
		for(int i=0; i<n; i++) {
			int x = in.nextInt();
			out.println((double)(x+s+t)/2);
		}
		out.flush();
    }
}
