/*

Nama    : Fajar Aziz Kurniawan
NIM     : A11.2024.15685
Kelas   : A11.4204

*/

#include <iostream>
using namespace std;

typedef string DataType;

struct Node {
    string data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;
    int count;
    const int MAX_SIZE = 4;

public:
    Queue() {
        front = rear = nullptr;
        count = 0;
    }

    void enqueue(DataType value) {
        if (count >= MAX_SIZE) {
            cout << "Antrian penuh! Maksimal Input : " << MAX_SIZE << endl;
            return;
        }

        cout << "Proses pembuatan Node baru dengan value : " << value << endl;
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        count++;
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Antrian kosong!" << endl;
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        cout << "Proses mengeluarkan Node lama dengan value : " << temp->data << endl;
        delete temp;
        count--;
    }

    void display() {
        Node* current = front;
        cout << "=================================\nIsi Antrian berserta alamt memory: " << endl;
        while (current != nullptr) {
            cout << current->data << " | Alamat Memory : " << &current->data << endl;
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Queue queue;

    cout << "Proses pengisian pertama :" << endl;
    queue.enqueue("a");
    queue.enqueue("b");
    queue.enqueue("c");
    queue.display();

    cout << "Proses pengisian kedua setelah menghapus Node pertama :" << endl;
    queue.dequeue();
    queue.enqueue("d");
    queue.display();

    cout << "Menghapus lalu menampilkan :" << endl;
    queue.dequeue();
    queue.display();

    return 0;
}
