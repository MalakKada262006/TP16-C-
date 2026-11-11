#include <iostream>
#include <string>

class Configuration {
private:
    std::string cheminFichier;
    std::string utilisateur;
    std::string motDePasse;

    Configuration()
        : cheminFichier("/etc/app/config.json"),
          utilisateur("admin"),
          motDePasse("Secret123!") {}

public:

    Configuration(const Configuration&) = delete;
    Configuration& operator=(const Configuration&) = delete;

    static Configuration& getInstance() {
        static Configuration instance;
        return instance;
    }

    void setCheminFichier(const std::string& chemin) { cheminFichier = chemin; }
    void setUtilisateur(const std::string& user) { utilisateur = user; }
    void setMotDePasse(const std::string& pass) { motDePasse = pass; }

    void afficherParametres() const {
        std::cout << "--- Configuration Actuelle ---" << std::endl;
        std::cout << "Chemin du fichier : " << cheminFichier << std::endl;
        std::cout << "Utilisateur       : " << utilisateur << std::endl;
        std::cout << "Mot de passe      : " << motDePasse << std::endl;
        std::cout << "Adresse mémoire   : " << this << std::endl;
    }
};

int main() {

    Configuration& config1 = Configuration::getInstance();
    config1.afficherParametres();

    Configuration& config2 = Configuration::getInstance();
    config2.setCheminFichier("/var/log/app.conf");

    std::cout << "\nAprès modification via 'config2' :" << std::endl;
    config1.afficherParametres();

    return 0;
}
