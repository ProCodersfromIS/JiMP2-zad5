/**
* \file aghSlist.h
* \author Beata Gie³baga & Kamil Dawidów
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
* \author Beata Gie³baga & Kamil Dawidów
* \date 03.06.2014
* \brief Szablon klasy aghSlist implementuj¹cej listê pojedynczo wi¹zan¹
// -------------------------------------------------------------------------
*/
template <class T>
class aghSlist: public aghContainer<T>
{
private:
    aghSnode* head; ///< wskaŸnik do pierwszego elementu listy
    int length; ///< iloœæ elementów w liœcie

public:
    /// \brief Konstruktor bezparametrowy
    aghSlist();

    /// \brief Konstruktor kopiuj¹cy
    ///
    /// \param pattern - referencja do obiektu macierzystego
    aghSlist(const aghSlist<T>& pattern);

    /// \brief Konstruktor kopiuj¹cy przyjmuj¹cy jako argument referencjê do obiektu klasy aghContainer
    ///
    /// \param pattern - referencja do obiektu macierzystego
    aghSlist(const aghContainer<T>& pattern);

    /// \brief Destruktor
    ~aghSlist();

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
