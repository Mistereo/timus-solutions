import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

class Solver {
    Reader in;
    PrintWriter out;

    public void solve() {
        int n = in.nextInt();
        int k = in.nextInt();
        int[] count = new int[n + 2];
        int[] numbers = new int[k];

        count[0] = count[n] = 1;
        for (int i = 1; i < n; i++) {
            count[i] = 2;
        }
        for (int i = 0; i < k; i++) {
            numbers[i] = in.nextInt();
        }
        Arrays.sort(numbers);

        for (int i = 0; i < k; i++) {
            int id = numbers[i];
            count[id]--;
            if (count[id] == 0) {
                count[id + 1]--;
            }
        }

        for (int i = 0; i < n + 1; i++) {
            if (count[i] < 0) {
                out.println("NO");
                return;
            }
        }
        out.println("YES");
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