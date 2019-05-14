/**
 * A demo program for bull-pgia.
 * 
 * @author Erel Segal-Halevi
 * @since  2019-04
 */


#include <iostream>
using namespace std;
#include "range.hpp"
#include "chain.hpp"
#include "product.hpp"
#include "powerset.hpp"
#include "zip.hpp"
#include "badkan.hpp"
#define COMMA ,

using namespace itertools;

int main() {

	badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {
        //////////////range////////////////////

		testcase.setname("range test");
		int a=-3;
        for (int j:range (-3,4))
        {
            testcase.CHECK_EQUAL(a,j);
            a++;
        }

        double b=-3.5;
        for (double j:range (-3.5,4.5))
        {
            testcase.CHECK_EQUAL(b,j);
            b++;
        }

        char c='a';
        for (auto j:range ('a','f'))
        {
            testcase.CHECK_EQUAL(c,j);
            c++;
        }
        //////////////////chain////////////
        testcase.setname("chain test");
        //test to two ranges
        char d='a';
        for (auto j:chain(range ('a','f'),range('f','k')))
        {
            testcase.CHECK_EQUAL(d,j);
            d++;
        }

        int e=1;
        for (auto j:chain(range (1,4),range(4,8)))
        {
            testcase.CHECK_EQUAL(e,j);
            e++;
        }

		double f=1.7;
        for (auto j:chain(range (1.7,4.7),range(4.7,8.7)))
        {
            testcase.CHECK_EQUAL(f,j);
            f++;
        }

        //test to two strings
	    string g="";
        for (auto j:chain(string("hadarbaronn"),string("shirabaron")))
        {
          g=g+j;
        }
        testcase.CHECK_EQUAL(g,"hadarbaronshirabaron");

        string h="";
        for (auto j:chain(range('a','b'),string("shirabaron")))
        {
          h=h+j;
        }
        testcase.CHECK_EQUAL(h,"ashirabaron");
///////////////zip/////////////////////
        testcase.setname("zip test");
        char i='a';
        int k=1;
        for (auto j:zip(range(1,6),string("abcde")))
        {
          testcase.CHECK_EQUAL(k,j.first);
          testcase.CHECK_EQUAL(i,j.second);
          k++;
          i++;
        }

        char l='a';
        double m=1.5;
        for (auto j:zip(range(1.5,6.5),range('a','f')))
        {
          testcase.CHECK_EQUAL(m,j.first);
          testcase.CHECK_EQUAL(l,j.second);
          l++;
          m++;
        }
         char n='a';
        double o=1.5;
        for (auto j:zip(chain(range(1.5,6.5),range(6.5,11.5)),range('a','k')))
        {
          testcase.CHECK_EQUAL(o,j.first);
          testcase.CHECK_EQUAL(n,j.second);
          n++;
          o++;
        }
/////////product/////////
      testcase.setname("product test"); 

      testcase.setname("Test product: ");
		string answerSS[]={"100,1","100,2","101,3","101,1","101,2","101,3","102,1","102,2","102,3"} ;
		number=0;
        for (auto i: product(range(100,103), string("123"))){
         testcase.CHECK_OUTPUT(i, answerSS[number]); 
         number++;
///////////powerset///////////////////

     testcase.setname("powerset-test");
    ostringstream streamPowerSet1,streamPowerSet2;
		for (auto i: powerset(string("abc")))
			streamPowerSet1 << i << " "; 
	    testcase.CHECK_OUTPUT(streamPowerSet1.str(),"{},{a},{b},{a,b},{c},{a,c},{b,c},{a,b,c}");
		
        for (auto i: powerset(chain(range('a','d'),range('x','z'))))
			streamPowerSet2 << i << " "; 
		testcase.CHECK_OUTPUT(streamPowerSet2.str(),"{},{a},{b},{ab},{c},{ac},{bc},{abc},{},{x},{y},{xy}");
}  

    grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}
