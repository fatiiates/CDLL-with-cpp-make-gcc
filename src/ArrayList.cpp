/**
* @file ArrayList.cpp
* @description ArrayList mantığıyla iki yönlü dairesel bağıl listeleri dizi içerisinde
  saklayan kaynak dosyası.
* @course Uzaktan Eğitim - Grup B - 1. Öğretim - BSM 207
* @assignment 1. Ödev - 1. Ara Sınav
* @date 03.08.2020 19:32
* @author Fatih ATEŞ
*/

#include "ArrayList.hpp"

    void ArrayList::reserve(int newCapacity){
      CircularDoublyLinkedList **temp = new CircularDoublyLinkedList*[newCapacity];

      for (int i = 0; i < length; i++)
        temp[i] = items[i];

      delete [] items;
      items = temp;
      capacity =  newCapacity;
    }
    ArrayList::ArrayList(){
      length=0;
      capacity=100;
      items = new CircularDoublyLinkedList*[capacity];
    }
    int ArrayList::Count() const {
      return length;
    }
    bool ArrayList::isEmpty() const {
      return length == 0;
    }
    CircularDoublyLinkedList* ArrayList::elementAt(int index){
      if(index < 0 || index >= length)
        throw invalid_argument("İndex 0'dan küçük, kapasiteye eşit veya kapasiteden büyük olamaz . Error Code: 101");
      else
        return items[index];
    }
    void ArrayList::add(CircularDoublyLinkedList* item){
      insert(length, item);
    }
    void ArrayList::insert(int index,CircularDoublyLinkedList* item){
      if(index < 0 || index > length)
        throw invalid_argument("İndex 0'dan küçük veya kapasiteden büyük olamaz . Error Code: 101");
      else{
        if(length == capacity) reserve(2*capacity);
        for (int i = length - 1; i >= index; i--)
          items[i+1] = items[i];
        items[index] = item;
        length++;
      }
    }
    ArrayList::~ArrayList(){
      for (int i = 0; i < length; i++)
        delete items[i];
      delete [] items;
    }
