#include<iostream>
using namespace std;

class Payment{
    public:
        virtual void pay()=0;
        virtual ~Payment(){}
};

class UPI:public Payment{
    public:
        void pay() override{
            cout<<"Paying with UPI \n";
        }
};

class Cash:public Payment{
    public:
        void pay() override{
            cout<<"Paying with Cash \n";
        }
};

class PaymentFactory{
    public:
    virtual Payment *givePayment()=0;
    virtual ~PaymentFactory(){}
};

class UpiPaymentFactory:public PaymentFactory{
    Payment *givePayment() override{
        return new UPI();
    }
};

class CashPaymentFactory:public PaymentFactory{
    Payment *givePayment() override{
        return new Cash();
    }
};

class Client{
    private:
    Payment *payment;
    public:
    Client(PaymentFactory *paymentFactory){
        payment=paymentFactory->givePayment();
    }

    Payment *getPaymentType(){
        return payment;
    }
};

int main(){
    PaymentFactory *factory=new UpiPaymentFactory();
    Client client(factory);
    Payment *upi=client.getPaymentType();
    upi->pay();
    delete factory;
}