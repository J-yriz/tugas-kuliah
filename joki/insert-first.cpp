#include <iostream>
using namespace std;

// Struktur Node
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Fungsi untuk membuat node baru
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

// Fungsi untuk menyisipkan node sebagai elemen pertama dalam linked list
void insertFirst(Node*& head, int data) {
    cout << ">> Menambahkan " << data << " roti ke depan etalase (Insert First)" << endl;
    Node* newNode = createNode(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Fungsi untuk menyisipkan node setelah node dengan nilai tertentu dalam linked list
void insertAfter(Node* head, int valueToInsertAfter, int data) {
    Node* current = head;
    while (current != nullptr && current->data != valueToInsertAfter) {
        current = current->next;
    }
    if (current == nullptr) {
        cout << "Node dengan nilai " << valueToInsertAfter << " tidak ditemukan" << endl;
        return;
    }
    cout << ">> Menambahkan " << data << " roti setelah stok " << valueToInsertAfter << " roti" << endl;
    Node* newNode = createNode(data);
    newNode->next = current->next;
    newNode->prev = current;
    current->next = newNode;
    if (newNode->next != nullptr) {
        newNode->next->prev = newNode;
    }
}

// Fungsi untuk menampilkan informasi tentang setiap node dalam linked list
void displayList(Node* head) {
    Node* current = head;
    cout << "\n[ Etalase Roti Sekarang ]" << endl;
    while (current != nullptr) {
        cout << "Jumlah Roti: " << current->data << " | Alamat: " << current;
        cout << " | Prev: " << current->prev << " | Next: " << current->next << endl;
        current = current->next;
    }
    cout << "---------------------------------------\n";
}

int main() {
    // Inisialisasi pointer simpul
    Node* head = nullptr;

    // Pertama kali toko buka, datang stok 5 roti
    head = createNode(5);
    cout << ">> Toko buka, datang pertama kali 5 roti" << endl;
    displayList(head);

    // Lalu datang roti spesial 7 pcs dan ditaruh paling depan
    insertFirst(head, 7);
    displayList(head);

    // Tambahkan 8 roti setelah roti 7 (roti manis datang belakangan)
    insertAfter(head, 7, 8);
    displayList(head);

    return 0;
}
