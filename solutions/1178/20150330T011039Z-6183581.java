import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

class Solver {
    Reader in;
    PrintWriter out;

    class Point {
        int x = 0;
        int y = 0;
        int id = 0;
        Point() {}
        Point(int x, int y) {
            this.x = x;
            this.y = y;
            this.id = 0;
        }
        public void scan(int id) {
            this.x = in.nextInt();
            this.y = in.nextInt();
            this.id = id;
        }
        public void print() {
            out.printf("%d %d\n", x, y);
        }
    }

    public void solve() {
        int n = in.nextInt();
        Point[] A = new Point[n];
        for (int i = 0; i < n; i++) {
            A[i] = new Point();
            A[i].scan(i + 1);
        }
        Arrays.sort(A, (a, b) -> {
            if (a.x < b.x) {
                return -1;
            }
            if (a.x > b.x) {
                return 1;
            }
            return a.y - b.y;
        });
        for (int i = 0; i < n; i += 2) {
            out.printf("%d %d\n", A[i].id, A[i + 1].id);
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