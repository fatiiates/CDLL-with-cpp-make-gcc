/**
* @file ArrayList.hpp
* @description ArrayList yapısı için class bildiriminin bulunduğu ve liste yapımızın dahil
  edildiği başlık dosyası.
* @course Uzaktan Eğitim - Grup B - 1. Öğretim - BSM 207
* @assignment 1. Ödev - 1. Ara Sınav
* @date 03.08.2020 20:13
* @author Fatih ATEŞ
*/

#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP

#include "CircularDoublyLinkedList.hpp"

class ArrayList {
  private:
    CircularDoublyLinkedList **items;
    int length;
    int capacity;

    void reserve(int);
  public:
    ArrayList();
    int Count() const;
    bool isEmpty() const;
    void add(CircularDoublyLinkedList*);
    void insert(int, CircularDoublyLinkedList*);
    CircularDoublyLinkedList* elementAt(int);
    ~ArrayList();
};

#endif
