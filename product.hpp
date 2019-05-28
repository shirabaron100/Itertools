#include <iterator> // std::iterator,std::input_iterator_tag
#include <iostream> // std::cout
using namespace std;
namespace itertools{
    bool flag=false;
template <class Z, class G>
class product
{
Z a;
G b;

public: 
template <typename V1, typename V2>
class iterator{

public:
V2 secondIterator;
V1 firstIteratorP;
V2 secondIteratorP;

iterator(V1 first, V2 second)
:firstIteratorP(first), secondIteratorP(second),secondIterator(second){
    
}
iterator& operator++() { 
secondIteratorP++;
//std::cout << *secondIteratorP << "    : shira" << std::endl;
return *this;
}
iterator operator++(int) { 
iterator tmp(*this); 
operator++(); 
return tmp;
}
bool operator!=(iterator &rhs) 
{
     if(!(this->secondIterator!=rhs.secondIterator))
        {
            return false;
        }
    if(!(this->secondIteratorP!=rhs.secondIterator))
        { 
            this->firstIteratorP++;
            this->secondIteratorP=this->secondIterator;
        }
    if(!(this->firstIteratorP!=rhs.firstIteratorP))
        {
            return false;
        }
        
return true;
}

pair<decltype(*firstIteratorP),decltype(*secondIteratorP)> operator*() {
// return make_pair(*firstIterator,*secondIterator);
return pair<decltype(*firstIteratorP),decltype(*secondIteratorP)>(*firstIteratorP,*secondIteratorP);
} 
};
product<Z,G>(Z a, G b): a(a),b(b){
   
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