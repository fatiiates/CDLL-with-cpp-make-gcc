/**
* @file CircularDoublyLinkedList.cpp
* @description İki yönlü dairesel bağıl liste veri yapısını oluşturmayı sağlayan
  kaynak dosyası.
* @course Uzaktan Eğitim - Grup B - 1. Öğretim - BSM 207
* @assignment 1. Ödev - 1. Ara Sınav
* @date 30.07.2020 17:00
* @author Fatih ATEŞ
*/

#include "CircularDoublyLinkedList.hpp"

    Node* CircularDoublyLinkedList::FindPreNode(int index){
      int i=1;
      Node* prv = head;
      for (Node* itr = head;i != index; itr=itr->next,i++) {
        prv = prv->next;
      }
      return prv;
    }
    CircularDoublyLinkedList::CircularDoublyLinkedList(){
      head = NULL;
      size = 0;
    }
    int CircularDoublyLinkedList::Count() const {
      return size;
    }
    const unsigned char& CircularDoublyLinkedList::first(){
      if(isEmpty())
        throw invalid_argument("Listede eleman bulunmuyor. Error Code: 101");
      return head->data;
    }
    const unsigned char& CircularDoublyLinkedList::last(){
      if(isEmpty())
        throw invalid_argument("Listede eleman bulunmuyor. Error Code: 102");
      return head->prev->data;
    }
    bool CircularDoublyLinkedList::isEmpty() const {
      return size == 0;
    }
    void CircularDoublyLinkedList::add(const unsigned char& item){
      insert(size, item);
    }
    void CircularDoublyLinkedList::insert(int index, const unsigned char& item){
      if(index < 0  || index > size){
        throw invalid_argument("Index 0'dan kucuk veya eleman sayisindan buyuk olamaz.  Error Code: 103");
      }else{
        if(index == 0){
          if(isEmpty()){
            head = new Node(item);
            head->next = head;
            head->prev = head;
          }
          else{
            head = new Node(item, head, head->prev);
            head->prev->next = head;
            head->next->prev = head;
          }
        }else{
          Node* preNodeIndex = FindPreNode(index);
          preNodeIndex->next = new Node(item, preNodeIndex->next, preNodeIndex);
          preNodeIndex->next->next->prev = preNodeIndex->next;
        }
        size++;
      }
    }
    int CircularDoublyLinkedList::indexOf(const unsigned char& item) const {
      int i = 0;
      for (Node* itr=head;i != size;itr=itr->next) {
        if(itr->data == item) return i;
				i++;
      }
      return -1;
    }
    void CircularDoublyLinkedList::remove(const unsigned char& item){
      int index = indexOf(item);
      if (index == -1)
        throw invalid_argument("Eleman listeye ait degil. Error Code: 104");
      else
        removeAt(index);
    }
    void CircularDoublyLinkedList::removeFirst(){
      removeAt(0);
    }
    void CircularDoublyLinkedList::removeLast(){
      removeAt(size-1);
    }
    void CircularDoublyLinkedList::removeAt(int index){

      if(isEmpty()){
        throw invalid_argument("Listede hic eleman bulunmuyor. Error Code: 105");
      }else{
        if(index < 0  || index >= size){
          throw invalid_argument("Index 0'dan kucuk, eleman sayisina esit veya buyuk olamaz. Error Code: 106");
        }else{
          Node* del;

          if(index == 0){
            del = head;

            if(size == 1){
              head = head->next = head->prev = NULL;
            }else{
              head = head->next;
              head->prev = del->prev;
              del->prev->next = head;
            }
          }else{
            Node* preNodeIndex = FindPreNode(index);
            del = preNodeIndex->next;
            preNodeIndex->next = del->next;
            del->next->prev = preNodeIndex;
          }

          delete del;
          size--;
        }
      }
    }
    bool CircularDoublyLinkedList::find(const unsigned char& item){
      int i=0;
      for (Node* itr=head;i != size;itr=itr->next,i++)
        if(itr->data == item) return true;

      return false;
    }
    const unsigned char& CircularDoublyLinkedList::elementAt(int index){
      if(index == 0)
        return first();
      else if(index == (size -1))
        return last();

      return FindPreNode(index)->next->data;
    }
    void CircularDoublyLinkedList::clear(){
      while (!isEmpty())
        removeAt(0);
    }
    ostream& operator<<(ostream& screen, CircularDoublyLinkedList& right){
      if (right.isEmpty()) {
        screen << "Listede eleman bulunmuyor. Error Code: 107";
      }else{
        int i=0;
        for(Node* itr=right.head;i != right.size;itr=itr->next,i++)
          screen << itr->data;
      }
      return screen;
    }
    void CircularDoublyLinkedList::printListPositionReverse(int index){
      if (isEmpty()) {
        cout << "Listede eleman bulunmuyor. Error Code: 108";
      }else{
        if(index<=0 || index>=size){
          throw invalid_argument("Index 0'dan kucuk, 0'a esit, eleman sayisina esit veya buyuk olamaz. Error Code: 109");
        }else{
          int i=0;
    			for(Node* itr = FindPreNode(index+1);i != size;itr=itr->prev,i++)
    				cout<<itr->data<<" ";
    			cout<<endl;
        }
      }
		}
    void CircularDoublyLinkedList::printListReverse(){
      printListPositionReverse(size - 1);
    }

    CircularDoublyLinkedList::~CircularDoublyLinkedList(){
      clear();
    }
