#include <iterator> // std::iterator,std::input_iterator_tag
#include <iostream> // std::cout
using namespace std;
namespace itertools{
template <class Z, class G>
class zip
{
    Z a;
    G b;
public:   
   
        template <typename V1, typename V2>
        class iterator{

        public:
        V1 firstIterator;
        V2 secondIterator;
        
            bool type;
            iterator(V1 first, V2 second): firstIterator(first), secondIterator(second), type(true){}
    
        iterator& operator++() { 
        firstIterator++;
        secondIterator++;
        return *this;
        }
        iterator operator++(int) { 
          iterator tmp(*this); 
          operator++(); 
          return tmp;
          }
        bool operator!=( iterator<V1,V2>  &rhs) {
         return !(*firstIterator==*rhs.firstIterator);
        }
      pair<decltype(*firstIterator),decltype(*secondIterator)> operator*() {
       //  return make_pair(*firstIterator,*secondIterator);
        return pair<decltype(*firstIterator),decltype(*secondIterator)>(*firstIterator,*secondIterator);
        } 
    };
    zip() {}

    zip<Z,G>(Z a, G b): a(a),b(b){}
    auto begin() 
        { 
            return iterator<decltype(this->a.begin()),decltype(this->b.begin())>(this->a.begin(),this->b.begin()); 
        }  
    auto end()  
        { 
            return iterator<decltype(this->a.end()),decltype(this->b.end())>(this->a.end(),this->b.end()); 
        }   
};
template <typename v,typename m>
 ostream& operator<< (ostream& os, const pair<v,m>& p){
     return (os << p.first << "," << p.second);
 }
}