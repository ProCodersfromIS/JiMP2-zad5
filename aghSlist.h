/**
* \file aghSlist.h
* \author Beata Gie�baga & Kamil Dawid�w
* \date 03.06.2014
* \brief Deklaracja i definicja szablonu klasy aghSlist
*/
// -------------------------------------------------------------------------

#ifndef AGHSLIST_H
#define AGHSLIST_H
// -------------------------------------------------------------------------

#include "aghSnode.h"
#include "aghContainer.h"
// -------------------------------------------------------------------------

/**
* \class aghSlist
* \author Beata Gie�baga & Kamil Dawid�w
* \date 03.06.2014
* \brief Szablon klasy aghSlist implementuj�cej list� pojedynczo wi�zan�
// -------------------------------------------------------------------------
*/
template <class T>
class aghSlist: public aghContainer<T>
{
private:
    aghSnode<T>* head = nullptr; ///< wska�nik do pierwszego elementu listy
    int length = 0; ///< ilo�� element�w w li�cie

    /// \brief Metoda zwraca wska�nik do ��danego w�z�a
    ///
    /// \param n - indeks w�z�a
    /// \return wska�nik do w�z�a
    aghSnode<T>* getSnodePtr(int n) const;
public:
    /// \brief Konstruktor bezparametrowy
    aghSlist();

    /// \brief Konstruktor kopiuj�cy
    ///
    /// \param pattern - referencja do obiektu macierzystego
    aghSlist(const aghSlist<T>& pattern);

    /// \brief Konstruktor kopiuj�cy przyjmuj�cy jako argument referencj� do obiektu klasy aghContainer
    ///
    /// \param pattern - referencja do obiektu macierzystego
    aghSlist(const aghContainer<T>& pattern);

    /// \brief Destruktor
    ~aghSlist();

    /// \brief Metoda  zwraca warto�� elementu
    ///
    /// \param n - indeks zwracanego elementu
    T& at(int n) const;

    /// \brief Metoda  zwraca ilo�� element�w w pojemniku
    ///
    /// \return zwraca ilo�� element�w element�w
    int size(void) const;

    /// \brief Metoda wstawia element w podane miejsce
    /// 
    /// \param n - miejsce, w kt�re zostanie wstawiony element
    /// \param element - referencja do elementu, kt�ry zostanie wstawiony
    /// \return metoda zwraca:
    /// \li true - gdy uda si� wstawi� element
    /// \li false - gdy nie uda si� wstawi� elementu
    bool insert(int n, T const& element);

    /// \brief Metoda usuwa wybrany element
    ///
    /// \param n - indeks usuwanego elementu
    /// \return zwraca:
    /// \li true - gdy uda si� usun�� element
    /// \li false - gdy nie uda si� usun�� elementu
    bool remove(int n);

    /// \brief Prze�adowanie operatora przypisania "="
    ///
    /// \param right - referencja do obiektu macierzystego
    /// \return zwraca referencj� do obiektu macierzystego
    aghSlist<T>& operator=(aghSlist<T> const& right);

};
// ---------------------------------------------------------------
// Definicje metod szablonu
// ---------------------------------------------------------------

template <class T>
aghSnode<T>* aghSlist<T>::getSnodePtr(int n) const
{
    if (this->invalidIndex(n))
        throw aghException(0, "Index out of range", __FILE__, __LINE__);
    aghSnode<T>* it = head;
    for (int i = 0; i < n; ++i)
        it = it->getNext();
    return it;
}
// ---------------------------------------------------------------

template <class T>
aghSlist<T>::aghSlist()
{
}
// ---------------------------------------------------------------

template <class T>
aghSlist<T>::aghSlist(const aghSlist<T>& pattern)
{
    this->operator=(pattern);
}
// ---------------------------------------------------------------

template <class T>
aghSlist<T>::aghSlist(const aghContainer<T>& pattern)
{
    this->aghContainer::operator=(pattern);
}
// ---------------------------------------------------------------

template <class T>
aghSlist<T>::~aghSlist()
{
    aghSnode<T>* it = head;
    aghSnode<T>* helper;

    for (int i = 0; i < this->size(); ++i)
    {
        helper = it;
        it = it->getNext();
        delete helper;
    }
}
// ---------------------------------------------------------------

template <class T>
T& aghSlist<T>::at(int n) const
{
    if (this->invalidIndex(n))
        throw aghException(0, "Index out of range", __FILE__, __LINE__);
    aghSnode<T>* helper = this->getSnodePtr(n);
    return helper->getData();
}
// --------------------------------------------------------------

template <class T>
int aghSlist<T>::size(void) const
{
    return length;
}
// ---------------------------------------------------------------

template <class T>
bool aghSlist<T>::insert(int n, T const& element)
{
    if (n < 0 || n > this->size())
        return false;

    aghSnode<T>* helper = head;
    if (n == 0)
    {
        head = new aghSnode<T>;
        head->setNext(helper);
        head->setData(element);
    }
    else
    {
        aghSnode<T>* it = this->getSnodePtr(n - 1);
        helper = it->getNext();
        it->setNext(new aghSnode<T>);
        it->getNext()->setData(element);
        it->getNext()->setNext(helper);
    }

    ++length;
    return true;
}
// --------------------------------------------------------------

template <class T>
bool aghSlist<T>::remove(int n)
{
    if (this->invalidIndex(n))
        return false;

    aghSnode<T>* helper = head;
    if (n == 0)
    {
        head = head->getNext();
    }
    else
    {
        aghSnode<T>* it = this->getSnodePtr(n - 1);
        helper = it->getNext();
        it->setNext(helper->getNext());
    }
    delete helper;

    --length;
    return true;
}
// ---------------------------------------------------------------

template <class T>
aghSlist<T>& aghSlist<T>::operator=(const aghSlist<T>& right)
{
    this->aghContainer::operator=(right);
    return *this;
}
// ---------------------------------------------------------------

#endif
