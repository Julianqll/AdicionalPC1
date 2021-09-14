#ifndef __LINKEDLIST_H__  // # es una DIRECTIVAs al PreCOMPILADOR
#define __LINKEDLIST_H__ 
using namespace std;

template <typename T>
class LinkedList
{
   class Node
  { private:
      T       m_data;
      Node   *m_pNext;
    public:
      Node(T data, Node *pNext = nullptr) : m_data(data), m_pNext(pNext)
      {};
      T         getData()                {   return m_data;    }
      T        &getDataRef()             {   return m_data;    }
      void      setpNext(Node *pNext)    {   m_pNext = pNext;  }
      Node     *getpNext()               {   return m_pNext;   }
  };
  private:
    Node    *m_pHead = nullptr, 
            *m_pTail = nullptr;
    size_t   m_size  = 0;
  public:
    // LinkedList() {}
    void    insert_at_head(T elem);
    void    insert_at_tail(T elem);
    Node    *begin() ;              //Error
    Node    *end() ;             
    T       PopHead();
    size_t  size()  const       { return m_size;       }
    bool    empty() const       { return size() == 0;  }

    ostream & print(ostream &os);
    T &operator[](size_t pos); //
};

template <typename T>
void LinkedList<T>::insert_at_head(T elem)
{
  Node *pNew = new Node(elem, m_pHead);
  m_pHead = pNew;
  m_size++;
}

template <typename T>
void LinkedList<T>::insert_at_tail(T elem)
{
    Node *pNew = new Node(elem);
    if(m_pTail)
    {  m_pTail->setpNext(pNew);
    }
    m_pTail = pNew;
    if(!m_pHead)
    { m_pHead = pNew;   }
    m_size++;
}
//----
template <typename T>
Node LinkedList<T>::begin()
{
  return *m_pHead;
}

template <typename T>
T LinkedList<T>::PopHead()
{
    if(m_pHead)
    {
        Node *pNode = m_pHead;
        T data = pNode->getData();
        m_pHead = m_pHead->getpNext();
        delete pNode;
        m_size--;
        return data;
    }
    throw "hola excepcion";
}

template <typename T>
T &LinkedList<T>::operator[](size_t pos)
{
  assert(pos <= size());
  Node *pTmp = m_pHead;
  for(auto i= 0 ; i < pos ; i++)
    pTmp = pTmp->getpNext();
  return pTmp->getDataRef();
}

template <typename T>
ostream &LinkedList<T>::print(ostream &os)
{
  Node *pNode = m_pHead;
  while(pNode)
  {
    os << pNode->getData() << ", ";
    pNode = pNode->getpNext();
  }
  return os;
}

template <typename T>
class Iterator
{private:
    // using Node = typename LinkedList<T>::Node;
    typename LinkedList<T>::Node *m_pNode;
 public:
    Iterator(typename LinkedList<T>::Node *pNode, T data) : m_pNode(pNode) {} //errro 1 typename
    bool operator==(Iterator &iter)       { return m_pNode == iter.m_pNode; }
    bool operator!=(Iterator &iter)       { return m_pNode != iter.m_pNode; }
    T &operator*()                        { return *m_pNode->getData();     }
    void operator++();
};

template <typename T>
void Iterator<T>::operator++()
{
    m_pNode = m_pNode->getpNext();
}

#endif