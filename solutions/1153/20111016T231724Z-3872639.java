import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;

public class Main {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		String number = in.next();
		BigInteger num = new BigInteger(number);
		num = num.multiply(BigInteger.valueOf(8)).add(BigInteger.ONE);
		BigInteger ans = num;
		BigInteger left = new BigInteger("0");
		BigInteger right = num;
		
		int comp = num.compareTo(ans.pow(2)); 
		int i = 0;
		while(comp != 0 && i<10) {
			if(comp > 0) {
				left = ans;
			} else {
				right = ans;
			}
			ans = left.add(right).divide(BigInteger.valueOf(2));
			//out.write(ans.toString()+"\n");
			comp = num.compareTo(ans.pow(2));
		}
		out.write(ans.add(BigInteger.valueOf(-1)).divide(BigInteger.valueOf(2)).toString());
		out.flush();
	}

}
