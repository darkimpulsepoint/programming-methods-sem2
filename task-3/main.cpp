#include <iostream>
#include <ctime>
#include <vector>

#define LIST_TYPE double

using namespace std;

template <typename T>
class Node {

private:
    T data;
    Node* next;

public:
    Node<T>(T data);
    void setNext(Node*);
    void setData(T);
    Node* getNext();
    T getData();

};

template <typename T>
class List {

private:
    Node<T>* head;
    Node<T>* back;

public:
    List<T>();
    Node<T>* operator[] (int);
    bool isEmpty();
    void pushBack(T);
    void print();
    void removeAll(T);
    T pop();
    T getMax();
    void clear();
};

template <typename T>
int count(List<T>& list, T el);

template <typename T>
void removeElsRepeatingOneTime(List<T> list);

template<typename T, typename C>
void fill(List<T>& l, int size, C min, C max);

void printTask();

int choice(){
    int choice;
    cin >> choice;
    return choice;
}

int main() {
    srand(time(nullptr));

    auto l = List<double>();
    int size = 0;

    try {
        while (true) {
            printTask();

            switch (choice()) {
                case 1:
                    LIST_TYPE el;
                    cout << "enter el:" << endl;
                    cin >> el;
                    l.pushBack(el);
                    break;

                case 2:
                    l.pop();
                    break;

                case 3:
                    l.print();
                    break;

                case 4:
                    l.removeAll(l.getMax());
                    break;

                case 5:
                    removeElsRepeatingOneTime(l);
                    break;

                case 6:
                    cout << "size: " << endl;
                    size = choice();

                    if (size < 0){
                        cout << "wrong size" << endl;
                    } else {
                        l.clear();
                        fill(l, size, -5, 5);
                    }
                    break;

                case 7:
                    exit(0);
                    break;

            }
        }
    } catch (const char* err) {
        cout << err << endl;
    }

    return 0;
}

template<typename T, typename C>
void fill(List<T>& l, int size, C min, C max){
    for (size_t i=0; i<size; i++){
        l.pushBack(rand()%(abs(min)+abs(max)+1)+min);
    }
}

template <typename T>
int count(List<T>& list, T el){
    auto* head = list[0];
    int counter = 0;
    while (head!= nullptr){
        if (head->getData() == el){
            counter++;
        }
        head = head->getNext();
    }
    return counter;
}

void printTask(){
    cout << "1 - push el\n"
         << "2 - remove last\n"
         << "3 - print list\n"
         << "4 - remove max els\n"
         << "5 - remove els repeating once\n"
         << "6 - rand fill list\n"
         << "0 - exit\n\n"
         <<"choice:";
}

template <typename T>
void removeElsRepeatingOneTime(List<T> list){
    auto* p = list[0];
    auto elsToDelete = vector<T>();

    while (p!= nullptr){
        if (count(list, p->getData()) == 1){
            elsToDelete.push_back(p->getData());
        }
        p = p->getNext();
    }

    for (auto el: elsToDelete){
        list.removeAll(el);
    }
}

template <typename T>
bool List<T>::isEmpty(){
    return this->head == nullptr;
}

template <typename T>
void List<T>::pushBack(T data) {
    auto *p = new Node(data);

    if (this->isEmpty()) {
        this->head = p;
        this->back = p;
    } else {
        this->back->setNext(p);
        this->back = p;
    }
}

template <typename T>
void List<T>::print() {
    auto* curr = this->head;
    while (curr){
        cout << curr->getData() << " ";
        curr = curr->getNext();
    }
    cout << endl;
}

template <typename T>
Node<T>* List<T>::operator[] (const int index) {
    if (this->isEmpty()) return nullptr;
    auto* p = head;
    for (int i = 0; i < index; i++) {
        p = p->getNext();
        if (!p) return nullptr;
    }
    return p;
}

template<typename T>
Node<T>::Node(T data) {
    this->setData(data);
    this->setNext(nullptr);
}

template<typename T>
void Node<T>::setNext(Node* nextel){
    this->next = nextel;
}

template<typename T>
void Node<T>::setData(T newdata){
    this->data = newdata;
}

template<typename T>
Node<T>* Node<T>::getNext(){
    return this->next;
}

template<typename T>
T Node<T>::getData(){
    return this->data;
}

template <typename T>
List<T>::List() {
    this->head = nullptr;
    this->back = nullptr;
}

template <typename T>
T List<T>::getMax(){
    if (!head){
        throw "Empty list!";
    } else {
        auto* p= this->head;
        T maxV = p->getData();

        while (p){
            if (p->getData() > maxV){
                maxV = p->getData();
            }
            p = p->getNext();
        }
        return maxV;
    }
}

template <typename T>
void List<T>::removeAll(T value) {
    auto* p = this->head;
    auto* prev = this->head;

    if (!head) return;

    while (head->getData() == value){
        p = head->getNext();
        delete head;
        prev = p;
        head = p;

        if(!head) back=head;
    }

    while (p != nullptr && p != this->back){
        if(p->getData() == value){
            prev->setNext(p->getNext());
            auto* temp = p;
            p = p->getNext();
            delete temp;
        }
        else {
            prev = p;
            p = p->getNext();
        }
    }

    if (p!= nullptr){
        if (p->getData() == value){
            delete p;
            this->back = prev;
            this->back->setNext(nullptr);
        }
    }
}

template <typename T>
T List<T>::pop() {
    if (isEmpty()) throw "Empty list!" ;

    if(head == back){
        T val = head->getData();

        delete back;
        back = nullptr;
        head = nullptr;

        return val;
    }

    auto* p = this->head;
    auto* prev = this->head;

    while (p!= back){
        prev = p;
        p = p->getNext();
    }

    delete p;
    back = prev;
    back->setNext(nullptr);

    return back->getData();
}

template <typename T>
void List<T>::clear() {
    if(isEmpty()) return;

    auto* p =head;

    while (p){
        auto* temp = p;
        p = p->getNext();
        delete temp;
    }
}
