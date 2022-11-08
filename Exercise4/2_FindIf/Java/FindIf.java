import java.util.Iterator;

public class FindIf {
    public static <T> T findIf(Iterator<T> iter, Matcher<T> matcher){
        while(iter.hasNext()){
            T elem = iter.next();
            if(matcher.match(elem)) return elem;
        }
        return null;
    }
}