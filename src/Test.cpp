/**
* @file Test.cpp
* @description Oluşturduğumuz dosyaların birleştirilip asıl amacın(Dosyadan satır satır okunan
  sayıları belirli algoritmaya göre listeye atıp daha sonra satır satır şifreleri çözmek)
  gerçekleştirildiği ve test edildiği kaynak dosyası.
* @course Uzaktan Eğitim - Grup B - 1. Öğretim - BSM 207
* @assignment 1. Ödev - 1. Ara Sınav
* @date 30.07.2020 16:53
* @author Fatih ATEŞ
*/

#include "ArrayList.hpp"
#include <typeinfo>
int readSayilar();
int mod(unsigned char, unsigned char);
int obeb(unsigned char, unsigned char);
void createSayilar();

int main(){

  //createSayilar();
  readSayilar();
  return 0;
}

int readSayilar(){
  ifstream file("doc/Sayilar.txt");
  string line = "", cell = "";
  ArrayList* rows = new ArrayList();
  if ( file.is_open() ){
    for (int j = 0; getline(file, line);j++){

      stringstream row(line);
      int MAXOBEB = 0;
      rows->add(new CircularDoublyLinkedList());
      while ( getline(row, cell, ' ') ) {
      	stringstream intTicket(cell);
      	int item = 0;
      	intTicket >> item;
        try {
          unsigned char ch = (unsigned char)item;

          if(rows->elementAt(j)->Count() == 0)
            rows->elementAt(j)->add(ch);
          else{
            for (int i = 0; i != rows->elementAt(j)->Count();i++) {
              int ebob = obeb(ch, rows->elementAt(j)->elementAt(i));

              if(ebob >= MAXOBEB){
                MAXOBEB = ebob;
                int val = mod(ch, rows->elementAt(j)->elementAt(i));
                if(val == 0)
                  rows->elementAt(j)->insert(i+1, ch);
                else{
                  if(val >= i)
                    rows->elementAt(j)->insert(0, ch);
                  else
                    rows->elementAt(j)->insert(i-val+1, ch);
                }
                break;
              }else if(i == rows->elementAt(j)->Count() - 1){
                int val = mod(ch, rows->elementAt(j)->last());
                if(val == 0)
                  rows->elementAt(j)->add(ch);
                else
                  if(val >= i)
                    rows->elementAt(j)->insert(0, ch);
                  else
                    rows->elementAt(j)->insert(i-val+1, ch);
                break;
              }
            }
          }
        } catch (invalid_argument& e) {
          cerr << e.what() << " TEST "<<endl;
        } catch (length_error& e) {
          cerr << e.what() << " TEST 2"<< endl;
        } catch (...) {
          cout << "Bilinmeyen bir hata oluştu lütfen ilgili kişiye yönlendiriniz.";
        }
      }
    }
    cout << endl;
    for (int i = 0; i < rows->Count(); i++){
      cout << int(i+1) << ".Satir Sifre:"<< endl;
      cout << *rows->elementAt(i) << endl;
    }

    delete rows;
  }

  return 0;
}

int mod(unsigned char n1, unsigned char n2){
  if(n1 > n2)
    return n1 % n2;
  else
    return n2 % n1;
}

int obeb(unsigned char n1, unsigned char n2){
  int largest = 0;
  for(int i=1; i <= n1 && i <= n2; i++)
    if(n1%i==0 && n2%i==0)
      largest = i;
  return largest;
}

void createSayilar(){
  ofstream file;
  file.open ("doc/Sayilar.txt");

  for (int i = 0; i < 500; i++) {
    for (int j = 0; j < 250; j++) {
      int v1 = rand() % 254 + 1;
      file << v1<<" ";
    }
    file << endl;
  }
  file.close();
}
