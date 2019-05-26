#include <iterator> // std::iterator,std::input_iterator_tag
#include <iostream> // std::cout
namespace itertools{
template <class Z, class G>
class chain
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
            iterator(V1 first, V2 second): firstIterator(first), secondIterator(second), type(true){
              
            }
    
        iterator& operator++() { 
        if(type==true)
        (firstIterator)++;
        else
        {
          secondIterator++;
        }
        return *this;
        }

        iterator operator++(int) { 
          iterator tmp(*this); 
          operator++(); 
          return tmp;
          }
        bool operator!=(iterator<V1,V2> const &diff) {
               if(this->type && !(this->firstIterator != (diff.firstIterator))){
                    this->type=false;
               }
               if(this->type==true){
                return this->firstIterator != (diff.firstIterator);
               }
               else{
                   return this->secondIterator != (diff.secondIterator);
               }
            }

        auto operator*() {
        if(type==true)
        return *firstIterator;
        return *secondIterator;
        } 
    };
    chain() {}

    chain<Z,G>(Z a, G b): a(a),b(b){
     }
    auto begin() const
        { 
            return iterator<decltype(this->a.begin()),decltype(this->b.begin())>(this->a.begin(),this->b.begin()); 
        }  
        auto end() const  
        { 
            return iterator<decltype(this->a.end()),decltype(this->b.end())>(this->a.end(),this->b.end()); 
        }   
};
}