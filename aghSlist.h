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
    aghSnode* head; ///< wska�nik do pierwszego elementu listy
    int length; ///< ilo�� element�w w li�cie

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
aghSlist<T>::aghSlist<T>()
{
    head = nullptr;
    length = 0;
}
// ---------------------------------------------------------------

template <class T>
aghSlist<T>::aghSlist(const aghSlist<T>& pattern)
{

}
// ---------------------------------------------------------------

template <class T>
aghSlist<T>::~aghSlist<T>()
{
    
}
// ---------------------------------------------------------------

template <class T>
T& aghSlist<T>::at(int n) const
{
    if (this->invalidIndex(n))
        throw aghException(0, "Index out of range", __FILE__, __LINE__);
   
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
   
}
// --------------------------------------------------------------

template <class T>
bool aghSlist<T>::remove(int n)
{
    
}
// ---------------------------------------------------------------

template <class T>
aghSlist<T>& aghSlist<T>::operator=(const aghSlist<T>& pattern)
{
    this->aghContainer::operator(right);
    return *this;
}
// ---------------------------------------------------------------

#endif
