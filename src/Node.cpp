/**
* @file Node.cpp
* @description Herhangi bir tipte iki yönlü bağıl liste  veri yapısı
  için gerekli olan düğüm yapısının kaynak dosyası.
* @course Uzaktan Eğitim - Grup B - 1. Öğretim - BSM 207
* @assignment 1. Ödev - 1. Ara Sınav
* @date 30.07.2020 16:51
* @author Fatih ATEŞ
*/

#include "Node.hpp"

  Node::Node(const unsigned char& data, Node* nx , Node* prv ){
    this->data = data;
    next = nx;
    prev = prv;
  }
