import java.util.Scanner

object Task {
  def main(args: Array[String]) {
    val in = new Scanner(System.in)
    val a: BigInt = in.nextBigInteger
    val b: BigInt = in.nextBigInteger
    println(a + b)
  }
}