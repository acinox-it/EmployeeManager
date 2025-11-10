#include <iostream>
#include <windows.h>
#include "DatabaseManager.h"

int main() {

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    DatabaseManager db;

    if (!db.connect("localhost", "root", "", "employes_manager_db", 3306)) {
        std::cerr << "Erreur connexion: " << db.lastError() << std::endl;
        return 1;
    }
    std::cout << "✅ Connexion réussie !" << std::endl;

    auto users = db.listUsers();
    for (const auto& u : users) {
        u.display();
        std::cout << "Login: " << u.getUsername()
                  << " | Rôle: " << u.getRole()
                  << std::endl;
    }

    db.disconnect();
    return 0;
}
