#pragma once

#include <vector>
#include <iterator>


template <class Ran>
bool __between(Ran fst, Ran lst, Ran i, std::random_access_iterator_tag dummy){
    // std::cout << "between() called with random iterator!" << std::endl;
    return fst < i && i < lst;
}
template <class In>
bool __between(In fst, In lst, In i, std::input_iterator_tag dummy){ // Why not fwd-iter tag?
    // std::cout << "between() called with input iterator" << std::endl;
    if(fst == i) return false;
    while(fst != lst && fst != i) fst++;
    return fst == i && fst != lst ; 
}


template <typename I>
bool between(I fst, I lst, I i){
    typedef typename std::iterator_traits<I>::iterator_category cat;
    return __between(fst, lst, i, cat());
}


// template <class In> std::iterator_traits<In>::difference_type
// __distance(In first, In last ) {
// In ::difference_type n = 0;
// while(first!=last) { ++first; ++n; }
// return n;
// }
// template <class Ran> std::iterator_traits<Ran>::difference_type
// __distance(Ran fst, Ran lst ) {
// return lst-fst;
// }
// template <class I> inline
// std::iterator_traits<I>::difference_type distance(I first, I last) {
// typedef typename I ::iterator_category cat;
// return __distance(first, last, cat());
// }