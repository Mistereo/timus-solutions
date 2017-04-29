import java.io.*;
import java.math.BigDecimal;
import java.util.*;

public class C {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		
		String s = "";
		s = in.nextLine();
		int count = 0;
		for(int i=0; i<s.length(); i++) {
			char x = s.charAt(i);
			if(x=='a' || x=='d' || x=='g' || x=='j' ||x=='m' || x=='p' || x=='s' || x=='v' ||x=='y' || x=='.' || x==' ')
				count++;
			else if (x=='b' || x=='e' || x=='h' || x=='k' ||x=='n' || x=='q' || x=='t' || x=='w' ||x=='z' || x==',') 
				count+=2;
			else 
				count+=3;
		}
		out.println(count);
		out.flush();
	}
}