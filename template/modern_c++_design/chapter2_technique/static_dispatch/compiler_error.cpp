/**
 * This is almost exactly the same as constexper_if.cpp, except that we don't use the key word "constexpr"
 * Thus, the compiler would try to compile all the branches, which will give us error
 */

#include <iostream>
using namespace std;

template <typename T, int funcType>
class NiftyContainer
{
private:
    // void DoSomething(T* pObj, Int2Type<0>) {
    //     T* pNewObj = pObj->Clone();
    // }
    // void DoSomething(T* pObj, Int2Type<1>) {
    //     T* pNewObj = new T(*pObj);
    // }
    // void DoSomething(T* pObj, Int2Type<2>) {
    //     cout << "bluh" << endl;
    // }
public:
    void DoSomething(T* pObj){
        if (funcType == 0){
            T* pNewObj = pObj->Clone();
        }else if (funcType == 1) {
            T* pNewObj = new T(*pObj);
        }else{
            cout << "bluh" << endl;
        }
        
    }
};

class Clonable{
public:
    Clonable* Clone() {
        cout << "cloned" << endl;
        return new Clonable(*this); 
    }
};

int main(){
    NiftyContainer<Clonable, 0> clone;
    // error, no clone
    // int a = 1;
    // clone.DoSomething(&a);
    Clonable c;
    clone.DoSomething(&c);
    int a = 1;
    NiftyContainer<int, 1> normalNew;
    normalNew.DoSomething(&a);
    NiftyContainer<int, 2> bluh;
    bluh.DoSomething(&a);

    return 0;
}