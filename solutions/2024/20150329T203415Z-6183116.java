import java.io.*;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

class Solver {
    BigInteger fact(int n) {
        BigInteger result = BigInteger.ONE;
        for (int i=1; i<=n; i++) {
            result = result.multiply(BigInteger.valueOf(i));
        }
        return result;
    }
    public void solve(InputReader in, PrintWriter out) {
        String S = in.next();
        int[] count = new int[26];
        for (int i=0; i<S.length(); i++) {
            count[S.charAt(i) - 'a']++;
        }

        Arrays.sort(count);

        int sum = 0;
        int k = in.nextInt();

        int last = -1;
        int lastCount = 0;
        int lastNeeded = 0;
        for (int i = 0; i < k; i++) {
            int t = count[count.length - i - 1];
            sum += t;
            if (t != 0) {
                last = count[count.length - i - 1];
            }
        }

        for (int i=count.length - 1, t=0; i != -1; i--, t++) {
            if (count[i] == last) {
                if (t < k) {
                    lastNeeded++;
                }
                lastCount++;
            }
        }

        BigInteger answer = fact(lastCount).divide(fact(lastNeeded).multiply(fact(lastCount - lastNeeded)));

        out.printf("%d %s", sum, answer);
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