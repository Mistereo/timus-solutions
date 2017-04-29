import java.io.*;
import java.math.BigDecimal;
import java.util.*;

public class C {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		String s = "";
		boolean first = false;
		while (in.hasNext()) {
			s = in.nextLine();
			s = s.toLowerCase();
			for (int i = 0; i < s.length(); i++) {
				if (!first && (s.charAt(i)>=97 && s.charAt(i)<=122)) {
					out.print((char)(s.charAt(i)-32));
					first = true;
				} else {
					out.print(s.charAt(i));
					if (s.charAt(i)=='!' || s.charAt(i)=='.' || s.charAt(i)=='?')
						first = false;
				}
			}
			out.println();
		}
		out.flush();
	}
}