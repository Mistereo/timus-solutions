import java.io.*;
import java.util.*;

public class temp {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);

		int[][] a = new int[4][13];
		String cdhs = "CDHS";

		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 13; j++)
				a[i][j] = cdhs.indexOf(in.next().charAt(1));
		int step = 0;
		int x = 0;
		int sum = 0;
		while (true) {
			x = 0;
			for (int i = 0; i < 4; i++) {
				if (a[i][step] == a[i][step + 1])
					x++;
			}
			if (x == 0) {
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {
						if (i != j)
							if (a[i][step] == a[j][step + 1]&&a[j][step]==a[i][step+1])
								x=3;
					}
				}	
			}
			switch (x) {
			case 0:
				sum+=5;
				break;
			case 1:
				sum+=4;
				break;
			case 2:
				sum+=3;
				break;
			case 3:
				sum+=6;
				break;
			}
			step++;
			if (step == 12)
				break;
		}
		out.print(sum);
		out.flush();
	}
}
