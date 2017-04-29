import java.io.*;
import java.util.*;

public class Test {
	public static String find_qr(long a){
		String outer = "";
		long b = a;
		while (a != 1) {
			b = a;
				for (int j = 9; j > 1; j--) {
					if (a % j == 0) {
						outer += j;
						a /= j;
						if (a < 10) {
							outer += a;
							a = 1;
							break;
						}
						break;
					}
				}
			if (a == b) {
				outer = "-1";
				break;
			}
		}
		return outer;
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		String outer="";
		long a = in.nextLong();
		if(a==0)
			out.print("10");
		else if(a==1)
			out.print("1");
		else if(a==2)
			out.print("2");
		else if(a==3)
			out.print("3");
		else if(a==5)
			out.print("5");
		else if(a==4)
			out.print("4");
		else if(a==6)
			out.print("6");
		else if(a==7)
			out.print("7");
		else if(a==8)
			out.print("8");
		else if(a==9)
			out.print("9");
		else {
		outer=find_qr(a);
		char[] arr = outer.toCharArray();
		Arrays.sort(arr);
		out.print(arr);
		}
		out.flush();
	}
}
