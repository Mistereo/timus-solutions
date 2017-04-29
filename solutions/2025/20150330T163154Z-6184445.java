import java.io.*;
import java.util.*;

class Solver {
    Reader in;
    PrintWriter out;

    public void solve() {
        int T = in.nextInt();

        for (int q = 0; q < T; q++) {
            int n = in.nextInt();
            int k = in.nextInt();

            int[] teams = new int[k];
            for (int i = 0; i < n; i++) {
                teams[i % k]++;
            }
            int answer = 0;
            for (int i = 0; i < k; i++) {
                answer += (n - teams[i]) * teams[i];
            }
            out.println(answer / 2);
        }
    }

    Solver(Reader reader, PrintWriter printWriter) { in = reader; out = printWriter; }
}

public class Main {
    public static void main(String[] args) {
        Reader in = new Reader(System.in);
        PrintWriter out = new PrintWriter(System.out);
        new Solver(in, out).solve();
        out.close();
    }
}

class Reader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;
    public Reader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream), 32768);
        tokenizer = new StringTokenizer("");
    }
    public String next() {
        while (!tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException ignored) {}
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
    public boolean hasNext() {
        while (!tokenizer.hasMoreTokens()) {
            try {
                String line = reader.readLine();
                if (line == null) {
                    return false;
                }
                tokenizer = new StringTokenizer(line);
            } catch (IOException ignored) {}
        }
        return true;
    }
}