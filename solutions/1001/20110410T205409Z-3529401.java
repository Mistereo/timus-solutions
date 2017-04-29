import java.io.*;
import java.util.*;

public class temp {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);

		ArrayList<Double> lst = new ArrayList<Double>();
		
		while(in.hasNext()){
			lst.add(Math.sqrt(in.nextDouble()));
		}
		for(int i=lst.size()-1; i>=0; i--)
			out.println(lst.get(i));
		out.flush();
	}
}