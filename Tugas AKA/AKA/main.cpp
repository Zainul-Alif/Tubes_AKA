#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

// Fungsi untuk menghitung total nilai katalog secara iteratif
int iterative_sum(const vector<int>& catalog) {
    int total = 0;
    for (int value : catalog) {
        total += value;
    }
    return total;
}

// Fungsi untuk menghitung total nilai katalog secara rekursif
int recursive_sum(const vector<int>& catalog, int index = 0) {
    if (index == catalog.size()) {
        return 0;
    }
    return catalog[index] + recursive_sum(catalog, index + 1);
}

// Fungsi untuk menghitung persentase perbedaan antara hasil iteratif dan rekursif
double calculate_percentage(int iterative_result, int recursive_result) {
    if (iterative_result == 0) {
        return 0.0;
    }
    double difference = abs(iterative_result - recursive_result);
    double percentage = (difference / iterative_result) * 100.0;
    return percentage;
}

int main() {
    // Contoh katalog perpustakaan
    vector<int> catalog = {10, 20, 30, 40, 50};

    // Hitung total menggunakan pendekatan iteratif
    int iterative_result = iterative_sum(catalog);
    cout << "Total nilai katalog (Iteratif): " << iterative_result << endl;

    // Hitung total menggunakan pendekatan rekursif
    int recursive_result = recursive_sum(catalog);
    cout << "Total nilai katalog (Rekursif): " << recursive_result << endl;

    // Hitung persentase perbedaan
    double percentage_difference = calculate_percentage(iterative_result, recursive_result);
    cout << fixed << setprecision(2); // Menampilkan 2 angka di belakang koma
    cout << "Persentase perbedaan: " << percentage_difference << "%" << endl;

    return 0;
}

/*
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Book {
    string title;
    string author;
    int year;
    double rating;
    int borrowCount;
};

// Fungsi untuk mengisi katalog dengan data buku secara otomatis
vector<Book> generateBooks(int count) {
    vector<Book> books;
    srand(time(0));

    for (int i = 1; i <= count; ++i) {
        books.push_back({
            "Book " + to_string(i),
            "Author " + to_string(i),
            1980 + rand() % 43,  // Tahun terbit antara 1980-2023
            (rand() % 501) / 100.0, // Rating antara 0.0-5.0
            rand() % 1001  // Jumlah peminjaman antara 0-1000
        });
    }

    return books;
}

// Fungsi iteratif untuk mencari buku terbaik berdasarkan rating tertinggi
Book findBestBookIterative(const vector<Book>& books) {
    Book bestBook = books[0];

    for (const auto& book : books) {
        if (book.rating > bestBook.rating) {
            bestBook = book;
        }
    }

    return bestBook;
}

// Fungsi rekursif untuk mencari buku terbaik berdasarkan rating tertinggi
Book findBestBookRecursive(const vector<Book>& books, int index, Book currentBest) {
    if (index == books.size()) {
        return currentBest;
    }

    if (books[index].rating > currentBest.rating) {
        currentBest = books[index];
    }

    return findBestBookRecursive(books, index + 1, currentBest);
}

int main() {
    // Generate katalog buku dengan 100 data
    vector<Book> books = generateBooks(10);

    // Menampilkan data buku
    cout << "Daftar Buku:\n";
    for (const auto& book : books) {
        cout << "Judul: " << book.title
             << ", Penulis: " << book.author
             << ", Tahun: " << book.year
             << ", Rating: " << book.rating
             << ", Dipinjam: " << book.borrowCount << " kali\n";
    }

    // Mencari buku terbaik secara iteratif
   /* Book bestBookIterative = findBestBookIterative(books);
    cout << "\nBuku Terbaik (Iteratif):\n"
         << "Judul: " << bestBookIterative.title
         << ", Penulis: " << bestBookIterative.author
         << ", Tahun: " << bestBookIterative.year
         << ", Rating: " << bestBookIterative.rating
         << ", Dipinjam: " << bestBookIterative.borrowCount << " kali\n";

    // Mencari buku terbaik secara rekursif
    Book bestBookRecursive = findBestBookRecursive(books, 0, books[0]);
    cout << "\nBuku Terbaik (Rekursif):\n"
         << "Judul: " << bestBookRecursive.title
         << ", Penulis: " << bestBookRecursive.author
         << ", Tahun: " << bestBookRecursive.year
         << ", Rating: " << bestBookRecursive.rating
         << ", Dipinjam: " << bestBookRecursive.borrowCount << " kali\n";

    return 0;
}
*/
