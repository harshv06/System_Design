/*
    This implementation is usage of Eager loading, because using locks is a very expensive opeation in any programming language we use it only in critical applications like finance systems.

    But Eager loading also has some diadvantages and you should know how to overcome them and study lazy loading
*/

#include<iostream>
using namespace std;

class Singleton{
    private:
        static Singleton* instance;

    public:
        static Singleton* getInstance(){
            return instance;
        }
};

Singleton* Singleton::instance=new Singleton();

int main(){
    Singleton* s1=Singleton::getInstance();
    Singleton* s2=Singleton::getInstance();
    cout<<(s1 == s2)<<endl;
}
