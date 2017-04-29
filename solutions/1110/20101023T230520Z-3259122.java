import java.io.PrintWriter;
import java.util.Scanner;

public class Foo {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		long n = in.nextInt();
		long m = in.nextInt();
		long y = in.nextInt();
		long test=1;
		boolean x = false;
		for (int i = 0; i < m; i++) {
			test=1;
			for (int j = 0; j < n; j++) {
				test = (test*(i%m))%m;
			}
			if (test == y) {
				out.print(i + " ");
				x = true;
			}
		}
		if (!x)
			out.print("-1");
		out.flush();
	}
}