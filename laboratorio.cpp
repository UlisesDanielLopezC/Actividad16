#include "laboratorio.h"
#include<fstream>
#include<algorithm>

Laboratorio::Laboratorio(){
    
}

void Laboratorio::agregarComputadora(const Computadora &c){
    computadoras.push_back(c);
}

void Laboratorio::mostrar(){

    cout << left;
    cout << setw(13) << "Sistema Op.";
    cout << setw(16) << "Procesador";
    cout << setw(12) << "RAM (GB)";
    cout << setw(8) << "Espacio";
    cout << endl;

    for(size_t i = 0; i<computadoras.size(); i++){

        Computadora &c = computadoras[i];
        cout << c;
        //cout<<"Sistema Operativo: "<< arreglo[i].getSistema() <<endl;
        //cout<<"Procesador: "<< arreglo[i].getProcesador() <<endl;
        //cout<<"Memoria RAM: "<< arreglo[i].getRAM() <<endl;
        //cout<<"Almacenamiento: "<< arreglo[i].getEspacio() <<endl<<endl;
    }
    cout<<endl;
}

void Laboratorio::respaldar_tabla(){

    ofstream archivo("computadoras_tabla.txt");
    if(archivo.is_open()){

        archivo << left;
        archivo << setw(13) << "Sistema Op.";
        archivo << setw(16) << "Procesador";
        archivo << setw(12) << "RAM (GB)";
        archivo << setw(8) << "Espacio";
        archivo << endl;

        for(size_t i = 0; i<computadoras.size(); i++){
            Computadora &c = computadoras[i];
            archivo << c;
        }
    }
    archivo.close();
}

void Laboratorio::respaldar(){

    ofstream archivo("computadoras.txt");
    if(archivo.is_open()){

        for(size_t i = 0; i<computadoras.size(); i++){
            Computadora &c = computadoras[i];
            archivo << c.getSistema() << endl;
            archivo << c.getProcesador() << endl;
            archivo << c.getRAM() << endl;
            archivo << c.getEspacio() << endl;
        }
    }
    archivo.close();
}

void Laboratorio::recuperar(){

    ifstream archivo("computadoras.txt");
    if(archivo.is_open()){
        string temp;
        int RAM;
        Computadora c;

        while (true){
            getline(archivo, temp);
            if(archivo.eof()){
                break;
            }
            c.setSistema(temp);

            getline(archivo, temp);
            c.setProcesador(temp);

            getline(archivo, temp);
            RAM = stoi(temp);
            c.setRAM(RAM);

            getline(archivo, temp);
            c.setEspacio(temp);

            agregarComputadora(c);
        }
        
    }
    archivo.close();
}

void Laboratorio::insertar(const Computadora &c, size_t ps){
    computadoras.insert(computadoras.begin()+ps, c);
}

size_t Laboratorio::size(){
    return computadoras.size();
}

void Laboratorio::inicializar(const Computadora &c, size_t n){
    computadoras = vector<Computadora>(n, c);
}

void Laboratorio::eliminar(size_t ps){
    computadoras.erase(computadoras.begin()+ps);
}

void Laboratorio::ordenar(){
    sort(computadoras.begin(), computadoras.end());
}

Computadora* Laboratorio::buscar(const Computadora &c){
    //vector<Computadora>::iterator
    auto it = find(computadoras.begin(), computadoras.end(), c);

    if(it == computadoras.end()){
        return nullptr;
    }else{
        return &(*it);
    }
}

void Laboratorio::borrarultimo(){
    if(computadoras.empty()){
        cout <<"El vector esta vacio"<<endl;
    }else{
        computadoras.pop_back();
    }
    cout <<endl;
}