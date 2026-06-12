#include<iostream>
using namespace std;

class SortStratergy{
    public:
        virtual void Sort()=0;
};

class BubbleSort:public SortStratergy{
    public:
        void Sort() override{
            cout<<"Using Bubble Sort\n";
        }
};

class SelectionSort:public SortStratergy{
    public:
        void Sort() override{
            cout<<"Using Selection Sort\n";
        }
};

class InsertionSort:public SortStratergy{
    public:
        void Sort() override{
            cout<<"Using Insertion Sort\n";
        }
};

class SortContext{
    private:
    SortStratergy* sortStratergy;
    public:
    SortContext(SortStratergy* sort){
        sortStratergy=sort;
    }

    void setStratergy(SortStratergy* sort){
        sortStratergy=sort;
    }

    void sort(){
        this->sortStratergy->Sort();
    }
};

int main(){
    SortContext* context=new SortContext(new BubbleSort());
    context->sort();
    context->setStratergy(new InsertionSort());
    context->sort();
}