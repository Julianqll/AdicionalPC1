#include <iostream>
#include "type.h"
#include "stack.h"
#include "queue.h"
#include "linkedlist.h"
#include "operators.h"

using namespace std;

const int nElem = 20;

int main()
{
  TX vect[nElem] = {5,30,40, 7,80, 90, 3,25, 54,47, 
                  3, 6, 12, 8, 25, 27, 19, 83, 9, 0};
  /*Queue<TX> queue;
  for(auto x=0; x<10; x++)
  {
    queue.insert(vect[x]);
    cout << queue << endl;
  }
  cout << endl;

  for(auto x=0; x<10; x++)
  {
      auto dato = queue.pop();
      cout << "dato removido: " << dato << endl;
      cout << queue <<endl;
  }*/

  /*int x = 6;
  int *px;
  px = &x;
  *px += 20;
  cout << x << endl;*/

  int z = 5;
  LinkedList<TX> mylist;
  for(auto x=0; x<10; x++)
  {   mylist.insert_at_tail(vect[x]);
      cout << mylist << " ... " << z << "hola " <<endl;
  }
  cout << endl;

  for(auto x=10; x< nElem; x++)
  {   mylist.insert_at_head(vect[x]);
      cout << mylist << endl;
  }
  
 //myList[5] = 14;

  Iterator<TX> iter= new Iterator (mylist.begin() , mylist.begin()-> getData())
  for(auto iter= mylist.begin() ; iter != mylist.end() ; iter= node.getNext())
  {
      cout << *iter << endl;
  }

  /*while( !mylist.empty() )
  {   
      auto dato = mylist.PopHead();
      cout << "dato removido: " << dato << endl;
      cout << mylist <<endl;
  }*/

  try
  {
      auto dato = mylist.PopHead();
      cout << "abc" << endl;
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
  /*Stack<T1> stack;
  Stack<T1> *pStack = new Stack<T1>;

  auto w = "hola";
  auto x = 0; 
  for( x = 0 ; x < nElem ; x++ )
     stack.push(x+x);
  
  for( x = 0 ; x < nElem ; x++ )
  {
    auto y = stack.pop();
    cout << y << endl;
  }
  */
}