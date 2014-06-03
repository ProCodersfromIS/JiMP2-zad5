/**
* \file aghDlist.h
* \author Beata Gie�baga & Kamil Dawid�w
* \date 03.06.2014
* \brief Deklaracja i definicja szablonu klasy aghDlist
*/
// -------------------------------------------------------------------------

#ifndef AGHDLIST_H
#define AGHDLIST_H
// -------------------------------------------------------------------------

#include "aghDnode.h"
// -------------------------------------------------------------------------

/**
* \class aghDlist
* \author Beata Gie�baga & Kamil Dawid�w
* \date 03.06.2014
* \brief Szablon klasy aghDlist implementuj�cej list� podw�jnie wi�zan�
// -------------------------------------------------------------------------
*/
template <class T>
class aghDlist
{
private:
    aghDnode* head; ///< wska�nik do pierwszego elementu listy
    aghDnode* tail; ///< wska�nik do ostatniego elementu listy
    int length; ///< ilo�� element�w w li�cie

public:
    /// \brief Konstruktor bezparametrowy
    aghDlist();

    /// \brief Konstruktor kopiuj�cy
    ///
    /// \param pattern - referencja do obiektu macierzystego
    aghDlist(const aghDlist<T>& pattern);

    /// \brief Konstruktor kopiuj�cy przyjmuj�cy jako argument referencj� do obiektu klasy aghContainer
    ///
    /// \param pattern - referencja do obiektu macierzystego
    aghDlist(const aghContainer<T>& pattern);

    /// \brief Destruktor
    ~aghDlist();

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
    aghDlist<T>& operator=(aghDlist<T> const& right);

};
// -------------------------------------------------------------------------
// Definicje metod szablonu
// -------------------------------------------------------------------------

template <class T>
aghDlist<T>::aghDlist<T>()
{
    head = nullptr;
    tail = nullptr;
    length = 0;
}
// ---------------------------------------------------------------

template <class T>
aghDlist<T>::aghDlist(const aghDlist<T>& pattern)
{

}
// ---------------------------------------------------------------

template <class T>
aghDlist<T>::~aghDlist<T>()
{

}
// ---------------------------------------------------------------

template <class T>
T& aghDlist<T>::at(int n) const
{
    if (this->invalidIndex(n))
        throw aghException(0, "Index out of range", __FILE__, __LINE__);

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

}
// --------------------------------------------------------------

template <class T>
bool aghDlist<T>::remove(int n)
{

}
// ---------------------------------------------------------------

template <class T>
aghDlist<T>& aghDlist<T>::operator=(const aghDlist<T>& pattern)
{
    this->aghContainer::operator(right);
    return *this;
}
// ---------------------------------------------------------------

#endif
