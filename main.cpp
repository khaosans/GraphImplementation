//Souriya Khaosanga
//CS201 HW5

//The point of this program was to develop a graph
//that stored struct nodes and struct link which
//are the ajacent list.

#include <iostream>
//This library is used for cin and cout.
#include <vector>
//This library is used for the vector to store in
//numbers from the user.
#include <sstream>
//Library used for istringstream.


using namespace std;
//using std scope

        


//definitions are shown below
typedef struct link_tp * link_ptr_tp; 
typedef struct node_tp * node_ptr_tp;


//structs are defined below
typedef struct link_tp
{
	link_ptr_tp	next_link;	// point to next link
	node_ptr_tp	adj_node;	// point to successor node
} str_link_tp;

typedef struct node_tp
{
	link_ptr_tp	link;		// points to LL of successors
	node_ptr_tp	finger;	// finger through all nodes
	int				name;		// name given at creation
	bool		   visited;	// to check connectivity

} str_node_tp;

//global is defined below
node_ptr_tp global_finger = NULL;

//Prototype functions are defined below
node_ptr_tp make_node( int name ); //function builds a node

void get_input(int & num1, int & num2); //gets input from the user

bool exist(int to_find); //checks to find if the number already exist

void build(int num1, int num2); //builds the integers

bool new_link( node_ptr_tp first, node_ptr_tp second ); //checks for link from
//first node ptr to the second node ptr

link_ptr_tp make_link( link_ptr_tp one, node_ptr_tp two); //creakes a link
//between the what one ptr is pointing to to the two poiter

node_ptr_tp match(int num); //function returns the pointer to a number
//that matches the argument num

void sucessor();//displays graph 

void adjacent(link_ptr_tp current);//displays the sucessors of each node


//The main part of the body exist below here.
int main()
{
    
     
     int num1, num2;
     //create two numbers which are modified  by reference
     //using the build function
     
     cout<<"Input 1 to 2 integers seperated by a space followed by enter."<<endl;
     cout<<"The integer must be between 1 and 999."<<endl;
     cout<<"After completion enter 0 to quit and display the graph. "<<endl;

     do{
          get_input(num1,num2);
          build(num1,num2);
          num2=0;
          //num2 to 0
     }while(num1 != 0); //function continues to get input from user
     //so long as the number 0 is not inputted.

    


     
     sucessor();
     //display the graph nodes and sucessor list
    


  

    
    
    cin.get();
    //pause the program    
    return 0;   
}

void adjacent(link_ptr_tp head_link)
{
     link_ptr_tp current = head_link;
     //create that is pointint to the head
     //of the link nodes
     
     while(current)
     {
                   cout<<current->adj_node->name<<" ";
                   current = current->next_link;
                   //traverse
     }
     //traverse and print out each adjacent node
     
}


         

void sucessor()
//function is ised to display the entire graph and sucessors
{
     node_ptr_tp current = global_finger;
     //create a pointer to the global finger
   
    
     while(current)
     {
           cout<<"Node "<<current->name<<" successors are: ";
           adjacent(current->link);//print the sucessors of each node
           current = current->finger;//traverse
           cout<<endl;

     }
     
     return;
     
                        
}

node_ptr_tp match(int num)
//function is used to return a poiter to the node of 
//a matching number
{
            node_ptr_tp current;//create a node pointer that is
            //current
            
            while(current)
            {
                          if(current->name == num) //if the node exist
                                           return current;//return the 
                                           //current pointer
                 current = current->finger;//traverse
            }
}
     

node_ptr_tp make_node( int name )
//function creates a pointer to the int  of the name
{   
    // make_node
	node_ptr_tp node = new str_node_tp;
	
	// check once non-Null, not repeatedly on user side!
	node->finger	 = global_finger;	// re-assign glob finger!!
	node->link	   = NULL;		// pointer type
	node->name	   = name;		// IDs this node
	node->visited	= false;		// initially
	global_finger	= node;		// now link to “this”
	return node; //return that node pointer
} 


void get_input(int & num1, int & num2)
//function is used to get input from the user or stdin
{   
    string line;//create line which it takes input from
    
    getline(cin, line);//Get and cin each input
    
    istringstream in(line, std::istringstream::in);//store those ints
    
    int n; //initialize a n for pushing onto heap
    
    vector<int> v; //create an array vector in
    
    while (in >> n) {
        v.push_back(n);
    }//while there is a number in vector push back n
    
    num1 = 0;//initialize num1 as zero 
    
    num2 = 0;//initialize num2 as zero

    if(v[0] == 0 )//if the input is 0
            return;//get out
    if(v[0] > 0 && v[0] <= 999)
    {
            num1 = v[0];
    }//if number is between 0 and 99
    
    

    
    if(v[1] <= 999  && v[1] > 0)//if input number between 999 and 0
    { 
            num2 = v[1];//store num2 as vector subscript 1
    }
    else{
         num2 = 0;
    }
    
}

bool exist(int to_find)
//function used to check if a node of that number exists
{
    node_ptr_tp current = global_finger;
    //store the current as the global finger
    //or head of the graph
    
    while(current)
    {
                  if(current->name == to_find)
                  {
                       
                       return true;//if the the node of to_find exist
                  }
    current = current->finger;//traverse
    }
    return false;
}                 

void build(int num1, int num2)
//function is used to build from two numbers
{
     
     //create pointers below
     node_ptr_tp first;
     node_ptr_tp second;
     link_ptr_tp linkup;
     
     if(num1 == 0)
     {
             cout<<"Exited input"<<endl;
             cout<<"---Printing the graph now---"<<endl;
             return;//get out of the function
     }
     if(!exist(num1) && num2 ==0)
     //if num1 input and num2 is  zero
     {
          cout<<"node "<<num1<<" is new "<<endl;
          first = make_node(num1);
          //create the node of num1
     }
     else if(!exist(num1) && num2 != 0)
     //if num1 exist and the num2 not equal to zero
     {
          cout<<"node "<<num1<<" is new "<<endl;
          first = make_node(num1);
          //create the node of num1
     }
     else{        
          first = match(num1);
          //first is a pointer to the matching node
          cout<<"node "<<num1<<" pre-existed"<<endl;
     }
     
     if(!exist(num2) && num2 !=0)
     //if num2 exist and num2 is not equal to zero
     {
          cout<<"node "<<num2<<" is new"<<endl;
          second = make_node(num2);
          //make a node at second;
     }
     else{
          if(num2 == 0)
          //if num2 is equal to zero
          {
                  return;//get out
          }
          else{
          second = match(num2);
          //second is a pointer to node that matches num2
          cout<<"node "<<num2<<" pre-existed"<<endl;
          }
     }
     
              
     if(new_link(first,second)) 
     //used to create link between two nodes
     {
           linkup = make_link(first->link, second);
           //linkup is a pointer between the first and second input
           first->link = linkup;
           //set the link of first to linkup
           cout<<"Set link from "<<first->name<<" to "<<linkup->adj_node->name<<endl;
     }
     else{
          cout<<"Link already exist"<<endl;
          
          }
          
     
     return;
 
}
    
link_ptr_tp make_link( link_ptr_tp one, node_ptr_tp two)
//function is used to add a link between argument one and two
{  
            
    if(!one)
    //if no nodes exist
    {
         one = new str_link_tp;
         one->adj_node = two;
         one->next_link = NULL;
    }
    else{
         //add to the front of the linear linked list
         //of links
         link_ptr_tp temp = new str_link_tp;
         temp->next_link = one;
         temp->adj_node = two;
         one = temp;
    }
    
    return one;
    //return that pointer

}


bool new_link( node_ptr_tp first, node_ptr_tp second )
//function is usesd to determine if a new link is needed
//depending on the first and second arguments
{   
    // new_link
	int target			= second->name;
	link_ptr_tp link	= first->link;

	while ( link ) {
			if ( target == link->adj_node->name ) {
				return false; // it is an existing link, NOT new
			} //end if
			// check next node; if any
			link = link->next_link;
	} //end while
	
	// none of successors equal the second node's name
	return true; 			 // is a new link
} //end new_link

