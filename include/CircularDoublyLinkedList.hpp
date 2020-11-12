/**
* @file CircularDoublyLinkedList.hpp
* @description İki yönlü dairesel bağıl liste yapısı için class bildiriminin
  bulunduğu ve düğüm yapımızın dahil edildiği başlık dosyası.
* @course Uzaktan Eğitim - Grup B - 1. Öğretim - BSM 207
* @assignment 1. Ödev - 1. Ara Sınav
* @date 03.08.2020 19:22
* @author Fatih ATEŞ
*/

#ifndef CDLL_HPP
#define CDLL_HPP

#include "Node.hpp"

class CircularDoublyLinkedList{
  private:
    Node* head;
    int size;

    Node* FindPreNode(int);
  public:
    CircularDoublyLinkedList();
    int Count() const ;
    const unsigned char& first();
    const unsigned char& last();
    bool isEmpty() const;
    void add(const unsigned char&);
    void insert(int, const unsigned char&);
    int indexOf(const unsigned char&) const;
    void remove(const unsigned char&);
    void removeFirst();
    void removeLast();
    void removeAt(int);
    bool find(const unsigned char&);
    const unsigned char& elementAt(int);
    void clear();
    void printListPositionReverse(int);
    friend ostream& operator<<(ostream&, CircularDoublyLinkedList&);
    void printListReverse();
    ~CircularDoublyLinkedList();

};

#endif
