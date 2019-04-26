//
// Created by nutax on 25/04/19.
//

#include "Carga.h"
#include <iostream>
#include <vector>
#include <math.h>
#include <string>

using namespace std;

Carga::Carga(float _x, float _y, float _q, float _x1, float _y1 ): x{_x}, y{_y}, q{_q} {
v = 8.99*1000000000*q/(pow(pow(_x1-x,2.0)+pow(_y1-y,2.0), 1.0/2.0));

} //Fin del constructor de Carga

Simulador::Simulador(float _h, float _w, float _n, float _m, float _x1, float _y1, float _q):
h{_h}, w{_w}, n{_n}, m{_m}, x1{_x1}, y1{_y1} {
    vtotal = 0;
for (float i = h/n; i<=h; i = i + h/n ){
    for (float j = w/m; j<=w; j = j + w/m){
        Carga nueva_carga(i, j, _q, x1, y1 );
        vtotal = vtotal + nueva_carga.v;
        cargas.push_back(nueva_carga);
    }
}//Todas las cargas son guardadas en un vector
}//Fin del constructor de Simulador

void Simulador::Imprimir() {
    for (int i = 0; i<cargas.size(); i++){
        cout<<ImprimirElemento(i);
    }//Se imprime las coordenadas de cada carga y su potencia
}//Fin del mètodo imprimir de Simulador


string Simulador::ImprimirElemento(int e) {
    string resultado = to_string(cargas[e].x);
    resultado = resultado + ", ";
    resultado = resultado + to_string(cargas[e].y);
    resultado = resultado + ", ";
    resultado = resultado + to_string(cargas[e].v);
    resultado = resultado + '\n';
    return resultado;
}