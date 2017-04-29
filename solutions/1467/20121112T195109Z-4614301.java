import javax.script.ScriptException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;


public class Main {

	public static class Rational {
		static Rational ONE = new Rational(BigInteger.ONE,BigInteger.ONE);
		static Rational ZERO = new Rational(BigInteger.ZERO, BigInteger.ONE);
		BigInteger n;
		BigInteger m;
		public Rational(BigInteger a, BigInteger b) {
			BigInteger g = a.gcd(b);
			n = a.divide(g);
			if(b.signum() < 0)
				n = n.negate();
			m = b.divide(g);
		}
		public Rational divide(Rational b) {
			BigInteger nN;
			BigInteger nM;
			nN = n.multiply(b.m);
			nM = m.multiply(b.n);
			if(nM.signum() < 0) {
				nM = nM.negate();
				nN = nN.negate();
			}
			return new Rational(nN, nM);
		}
		public Rational add(Rational b) {
			BigInteger nN = n.multiply(b.m).add(m.multiply(b.n));
			BigInteger nM = m.multiply(b.m);
			return new Rational(nN, nM);
		}
		public Rational multiply(Rational b) {
			if(b.equals(Rational.ZERO) || this.equals(Rational.ZERO)) {
				return Rational.ZERO;
			}
			BigInteger nN = n.multiply(b.n);
			BigInteger nM = m.multiply(b.m);
			return new Rational(nN, nM);
		}
		public String toString() {
			return n.toString() + "/" + m.toString();
		}
	}

	public static class Poly {
		ArrayList<Rational> K;
		public Poly() {
			K = new ArrayList<Rational>();
		}
		public Poly(Rational r) {
			K = new ArrayList<Rational>();
			K.add(r);
		}
		public void add(Rational c) {
			K.add(c);
		}
		public Poly add(Poly b) {
			Poly R = new Poly();
			for(int i=0; i<K.size(); i++) {
				R.add( K.get(i).add(b.K.get(i)) );
			}
			return R;
		}
		public Poly divide(BigInteger d) {
			Rational D = new Rational(d, BigInteger.ONE);
			Poly R = new Poly();
			for(int i=0; i<K.size(); i++) {
				R.add(K.get(i).divide(D));
			}
			return R;
		}
		public Poly mltiply(Poly b) {
			Poly res = new Poly();
			for(int i=0; i<K.size()+b.K.size()-1; i++) {
				res.add(Rational.ZERO);
			}
			for(int i=0; i<K.size(); i++) {
				for(int j=0; j<b.K.size(); j++) {
					res.K.set(i+j, res.K.get(i+j).add(K.get(i).multiply(b.K.get(j))));
				}
			}
			return res;
		}
		public String toString() {
			String s = "";
			for(int i=K.size()-1; i>=0; i--) {
				s+=K.get(i).toString() + " ";
			}
			return s;
		}
	}

    public static void main(String[] args) throws ScriptException {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);

		int k = in.nextInt();

		ArrayList<Poly> Y = new ArrayList<Poly>();
		for(int i=0; i<=k+1; i++) {
			if(i==0)
				Y.add(new Poly(new Rational(BigInteger.valueOf((long)(i+1)).pow(k),BigInteger.ONE)));
			else
				Y.add(Y.get(i-1).add(new Poly(new Rational(BigInteger.valueOf((long)(i+1)).pow(k),BigInteger.ONE))));
		}

		ArrayList<Poly> L = new ArrayList<Poly>();
		for(int j=0; j<=k+1; j++) {
			BigInteger divider = BigInteger.ONE;
			L.add(new Poly());
			L.get(j).add(Rational.ONE);
			for(int i=0; i<=k+1; i++) {
				if(i!=j) {
					divider = divider.multiply(BigInteger.valueOf((long)(j-i)));
					Poly tmp = new Poly();
					tmp.add(new Rational(BigInteger.valueOf((long)(-1-i)),BigInteger.ONE));
					tmp.add(Rational.ONE);
					L.set(j, L.get(j).mltiply(tmp));
				}
			}
			L.set(j, L.get(j).divide(divider));
			L.set(j, L.get(j).mltiply(Y.get(j)));
		}
		for(int i=1; i<=k+1; i++) {
			L.set(0,L.get(0).add(L.get(i)));
		}
		out.println(L.get(0));
		out.flush();
    }
}
