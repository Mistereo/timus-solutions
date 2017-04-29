import java.io.*;
import java.util.StringTokenizer;

class Solver {
    public boolean valid(int x, int y, int n) {
        return 0 <= x && x < n && 0 <= y && y < n;
    }
    public void solve(InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int x = in.nextInt();
        int y = in.nextInt();
        x--; y--;
        int[] dx = { 0, 1, 0, -1, 1, 1, -1, -1 };
        int[] dy = { -1, 0, 1, 0, -1, 1, 1, -1 };
        int king = 0;
        int knight = 0;
        int bishop = Math.min(x, y) + Math.min(n - x - 1, y) + Math.min(n - x - 1, n - y - 1) + Math.min(x, n - y - 1);
        int rook = 2 * (n - 1);

        for (int i=0; i<8; i++) {
            if (valid(x + dx[i], y + dy[i], n)) {
                king++;
            }
        }

        for (int i=0; i<4; i++) {
            int sx = 2 * dx[i];
            int sy = 2 * dy[i];

            if (valid(x + (sx == 0 ?  1 : sx), y + (sy == 0 ?  1 : sy), n)) knight++;
            if (valid(x + (sx == 0 ? -1 : sx), y + (sy == 0 ? -1 : sy), n)) knight++;
        }

        out.println("King: " + king);
        out.println("Knight: " + knight);
        out.println("Bishop: " + bishop);
        out.println("Rook: " + rook);
        out.println("Queen: " + (bishop + rook));
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