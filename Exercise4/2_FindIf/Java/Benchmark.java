import java.util.Vector;

public class Benchmark {
    public static <T> long measure(Vector<T> vec, Matcher<T> matcher){
        long start = System.nanoTime();
        T elem = FindIf.findIf(vec.iterator(), matcher);
        long end = System.nanoTime();
        
        long diff = end - start;
        // System.out.println("start: " + start + " nanoseconds");
        // System.out.println("end: " + end + " nanoseconds");
        System.out.println(elem + " found");
        System.out.println("Time: " + diff / 1000000 + " miliseconds");
        return diff;
    }
}
