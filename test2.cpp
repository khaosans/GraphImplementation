#include <iostream>
using namespace std;
class base
{
      public:
             base(){ data = 0;}
             ~base(){ data = 0;}
             base(int number){ data = number;}
             virtual void add(int num){ data= num;}
             friend ostream & operator<<(ostream &, const base&);
      protected:
              int data;
};

class derived : public base
{
      public:
             derived(){number = 0.0;}
             ~derived(){number = 0.0;}
             void add(int data){number = data;};
             derived(float num, int num2) { data = num2,  number = num;}
             void display(){ cout<<"float "<<number<<endl;}
      protected:
              float number;
};


int main()
{
    base b(10);
    derived d(10.1,17);
    
    base * pb = &d;
    
    derived * pd; 
    
    
    pd = dynamic_cast<derived*>(pb);
    
    cout<<*pd;
    
    cin.get();
    exit(0);
    
}

ostream & operator<<(ostream & out, const base& op2)
{
        out<<op2.data;
        return out;
}
