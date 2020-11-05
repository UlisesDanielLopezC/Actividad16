#ifndef LABORATORIO_H
#define LABORATORIO_H

#include "computadora.h"
#include <vector>

class Laboratorio{
    vector<Computadora> computadoras;
    
public:
    Laboratorio();
    void agregarComputadora(const Computadora &c);
    void mostrar();
    void respaldar_tabla();
    void respaldar();
    void recuperar();

    void insertar(const Computadora &c, size_t ps);
    size_t size();
    void inicializar(const Computadora &c, size_t n);
    void eliminar(size_t ps);
    void ordenar();
    Computadora* buscar(const Computadora &c);
    void borrarultimo();

    friend Laboratorio& operator<<(Laboratorio &l, const Computadora &c){

        l.agregarComputadora(c);

        return l;
    }

};

#endif