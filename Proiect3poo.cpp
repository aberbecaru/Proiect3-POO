#include <iostream>
#include <cmath>

///Template
template <typename T> class Medii{
public:
    Medii(T aa, T bb, T cc);
    T medie_aritmetica();
    T medie_geometrica();
    T medie_armonica();
    void afisare();
private:
    T a, b, c;
};

template <typename T> Medii<T>::Medii(T aa, T bb, T cc){
    a = aa;
    b = bb;
    c = cc;
}

template <typename T> T Medii<T>::medie_aritmetica() {
    return (a+b+c)/3;
}

template <typename T> T Medii<T>::medie_geometrica() {
    return (sqrt(a*b*c));
}

template <typename T> T Medii<T>::medie_armonica(){
    return (3*a*b*c)/(a*b+b*c+c*a);
}

template <typename T> void Medii<T>::afisare() {
    std::cout<<"Numerele: "<<a<<", "<<b<<" si "<<c<<"\n";
    std::cout<<"Media aritmetica: "<<medie_aritmetica()<<"\n";
    std::cout<<"Media geometrica: "<<medie_geometrica()<<"\n";
    std::cout<<"Media armonica: "<<medie_armonica()<<"\n";
}

///Singleton Design Pattern

class Cinema{
public:
    std::string getNume();
    void setNume(std::string nume);
    static Cinema* getInstance();
private:
    static Cinema* instance;
    std::string nume;
    Cinema(){
        nume = "Cinemaplex";
    }
};

std::string Cinema::getNume() {
    return this->nume;
}

void Cinema::setNume(std::string nume) {
    this->nume = nume;
}

Cinema* Cinema::getInstance() {
    if(!instance)
        instance = new Cinema;
    return instance;
}

Cinema* Cinema::instance = 0;

///Abstract Factory design pattern

class Telefon{
public:
    virtual void marca()=0;
};

class Samsung: public Telefon{
    void marca(){
        std::cout<<"Samsung"<<" ";
    }
};

class Huawei: public Telefon{
    void marca(){
        std::cout<<"Huawei"<<" ";
    }
};

class Apple: public Telefon{
    void marca(){
        std::cout<<"Iphone"<<" ";
    }
};

class Google: public Telefon{
    void marca(){
        std::cout<<"GooglePixel"<<" ";
    }
};


class Factory{
public:
    virtual Telefon* popular() = 0;
    virtual Telefon* nepopular() = 0;
};

class Asia: public Factory{
public:
    Telefon* popular();
    Telefon* nepopular();
};

Telefon* Asia::popular() {
    return new Samsung;
}

Telefon* Asia::nepopular() {
    return new Huawei;
}

class America: public Factory{
public:
    Telefon* popular();
    Telefon* nepopular();
};

Telefon* America::popular() {
    return new Apple;
}

Telefon* America::nepopular() {
    return new Google;
}

int main(){
    std::cout<<"Flux testare pentru template: "<<"\n";
    Medii<double>NrIntregi(5.0, 4.0, 3.0);
    Medii<double>Numere2(10.4, 8.12, 4.3);
    NrIntregi.afisare();
    std::cout<<"\n";
    Numere2.afisare();

    std::cout<<"\n";
    std::cout<<"Flux testare pentru Singleton: "<<"\n";

    Cinema *cinema = cinema->getInstance();
    std::cout<<cinema->getNume()<<"\n";
    cinema->setNume("CinemaCity");
    std::cout<<cinema->getNume()<<"\n";

    std::cout<<"\n";
    std::cout<<"Flux testare pentru Abstract Factory: "<<"\n";

    Factory *f1, *f2;
    f1 = new Asia;
    f2 = new America;
    Telefon *tel1, *tel2, *tel3, *tel4;
    tel1 = f1->popular();
    tel2 = f2->popular();
    tel3 = f1->nepopular();
    tel4 = f2->nepopular();

    tel1->marca();
    tel2->marca();
    tel3->marca();
    tel4->marca();
    std::cout<<"\n";
}
