import java.io.*;
import java.util.*;

class Solver {
    Scanner in;
    PrintWriter out;

    public void solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        int p = in.nextInt();

        int[] letters = new int[26];
        for (int i = 0; i < n; i++) {
            String line = in.next();
            for (int j = 0; j < m; j++) {
                letters[line.charAt(j) - 'A']++;
            }
        }
        for (int i = 0; i < p; i++) {
            String word = in.next();
            for (int j = 0; j < word.length(); j++) {
                letters[word.charAt(j) - 'A']--;
            }
        }
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < letters[i]; j++) {
                out.print((char)('A' + i));
            }
        }
    }

    Solver(Scanner in, PrintWriter out) { this.in = in; this.out = out; }
}

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        new Solver(in, out).solve();
        out.close();
    }
}
