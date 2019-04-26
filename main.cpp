#include <iostream>
#include "Carga.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <vector>
#include <string>
using namespace std;
TEST_CASE("Creaciòn de Carga", "[carga]"){
    //prueba(x,y,q,x1,y1)
    Carga prueba(10.0,5.0,2.0,10.0,20.0);

SECTION("Atributos"){
REQUIRE(prueba.get_x()==10.0);
REQUIRE(prueba.get_y()==5.0);
REQUIRE(prueba.get_q()==2.0);
};

SECTION("Potencia"){
CHECK(prueba.get_v()==Approx(1198666666.67));
}

}

TEST_CASE("Creaciòn de Simulador", "[simulador]"){
//prueba_simulador(h,w,n,m,x1,y1,q)
    Simulador prueba_simulador(10.0,5.0,2.0,3.0,10.0,20.0,2.0);
    SECTION("Vector de cargas"){
        vector<Carga> prueba_vector = prueba_simulador.get_cargas();
        int prueba_tamano = 3*2;
        CHECK(prueba_vector.size()==prueba_tamano);
    }
    SECTION("Imprimir elemento: comas, espaciado y fin de lìnea"){
        string prueba_linea = prueba_simulador.ImprimirElemento(0);
        int prueba_ncomas = 0;
        int prueba_nespacios = 0;
        bool prueba_findelinea = false;
        for (int i = 0; i<prueba_linea.length(); i++){
            if (prueba_linea[i]==','){
                prueba_ncomas++;
            }
            if (prueba_linea[i]==' '){
            prueba_nespacios++;
            }
            if (prueba_linea[i]=='\n'){
            prueba_findelinea = true;
            }
        }
        CHECK(prueba_nespacios == 2);
        CHECK(prueba_ncomas == 2);
        CHECK(prueba_findelinea == true);
    }
}