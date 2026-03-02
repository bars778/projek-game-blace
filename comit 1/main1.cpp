#include <iostream> // Wajib ada untuk input/output
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;

enum Element { PYRA, NERIS, VOLTAR };
string namaElemen[] = {"Pyra", "Neris", "Voltar"};

struct Kartu {
    Element elemen;
    int level;
    bool isWild;
};

// --- Fungsi Pembantu ---
vector<Kartu> buatDeck() {
    vector<Kartu> deck;
    for(int e = 0; e < 3; e++) {
        for(int lvl = 1; lvl <= 2; lvl++) {
            deck.push_back({(Element)e, lvl, false});
            deck.push_back({(Element)e, lvl, true});
        }
    }
    return deck;
}

// --- FUNGSI UTAMA (WAJIB ADA) ---
int main() {
    srand(time(0));
    vector<Kartu> deck = buatDeck();
    
    cout << "=== GAME BERHASIL DIJALANKAN ===" << endl;
    cout << "Jumlah kartu di deck: " << deck.size() << endl;
    
    // Contoh menampilkan kartu pertama
    cout << "Kartu 1: " << namaElemen[deck[0].elemen] << " Lvl: " << deck[0].level << endl;

    system("pause"); // Agar jendela tidak langsung tertutup
    return 0;
}
