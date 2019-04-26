//
// Created by nutax on 25/04/19.
//

#ifndef UNTITLED_CARGA_H
#define UNTITLED_CARGA_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Carga {
float x;
float y;
float q;
float v;

public:
    Carga(float _x, float _y, float _q, float _x1, float _y1);
    float get_x(){return x;}
    float get_y(){return y;}
    float get_q(){return q;}
    float get_v(){return v;}
    friend class Simulador;

};

class Simulador {
    float h;
    float w;
    float n;
    float m;
    float x1;
    float y1;
    float vtotal;
    vector <Carga> cargas;
public:
    Simulador(float _h, float _w, float _n, float _m, float _x1, float _y1, float _q);
    void Imprimir();
    vector<Carga> get_cargas(){return cargas;}
    string ImprimirElemento(int e);

};
#include "Carga.cpp"


#endif //UNTITLED_CARGA_H
