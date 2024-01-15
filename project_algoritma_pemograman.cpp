#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Pesanan {
    string namaPenerima;
    string alamatPenerima;
    string merk;
    string jadwal;
    string jam;
    int jumlahBotol;
    double hargaPerBotol;
};

int main() {
    
    string namaPenerima, alamatPenerima;
    cout << "Masukkan Nama Penerima: ";
    getline(cin, namaPenerima);
    cout << "Masukkan Alamat Penerima: ";
    getline(cin, alamatPenerima);

    vector<string> merkAir = {"Aqua", "Pristine", "Cleo", "Le Minerale", "Amidis", "Evian"};
    vector<double> hargaPerBotol = {5000.0, 6000.0, 7000.0, 8000.0, 7500.0, 10000.0};

    vector<string> jadwalPengiriman = {"Senin", "Selasa", "Rabu", "Kamis", "Jumat"};

    vector<string> jamPengiriman = {"08:00", "10:00", "13:00", "15:00", "18:00"};

    cout << "Pilih Merk Air Mineral:" << endl;
    for (int i = 0; i < merkAir.size(); ++i) {
        cout << i + 1 << ". " << merkAir[i] << " - Harga per Botol: " << hargaPerBotol[i] << " IDR" << endl;
    }

    int pilihanMerk;
    cout << "Masukkan nomor merk yang dipilih: ";
    cin >> pilihanMerk;

    if (pilihanMerk < 1 || pilihanMerk > merkAir.size()) {
        cout << "Pilihan merk tidak valid. Program berhenti." << endl;
        return 1;
    }

    cout << "Pilih Jadwal Pengiriman:" << endl;
    for (int i = 0; i < jadwalPengiriman.size(); ++i) {
        cout << i + 1 << ". " << jadwalPengiriman[i] << " - " << jamPengiriman[i] << endl;
    }

    int pilihanJadwal;
    cout << "Masukkan nomor jadwal yang dipilih: ";
    cin >> pilihanJadwal;

    if (pilihanJadwal < 1 || pilihanJadwal > jadwalPengiriman.size()) {
        cout << "Pilihan jadwal tidak valid. Program berhenti." << endl;
        return 1;
    }

    int jumlahBotol;
    cout << "Masukkan jumlah botol yang dipesan: ";
    cin >> jumlahBotol;

    Pesanan pesanan;
    pesanan.namaPenerima = namaPenerima;
    pesanan.alamatPenerima = alamatPenerima;
    pesanan.merk = merkAir[pilihanMerk - 1];
    pesanan.jadwal = jadwalPengiriman[pilihanJadwal - 1];
    pesanan.jam = jamPengiriman[pilihanJadwal - 1];
    pesanan.jumlahBotol = jumlahBotol;
    pesanan.hargaPerBotol = hargaPerBotol[pilihanMerk - 1];

    double totalHarga = pesanan.jumlahBotol * pesanan.hargaPerBotol;

    cout << "Pesanan Anda:" << endl;
    cout << "Nama Penerima: " << pesanan.namaPenerima << endl;
    cout << "Alamat Penerima: " << pesanan.alamatPenerima << endl;
    cout << "Merk: " << pesanan.merk << endl;
    cout << "Jadwal Pengiriman: " << pesanan.jadwal << " - Jam: " << pesanan.jam << endl;
    cout << "Jumlah Botol: " << pesanan.jumlahBotol << endl;
    cout << "Harga per Botol: " << pesanan.hargaPerBotol << " IDR" << endl;
    cout << "Total Harga: " << totalHarga << " IDR" << endl;

    return 0;
}