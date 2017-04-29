import java.io.*;
import java.util.HashMap;
import java.util.StringTokenizer;

class Solver {
    public void solve(InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int[] A = new int[n];
        for (int i = 0; i < n; i++) {
            A[i] = in.nextInt();
        }
        int a = in.nextInt();
        int b = in.nextInt();
        a--;
        b--;

        int aSum = 0;
        int bSum = 0;

        if (a == b) {
            for (int i=a; i<n; i++) {
                aSum += A[i];
            }
            for (int i=a; i >= 0; i--) {
                bSum += A[i];
            }
            out.printf("%d %d", Math.max(aSum, bSum), Math.min(aSum, bSum) - A[a]);
        } else {
            int step = 1;
            if (a > b) {
                step = -1;
            }
            while(Math.abs(a - b) > 1) {
                a += step;
                b -= step;
            }
            for (int i=a; i >=0 && i < n; i -= step) {
                aSum += A[i];
                A[i] = 0;
            }

            for (int i=0; i<n; i++) {
                bSum += A[i];
            }
            out.printf("%d %d", aSum, bSum);
        }

    }
}

public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        new Solver().solve(in, out);
        out.close();
    }
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;
    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream), 32768);
        tokenizer = null;
    }
    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }
    public int nextInt() { return Integer.parseInt(next()); }
    public long nextLong() { return Long.parseLong(next()); }
    public double nextDouble() { return Double.parseDouble(next()); }
    public String nextLine() {
        String str = "";
        try {
            str = reader.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return str;
    }
}