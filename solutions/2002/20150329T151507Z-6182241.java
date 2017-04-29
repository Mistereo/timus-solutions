import com.sun.org.apache.xpath.internal.operations.Bool;

import java.io.*;
import java.util.HashMap;
import java.util.StringTokenizer;

class Timus2002 {
    public void solve(InputReader in, PrintWriter out) {
        HashMap<String, String> users = new HashMap<String, String>();
        HashMap<String, Boolean> logged = new HashMap<String, Boolean>();
        int n = in.nextInt();
        for (int i = 0; i < n; i++) {
            String action = in.next();
            switch (action) {
                case "register": {
                    String username = in.next();
                    String password = in.next();
                    if (users.containsKey(username)) {
                        out.println("fail: user already exists");
                    } else {
                        logged.put(username, false);
                        users.put(username, password);
                        out.println("success: new user added");
                    }
                    break;
                }
                case "login": {
                    String username = in.next();
                    String password = in.next();
                    if (users.containsKey(username)) {
                        if (password.equals(users.get(username))) {
                            boolean loggedIn = logged.get(username);
                            logged.put(username, true);
                            out.println(loggedIn ? "fail: already logged in" : "success: user logged in");
                        } else {
                            out.println("fail: incorrect password");
                        }
                    } else {
                        out.println("fail: no such user");
                    }
                    break;
                }
                case "logout": {
                    String username = in.next();
                    if (users.containsKey(username)) {
                        boolean loggedIn = logged.get(username);
                        logged.put(username, false);
                        out.println(loggedIn ? "success: user logged out" : "fail: already logged out");
                    } else {
                        out.println("fail: no such user");
                    }
                }
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
        new Timus2002().solve(in, out);
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