
/* Task 10_8
    Output:
    5
    10
    10

    Explanation:
    A.getptrN() returns the address of the private member N, which can be used to directly
    manipulate the value.
    This is bad practice because the purpose of encapsulation is to hide senstive data from the user.
    Sensitive data must only be accessed and manipulated through class methods. The pointer allows to bypass this required behaviour.
*/
#include <iostream> 

using std::cout; 
using std::endl;

class Test{
	
private: 
	int N;
	
public: 
	void setN(int N_in) { N = N_in; }; 
	int getN(){ return N; }; 
	int* getptrN(){ return &N; };
};

int main(){
	
	Test A; 
	A.setN(5); 
	int* ptr = A.getptrN(); 
	cout << A.getN() << endl; 
	*ptr = 10; 
	cout << ptr << endl; 
	cout << A.getN() << endl;
	
	return 0;
}