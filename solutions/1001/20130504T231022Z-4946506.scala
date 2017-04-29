import io.Source
object ReverseRoot extends App {
   val longs = Source.stdin.getLines().flatMap(
      _.split(" ").filter(!_.isEmpty).map(_.toLong)).toArray
   println(longs.reverse.map(t => math.sqrt(t)).mkString("\n"))
}