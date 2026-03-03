#include "RunSession.h"
#include <iostream>

using namespace std;

// Konstruktor: Inisialisasi awal permainan
RunSession::RunSession() {
    // stats = {level, round, targetScore, hands, discards, maxScore, currentScore}
    stats = {1, 1, 300, 4, 3, 1000, 0}; 
    isRunning = true;
}

void RunSession::setStyle(int color) {
    cout << "\n[System] Tema visual diatur ke mode: " << color << endl;
}

void RunSession::renderUI() {
    cout << "\n===============================" << endl;
    cout << "       CARD STRATEGY SIM       " << endl; // Nama baru
    cout << "===============================" << endl;
    cout << " Level: " << stats.level << " | Round: " << stats.round << endl;
    cout << " Target Skor : " << stats.targetScore << endl;
    cout << " Skor Saat Ini: " << stats.currentScore << endl;
    cout << "-------------------------------" << endl;
    cout << " Sisa Hands   : " << stats.hands << endl;
    cout << " Sisa Discards: " << stats.discards << endl;
    cout << "===============================" << endl;
}

void RunSession::playHand() {
    if (stats.hands > 0) {
        stats.hands--;
        stats.currentScore += 100; // Logika penambahan skor
        cout << ">> Kartu dimainkan! (+100 Skor)" << endl;
    } else {
        cout << ">> Gagal! Sisa 'Hands' kamu habis." << endl;
    }
}

void RunSession::discardHand() {
    if (stats.discards > 0) {
        stats.discards--;
        cout << ">> Kartu dibuang (Discard)." << endl;
    } else {
        cout << ">> Gagal! Sisa 'Discard' kamu habis." << endl;
    }
}

void RunSession::updateState() {
    if (stats.currentScore >= stats.targetScore) {
        cout << "\n*** VICTORY! TARGET TERCAPAI ***" << endl;
        isRunning = false;
    } else if (stats.hands <= 0) {
        cout << "\n*** DEFEAT! KAMU KEHABISAN TANGAN ***" << endl;
        isRunning = false;
    }
}

bool RunSession::isActive() const {
    return isRunning;
}
