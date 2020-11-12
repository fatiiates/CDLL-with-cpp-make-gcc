/**
* @file Node.hpp
* @description Düğüm yapısı için struct bildirimlerinin yapıldığı ve gerekli
  kütüphane dosyalarının dahil edildiği başlık dosyası.
* @course Uzaktan Eğitim - Grup B - 1. Öğretim - BSM 207
* @assignment 1. Ödev - 1. Ara Sınav
* @date 03.08.2020 19:04
* @author Fatih ATEŞ
*/

#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
using namespace std;

struct Node {
  unsigned char data;
  Node* next;
  Node* prev;

  Node(const unsigned char&, Node* nx=NULL, Node* prv=NULL);
};

#endif
