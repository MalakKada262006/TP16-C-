#include <iostream>
#include <memory>
#include <string>

class Forme {
public:
    virtual void afficher() const = 0;
    virtual ~Forme() = default;
};

class Cercle : public Forme {
public:
    void afficher() const override {
        std::cout << "Forme : Cercle " << std::endl;
    }
};

class Carre : public Forme {
public:
    void afficher() const override {
        std::cout << "Forme : Carré " << std::endl;
    }
};

class Triangle : public Forme {
public:
    void afficher() const override {
        std::cout << "Forme : Triangle " << std::endl;
    }
};

class FabriqueForme {
public:
    enum class TypeForme {
        Cercle,
        Carre,
        Triangle
    };

    static std::unique_ptr<Forme> creerForme(TypeForme type) {
        switch (type) {
            case TypeForme::Cercle:
                return std::make_unique<Cercle>();
            case TypeForme::Carre:
                return std::make_unique<Carre>();
            case TypeForme::Triangle:
                return std::make_unique<Triangle>();
            default:
                return nullptr;
        }
    }
};

int main() {
    auto f1 = FabriqueForme::creerForme(FabriqueForme::TypeForme::Cercle);
    auto f2 = FabriqueForme::creerForme(FabriqueForme::TypeForme::Carre);
    auto f3 = FabriqueForme::creerForme(FabriqueForme::TypeForme::Triangle);

    if (f1) f1->afficher();
    if (f2) f2->afficher();
    if (f3) f3->afficher();

    return 0;
}
