#include "linked_list.h"

template<class T>
void LinkedList<T>::push_front(const T &value) 
{
    /*
     * TODO: homework
     */
    ListNode<T>* ntemp = new ListNode<T>();
    ntemp->setData(value);

    if (head == 0)
    {
        head = ntemp;
        tail = ntemp;
        count++;
    }
    else
    {
        ntemp->setNext(head);
        head->setPrev(ntemp);
        head = ntemp;
        count++;
    }
}

template<class T>
void LinkedList<T>::push_back(const T &value) 
{
    /*
     * TODO: homework
     */
    ListNode<T>* ntemp = new ListNode<T>();
    ntemp->setData(value);

    if (head == 0)
    {
        head = ntemp;
        tail = ntemp;
        count++;
    }
    else
    {
        ntemp->setPrev(tail);
        tail->setNext(ntemp);
        tail = tail->getNext();
        count++;
    }
}

template<class T>
void LinkedList<T>::pop_back() 
{
    /*
     * TODO: homework
     */
    if (head == 0)
    {
        return;
    }
    else
    {
        ListNode<T>* temp = tail;
        tail = tail->getPrev();
        tail->setNext(0);
        delete temp;
        count--;
    }
}

template<class T>
void LinkedList<T>::pop_front() 
{
    /*
     * TODO: homework
     */
    if (head == 0)
    {
        return;
    }
    else
    {
        ListNode<T>* ntemp;
        ntemp = head;
        head = head->getNext();
        head->setPrev(0);
        delete ntemp;
        count--;
    }
}

template<class T>
void LinkedList<T>::remove(T &val) 
{
    /*
     * TODO: homework
     */
    if (head == 0)
    {
        return;
    }
    else
    {
        if (val < 1)
        {
            push_front();
        }
        else if (val >= count)
        {
            push_back();
        }
        else
        {
            ListNode<T>* temp = head;

            for (int i = 0; i < val - 1; i++)
            {
                temp = temp->getNext();
            }
            ListNode<T>* todelete = temp->getNext();
            temp->setNext(todelete->getNext());
            todelete->getNext()->setPrev(temp);
            delete todelete;
            count--;
        }
    }
}

/*
 * merge in ascending order
 */
template<class T>
void LinkedList<T>::merge(const List<T> &ot) 
{
    /*
     * TODO: homework
     */
}

template<class T>
void LinkedList<T>::reverse_iterative() 
{
    /*
     * TODO: homework
     */
    ListNode<T>* current = head,
        prev = NULL,
        next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}