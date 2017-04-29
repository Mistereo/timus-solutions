import javax.script.ScriptException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws ScriptException {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);

		int k = in.nextInt();
		BigInteger x = new BigInteger("36");
		x = x.multiply((new BigInteger("55").pow(k-1)));
		out.print(x);
		out.flush();
    }
}
