#include <iterator> // std::iterator,std::input_iterator_tag
#include <iostream> // std::cout
namespace itertools{
template <typename T>
class range
{
  private:
    T a;
    T b;
 public:   
    class iterator : public std::iterator<std::input_iterator_tag, T>
    {
        T vector_ptr;
      
    public:
        iterator(T vector) : vector_ptr(vector) {
  
        }
        iterator& operator++() { 
        vector_ptr++; 
        return *this;
        }
        iterator operator++(int) { 
          
          iterator tmp(*this); 
          operator++(); 
          return tmp;
           }
        bool operator==(const iterator& rhs) { 
           
          return (vector_ptr == rhs.vector_ptr); 
          }
        bool operator!=(const iterator& rhs) {     
         return !(vector_ptr==rhs.vector_ptr);
          }
        T& operator*() {
          return vector_ptr;
          } 
    };
    range() {}
    range(T a, T b): a(a),b(b){}
    iterator begin()
    {
        return iterator(a);
    }  
    iterator end()
    {
        return iterator(b);
    }
};
}