#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Nilai {
    float mtk;
    float bind;
    float bing;
    float ipa;
};

struct Siswa {
    string nama;
    string nisn;
    string jurusan;
    Nilai nilai;
};

float hitungNilaiAkhir(Nilai n) {
    float hasil;
    hasil = (n.mtk * 0.4) + (n.ipa * 0.3) + (n.bind * 0.2) + (n.bing * 0.1);
    return hasil;
}

void tambahData() {
    ofstream file;
    file.open("siswa.txt", ios::app);
    Siswa s;

    cout << "\nMasukkan nama: ";
    getline(cin, s.nama);
    cout << "Masukkan NISN: ";
    getline(cin, s.nisn);
    cout << "Masukkan jurusan: ";
    getline(cin, s.jurusan);

    cout << "Nilai Matematika: ";
    cin >> s.nilai.mtk;
    cout << "Nilai Bahasa Indonesia: ";
    cin >> s.nilai.bind;
    cout << "Nilai Bahasa Inggris: ";
    cin >> s.nilai.bing;
    cout << "Nilai IPA: ";
    cin >> s.nilai.ipa;
    cin.ignore();

    file << s.nama << " " << s.nisn << " " << s.jurusan << " "
         << s.nilai.mtk << " " << s.nilai.bind << " " << s.nilai.bing << " " << s.nilai.ipa << endl;

    file.close();
    cout << "Data berhasil disimpan!\n";
}

void tampilData() {
    ifstream file;
    file.open("siswa.txt");
    if (!file.is_open()) {
        cout << "Belum ada data siswa!\n";
        return;
    }

    Siswa s;
    cout << "\n===== DATA SISWA =====\n";
    while (file >> s.nama >> s.nisn >> s.jurusan
           >> s.nilai.mtk >> s.nilai.bind >> s.nilai.bing >> s.nilai.ipa) {
        cout << "Nama: " << s.nama << endl;
        cout << "NISN: " << s.nisn << endl;
        cout << "Jurusan: " << s.jurusan << endl;
        cout << "Nilai Akhir: " << hitungNilaiAkhir(s.nilai) << endl;
        cout << "------------------------\n";
    }

    file.close();
}

void cariSiswa() {
    ifstream file;
    file.open("siswa.txt");
    if (!file.is_open()) {
        cout << "Belum ada data siswa!\n";
        return;
    }

    string cari;
    cout << "Masukkan NISN yang dicari: ";
    getline(cin, cari);

    Siswa s;
    bool ketemu = false;
    while (file >> s.nama >> s.nisn >> s.jurusan
           >> s.nilai.mtk >> s.nilai.bind >> s.nilai.bing >> s.nilai.ipa) {
        if (s.nisn == cari) {
            cout << "\nData Ditemukan!\n";
            cout << "Nama: " << s.nama << endl;
            cout << "Jurusan: " << s.jurusan << endl;
            cout << "Nilai Akhir: " << hitungNilaiAkhir(s.nilai) << endl;
            ketemu = true;
            break;
        }
    }

    if (!ketemu)
        cout << "Data tidak ditemukan!\n";

    file.close();
}

int main() {
    int pilih;

    do {
        cout << "\n===== MENU DATA SISWA =====\n";
        cout << "1. Tambah Data Siswa\n";
        cout << "2. Tampilkan Semua Data\n";
        cout << "3. Cari Data Siswa\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu (1-4): ";
        cin >> pilih;
        cin.ignore();

        if (pilih == 1)
            tambahData();
        else if (pilih == 2)
            tampilData();
        else if (pilih == 3)
            cariSiswa();
        else if (pilih == 4)
            cout << "Program selesai.\n";
        else
            cout << "Pilihan tidak ada!\n";

    } while (pilih != 4);

    return 0;
}
