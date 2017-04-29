import java.io.*;
import java.util.StringTokenizer;

class Timus2005 {
    public void solve(InputReader in, PrintWriter out) {
        int[][] cost = new int[5][5];
        int variations[][] = {
            { 1, 2, 3, 4, 5 },
            { 1, 3, 2, 4, 5 },
            { 1, 4, 3, 2, 5 },
            { 1, 3, 4, 2, 5 }
        };
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cost[i][j] = in.nextInt();
            }
        }
        int bestSum = Integer.MAX_VALUE;
        int bestId = -1;
        for (int i = 0; i < variations.length; i++) {
            int sum = 0;
            for (int j = 0; j < variations[i].length - 1; j++) {
                sum += cost[variations[i][j]-1][variations[i][j + 1]-1];
            }
            if (sum < bestSum) {
                bestSum = sum;
                bestId = i;
            }
        }
        out.println(bestSum);
        for (int i = 0; i < variations[bestId].length; i++) {
            out.printf("%d ", variations[bestId][i]);
        }
    }
}

public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        new Timus2005().solve(in, out);
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