#include<iostream>
using namespace std;

class Singleton{
    Singleton(){}
    public:
    static Singleton& get_instance(){
        static Singleton instance;
        return instance;
    }
};

int main(){
    Singleton& s1=Singleton::get_instance();
    Singleton& s2=Singleton::get_instance();
    cout<<" "<<(&s1==&s2)<<" "<<&s2<<" ";
}