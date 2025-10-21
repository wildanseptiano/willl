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

