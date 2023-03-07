#include <iostream>
#include <cstring>
using namespace std;
class Cladire{
    int nrCamere;
    const int idCladire;
    static int contorCladire;
    int nrLocuitori;
//    char* Locuitori; //Numele Locuitorilor
    float Pret;
    bool Chirie;
    float* suprafata; //Lungime si Latime
public:

    Cladire();
    Cladire(int nrLocuitori, float Pret, bool Chirie,
            int nrCamere,float* suprafata);

    Cladire(const Cladire &obj);
//    Cladire &operator =(const Cladire &obj);
    ~Cladire();


    float getPret() const{
        return Pret;
    }
    void setPret(float aux){
        this->Pret = aux;
    }
    bool getChirie() const{
        return Chirie;
    }
    void setChirie(bool aux){
        this->Chirie = aux;
    }
    int getnrLocuitori() const{
        return nrLocuitori;
    }
    void setnrLocuitori(int aux){
        this->nrLocuitori = aux;
    }
    int getnrCamere() const {
        return nrCamere;
    }
    void setnrCamere(int aux){
        this->nrCamere = aux;
    }

    const int getidCladire() const {
        return idCladire;
    }
    static int getcontorCladire(){
        return contorCladire;
    }

    const float* getsuprafata(){
        return this->suprafata;
    }


    };

Cladire::Cladire():idCladire(contorCladire++) {
    nrLocuitori = 0;
    nrCamere = 0;

    Pret = 0.0;
    Chirie = true;

    suprafata = NULL;

}
Cladire::Cladire(int nrLocuitori, float Pret, bool Chirie,
                 int nrCamere,float* suprafata):idCladire(contorCladire++){

    this->nrLocuitori = nrLocuitori;
    this->Pret = Pret;
    this->Chirie = Chirie;
    this->nrCamere = nrCamere;

    this->suprafata = new float[nrCamere];
    for(int i=0; i<nrCamere; i++){
        this->suprafata[i] = *(suprafata+i);
    }

}
Cladire::Cladire(const Cladire &obj):idCladire(contorCladire++){
    this->nrLocuitori = obj.nrLocuitori;
    this->Pret = obj.Pret;
    this->Chirie = obj.Chirie;
    this->nrCamere = obj.nrCamere;
    this->suprafata = new float [obj.nrCamere];
    for(int i=0; i<nrCamere;i++){
        this->suprafata[i] = obj.suprafata[i];
    }


}
Cladire::~Cladire(){
    if(this->suprafata != NULL)
        delete[] this->suprafata;
    this->suprafata = NULL;
}


int Cladire::contorCladire = 0;



int main()
{
    float a[]={12.3,45.6,23.4};
    Cladire s1(10,123.3,true,3,a);
    cout << s1.getPret() <<" este Pret OB 1" << endl << s1.getChirie()<< " este Chirie OB1" << endl << s1.getidCladire() <<" este ID OB1" << endl;
    Cladire s2(s1);
    cout << s2.getidCladire() << " este ID OB2" << endl << s2.getnrCamere() << " Sunt Camerele la OB2" << endl;

    for(int i=0; i< s1.getnrCamere(); i++){
        cout << s1.getsuprafata()[i] << endl;
        cout << s1.getcontorCladire(); //???????
    }



    return 0;
}
