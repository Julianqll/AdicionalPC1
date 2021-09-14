#include <iostream>
#include <vector>

#include "type.h"
#include "stack.h"
#include "queue.h"
#include "linkedlist.h"
#include "operators.h"

using namespace std;

const TX nElem = 20;

TX main()
{
  TX vect[nElem] = {5,30,40, 7,80, 90, 3,25, 54,47, 
                  3, 6, 12, 8, 25, 27, 19, 83, 9, 0};

  vector<TX> v1;
  cout<< "linkedlist"<< endl;
  TX z = 5;
  LinkedList<TX> mylist;
  for(auto x=0; x<10; x++)
  {   mylist.insert_at_tail(vect[x]);
      cout << mylist <<endl;
  }
  cout << endl;
  cout<< "linkedlist aumentando mas datos"<< endl;

  for(auto x=10; x< nElem; x++)
  {   mylist.insert_at_head(vect[x]);
      cout << mylist << endl;
  }
  
  mylist[5] = 14;

  cout<<endl<< "recorrido por iterator"  << endl;
  LinkedList<TX>::iterator iter = mylist.begin();
  for(; iter != mylist.end() ; ++iter)
  {
      cout << *iter << endl;
  }


  try
  {
      auto dato = mylist.PopHead();
      cout <<endl<< "Correcto" << endl;
  }
  catch(int n) 
  {
    cout << "Excepcion atrapada ... puedes continuar !!!" <<endl;
  }
  catch(double n) 
  {
    cout << "Excepcion de doubles atrapada ... puedes continuar !!!" <<endl;
  } 
  catch(exception n) 
  {
    cout << "Excepcion generica atrapada ... puedes continuar !!!" <<endl;
  }  
  catch( ... )
  {
      cout << "todo lo demas atrapada ... puedes continuar !!!" <<endl;
  }
  cout << "Finalizando el programa ..." << endl;
  
  char c = 'A';

}