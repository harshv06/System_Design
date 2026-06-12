#include<iostream>
using namespace std;

/*
Advantages
The Factory Method pattern provides flexibility and better design structure in object creation:

Encapsulates object creation logic, so clients don’t need to know how objects are created internally.
Promotes loose coupling by depending on abstractions instead of concrete classes.
Supports scalability and extensibility by allowing new product types without modifying existing code.
Improves reusability and maintainability by centralizing and reusing creation logic.

Disadvantages
Although useful, the pattern can introduce some complexity:

Increases the number of classes in the system.
Can make the code more complex compared to simple object creation.
May be unnecessary for small or simple applications.

*/

class Vehicle{
    // product interface 
    public:
    virtual void printVehicle()=0;
};

class TwoWheeler:public Vehicle{
    // concrete products
    public:
    void printVehicle() override{
        cout<<"Two wheeler \n";
    }
};

class FourWheeler:public Vehicle{
    public:
    void printVehicle() override{
        cout<<"Four wheeler \n";
    }
};

class VehicleFactory{
    public:
    virtual Vehicle *createVehicle()=0;
    virtual ~VehicleFactory(){

    }
};

class TwoWheelerFactory:public VehicleFactory{
    Vehicle *createVehicle() override{
        return new TwoWheeler();
    }
};

class FourWheelerFactory:public VehicleFactory{
    Vehicle *createVehicle() override{
        return new FourWheeler();
    }
};

class Client{
    private:
    Vehicle *pvehicle;
    public:
    Client(VehicleFactory *factory){
        pvehicle=factory->createVehicle();
    }
    Vehicle *getVehicle(){
        return pvehicle;
    }
};

int main(){
    VehicleFactory *vehicle=new TwoWheelerFactory();
    Client twoWheelerClient(vehicle);
    Vehicle *twoWheeler=twoWheelerClient.getVehicle();
    twoWheeler->printVehicle();
    delete vehicle;
}