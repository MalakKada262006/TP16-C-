#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <functional>

class Observateur {
public:
    virtual void mettreAJour(float temperature, float humidite, float pression) = 0;
    virtual ~Observateur() = default;
};

class StationMeteo {
private:
    std::vector<Observateur*> observateurs;
    float temperature = 0.0f;
    float humidite = 0.0f;
    float pression = 0.0f;

public:
    void ajouterObservateur(Observateur* obs) {
        observateurs.push_back(obs);
    }

    void supprimerObservateur(Observateur* obs) {
        observateurs.erase(
            std::remove(observateurs.begin(), observateurs.end(), obs),
            observateurs.end()
        );
    }

    void notifierObservateurs() {
        for (Observateur* obs : observateurs) {
            obs->mettreAJour(temperature, humidite, pression);
        }
    }

    void setMesures(float t, float h, float p) {
        temperature = t;
        humidite = h;
        pression = p;
        notifierObservateurs();
    }
};

class AffichageTemperature : public Observateur {
public:
    void mettreAJour(float temperature, float, float) override {
        std::cout << "[Affichage Temperature] : " << temperature << " °C" << std::endl;
    }
};

class AffichageHumidite : public Observateur {
public:
    void mettreAJour(float, float humidite, float) override {
        std::cout << "[Affichage Humidite]    : " << humidite << " %" << std::endl;
    }
};

class AffichagePression : public Observateur {
public:
    void mettreAJour(float, float, float pression) override {
        std::cout << "[Affichage Pression]    : " << pression << " hPa" << std::endl;
    }
};

int main() {
    StationMeteo station;

    AffichageTemperature affTemp;
    AffichageHumidite affHum;
    AffichagePression affPress;

    std::cout << "--- Inscription des 3 observateurs ---" << std::endl;
    station.ajouterObservateur(&affTemp);
    station.ajouterObservateur(&affHum);
    station.ajouterObservateur(&affPress);

    std::cout << "\n--- Premiere mise a jour des donnees ---" << std::endl;
    station.setMesures(25.5f, 75.0f, 1014.2f);

    std::cout << "\n--- Desinscription de l affichage d humidite ---" << std::endl;
    station.supprimerObservateur(&affHum);

    std::cout << "\n--- Deuxieme mise a jour des donnees ---" << std::endl;
    station.setMesures(27.1f, 78.0f, 1021.5f);

    return 0;
}
