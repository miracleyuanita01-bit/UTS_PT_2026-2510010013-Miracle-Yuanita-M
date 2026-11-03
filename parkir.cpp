#include <bits/stdc++.h>
using namespace std;

int main() {
    const int TARIF_AWAL_MOTOR = 3000;
    const int TARIF_LANJUT_MOTOR = 1000;
    const int BATAS_MAKS_MOTOR = 10000;
    const int TARIF_AWAL_MOBIL = 5000;
    const int TARIF_LANJUT_MOBIL = 3000;
    const int BATAS_MAKS_MOBIL = 30000;

    cout << "=== Parkir Kampus ===\n";
    int jumlah = 0;
    cout << "Jumlah kendaraan:\n";
    cin >> jumlah;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // TODO 5a
    int biayaTertinggi = -1;
    string platTertinggi = "";
    int totalPendapatan = 0;
    int hitungMotor = 0, hitungMobil = 0;

    for (int i = 1; i <= jumlah; i++) {
        cout << "\n--- Kendaraan ke-" << i << " dari " << jumlah << " ---\n";

        // TODO 1
        string plat;
        bool platSah = false;
        do {
            cout << "Plat nomor : ";
            getline(cin, plat);
            string cek = plat;
            cek.erase(remove_if(cek.begin(), cek.end(), ::isspace), cek.end());
            if (cek.empty()) {
                cout << "Plat tidak boleh kosong.\n";
                platSah = false;
            } else {
                platSah = true;
                for (size_t k = 0; k < plat.length(); k++) {
                    plat[k] = toupper(plat[k]);
                }
            }
        } while (!platSah);

        // TODO 2
        char jenis = 0;
        cout << "Jenis (M/R): ";
        while (true) {
            string s;
            getline(cin, s);
            if (s.empty()) { cout << "Jenis (M/R): "; continue; }
            char j = toupper(s[0]);
            if (j == 'M' || j == 'R') { jenis = j; break; }
            cout << "Hanya M (motor) atau R (roda empat). Jenis (M/R): ";
        }

        // TODO 3
        int durasi = 0;
        cout << "Durasi (jam, 1-24): ";
        while (true) {
            cin >> durasi;
            if (cin.fail() || durasi < 1 || durasi > 24) {
                cout << "Harus bilangan bulat 1 sampai 24. Durasi (jam): ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }

        // TODO 4
        int biaya = 0;
        string namaJenis;
        if (jenis == 'M') {
            namaJenis = "Motor";
            if (durasi <= 2) biaya = TARIF_AWAL_MOTOR;
            else biaya = TARIF_AWAL_MOTOR + (durasi - 2) * TARIF_LANJUT_MOTOR;
            if (biaya > BATAS_MAKS_MOTOR) biaya = BATAS_MAKS_MOTOR;
            hitungMotor++;
        } else {
            namaJenis = "Mobil";
            if (durasi <= 2) biaya = TARIF_AWAL_MOBIL;
            else biaya = TARIF_AWAL_MOBIL + (durasi - 2) * TARIF_LANJUT_MOBIL;
            if (biaya > BATAS_MAKS_MOBIL) biaya = BATAS_MAKS_MOBIL;
            hitungMobil++;
        }

        cout << plat << "  " << namaJenis << "    " << durasi << " jam    " << biaya << "\n";
        totalPendapatan += biaya;

        // TODO 5b
        if (biaya > biayaTertinggi) {
            biayaTertinggi = biaya;
            platTertinggi = plat;
        }
    }

    cout << "\n=== Rekap Hari Ini ===\n";
    cout << "Jumlah kendaraan : " << jumlah << "\n";
    cout << "Motor            : " << hitungMotor << "\n";
    cout << "Mobil            : " << hitungMobil << "\n";
    cout << "Total pendapatan : " << totalPendapatan << "\n";
    cout << fixed << setprecision(2);
    cout << "Rata-rata biaya  : " << (jumlah ? (double)totalPendapatan / jumlah : 0) << "\n";
    cout.unsetf(ios::floatfield);
    cout << "Tertinggi        : " << platTertinggi << " (" << biayaTertinggi << ")\n";

    // TODO 6 - bersarang
    cout << "\nSebaran jenis:\n";
    cout << "Motor | ";
    for (int a = 0; a < 1; a++) {
        for (int b = 0; b < hitungMotor; b++) cout << "#";
    }
    cout << " " << hitungMotor << "\n";
    cout << "Mobil | ";
    for (int a = 0; a < 1; a++) {
        for (int b = 0; b < hitungMobil; b++) cout << "#";
    }
    cout << " " << hitungMobil << "\n";
    return 0;
}