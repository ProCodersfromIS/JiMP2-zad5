/**
* \file aghSnode.h
* \author Beata Gie³baga & Kamil Dawidów
* \date 03.06.2014
* \brief Deklaracja i definicja szablonu klasy aghSnode
*/
// -------------------------------------------------------------------------

#ifndef AGHSNODE_H
#define AGHSNODE_H
// -------------------------------------------------------------------------

/**
* \class aghSnode
* \author Beata Gie³baga & Kamil Dawidów
* \date 03.06.2014
* \brief szablon klasy aghSnode implementuj¹cej wêze³ listy pojedynczo wi¹zanej
// -------------------------------------------------------------------------
*/
template <class T>
class aghSnode
{
private:
    T data; ///< dane zapisane w wêŸle
    aghSnode<T>* next; ///< wskaŸnik do nastêpnego wêz³a

public:
    /// \brief Konstruktor bezparametrowy
    aghSnode();

    /// \brief Konstruktor kopiuj¹cy
    ///
    /// \param pattern - obiekt macierzysty
    aghSnode(const aghSnode<T>& pattern);

    /// \brief Destruktor
    ~aghSnode();

    /// \brief Metoda ustawia zapisane dane
    ///
    /// \param _data - referencja do danych
    void setData(const T& _data);

    /// \brief Metoda zwraca referencjê do zapisanych danych
    T& getData(void) const;

    /// \brief Metoda zmienia wartoœæ pola next
    ///
    /// \param _next - nowa wartoœæ pola next
    void setNext(const aghSnode<T>* _next);

    /// \brief Metoda zwraca wartoœæ pola next
    ///
    /// \return - wartoœæ pola next
    aghSnode<T>* getNext(void) const;
};
// ---------------------------------------------------------------

// Definicje metod szablonu
// ---------------------------------------------------------------
template <class T>
aghSnode<T>::aghSnode()
{
    next = nullptr;
}
// ---------------------------------------------------------------

template <class T>
aghSnode<T>::aghSnode(const aghSnode<T>& pattern)
{
    next = pattern.getNext();
    data = pattern.getData();
}
// ---------------------------------------------------------------

template <class T>
aghSnode<T>::~aghSnode()
{

}
// ---------------------------------------------------------------

template <class T>
void aghSnode<T>::setData(const T& _data)
{
    data = _data;
}
// ---------------------------------------------------------------

template <class T>
T& aghSnode<T>::getData(void) const
{
    return data;
}
// ---------------------------------------------------------------

template <class T>
void aghSnode<T>::setNext(const aghSnode<T>* _next)
{
    next = _next;
}
// ---------------------------------------------------------------

template <class T>
aghSnode<T>* aghSnode<T>::getNext(void) const
{
    return next;
}
// ---------------------------------------------------------------

#endif
