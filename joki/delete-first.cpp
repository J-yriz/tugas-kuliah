#include <iostream>
using namespace std;

// Struktur Node
struct Node {
    int data;         // ID atau berat paket
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
    cout << "\n[ Daftar Paket di Gudang Kurir ]" << endl;
    while (current != nullptr) {
        cout << "Paket: " << current->data
             << " | Alamat: " << current
             << " | Prev: " << current->prev
             << " | Next: " << current->next << endl;
        current = current->next;
    }
    cout << "---------------------------------------" << endl;
}

// Fungsi untuk menyisipkan node sebagai elemen pertama dalam linked list
void insertFirst(Node*& head, int data) {
    cout << ">> Paket baru masuk (ID: " << data << ") dimasukkan ke antrian terdepan (Insert First)" << endl;
    Node* newNode = createNode(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Fungsi untuk menghapus node pertama dari linked list
void deleteFirst(Node*& head) {
    if (head == nullptr) {
        cout << ">> Tidak ada paket di gudang, kurir menunggu..." << endl;
        return;
    }

    cout << ">> Kurir mengambil dan mengirim paket (ID: " << head->data << ") dari depan (Delete First)" << endl;
    Node* temp = head;
    head = head->next;

    if (head != nullptr) {
        head->prev = nullptr;
    }

    delete temp;
}

int main() {
    Node* head = nullptr;

    // Awal: ada satu paket dengan ID 5
    head = createNode(5);
    cout << ">> Gudang awal: 1 paket (ID: 5)" << endl;
    displayList(head);

    // Tambah paket baru (ID: 7) ke depan
    insertFirst(head, 7);
    displayList(head);

    // Kurir mengambil paket terdepan
    deleteFirst(head);
    displayList(head);

    // Kurir mengambil lagi paket berikutnya
    deleteFirst(head);
    displayList(head);

    // Coba hapus saat kosong
    deleteFirst(head);

    return 0;
}
