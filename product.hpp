#include <iterator> // std::iterator,std::input_iterator_tag
#include <iostream> // std::cout
namespace itertools{
template <class Z, class G>
class product
{
    Z a;
    G b;
public:   
   
        template <typename V1, typename V2>
        class iterator{

        public:
        V1 firstIterator;
        V2 secondIterator;
        V1 firstIteratorP;
        V2 secondIteratorP;
        iterator(V1 first, V2 second): firstIterator(first),firstIteratorP(first), secondIterator(second), secondIteratorP(second){
        }
    
        iterator& operator++() { 
        secondIteratorP++;
        return *this;
        }
        iterator operator++(int) { 
          iterator tmp(*this); 
          operator++(); 
          return tmp;
          }
     bool operator!=( iterator<V1,V2>  &rhs) {
        if(*secondIteratorP==*rhs.secondIterator&&*firstIteratorP!=*rhs.firstIterator)
        {
         firstIteratorP++;
         secondIteratorP=secondIterator;
        }
        if(*firstIteratorP==*rhs.firstIterator)
        {
         return false;
        }
          return true;
        }

      pair<decltype(*firstIteratorP),decltype(*secondIteratorP)> operator*() {
       //  return make_pair(*firstIterator,*secondIterator);
        return pair<decltype(*firstIteratorP),decltype(*secondIteratorP)>(*firstIteratorP,*secondIteratorP);
        } 
    };
    product() {}

    product<Z,G>(Z a, G b): a(a),b(b){}
    auto begin() 
        { 
            return iterator<decltype(this->a.begin()),decltype(this->b.begin())>(this->a.begin(),this->b.begin()); 
        }  
    auto end()  
        { 
            return iterator<decltype(this->a.end()),decltype(this->b.end())>(this->a.end(),this->b.end()); 
        }   
};

}
