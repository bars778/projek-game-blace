#include "RunSession.h"

RunSession::RunSession() {
    stats = {1, 1, 1000, 4, 3, 0, 0}; // Inisialisasi awal
    isRunning = true;
}

void RunSession::playHand() {
    if (stats.hands > 0) {
        stats.currentScore += 150; // Contoh: kartu memberi 150 poin
        stats.hands--;             // Kurangi sisa kesempatan
        updateState();             // Cek apakah menang/kalah
    }
}

void RunSession::updateState() {
    if (stats.currentScore >= stats.targetScore) {
        // Logika naik level atau menang
    } else if (stats.hands <= 0) {
        isRunning = false; // Game Over
    }
}
