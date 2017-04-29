import java.io.*;
import java.util.*;

class Solver {
    Reader in;
    PrintWriter out;

    HashMap<Integer, HashMap<Integer, Character>> M = new HashMap<>();

    void put(int x, int y, char value) {
        if (!M.containsKey(x)) {
            M.put(x, new HashMap<>());
        }
        M.get(x).put(y, value);
    }

    Character get(int x, int y) {
        if (M.containsKey(x) && M.get(x).containsKey(y)) {
            return M.get(x).get(y);
        }
        if (x == 0 && y == 0) {
            return '+';
        }
        if (x == 0) {
            return '|';
        }
        if (y == 0) {
            return '-';
        }
        return '.';
    }

    public void solve() {
        int n = in.nextInt();
        int minX = 0;
        int maxX = 0;

        int minY = 0;
        int maxY = 0;

        for (int i = 0; i < n; i++) {
            int x = in.nextInt();
            int y = in.nextInt();

            put(x, y, '*');

            minX = Math.min(minX, x);
            maxX = Math.max(maxX, x);

            minY = Math.min(minY, y);
            maxY = Math.max(maxY, y);
        }



        for (int y = maxY; y >= minY; y--) {
            for (int x = minX; x <= maxX; x++) {
                out.print(get(x, y));
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