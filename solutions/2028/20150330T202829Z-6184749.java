import java.io.*;
import java.util.*;

class Solver {
    Reader in;
    PrintWriter out;

    public void solve() {
        out.print("17 26\n" +
                "v.................>..A..!#\n" +
                "v...........v............<\n" +
                "?..>........>....A@....>v.\n" +
                ">A>^..............v.......\n" +
                "..................A....C..\n" +
                "..................>C>A.@..\n" +
                "....................^..-..\n" +
                "....................+..A..\n" +
                "....................^B+<..\n" +
                "..................v.....<.\n" +
                "..................A.......\n" +
                "..................-.......\n" +
                "..................A..>...^\n" +
                "..................>v.B....\n" +
                "...................>B@....\n" +
                "...................+.-....\n" +
                "...................^B<....\n");
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