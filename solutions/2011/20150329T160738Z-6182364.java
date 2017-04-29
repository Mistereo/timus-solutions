import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

class Solver {
    public void solve(InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int[] letters = { 0, 0, 0 };
        for (int i = 0; i < n; i++) {
            int type = in.nextInt();
            letters[type - 1]++;
        }
        Arrays.sort(letters);
        int count = letters.length;
        int first = 0;
        for (int letter : letters) {
            if (letter == 0) count--;
            else if (first == 0) first = letter;
        }
        if (count == 1) {
            out.println("No");
        } else if (count == 3) {
            out.println("Yes");
        } else {
            if (first == 1) {
                out.println(n - first > 4 ? "Yes" : "No");
            } else {
                out.println(n - first > 1 ? "Yes" : "No");
            }
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