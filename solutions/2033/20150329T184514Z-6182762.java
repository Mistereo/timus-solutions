import java.io.*;
import java.util.HashMap;
import java.util.StringTokenizer;

class Solver {
    public void solve(InputReader in, PrintWriter out) {
        HashMap<String, Integer> COST = new HashMap<>();
        HashMap<String, Integer> COUNT = new HashMap<>();
        for (int q = 0; q < 6; q++) {
            String name = in.next();
            String device = in.next();
            int price = in.nextInt();
            if (COST.containsKey(device)) {
                int count = COUNT.get(device);
                int cost  = COST.get(device);
                COUNT.put(device, count + 1);
                COST.put(device, Math.min(price, cost));
            } else {
                COUNT.put(device, 1);
                COST.put(device, price);
            }
        }

        String answer = "";
        int count = -1;
        int price = Integer.MAX_VALUE;

        for (String device : COUNT.keySet()) {
            int c = COUNT.get(device);
            int p = COST.get(device);
            if (c > count) {
                count = c;
                price = p;
                answer = device;
            } else if (c == count && p < price) {
                price = p;
                answer = device;
            }
        }
        out.println(answer);
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