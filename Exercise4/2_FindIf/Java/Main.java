import java.util.Vector;

public class Main {
    public static void main(String[] args) {
        Vector<String> vec = new Vector<>();
        for (int i = 0; i < 1000000; ++i) {
            vec.add("elem " + i);
        }
        Matcher<String> stringMatcher = new Matcher<String>("elem 999999");

        String firstElem = FindIf.findIf(vec.iterator(), stringMatcher);
        System.out.println(firstElem);
        Benchmark.measure(vec, stringMatcher);
    }    
}