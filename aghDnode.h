/**
* \file aghDnode.h
* \author Beata Gie³baga & Kamil Dawidów
* \date 03.06.2014
* \brief Deklaracja i definicja szablonu klasy aghDnode
*/
// -------------------------------------------------------------------------

#ifndef AGHDNODE_H
#define AGHDNODE_H
// -------------------------------------------------------------------------

/**
* \class aghDnode
* \author Beata Gie³baga & Kamil Dawidów
* \date 03.06.2014
* \brief szablon klasy aghDnode implementuj¹cej wêze³ listy podwójnie wi¹zanej
// -------------------------------------------------------------------------
*/
template <class T>
class aghDnode
{
private:
    T data; ///< dane zapisane w wêŸle
    aghDnode<T>* next; ///< wskaŸnik do nastêpnego wêz³a
    aghDnode<T>* prev; ///< wskaŸnik do poprzedniego wêz³a

public:

    /// \brief Konstruktor bezparametrowy
    aghDnode();

    /// \brief Destruktor
    ~aghDnode();

    /// \brief Metoda ustawia zapisane dane
    ///
    /// \param _data - referencja do danych
    void setData(const T& _data);

    /// \brief Metoda zwraca referencjê do zapisanych danych
    T& getData(void) const;

    /// \brief Metoda zmienia wartoœæ pola next
    ///
    /// \param _next - nowa wartoœæ pola next
    void setNext(const aghDnode<T>* _next);

    /// \brief Metoda zwraca wartoœæ pola next
    ///
    /// \return - wartoœæ pola next
    aghDnode<T>* getNext(void) const;

    /// \brief Metoda zmienia wartoœæ pola prev
    ///
    /// \param _prev - nowa wartoœæ pola prev
    void setPrev(const aghDnode<T>* _prev);

    /// \brief Metoda zwraca wartoœæ pola prev
    ///
    /// \return - wartoœæ pola prev
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
