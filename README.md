# Personnel Manager (C++ / MySQL)

## 📖 Description
Application console en **C++** avec base **MySQL** pour gérer le personnel d'une entreprise.  
Chaque utilisateur est aussi un employé : il possède des informations RH (nom, poste, salaire, année d'entrée) et des informations de connexion (login, mot de passe, rôle).

---

## 🏗️ Architecture
- **Person** → classe de base (nom, prénom, date de naissance)
- **Employee** → hérite de Person (poste, salaire, année d'entrée)
- **User** → hérite de Employee (username, password, rôle)
- **DatabaseManager** → gère la connexion MySQL et les opérations CRUD
- **main.cpp** → boucle principale, test de connexion et affichage

---

## 🗃️ Base de données
Base : `employes_manager_db`  
Table unique : `users`

```sql
CREATE TABLE users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    first_name VARCHAR(100) NOT NULL,
    last_name VARCHAR(100) NOT NULL,
    birth_date DATE NOT NULL,
    position VARCHAR(100) NOT NULL,
    salary DECIMAL(10,2) NOT NULL,
    joined_year INT NOT NULL,
    username VARCHAR(100) UNIQUE NOT NULL,
    password VARCHAR(100) NOT NULL,
    role VARCHAR(50) NOT NULL
);
```
---

## 🖥️ Choix du serveur MySQL : WAMP ou XAMPP

Pour exécuter le projet en local, vous pouvez utiliser :

- **WAMP** : recommandé si vous êtes sous Windows uniquement.
- **XAMPP** : recommandé si vous voulez un environnement multi‑plateforme (Windows, Linux, macOS).

Les deux fournissent :
- Un serveur MySQL/MariaDB
- phpMyAdmin pour gérer la base
- Les bibliothèques nécessaires pour connecter votre projet C++

⚠️ Par défaut :
- WAMP → utilisateur `root` sans mot de passe
- XAMPP → utilisateur `root` sans mot de passe (MariaDB)

Vous pouvez définir un mot de passe via phpMyAdmin pour plus de sécurité.

---

## ⚙️ Configuration Code::Blocks pour MySQL

### 1. Inclure les headers MySQL
- Ouvre **Project → Build options → Search directories → Compiler**
- Ajoute le chemin vers les headers MySQL :
````markdown
C:\wamp64\bin\mysql\mysqlX.Y\include
````
### 2. Lier la librairie `.lib`
- Ouvre **Project → Build options → Linker settings → Add**
- Ajoute la librairie :
````markdown
C:\wamp64\bin\mysql\mysqlX.Y\bin\libmysql.dll
````
- Colle‑le dans le dossier de sortie de ton projet :
````markdown
bin\Debug
````
---

## 🛣️ Roadmap

### ✅ Phase 1 : Base du projet
- [x] Création des classes `Person`, `Employee`, `User`
- [x] Mise en place de l’héritage (User hérite de Employee, Employee hérite de Person)
- [x] Ajout du champ `joined_year` pour gérer l’ancienneté
- [x] Implémentation de `DatabaseManager` avec connexion MySQL
- [x] Script SQL complet avec 10 utilisateurs (admins, managers, employés)

### 🚧 Phase 2 : Fonctionnalités principales
- [ ] Implémenter `AuthManager` (login/logout)
- [ ] Vérification des rôles (`admin`, `manager`, `employee`)
- [ ] Menus console différents selon le rôle
- [ ] CRUD complet sur les employés (ajout, modification, suppression, liste)
- [ ] Calcul automatique de l’ancienneté et du bonus

### 🔜 Phase 3 : Améliorations
- [ ] Gestion des équipes par Manager
- [ ] Ajout de logs (audit des actions)
- [ ] Export des données (CSV/JSON)
- [ ] Gestion des mots de passe sécurisés (hashage avec bcrypt ou SHA256)

### 🌍 Phase 4 : Déploiement et portabilité
- [ ] Documentation complète (README, guide d’installation)
- [ ] Compatibilité multi‑plateforme (Windows avec WAMP, Linux avec XAMPP)
- [ ] Tests unitaires et intégration continue
- [ ] Préparation pour un futur passage en interface graphique (Qt ou autre)

