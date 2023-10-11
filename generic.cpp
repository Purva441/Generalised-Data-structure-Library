#include<iostream>
using namespace std;
template <class T>
struct NodeS
{
    T data;
    struct NodeS*next;
};
template <class T>
struct NodeD
{
    T data;
    struct NodeD*next;
    struct NodeD*prev;
};

template <class T>
class SinglyLL
{
    public:
    struct NodeS<T>*first;
    int iCount;
    SinglyLL();
    void Display();
    int Count();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);

};
template <class T>
SinglyLL <T>::SinglyLL()
{
    first = NULL;
    iCount = 0;
}

template <class T>
void SinglyLL<T>::Display()
{
    cout<<"Elements of Singly Linear Linked list are : "<<"\n";

    NodeS<T> * temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp -> next;
    }
    cout<<"NULL"<<"\n";
}

template <class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyLL<T>::InsertFirst(T no)
{
    NodeS<T> * newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertLast(T no)
{
    NodeS<T> * newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        NodeS<T> *temp = first;

        while(temp->next != NULL)
        {
            temp= temp -> next;
        }
        temp->next = newn;
    }
    iCount++;
}
template <class T>
void SinglyLL<T>::InsertAtPos(T no, int iPos)
{   
    int iCount = Count();

    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        NodeS<T> * temp = first;
        NodeS<T> * newn = new NodeS<T>;

        newn-> data = no;
        newn-> next = NULL;

        for(int iCnt = 1; iCnt < iPos -1; iCnt++)
        {
            temp = temp -> next;
        }

        newn->next = temp -> next;
        temp -> next = newn;
        
        iCount++;
    }
}
template <class T>
void SinglyLL<T>::DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if(first -> next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodeS<T> *temp = first;

        first = first->next;
        delete temp;
    }
    iCount--;
}
template <class T>
void SinglyLL<T>::DeleteLast()
{
        if(first == NULL)
    {
        return;
    }
    else if(first -> next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodeS<T> *temp = first;

        while(temp ->next -> next!= NULL)
        {
            temp = temp -> next;
        }

        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}
template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    int iCount = Count();

    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeS<T> * temp1 = first;
        NodeS<T> * temp2 = NULL;

        for(int iCnt = 1; iCnt < iPos -1; iCnt++)
        {
            temp1 = temp1 -> next;
        }

        temp2 = temp1->next->next;
        delete temp1->next;
        temp1->next = temp2;
        
        iCount--;
    }
}

template <class T>
class SinglyCL
{
    public:
    struct NodeS <T>* first;
    struct NodeS <T>* last;
    int iCount;

    SinglyCL();
    void Display();
    int Count();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);

};
template <class T>
SinglyCL <T> ::SinglyCL()
{
    first = NULL;
    last= NULL;
    iCount = 0;

}

template <class T>
void SinglyCL <T>:: Display()
{
    cout<<"Elements of Singly circular Linked list are : "<<"\n";

    NodeS<T> * temp = first;
    do
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp -> next;
    }while (first != last->next);
    cout<<"NULL"<<"\n";

}
template <class T>   
int SinglyCL<T>:: Count()
{
    return iCount;
}
template <class T>   
void  SinglyCL <T>::InsertFirst(T no)
{
    NodeS<T> * newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;
    if((first==NULL)&&(last==NULL))
    {
        first =newn;
        last= newn;
    }
    else
    {
        newn->next=first;
        first=newn;

    }
    last->next=first;

}
template <class T>  
void SinglyCL <T>:: InsertLast(T no)
{
    NodeS<T> * newn = new NodeS<T>;
    newn->data = no;
    newn->next = NULL;
    if((first ==NULL) && (last ==NULL))
    {
        first= newn;
        last=newn;
    }
    else
    {
        last->next=newn;
        last=last->next;
    }
    last->next=first;



}
template <class T> 
void  SinglyCL <T>::InsertAtPos(T no,  int iPos)
{
    int iCnt=0;
    int iLength= 0;

    if((iPos<1)||(iPos>iLength +1))
    {
        cout<<"Invalid postion\n";
    }
    if(iPos ==1)
    {
        InsertFirst(no);
    }
    else if(iPos==iLength+1)
    {
        InsertLast(no);
    }
    else
    {
        NodeS<T> * temp = first;
        NodeS<T> * newn = new NodeS<T>;
        for(iCnt=1;iCnt<iPos;iCnt++)
        {
            temp =temp->next;
        }
        newn-> data = no;
        newn-> next = NULL;

        newn->next= temp->next;
        temp->next=newn;
    }
}
template <class T> 
void SinglyCL <T>:: DeleteFirst()
{
    if ((first ==NULL)&&(last=NULL))
    {
        return ;
    }
   else if(first =last)
   {
     free (first);
     first = NULL;
     last  = NULL;
   }
   else
   {
     first = first->next;
     free(last->next);
     last->next =first;
   }
   
}
template <class T> 
void  SinglyCL <T>::DeleteLast()
{
    NodeS<T> * temp = first;
    if ((first ==NULL)&&(last=NULL))
    {
        return ;
    }
   else if(first =last)
   {
     free (first);
     first =NULL;
     last =NULL;
   }
   else
   {
     while(temp->next !=first)
     {
        temp= temp->next;
     }
    
   }
   free(last);
   last =temp;
   last->next = first;
}
template <class T> 
void SinglyCL <T>:: DeleteAtPos(int iPos)
{
    int iLength =0;
    int iCnt =0;
    NodeS<T> * temp = first;
    NodeS<T> * tempX = NULL;

    if((iPos<1)||(iPos>iLength+1))
    {
        cout<<"Invalid position\n";
    }
    if(iPos==1)
    {
        DeleteFirst();
    }
    else if(iPos ==iLength +1)
    {
        DeleteLast();
    }
    else
    {
        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp -> next;
        }

        tempX = temp->next;

        temp->next = temp->next->next;
        free(tempX);

    }
}
template <class T>
class DoublyLL
{
    public:
    struct NodeD<T>*first;
    struct NodeD<T>*last;
    int iCount;
    DoublyLL();
    void Display();
    int Count();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);


};
template <class T>
DoublyLL <T> ::DoublyLL()
{
    first = NULL;
    iCount = 0;

}  

template <class T>
void DoublyLL <T>:: Display()
{
    cout<<"Elements of Doubly Linear Linked list are : "<<"\n";

    NodeD<T> * temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp -> next;
    }
    cout<<"NULL"<<"\n";


}
template <class T>   
int  DoublyLL <T>:: Count()
{
    return iCount;
}
template <class T>   
void  DoublyLL <T>::InsertFirst(T no)
{
    NodeD<T> * newn = new NodeD<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;
    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        first->prev=newn;
        newn->next=first;
        first=newn;
    }
    

}
template <class T>  
void DoublyLL  <T>:: InsertLast(T no)
{
    NodeD<T> * newn = new NodeD<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev-NULL;
    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        NodeD<T> *temp = first;
        while(temp->next!=NULL)
        {
            temp= temp->next;
        }
        temp->next=newn;
        newn->prev=temp;
    }
    

}
template <class T> 
void DoublyLL <T>::InsertAtPos(T no,  int iPos)
{
    int iLength =0;
    int iCnt =0;
    

    if((iPos < 1) || (iPos > iLength+1))
    {
        printf("Invalid position\n");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iLength+1)
    {
        InsertLast(no);
    }
    else
    {
        NodeD<T> * temp = first;
        NodeD<T> * newn = new NodeD<T>;
        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp -> next;
        }

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;      

        newn->next = temp->next;       
        temp->next->prev = newn;        
        temp->next = newn;             
        newn->prev = temp; 
    }             
}
template <class T> 
void DoublyLL <T>:: DeleteFirst()
{
    if(first == NULL)                   
    {
        return;
    }
    else if(first->next == NULL)      
    {
        free(first);
        first= NULL; 
    }
    else                                
    {
        first= first -> next;
        free (first->prev);        
        first-> prev = NULL;       
    }
}
template <class T> 
void DoublyLL <T>::DeleteLast()
{
    if(first == NULL)                   
    {
        return;
    }
    else if(first->next == NULL)      
    {
        free(first);
        first= NULL; 
    }
    else
    {
        NodeD<T> *temp = first;
        while(temp -> next -> next != NULL)     
        {
            temp = temp -> next;
        }

        free(temp->next);
        temp->next = NULL;
    }

}
template <class T> 
void DoublyLL <T>:: DeleteAtPos(int iPos)
{
    int iLength = 0;
    int iCnt = 0;
    
    if((iPos < 1) || (iPos > iLength+1))
    {
        printf("Invalid position\n");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iLength+1)
    {
        DeleteLast();
    }
    else
    {
        NodeD<T> *temp = first;
        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp -> next;
        }
    }
}

template <class T>
class DoublyCL
{
    public:
    struct NodeD<T>*first;
    struct NodeD<T>*last;
    int iCount;
    DoublyCL();
    void Display();
    int Count();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);

};
template <class T>
DoublyCL <T> ::DoublyCL()
{
    first = NULL;
    last= NULL;
    iCount = 0;

}

template <class T>
void DoublyCL <T>:: Display()
{
    
    cout<<"Elements of Doubly circular Linked list are : "<<"\n";

    NodeD<T> * temp = first;
    do
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp -> next;
    }while (first != last->next);
    
    cout<<"NULL"<<"\n";

}
template <class T>   
int  DoublyCL <T>:: Count()
{
    return iCount;
}
template <class T>   
void  DoublyCL <T>::InsertFirst(T no)
{
    NodeD<T> * newn = new NodeD<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;
    if((first == NULL) && (last == NULL))
    {
         first = newn;
         last = newn;
    }
    else
    {
        newn->next = first;
        (first)->prev = newn;

        first= newn;
    }

    (last) -> next = first;
    (first) -> prev = last;
}
template <class T>  
void DoublyCL  <T>:: InsertLast(T no)
{
    NodeD<T> * newn = new NodeD<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;
    if((first == NULL) && (last == NULL))
    {
         first = newn;
         last = newn;

    }
    else
    {
        (last)->next= first;
        newn->prev= last;
        last =newn;
    }
    last->next= first;
    first->prev= last;
}
template <class T> 
void DoublyCL <T>::InsertAtPos(T no,int iPos)
{
    int iLength =0;
    int iCnt =0;
    
    if((iPos < 1) || (iPos > iLength + 1))
    {
        printf("Invalid position\n");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no); 
    }
    else if(iPos == iLength + 1)
    {
        InsertLast(no);
    }
    else
    {
        NodeD<T> * temp = first;
        NodeD<T> * newn = new NodeD<T>;
        for(iCnt = 1; iCnt < iPos -1; iCnt++)
        {
            temp = temp->next;
        }
        newn ->data = no;
        newn->next = NULL;
        newn -> prev = NULL;

        newn->next = temp->next;
        temp -> next -> prev = newn;

        temp->next = newn;
        newn->prev = temp;
    }
}
template <class T> 
void DoublyCL <T>:: DeleteFirst()
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first ==last)
    {
        free(first);
        
        first= NULL;
        last = NULL;
    }
    else 
    {
        first = (first) -> next;
        free((last) -> next);

        (last)->next = first;
        (first)->prev =last;
    }

}
template <class T> 
void DoublyCL <T>::DeleteLast()
{
     if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first== last)
    {
        free(first);
        
        first = NULL;
        last = NULL;
    }
    else 
    {
        first = (first) -> prev;

        free((last)->next);    

        (first)->prev =last;
        (last) -> next =first;
    }

}
template <class T> 
void DoublyCL <T>:: DeleteAtPos(int iPos)
{
    int iLength =0;
    int iCnt =0;
    
    if((iPos < 1) || (iPos > iLength))
    {
        printf("Invalid position\n");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst(); 
    }
    else if(iPos == iLength)
    {
        DeleteLast();
    }
    else
    {
        NodeD<T> * temp = first;
        for(iCnt = 1; iCnt < iPos -1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        free(temp->next->prev);
        temp->next -> prev = temp;
    }

}                                             

int main()
{
    SinglyLL <int>obj1;

    obj1.InsertFirst(51);
    obj1.InsertFirst(21);
    obj1.InsertFirst(11);

    obj1.InsertLast(101);
    obj1.InsertLast(111);

    obj1.InsertAtPos(55,4);
    obj1.Display();
    cout<<"Number of elements are : "<<obj1.Count()<<"\n";

    obj1.DeleteAtPos(4);
    obj1.Display();
    cout<<"Number of elements are : "<<obj1.Count()<<"\n";

    obj1.DeleteFirst();
    obj1.DeleteLast();

    obj1.Display();
    cout<<"Number of elements are : "<<obj1.Count()<<"\n";

    
    SinglyCL<int>obj2;
    obj2.InsertFirst(61);
    obj2.InsertFirst(51);
    obj2.InsertFirst(41);
    
    obj2.InsertLast(121);
    obj2.InsertLast(131);

    obj2.InsertAtPos(111,4);
    obj2.Display();
    obj2.DeleteAtPos(4);

    obj2.Display();
    cout<<"Number of elements are : "<<obj2.Count()<<"\n";
    
    obj2.DeleteFirst();
    obj2.DeleteLast();
    obj2.Display();
    cout<<"Number of elements are : "<<obj2.Count()<<"\n";

    DoublyLL<int>obj3;
    obj3.InsertFirst(41);
    obj3.InsertFirst(31);
    obj3.InsertFirst(21);
    
    obj3.InsertLast(51);
    obj3.InsertLast(61);

    obj3.InsertAtPos(71,4);
    obj3.Display();
    obj3.DeleteAtPos(4);

    obj3.Display();
    cout<<"Number of elements are : "<<obj3.Count()<<"\n";
    
    obj3.DeleteFirst();
    obj3.DeleteLast();
    obj3.Display();
    cout<<"Number of elements are : "<<obj3.Count()<<"\n";
    
    DoublyCL<int>obj4;
    obj4.InsertFirst(121);
    obj4.InsertFirst(111);
    obj4.InsertFirst(101);
    
    obj4.InsertLast(131);
    obj4.InsertLast(141);

    obj4.InsertAtPos(151,4);
    obj4.Display();
    obj4.DeleteAtPos(4);

    obj4.Display();
    cout<<"Number of elements are : "<<obj4.Count()<<"\n";
    
    obj4.DeleteFirst();
    obj4.DeleteLast();
    obj4.Display();
    cout<<"Number of elements are : "<<obj4.Count()<<"\n";
    
}