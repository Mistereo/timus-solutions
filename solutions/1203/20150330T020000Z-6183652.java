import java.io.*;
import java.util.*;

class Solver {
    Reader in;
    PrintWriter out;

    class Lecture {
        public int start = 0;
        public int finish = 0;
        public void read() {
            start = in.nextInt();
            finish = in.nextInt();
        }
    }
    public void solve() {
        int n = in.nextInt();
        Lecture[] lectures = new Lecture[n];
        for (int i = 0; i < n; i++) {
            lectures[i] = new Lecture();
            lectures[i].read();
        }
        int current = 0;
        int answer = 0;
        Arrays.sort(lectures, (a, b) -> {
            if (a.finish != b.finish) {
                return a.finish - b.finish;
            }
            return a.start - b.start;
        });
        for (Lecture l : lectures) {
            if (l.start >= current) {
                answer++;
                current = l.finish + 1;
            }
        }
        out.println(answer);
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