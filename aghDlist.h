/**
* \file aghDlist.h
* \author Beata Gie³baga & Kamil Dawidów
* \date 03.06.2014
* \brief Deklaracja i definicja szablonu klasy aghDlist
*/
// -------------------------------------------------------------------------

#ifndef AGHDLIST_H
#define AGHDLIST_H
// -------------------------------------------------------------------------

#include "aghDnode.h"
#include "aghContainer.h"
// -------------------------------------------------------------------------

/**
* \class aghDlist
* \author Beata Gie³baga & Kamil Dawidów
* \date 03.06.2014
* \brief Szablon klasy aghDlist implementuj¹cej listê podwójnie wi¹zan¹
// -------------------------------------------------------------------------
*/
template <class T>
class aghDlist : public aghContainer<T>
{
private:
    aghDnode<T>* head = nullptr; ///< wskaŸnik do pierwszego elementu listy
    aghDnode<T>* tail = nullptr; ///< wskaŸnik do ostatniego elementu listy
    int length = 0; ///< iloœæ elementów w liœcie

    /// \brief Metoda zwraca wskaŸnik do ¿¹danego wêz³a
    ///
    /// \param n - indeks wêz³a
    /// \return wskaŸnik do wêz³a
    aghDnode<T>* getDnodePtr(int n) const;
public:
    /// \brief Konstruktor bezparametrowy
    aghDlist();

    /// \brief Konstruktor kopiuj¹cy
    ///
    /// \param pattern - referencja do obiektu macierzystego
    aghDlist(const aghDlist<T>& pattern);

    /// \brief Konstruktor kopiuj¹cy przyjmuj¹cy jako argument referencjê do obiektu klasy aghContainer
    ///
    /// \param pattern - referencja do obiektu macierzystego
    aghDlist(const aghContainer<T>& pattern);

    /// \brief Destruktor
    ~aghDlist();

    /// \brief Metoda  zwraca wartoœæ elementu
    ///
    /// \param n - indeks zwracanego elementu
    T& at(int n) const;

    /// \brief Metoda  zwraca iloœæ elementów w pojemniku
    ///
    /// \return zwraca iloœæ elementów elementów
    int size(void) const;

    /// \brief Metoda wstawia element w podane miejsce
    /// 
    /// \param n - miejsce, w które zostanie wstawiony element
    /// \param element - referencja do elementu, który zostanie wstawiony
    /// \return metoda zwraca:
    /// \li true - gdy uda siê wstawiæ element
    /// \li false - gdy nie uda siê wstawiæ elementu
    bool insert(int n, T const& element);

    /// \brief Metoda usuwa wybrany element
    ///
    /// \param n - indeks usuwanego elementu
    /// \return zwraca:
    /// \li true - gdy uda siê usun¹æ element
    /// \li false - gdy nie uda siê usun¹æ elementu
    bool remove(int n);

    /// \brief Prze³adowanie operatora przypisania "="
    ///
    /// \param right - referencja do obiektu macierzystego
    /// \return zwraca referencjê do obiektu macierzystego
    aghDlist<T>& operator=(aghDlist<T> const& right);

};
// -------------------------------------------------------------------------
// Definicje metod szablonu
// -------------------------------------------------------------------------

template <class T>
aghDnode<T>* aghDlist<T>::getDnodePtr(int n) const
{
    if (this->invalidIndex(n))
        throw aghException(0, "Index out of range", __FILE__, __LINE__);
    aghDnode<T> *it = head;
    for (int i = 0; i < n; ++i)
        it = it->getNext();
    return it;
}
// ---------------------------------------------------------------

template <class T>
aghDlist<T>::aghDlist()
{
}
// ---------------------------------------------------------------

template <class T>
aghDlist<T>::aghDlist(const aghDlist<T>& pattern)
{
    this->operator=(pattern);
}
// ---------------------------------------------------------------

template <class T>
aghDlist<T>::aghDlist(const aghContainer<T>& pattern)
{
   this->aghContainer::operator=(pattern);
}
// --------------------------------------------------------------

template <class T>
aghDlist<T>::~aghDlist()
{
    aghDnode<T>* it = head;
    aghDnode<T>* helper;

    for (int i = 0; i < this->size(); ++i)
    {
        helper = it;
        it = it->getNext();
        delete helper;
    }
}
// ---------------------------------------------------------------

template <class T>
T& aghDlist<T>::at(int n) const
{
    if (this->invalidIndex(n))
        throw aghException(0, "Index out of range", __FILE__, __LINE__);
    aghDnode<T>* helper = this->getDnodePtr(n);
    return helper->getData();
}
// --------------------------------------------------------------

template <class T>
int aghDlist<T>::size(void) const
{
    return length;
}
// ---------------------------------------------------------------

template <class T>
bool aghDlist<T>::insert(int n, T const& element)
{
    if (n < 0 || n > this->size())
        return false;

    aghDnode<T>* helper = head;
    if (n == 0)
    {
        head = new aghDnode<T>;
        head->setNext(helper);
        head->setData(element);
        head->setPrev(nullptr);
        if (tail == nullptr)
            tail = head;
        if (helper != nullptr)
            helper->setPrev(head);
    }
    else if (n == this->size())
    {
        helper = tail;
        tail = new aghDnode<T>;
        tail->setData(element);
        tail->setNext(nullptr);
        tail->setPrev(helper);
        helper->setNext(tail);
    }
    else
    {
        aghDnode<T>* it = this->getDnodePtr(n);
        helper = it->getPrev();
        helper->setNext(new aghDnode<T>);
        helper->getNext()->setData(element);
        helper->getNext()->setNext(it);
        it->setPrev(helper->getNext());
    }

    ++length;
    return true;

}
// --------------------------------------------------------------

template <class T>
bool aghDlist<T>::remove(int n)
{
    if (this->invalidIndex(n))
        return false;

    aghDnode<T>* helper = head;
    if (n == 0)
    {
        head = head->getNext();
        if (head != nullptr)
        {
            head->setPrev(nullptr);
            if (helper->getNext() != nullptr)
                helper->setPrev(head);
        }
        else
            tail = nullptr;
    }
    else if (n == this->size() - 1)
    {
        helper = tail;
        tail = tail->getPrev();
        if (tail != nullptr)
        {
            tail->setNext(nullptr);
            if (helper->getPrev() != nullptr)
                helper->setNext(tail);
        }
        else
            head = nullptr;
    }
    else
    {
        helper = this->getDnodePtr(n);
        helper->getNext()->setPrev(helper->getPrev());
        helper->getPrev()->setNext(helper->getNext());
       
    }
    delete helper;
    --length;
    return true;
}
// ---------------------------------------------------------------

template <class T>
aghDlist<T>& aghDlist<T>::operator=(const aghDlist<T>& right)
{
    this->aghContainer::operator=(right);
    return *this;
}
// ---------------------------------------------------------------

#endif
