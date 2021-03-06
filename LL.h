#ifndef DATA_STRUCTURES_LL_H
#define DATA_STRUCTURES_LL_H

#endif //DATA_STRUCTURES_LL_H


#include<iostream>
using namespace std;

template<typename T>

struct Node{
    T info;
    Node *link;
};

template<typename S>

class LL{
public:

    Node<S> *head;
    Node<S> *last;
    int count;

    LL(){
        count = 0;
        head = nullptr;
        last = nullptr;
    }

   virtual ~LL()=default;

    Node<S>* search(const S &item);
    bool isempty();
    int length();

    template <typename R>
    friend ostream& operator<<(ostream &os, LL<R> &ll);

    void insertFirst(const S &item);
    void insertLast(const S &item);
    void insertAt(const S &item, int place);
    void insertAfter(const S &item, const S &placeitem);
    void insertBefore(const S &item, const S &placeitem);

    void clearList();
    void deleteFirst();
    void deleteNode(const S &item);

    S front();
    S back();

};



template<typename S>
Node<S>* LL<S>::search(const S &item) {

    Node<S>* ptr = head;
    while(ptr != nullptr){

        if(ptr->info == item) return ptr;

        else ptr = ptr->link;
    }

    return nullptr;
}

template<typename S>
bool LL<S>::isempty() {
    if(head == nullptr) return true;
    else return false;
}

template<typename S>
int LL<S>::length() {
    return count;
}

template<typename S>
void LL<S>::insertFirst(const S &item) {

    if(isempty() == true){
        Node<S>* ptr = new Node<S>;
        ptr->info=item;
        head = ptr;
        last = ptr;
        ptr->link = nullptr;
    }

    else{
        Node<S>* ptr = new Node<S>;
        ptr->info=item;
        ptr->link=head;
        head=ptr;
    }
    count++;
}

template<typename S>
void LL<S>::insertLast(const S &item) {
        if(isempty() == true){
            Node<S>* ptr = new Node<S>;
            ptr->info=item;
            head = ptr;
            last = ptr;
            ptr->link = nullptr;
        }

else{
        Node<S> *ptr = new Node<S>;
        ptr->info = item;
        last->link = ptr;
        ptr->link = nullptr;
        last = ptr;
    }
        count++;
}

template<typename S>
void LL<S>::insertAt(const S &item, int place) {

    Node<S>* ptr = new Node<S>;
    Node<S>* placeptr = head;

    ptr->info=item;

    if(place <= 1 || place > count){
        cout<<"Out of range."<<endl;
        return;
    }

    for (int i = 2; i < place; i++) {
        placeptr = placeptr->link;
    }

    ptr->link = placeptr->link;
    placeptr->link = ptr;
    count++;
}

template<typename S>
void LL<S>::insertAfter(const S &item, const S &placeitem) {

    Node<S>* ptr = new Node<S>;
    ptr->info=item;

    Node<S>* placeptr;

    placeptr = search(placeitem);
    if(placeptr == nullptr){
        cout<<"There is no such item"<<endl;
        return;
    }

    if(placeptr == head && placeptr == last){
        ptr->link=head->link;
        head->link=ptr;
        last = ptr;
        count++;
        return;
    }

    ptr->link=placeptr->link;
    placeptr->link = ptr;

    if(placeptr->link == nullptr){
        insertLast(item);
    }

    count++;
}

template<typename S>
void LL<S>::insertBefore(const S &item, const S &placeitem) {

    Node<S>* ptr = new Node<S>;
    ptr->info=item;
    Node<S>* placeptr = head;
    Node<S>* searchptr = head;

    int placeCounter = 0;

    while(searchptr != nullptr){

        if(searchptr->info == placeitem){
            placeCounter++;
            break;
        }

        else{
            searchptr = searchptr->link;
            placeCounter++;
        }

        if(searchptr == last && searchptr->info != placeitem){
            cout<<"There is no such item."<<endl;
            return;
        }
    }


    if(searchptr == head){
        insertFirst(item);
        return;
    }

    for (int i = 1; i < placeCounter-1; i++) {
        placeptr = placeptr->link;
    }

    ptr->link = placeptr->link;
    placeptr->link = ptr;

}

template<typename S>
void LL<S>::clearList(){

    Node<S>* ptr = head;

    while(head->link != nullptr){
            ptr = ptr->link;
            delete head;
            head = ptr;
            count--;
    }

    delete ptr;
    count--;
    head = nullptr;
    last = nullptr;

}

template<typename S>
void LL<S>::deleteFirst() {

    Node<S>* ptr = head;

    if(head == last){
        delete ptr;
        head = nullptr;
        last = nullptr;
        count--;
        return;
    }

    head = head->link;
    delete ptr;

    count--;

}

template<typename S>
void LL<S>::deleteNode(const S &item) {

    Node<S> *ptr = head;
    Node<S> *ptrDelete = head;

    int placeCounter = 0;

    while (ptrDelete != nullptr) {

        if (ptrDelete->info == item) {
            placeCounter++;
            break;
        }

        else {
            ptrDelete = ptrDelete->link;
            placeCounter++;
        }
    }

    for (int i = 1; i < placeCounter-1; i++) {
        ptr = ptr->link;
    }

    if(ptrDelete == head){
        deleteFirst();
        return;
    }

    ptr->link = ptr->link->link;
    delete ptrDelete;

}

template<typename R>
ostream& operator<<(ostream &os, LL<R> &ll){

    if(ll.isempty() == true){
        os<<"The list is empty."<<endl;
    }

    else{
        Node<R>* ptr;
        ptr=ll.head;

        while(ptr != nullptr){
            if (ptr == ll.last){
                os<<ptr->info<<" ";
            }
            else{
                os<<ptr->info<<", ";
            }
            ptr = ptr->link;
        }
    }
        return os;
}

template<typename  S>
S LL<S>::front() {
    return head->info;
}

template<typename S>
S LL<S>::back() {
    return last->info;
}



/*

 * deletenode


 */

