import java.io.PrintWriter;
import java.util.Scanner;
import java.math.BigDecimal;


public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		BigDecimal sum = BigDecimal.ZERO;
		BigDecimal asd;
		int n = in.nextInt();
		for(int i=0; i<n; i++) {
			asd = new BigDecimal(in.next());
			sum=sum.add(asd);
		}
		
	    out.println(sum.toPlainString()+"e0");
	    out.flush();
	    
	}
}
