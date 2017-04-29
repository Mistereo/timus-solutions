import java.io.*;
import javax.script.*;

import java.math.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws ScriptException {
		ScriptEngineManager factory = new ScriptEngineManager();
		ScriptEngine engine = factory.getEngineByName("JavaScript");
		engine.eval(
		"importPackage(java.io);\n" + 
		"importPackage(java.lang);\n" +
		"importPackage(java.util);\n" +
		"var i = new Scanner(System['in']);\n" +
		"var o = new PrintWriter(System['out']);\n" +
		"var str = i.nextInt()+i.nextInt() + '';" +
		"o.print(str);\n" +
		"o.flush();\n"
		);
	}
}
