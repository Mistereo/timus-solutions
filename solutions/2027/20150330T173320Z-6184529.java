import java.io.*;
import java.util.*;

class Solver {
    Reader in;
    PrintWriter out;

    int h;
    int w;
    char[][] source;

    int x = 0;
    int y = 0;
    int[] dx = {0, 1,  0, -1};
    int[] dy = {1, 0, -1,  0};
    int direction = 0;

    int[] registers = new int[26];
    int[] input;
    int inputID = 0;
    int current = 0;

    int readFromInput() {
        return input[Math.min(inputID++, input.length - 1)];
    }

    boolean valid() {
        return 0 <= x && x < h && 0 <= y && y < w;
    }

    void swapRegisters(int id) {
        int temp = current;
        current = registers[id];
        registers[id] = temp;
    }

    boolean step() {
        if (!valid()) {
            out.println("RUNTIME ERROR");
            return false;
        }

        char op = source[x][y];
        if ('A' <= op && op <= 'Z') {
            swapRegisters(op - 'A');
        }
        switch (op) {
            case '^':
            case '>':
            case 'v':
            case '<':
                direction = Arrays.asList('>', 'v', '<', '^').indexOf(op);
                break;
            case '?':
                current = readFromInput();
                break;
            case '!':
                out.println(current);
                current = 0;
                break;
            case '+':
            case '-':
                if (op == '+') {
                    current++;
                } else {
                    current--;
                }
                if (Math.abs(current) > 100 * 1000) {
                    out.println("OVERFLOW ERROR");
                    return false;
                }
                break;
            case '@':
                if (current == 0) {
                    direction--;
                } else {
                    direction++;
                }
                direction = (direction + 4) % 4;
                break;
            case '#':
                return false;
            default:
                break;
        }

        x += dx[direction];
        y += dy[direction];

        return true;
    }

    public void solve() {
        h = in.nextInt();
        w = in.nextInt();
        source = new char[h][w];
        for (int i = 0; i < h; i++) {
            String line = in.next();
            for (int j = 0; j < w; j++) {
                source[i][j] = line.charAt(j);
            }
        }
        int k = in.nextInt();
        input = new int[k];
        for (int i = 0; i < k; i++) {
            input[i] = in.nextInt();
        }
        boolean exited = false;
        for (int i = 0; i < 1000 * 1000 && !exited; i++) {
            exited = !step();
        }
        if (!exited) {
            out.println("TIME LIMIT EXCEEDED");
        }
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