
#include <iostream>

using namespace std;

class list{
      
      public:
             list();
             list(const list&);
             list(char *);
             ~list();
             list & operator=(const list &);
             void copy(const list &);
             friend ostream & operator<<(ostream &,const list &);
             friend istream & operator>>(istream &,list &);
             friend list operator+(const list & op1, const list & op2); 
             list & operator+=(const list & obj1);
             
             
      private:
              char * info;
};

class derived : public list
{
      public      
      
}
int main()
{
    
    list obj1("test1 ");
    
    list obj2("test2 ");
    
    list obj3;
    
    obj1 += obj2;
    
    cout<<obj1;

    
    cin.get();
    cin.get();
    return 0;
}


list::list(): info(NULL) {}

list::list(const list& to_copy)
{
     copy(to_copy);
}

list::list(char * add)
{
     info = new char[strlen(add)+1];
     strcpy(info,add);
} 

list::~list()
{
             delete info;
             info = NULL;
}
          
list & list::operator=(const list & op1)
{
     if(this == &op1)
             return * this;
     if(info)
             delete info;
             
     info = new char[strlen(op1.info)+1];
     strcpy(info,op1.info);
}

void list::copy(const list & to_copy)
{
     info = new char[strlen(to_copy.info)+1];
     strcpy(info,to_copy.info);
}
                 
ostream & operator<<(ostream & out,const list & op2)
{
        out<<op2.info;
        return out;
}

istream & operator>>(istream & in, list & op2)
{
       char temp[100];
       if(op2.info)
                   delete op2.info;
       
       in>>temp;
       op2.info = new char[strlen(temp)+1];
       strcpy(op2.info,temp);
       
       return in;
}

list operator+(const list & op1, const list & op2)
{
     list temp;
     temp.info = new char[strlen(op1.info)+strlen(op2.info)];
     strcpy(temp.info, op1.info);
     strcat(temp.info, op2.info);
     return temp;
}
     
list & list::operator+=(const list & op1)
{
     char * temp = new char[strlen(op1.info)+strlen(this->info)+1];
     strcpy(temp, this->info);
     strcat(temp, op1.info);
     delete this->info;
     this->info = new char[strlen(op1.info)+strlen(this->info)+1];
     strcpy(this->info, temp);
}  
     
     

