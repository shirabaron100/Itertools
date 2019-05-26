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
bool operator!=( iterator &rhs) 
{
if(!(this->secondIteratorP!=rhs.secondIteratorP))
{ 
firstIteratorP++;
secondIteratorP=secondIterator;
}
if(*firstIteratorP==*rhs.firstIteratorP)
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
// std::cout << "a start: " << *a.begin() << std::endl;
// std::cout << "a end: " << *a.end() << std::endl;
// std::cout << "b start: " << *b.begin() << std::endl;
// std::cout << "b end: " << *b.end() << std::endl;
}
auto begin() const
{ 
return iterator<decltype(this->a.begin()),decltype(this->b.begin())>(this->a.begin(),this->b.begin()); 
} 
auto end() const
{ 
    std::cout << "a start: " << *b.end() << std::endl;

return iterator<decltype(this->a.end()),decltype(this->b.end())>(this->a.end(),this->b.end()); 
} 
};

}

