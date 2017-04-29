import java.io.*;
import java.util.*;

public class Test {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);

		Vector a = new Vector();
		while (in.hasNext()) {
			a.add(Math.sqrt(in.nextDouble()));
		}
		Object[] x = new Object[a.size()];
		for (int i = 0; i < a.size(); i++) {
			x[i] = a.get(i);
		}
		for (int i = x.length-1; i >= 0; i--)
			out.println(x[i]);
		out.flush();
	}
}
