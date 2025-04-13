#include <iostream>
#include <fstream>
#include <sstream>
#include "data.h"
#include "anggota.h"
using namespace std;

// Fungsi tambahAkun dikomentari karena tidak lagi digunakan
/*
void tambahAkun(string role, string username, string password) {
    AkunNode* baru = new AkunNode{role, username, password, nullptr};
    if (!akunHead) {
        akunHead = baru;
    } else {
        AkunNode* temp = akunHead;
        while (temp->next) temp = temp->next;
        temp->next = baru;
    }
}
*/

// Fungsi loadAkun dikomentari karena tidak lagi digunakan
/*
void loadAkun() {
    ifstream file("akun.txt");
    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string role, username, password;

        if (getline(ss, role, ',') && getline(ss, username, ',') && getline(ss, password, ',')) {
            cout << "Role: " << role << ", Username: " << username << ", Password: " << password << endl;

            tambahAkun(role, username, password);
        }
    }
    file.close();
}
*/

// Cek login
bool login(string role, string username, string password) {
    if (role == "ANGGOTA") {
        anggotaNode* temp = headAnggota;
        while (temp) {
            if (to_string(temp->id) == username && temp->pass == password) {
                return true;
            }
            temp = temp->next;
        }
    }
    // Placeholder for future roles (PELATIH, ADMIN)
    return false;
}

// Menu login interaktif
void menuLogin() {
    loadFromDatabase(); // Load data anggota dari database
    int pilihan;
    string role, username, pass;

    cout << "\n=== MENU LOGIN ===\n";
    cout << "1. Login Anggota\n";
    cout << "2. Login Pelatih\n";
    cout << "3. Login Admin\n";
    cout << "0. Keluar\n";
    cout << "Pilih opsi: ";
    cin >> pilihan;

    switch (pilihan) {
        case 1: role = "ANGGOTA"; break;
        case 2: role = "PELATIH"; break;
        case 3: role = "ADMIN"; break;
        case 0: return;
        default:
            cout << "Pilihan tidak valid!\n";
            return;
    }

    cout << "Username (ID): ";
    cin >> username;
    cout << "Password: ";
    cin >> pass;

    if (login(role, username, pass)) {
        cout << "Login berhasil sebagai " << role << "!\n";
        if (role == "ANGGOTA") {
            menuAnggota();
        } else if (role == "PELATIH") {
            // Placeholder for pelatih menu
        } else if (role == "ADMIN") {
            // Placeholder for admin menu
        }
    } else {
        cout << "Login gagal. Cek username/password.\n";
    }
}