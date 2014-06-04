/**
* \file aghSnode.h
* \author Beata Gie�baga & Kamil Dawid�w
* \date 03.06.2014
* \brief Deklaracja i definicja szablonu klasy aghSnode
*/
// -------------------------------------------------------------------------

#ifndef AGHSNODE_H
#define AGHSNODE_H
// -------------------------------------------------------------------------

/**
* \class aghSnode
* \author Beata Gie�baga & Kamil Dawid�w
* \date 03.06.2014
* \brief szablon klasy aghSnode implementuj�cej w�ze� listy pojedynczo wi�zanej
// -------------------------------------------------------------------------
*/
template <class T>
class aghSnode
{
private:
    T data; ///< dane zapisane w w�le
    aghSnode<T>* next; ///< wska�nik do nast�pnego w�z�a

public:
    /// \brief Konstruktor bezparametrowy
    aghSnode();

    /// \brief Konstruktor kopiuj�cy
    ///
    /// \param pattern - obiekt macierzysty
    aghSnode(const aghSnode<T>& pattern);

    /// \brief Destruktor
    ~aghSnode();

    /// \brief Metoda ustawia zapisane dane
    ///
    /// \param _data - referencja do danych
    void setData(const T& _data);

    /// \brief Metoda zwraca referencj� do zapisanych danych
    T& getData(void) const;

    /// \brief Metoda zmienia warto�� pola next
    ///
    /// \param _next - nowa warto�� pola next
    void setNext(const aghSnode<T>* _next);

    /// \brief Metoda zwraca warto�� pola next
    ///
    /// \return - warto�� pola next
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
