#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>

class StrategieTri {
public:
    virtual void trier(std::vector<std::string>& donnees) const = 0;
    virtual ~StrategieTri() = default;
};


class TriCroissant : public StrategieTri {
public:
    void trier(std::vector<std::string>& donnees) const override {
        std::sort(donnees.begin(), donnees.end());
    }
};

class TriDecroissant : public StrategieTri {
public:
    void trier(std::vector<std::string>& donnees) const override {
        std::sort(donnees.begin(), donnees.end(), std::greater<std::string>());
    }
};

class TriParLongueur : public StrategieTri {
public:
    void trier(std::vector<std::string>& donnees) const override {
        std::sort(donnees.begin(), donnees.end(), [](const std::string& a, const std::string& b) {
            return a.length() < b.length();
        });
    }
};

class GestionnaireTri {
private:
    std::unique_ptr<StrategieTri> strategie;

public:
    explicit GestionnaireTri(std::unique_ptr<StrategieTri> stratInitiale)
        : strategie(std::move(stratInitiale)) {}

    void setStrategie(std::unique_ptr<StrategieTri> nouvelleStrategie) {
        strategie = std::move(nouvelleStrategie);
    }

    void executerTri(std::vector<std::string>& donnees) const {
        if (strategie) {
            strategie->trier(donnees);
        } else {
            std::cout << "[Erreur] Aucune stratégie de tri n'est définie !" << std::endl;
        }
    }
};

void afficherVecteur(const std::vector<std::string>& vec, const std::string& titre) {
    std::cout << titre << " : [ ";
    for (const auto& elem : vec) {
        std::cout << "\"" << elem << "\" ";
    }
    std::cout << "]" << std::endl;
}

int main() {
    std::vector<std::string> mots = {"Mange", "Avocat", "Banane", "Ananas", "Fraise"};

    afficherVecteur(mots, "Vecteur original");

    GestionnaireTri gestionnaire(std::make_unique<TriCroissant>());

    gestionnaire.executerTri(mots);
    afficherVecteur(mots, "1. Tri Croissant   ");

    gestionnaire.setStrategie(std::make_unique<TriDecroissant>());
    gestionnaire.executerTri(mots);
    afficherVecteur(mots, "2. Tri Décroissant ");

    gestionnaire.setStrategie(std::make_unique<TriParLongueur>());
    gestionnaire.executerTri(mots);
    afficherVecteur(mots, "3. Tri par Longueur");

    return 0;
}
