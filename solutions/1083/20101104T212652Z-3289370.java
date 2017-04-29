import java.util.*;
public class C {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int k;
		int nk = n;
		String s = in.next();
		k=s.length();
		if(n%k!=0){
			int x = 1;
			while (n-k*x>0) {
				nk*=(n-k*x);
				x++;
			}
		} else {
			int x = 1;
			while (n-k*x>0) {
				nk*=(n-k*x);
				x++;
			}
		}
		System.out.print(nk);
	}
}