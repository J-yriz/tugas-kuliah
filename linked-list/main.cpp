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
    
    void showMenu() {
        cout << "+-------------------------------------+" << endl;
        cout << "|           MENU LINKED LIST          |" << endl;
        cout << "+-------------------------------------+" << endl;
        cout << "| 1. Insert First                     |" << endl;
        cout << "| 2. Insert Last                      |" << endl;
        cout << "| 3. Update First                     |" << endl;
        cout << "| 4. Update Last                      |" << endl;
        cout << "| 5. Delete First                     |" << endl;
        cout << "| 6. Delete Last                      |" << endl;
        cout << "| 7. Insert After Index               |" << endl;
        cout << "| 8. Update After Index               |" << endl;
        cout << "| 9. Delete After Index               |" << endl;
        cout << "| 10. Display Node                    |" << endl;
        cout << "| 0. Close Program                    |" << endl;
        cout << "+-------------------------------------+" << endl;
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

        if (front == nullptr) rear = nullptr;

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

    void insertFirst(DataType value) {
        if (count >= MAX_SIZE) {
            cout << "Antrian penuh! Maksimal Input : " << MAX_SIZE << endl;
            return;
        }

        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = front;
        front = newNode;

        if (rear == nullptr) rear = newNode;
        
        count++;
        cout << "Berhasil menambahkan " << value << " di awal antrian" << endl;
    }

    void insertLast(DataType value) {
        enqueue(value);
    }

    void updateFirst(DataType newValue) {
        if (front == nullptr) {
            cout << "Antrian kosong!" << endl;
            return;
        }
        
        cout << "Mengubah value pertama dari " << front->data << " menjadi " << newValue << endl;
        front->data = newValue;
    }

    void updateLast(DataType newValue) {
        if (rear == nullptr) {
            cout << "Antrian kosong!" << endl;
            return;
        }
        
        cout << "Mengubah value terakhir dari " << rear->data << " menjadi " << newValue << endl;
        rear->data = newValue;
    }

    void deleteFirst() {
        dequeue();
    }

    void deleteLast() {
        if (rear == nullptr) {
            cout << "Antrian kosong!" << endl;
            return;
        }

        if (front == rear) {
            cout << "Proses mengeluarkan Node terakhir dengan value : " << rear->data << endl;
            delete rear;
            front = rear = nullptr;
        } else {
            Node* temp = front;
            while (temp->next != rear) {
                temp = temp->next;
            }
            cout << "Proses mengeluarkan Node terakhir dengan value : " << rear->data << endl;
            delete rear;
            rear = temp;
            rear->next = nullptr;
        }
        count--;
    }

    void insertAfterIndex(int index, DataType value) {
        if (count >= MAX_SIZE) {
            cout << "Antrian penuh! Maksimal Input : " << MAX_SIZE << endl;
            return;
        }

        if (index < 0 || index >= count) {
            cout << "Index tidak valid!" << endl;
            return;
        }

        Node* newNode = new Node();
        newNode->data = value;

        Node* temp = front;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        if (newNode->next == nullptr) rear = newNode;
        
        count++;
        cout << "Berhasil menambahkan " << value << " setelah index " << index << endl;
    }

    void updateAfterIndex(int index, DataType newValue) {
        if (index < 0 || index >= count - 1) {
            cout << "Index tidak valid atau tidak ada node setelahnya!" << endl;
            return;
        }

        Node* temp = front;
        for (int i = 0; i < index + 1; i++) {
            temp = temp->next;
        }

        cout << "Mengubah value setelah index " << index << " dari " << temp->data << " menjadi " << newValue << endl;
        temp->data = newValue;
    }

    void deleteAfterIndex(int index) {
        if (index < 0 || index >= count - 1) {
            cout << "Index tidak valid atau tidak ada node setelahnya!" << endl;
            return;
        }

        Node* temp = front;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }

        Node* toDelete = temp->next;
        temp->next = toDelete->next;

        if (toDelete == rear) rear = temp;

        cout << "Proses menghapus Node setelah index " << index << " dengan value : " << toDelete->data << endl;
        delete toDelete;
        count--;
    }
};

int main() {
    Queue queue;

    bool conditionLoop = true;
    while (conditionLoop) {
        int userInput;
        queue.showMenu();
        cout << "Silakan masukkan input nomor sesuai menu di atas: "; cin >> userInput;
            switch (userInput) {
            case 1:
                {
                    cout << "-> Kamu memilih: Insert First" << endl;
                    string value;
                    cout << "Masukkan value: "; cin >> value;
                    cout << endl;
                    queue.insertFirst(value);
                    queue.display();
                    break;
                }
            case 2:
                {
                    cout << "-> Kamu memilih: Insert Last" << endl;
                    string value;
                    cout << "Masukkan value: "; cin >> value;
                    cout << endl;
                    queue.insertLast(value);
                    queue.display();
                    break;
                }
            case 3:
                {
                    cout << "-> Kamu memilih: Update First" << endl;
                    string newValue;
                    cout << "Masukkan new value: "; cin >> newValue;
                    cout << endl;
                    queue.updateFirst(newValue);
                    queue.display();
                    break;
                }
            case 4:
                {
                    cout << "-> Kamu memilih: Update Last" << endl;
                    string newValue;
                    cout << "Masukkan new value: "; cin >> newValue;
                    cout << endl;
                    queue.updateLast(newValue);
                    queue.display();
                    break;
                }
            case 5:
                {
                    cout << "-> Kamu memilih: Delete First" << endl;
                    cout << endl;
                    queue.deleteFirst();
                    queue.display();
                    break;
                }
            case 6:
                {
                    cout << "-> Kamu memilih: Delete Last" << endl;
                    cout << endl;
                    queue.deleteLast();
                    queue.display();
                    break;
                }
            case 7:
                {
                    cout << "-> Kamu memilih: Insert After Index" << endl;
                    int index;
                    string value;
                    cout << "Masukkan index: "; cin >> index;
                    cout << "Masukkan value: "; cin >> value;
                    cout << endl;
                    queue.insertAfterIndex(index, value);
                    queue.display();
                    break;
                }
            case 8:
                {
                    cout << "-> Kamu memilih: Update After Index" << endl;
                    int index;
                    string newValue;
                    cout << "Masukkan index: "; cin >> index;
                    cout << "Masukkan new value: "; cin >> newValue;
                    cout << endl;
                    queue.updateAfterIndex(index, newValue);
                    queue.display();
                    break;
                }
            case 9:
                {
                    cout << "-> Kamu memilih: Delete After Index" << endl;
                    int index;
                    cout << "Masukkan index: "; cin >> index;
                    cout << endl;
                    queue.deleteAfterIndex(index);
                    queue.display();
                    break;
                }
            case 10:
                {
                    queue.display();
                    break;
                }
            case 0:
                {
                    conditionLoop = false;
                    cout << "-> Program ditutup. Sampai jumpa!" << endl;
                    break;
                }
            default:
                {
                    cout << "-> Pilihan tidak valid, coba lagi ya!" << endl;
                }
        }
    }

    return 0;
}
