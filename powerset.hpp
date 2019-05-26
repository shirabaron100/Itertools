#include <iterator> // std::iterator,std::input_iterator_tag
#include <iostream> // std::cout
#include <bitset>
#include <math.h>
#include <string>
#include <set>
using namespace std;
namespace itertools{
template <class Z>
class powerset
{
    Z a;
public:   
   
   typedef
               typename std::remove_const<
               typename std::remove_reference<
               decltype(*a.begin())>::type>::type Element;

        class iterator{
    private:
    void reverseStr(string& str) 
    { 
    int n = str.length(); 
  
    // Swap character starting from two 
    // corners 
    for (int i = 0; i < n / 2; i++) 
        swap(str[i], str[n - i - 1]); 
    }
    std::string toBinary(int n)
    {
    std::string r;
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    return r;
    }

 
        public:

        decltype(a.begin()) itS;
        decltype(a.begin()) itE;
        int n=0;
        int subsetIndex=0;
        int length=0;
            iterator(Z theBaseRange): itS(theBaseRange.begin()), itE(theBaseRange.end())
            {
              auto start=itS;
                while(start!=itE)
                {
                    
                   start++;
                    n++;
                    length++;
                }
                n=pow(2,n);
            }
        iterator& operator++() { 
         subsetIndex++;
         return *this;
        }
        iterator operator++(int) { 
          iterator tmp(*this); 
          operator++(); 
          return tmp;
          }
        bool operator!=( iterator  &rhs) {
         return !(subsetIndex==rhs.n);
        }



     set<Element> operator*() 
     {  
       auto itPowerS =itS; 
    string binary = toBinary(subsetIndex); //to binary
    reverseStr(binary);
    auto binstart=binary.begin();
    auto binend=binary.end();
       set<Element> s;
       while ((binstart!=binend)&&itPowerS!=itE)
       {
        // std::cout << "shira" << std::endl; 
        // std::cout << *itPowerS << std::endl;
           
            if (*binstart=='1')
                {
                        s.insert(*itPowerS);                 
                }
              itPowerS++; 
              binstart++; 
       }  
        return s;
    } 
    };
    powerset (Z a): a(a){
    }
    auto begin() const
        { 
            return iterator(a); 
        }  
    auto end()  const
        { 
             return iterator(a); 
        }   
};
}

template <typename D>
std::ostream &operator<<(std::ostream &os, const std::set<D> &S)
{
    os << "{";

    auto it = S.begin();
    if(it != S.end())
    { // first element is without comma seperator.
        os << *it; 
        ++it;
    }

    while (it != S.end())
    {
        os << ',' << *it;
        ++it;
    }

    os << "}";

    return os;
}
