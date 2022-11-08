public class Matcher<E> {
    private E _elem;
    Matcher(E elem){ _elem = elem; }

    public boolean match(E elem){
        return elem.equals(_elem);
    }
}
