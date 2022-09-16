#include <iostream>
#include <stdlib.h>
#include <list>
#include <fstream>
#include <vector>


using namespace std;

/// CLASE PAQUETE///
class Paquete
{

 private:

      int id;
      string origen;
      string destino;
      float peso;

public:
    Paquete(){};
    Paquete(const string &origen ,const string &des,int id,float ps);

    int getID();
    string getORIGEN();
    string getDESTINO();
    float getPESO();

    void setID(int _id);
    void setORIGEN(string &_origen);
    void setDESTINO(string &_destino);
    void setPESO(float _peso);

};

Paquete::Paquete(const string &origen,const string &des, int id, float ps){

    this->id = id;
    this->origen = origen;
    this->destino = des;
    this->peso = ps;

}

void Paquete::setID(int _id){
    id = _id;
}

void Paquete::setORIGEN(string &_origen){
    origen = _origen;
}
void Paquete::setDESTINO(string &_destino){
    destino = _destino;
}
void Paquete::setPESO(float _peso){
    peso = _peso;
}

int Paquete::getID(){
    return id;
}
string Paquete::getORIGEN(){
    return origen;
}
string Paquete::getDESTINO(){
    return destino;
}
float Paquete::getPESO(){
    return peso;
}
///CLASE PAQUETERIA////

class Paqueteria{

    Paquete lista[7];
    size_t cont;

public:
    Paqueteria();
    void agregar(const Paquete &p);
    void mostrar();
    void guardar_archivo();
    void recuperar_archivo();
    void elminiar();

};

Paqueteria::Paqueteria(){
    cont = 0;
}

void Paqueteria::agregar(const Paquete &p){

    if(cont < 7){
        lista[cont] = p;
        cont++;
    }
    else{
        cout << "No se pueden agregar mas Paquetes. " << endl;
    }
}

void Paqueteria::mostrar(){

    cout << "Mostrando los elementos de la lista... " << endl << endl;

    for(size_t i = 0; i < cont; i++){
        Paquete &p = lista[i];
        cout << "ID:  " << p.getID() << endl;
        cout << "Origen:  " << p.getORIGEN() << endl;
        cout << "Destino:  " << p.getDESTINO() << endl;
        cout << "Peso:  " << p.getPESO() << endl;

    }

}

void Paqueteria::guardar_archivo(){

    ofstream archivo("Lista.txt");
    if(archivo.is_open()){

        for(size_t i = 0; i < cont; i++){
        Paquete &p = lista[i];
        archivo << p.getID() << endl;
        archivo << p.getORIGEN() << endl;
        archivo << p.getDESTINO() << endl;
        archivo << p.getPESO() << endl;
    }
    }
    else{
        cout<< "No se encontro el archivo." << endl;
    }
    archivo.close();
}

void Paqueteria::recuperar_archivo(){

    ifstream archivo2("Lista.txt");

    if(archivo2.is_open()){
        string temp;
        int num;
        float num2;
        Paquete p;

        while(true)
        {
            getline(archivo2,temp); //ID
            if(archivo2.eof()){
                break;
            }
            num = stoi(temp);
            p.setID(num);

            getline(archivo2,temp); //ORIRGEN
            p.setORIGEN(temp);

            getline(archivo2,temp); //DESTINO
            p.setDESTINO(temp);

            getline(archivo2, temp); //PESO
            num2 = stof(temp);
            p.setPESO(num2);

            agregar(p);

        }

    }
    archivo2.close();
    cout << "Datos recuperados del Archivo :)" << endl;
}

void Paqueteria::elminiar(){

    int a = 0;
    for(size_t i = 0; i <7;i++){
       if(i==a){
        while(i<6){
            lista[i] = lista[i+1];
            i++;
        }
        break;
       }
    }
}



int main()
{
    Paqueteria Pa;
    int opc;
    while(opc != 6){

    cout << "-----MENU-----" << endl;
    cout << "1). Agregar Paquete  "<<endl;
    cout << "2). Eliminar Paquete "<<endl;
    cout << "3). Mostrar          " << endl;
    cout << "4). Guardar          " << endl;
    cout << "5). Recuperar        " << endl;
    cout << "6). Salir            " << endl;
    cout << "Elije una opcion:    " << endl;
    cin>>opc;



    switch(opc)
    {

        case 1:
            {
                Paquete pq;
                cout << "Introduzca la ID del paquete: " << endl;
                int id;
                cin >> id;
                cin.ignore();

                cout << "Introduzca el Origen del paquete: " << endl;
                string origen;
                cin >> origen;
                cin.ignore();

                cout << "Introduzca el Destino del paquete: "<< endl;
                string destino;
                cin >> destino;
                cin.ignore();

                cout << "Introduzca el Peso del paquete: " << endl;
                float peso;
                cin >> peso;
                cin.ignore();

                pq.setID(id);
                pq.setORIGEN(origen);
                pq.setDESTINO(destino);
                pq.setPESO(peso);

                Pa.agregar(pq);

                system("cls");
            } //Fin Case 1
        break;

        case 2:{
            Pa.elminiar();

               } //Fin Case 2
        break;

        case 3:{
            Pa.mostrar();

                    } //Fin Case 3
            break;

        case 4:{
            cout << "Guardando los elementos en el archivo..." << endl << endl;
            Pa.guardar_archivo();
            cout << "Archivos Guardados :) " << endl;

            } //Fin Case 4

            break;

        case 5:{


            ifstream lectura("Lista.txt");
             if(!lectura.is_open()){
                cout << "No se pudo abrir el archivo. " << endl;
            }
            else{
                    Pa.recuperar_archivo();

            }
            break;

        } //Fin Case 5


    }

    };
    return 0;
    }
