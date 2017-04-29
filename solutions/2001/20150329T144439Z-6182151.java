import java.io.*;
import java.util.StringTokenizer;

class Task2001 {
    public void solve(InputReader in, PrintWriter out) {
        int[] A = new int[3];
        int[] B = new int[3];
        for (int i = 0; i < 3; i++) {
            A[i] = in.nextInt();
            B[i] = in.nextInt();
        }
        out.printf("%d %d", A[0] - A[2], B[0] - B[1]);
    }
}

public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        new Task2001().solve(in, out);
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

    public int nextInt() {
        return Integer.parseInt(next());
    }

}