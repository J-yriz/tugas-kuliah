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

// Fungsi untuk menampilkan informasi tentang setiap node dalam linked list
void displayList(Node* head) {
    Node* current = head;
    cout << "\n[ Rak Es Teh Sekarang ]" << endl;
    while (current != nullptr) {
        cout << "Jumlah Gelas: " << current->data << " | Alamat: " << current;
        cout << " | Prev: " << current->prev << " | Next: " << current->next << endl;
        current = current->next;
    }
    cout << "---------------------------------------" << endl;
}

// Fungsi untuk menyisipkan node sebagai elemen terakhir dalam linked list
void insertLast(Node*& head, int data) {
    cout << ">> Menambahkan " << data << " gelas es teh ke rak paling belakang (Insert Last)" << endl;
    Node* newNode = createNode(data);
    if (head == nullptr) {
        head = newNode; // Jika rak kosong, es teh pertama jadi head
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

int main() {
    Node* head = nullptr;

    // Pertama kali buka, ada 5 gelas es teh disiapkan
    head = createNode(5);
    cout << ">> Buka toko, siapin 5 gelas es teh di rak pertama" << endl;
    displayList(head);

    // Tambah 7 gelas es teh lagi ke belakang
    insertLast(head, 7);
    displayList(head);

    // Tambah 8 gelas lagi
    insertLast(head, 8);
    displayList(head);

    return 0;
}
