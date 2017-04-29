import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

class Solver {
    Reader in;
    PrintWriter out;

    class Cell {
        public int dist;
        public int x;
        public int y;
        Cell(int dist, int x, int y) {
            this.dist = dist;
            this.x = x;
            this.y = y;
        }
    }

    public void solve() {
        int n = in.nextInt();
        int[] A = new int[n * n];
        for (int i = 0; i < n * n; i++) {
            A[i] = in.nextInt();
        }
        Cell[] D = new Cell[n * n];
        int c = n / 2;
        int id = 0;
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                int dist = (x - c) * (x - c) + (y - c) * (y - c);
                D[id++] = new Cell(dist, x, y);
            }
        }
        Arrays.sort(A);
        Arrays.sort(D, (a, b) -> b.dist - a.dist);
        int[][] answer = new int[n][n];
        id = 0;
        for (Cell cell : D) {
            answer[cell.x][cell.y] = A[id++];
        }
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                out.printf("%d ", answer[x][y]);
            }
            out.print('\n');
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