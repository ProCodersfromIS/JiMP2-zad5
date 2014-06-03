/**
* \file aghDnode.h
* \author Beata Gie�baga & Kamil Dawid�w
* \date 03.06.2014
* \brief Deklaracja i definicja szablonu klasy aghDnode
*/
// -------------------------------------------------------------------------

#ifndef AGHDNODE_H
#define AGHDNODE_H
// -------------------------------------------------------------------------

/**
* \class aghDnode
* \author Beata Gie�baga & Kamil Dawid�w
* \date 03.06.2014
* \brief szablon klasy aghDnode implementuj�cej w�ze� listy podw�jnie wi�zanej
// -------------------------------------------------------------------------
*/
template <class T>
class aghDnode
{
private:
    T data; ///< dane zapisane w w�le
    aghDnode<T>* next; ///< wska�nik do nast�pnego w�z�a
    aghDnode<T>* prev; ///< wska�nik do poprzedniego w�z�a

public:

    /// \brief Konstruktor bezparametrowy
    aghDnode();

    /// \brief Destruktor
    ~aghDnode();

    /// \brief Metoda ustawia zapisane dane
    ///
    /// \param _data - referencja do danych
    void setData(const T& _data);

    /// \brief Metoda zwraca referencj� do zapisanych danych
    T& getData(void) const;

    /// \brief Metoda zmienia warto�� pola next
    ///
    /// \param _next - nowa warto�� pola next
    void setNext(const aghDnode<T>* _next);

    /// \brief Metoda zwraca warto�� pola next
    ///
    /// \return - warto�� pola next
    aghDnode<T>* getNext(void) const;

    /// \brief Metoda zmienia warto�� pola prev
    ///
    /// \param _prev - nowa warto�� pola prev
    void setPrev(const aghDnode<T>* _prev);

    /// \brief Metoda zwraca warto�� pola prev
    ///
    /// \return - warto�� pola prev
    aghDnode<T>* getPrev(void) const;
};
// ---------------------------------------------------------------

// Definicje metod szablonu
// ---------------------------------------------------------------

template <class T>
aghDnode<T>::aghDnode()
{
    next = nullptr;
    prev = nullptr;
}
// ---------------------------------------------------------------

template <class T>
aghDnode<T>::~aghDnode()
{

}
// ---------------------------------------------------------------

template <class T>
void aghDnode<T>::setData(const T& _data)
{
    data = _data;
}
// ---------------------------------------------------------------

template <class T>
T& aghDnode<T>::getData(void) const
{
    return data;
}
// ---------------------------------------------------------------

template <class T>
void aghDnode<T>::setNext(const aghDnode<T>* _next)
{
    next = _next;
}
// ---------------------------------------------------------------

template <class T>
aghDnode<T>* aghDnode<T>::getNext(void) const
{
    return next;
}
// ---------------------------------------------------------------

template <class T>
void aghDnode<T>::setPrev(const aghDnode<T>* _prev)
{
    prev = _prev;
}
// ---------------------------------------------------------------

template <class T>
aghDnode<T>* aghDnode<T>::getPrev(void) const
{
    return prev;
}
// ---------------------------------------------------------------

#endif
