import java.io.*;
import java.util.*;

class Solver {
    Reader in;
    PrintWriter out;

    class DSU {
        int[] parent;
        int[] rank;
        int sets;
        DSU(int n) {
            sets = n;
            parent = new int[n];
            rank = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                rank[i] = 0;
            }
        }
        int count() {
            return sets;
        }
        int find(int v) {
            if (parent[v] == v) {
                return v;
            }
            parent[v] = find(parent[v]);
            return parent[v];
        }
        void unite(int a, int b) {
            a = find(a);
            b = find(b);
            if (a != b) {
                sets--;
                if (rank[a] < rank[b]) {
                    int tmp = a;
                    a = b;
                    b = tmp;
                }
                if (rank[a] == rank[b]) {
                    rank[a]++;
                }
                parent[b] = a;
            }
        }
    };

    public void solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] A = new int[m];
        int[] B = new int[m];
        boolean[] bad = new boolean[m];
        for (int i = 0; i < m; i++) {
            A[i] = in.nextInt() - 1;
            B[i] = in.nextInt() - 1;
        }
        int k = in.nextInt();
        int[] toDelete = new int[k];
        for (int i = 0; i < k; i++) {
            toDelete[i] = in.nextInt() - 1;
            bad[toDelete[i]] = true;
        }
        DSU dsu = new DSU(n);
        int[] answer = new int[k];
        for (int i = 0; i < m; i++) {
            if (!bad[i]) {
                dsu.unite(A[i], B[i]);
            }
        }
        for (int i = 0; i < k; i++) {
            answer[k - i - 1] = dsu.count();
            dsu.unite(A[toDelete[k - i - 1]], B[toDelete[k - i - 1]]);
        }
        for (int i = 0; i < k; i++) {
            out.printf("%d ", answer[i]);
        }
    }

    Solver(Reader in, PrintWriter out) { this.in = in; this.out = out; }
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