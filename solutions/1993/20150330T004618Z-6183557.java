import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

class Solver {
    Reader in;
    PrintWriter out;
    Solver(Reader reader, PrintWriter printWriter) {
        in = reader;
        out = printWriter;
    }
    boolean firstTime;
    int[] positions;
    ArrayList<String> answer;
    String source;
    void print() {
        int id = 0;
        for (int i = 0; i < answer.size(); i++) {
            if (i != 0) {
                out.print(" ");
            }
            boolean special = false;
            for (int position : positions) {
                if (position == i) {
                    special = true;
                }
            }
            if (special) {
                if (firstTime) {
                    out.print(Character.toUpperCase(answer.get(positions[id]).charAt(0)));
                    out.print(answer.get(positions[id]).substring(1).toLowerCase());
                    id++;
                    firstTime = false;
                } else {
                    out.print(answer.get(positions[id++]).toLowerCase());
                }
            } else {
                if (firstTime) {
                    out.print(Character.toUpperCase(answer.get(i).charAt(0)));
                    out.print(answer.get(i).substring(1).toLowerCase());
                    firstTime = false;
                } else {
                    out.print(answer.get(i).toLowerCase());
                }
            }
        }
    }
    public void solve() {
        source = in.nextLine();
        answer = new ArrayList<>();
        firstTime = true;
        positions = new int[3];
        int type = -1;
        String current = "";
        for (int i=0; i<source.length(); i++) {
            switch (source.charAt(i)) {
                case ' ':
                    if (type != -1) {
                        current += " ";
                        break;
                    }
                    if (current.length() != 0) {
                        answer.add(current);
                        current = "";
                    }
                    type = -1;
                    break;
                case ',':
                    if (current.length() != 0) {
                        answer.add(current);
                        current = "";
                    }
                    print();
                    out.print(", ");
                    answer.clear();
                    type = -1;
                    break;
                case '{':
                    type = 0;
                    break;
                case '(':
                    type = 1;
                    break;
                case '[':
                    type = 2;
                    break;
                case '}':
                case ')':
                case ']':
                    positions[type] = answer.size();
                    answer.add(current);
                    current = "";
                    type = -1;
                    break;
                default:
                    current += source.charAt(i);
                    break;
            }
        }
        print();
    }
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