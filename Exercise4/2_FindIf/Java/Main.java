import java.util.Vector;

public class Main {
    public static void main(String[] args) {
        // Setup
        int n = 10000000;
        Vector<String> stringvec = new Vector<>();
        for (int i = 0; i < n; ++i) {
            stringvec.add("elem " + i);
        }
        Matcher<String> stringMatcher = new Matcher<String>("elem " + (n-2));
        
        Vector<Integer> intvec = new Vector<>();
        for (int i = 0; i < 10000000; ++i) {
            intvec.add(i);
        }
        Matcher<Integer> intMatcher = new Matcher<Integer>(n-2);
        
        // Benchmark
        Benchmark.measure(stringvec, stringMatcher);
        Benchmark.measure(intvec, intMatcher);

    }    
}