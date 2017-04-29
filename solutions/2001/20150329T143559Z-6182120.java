import java.io.PrintWriter;
import java.util.Scanner;

public class Main {
    static class Timus2001 {
        public static void solve(Scanner in, PrintWriter out) {
            int[] A = new int[3];
            int[] B = new int[3];
            for (int i = 0; i < 3; i++) {
                A[i] = in.nextInt();
                B[i] = in.nextInt();
            }
            out.printf("%d %d", A[0] - A[2], B[0] - B[1]);
        }
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        Timus2001.solve(in, out);
        out.flush();
    }
}
