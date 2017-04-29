import java.io.*;
import java.util.*;

class Solver {
    Scanner in;
    PrintWriter out;

    final long P = 1000 * 1000 * 1000 + 9;
    boolean[] isPrime;
    long[][][][] dp;

    void sieve(int N) {
        isPrime = new boolean[N];
        for (int i = 0; i < N; i++) {
            isPrime[i] = true;
        }
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i < N; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < N; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }

    public void solve() {
        sieve(1000);
        int n = in.nextInt();

        dp = new long[2][10][10][10];

        for (int i = 100; i < 1000; i++) {
            if (isPrime[i]) {
                int a = i / 100;
                int b = (i / 10) % 10;
                int c = i % 10;
                dp[0][a][b][c] = 1;
            }
        }

        for (int t = 4; t <= n; t++) {
            for (int i = 100; i < 1000; i++) {
                int a = i / 100;
                int b = (i / 10) % 10;
                int c = i % 10;
                dp[(t + 1) % 2][a][b][c] = 0;
                if (isPrime[i]) {
                    for (int j = 0; j < 10; j++) {
                        dp[(t + 1) % 2][a][b][c] += dp[t % 2][j][a][b];
                        dp[(t + 1) % 2][a][b][c] %= P;
                    }
                }
            }
        }

        long answer = 0;

        for (int i = 100; i < 1000; i++) {
            int a = i / 100;
            int b = (i / 10) % 10;
            int c = i % 10;
            answer += dp[(n + 1) % 2][a][b][c];
            answer %= P;
        }
        out.println(answer);
    }

    Solver(Scanner in, PrintWriter out) { this.in = in; this.out = out; }
}

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        new Solver(in, out).solve();
        out.close();
    }
}
