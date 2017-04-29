import java.io.*;
import java.util.*;


public class CopyOfasdas {
 public static String A(int n, String a){
  
   if(n != 1){
    if (n % 2 == 0)
     a += '-';
    else
     a += '+';
   }
   a += "sin(" + n;
  return a;
 }
 public static String S(int n){
  String a = "";
  for(int i = 1; i < n; i++){
   a += '(';
  }
  String b = "";
  String c = "";
  for(int i = n; i >= 1; i--){
   b = A(n-i + 1, b);
   c = b;
   for(int j = 1; j <= n-i + 1; j++){
    c += ')';
   }
   a += c + '+' + i;
   //a += "A" + (n-i + 1) + '+' + i;
   if(i != 1)
    a  += ')';
  }
  return a;
 }
 public static void main(String[] args){
  Scanner in = new Scanner(System.in);
  PrintWriter out = new PrintWriter(System.out);
  
  int k = in.nextInt(); 
  out.println(S(k));
  out.flush();
 }
 
}