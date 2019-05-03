#include <iostream>
#include "Carga.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <vector>
#include <string>
using namespace std;
SCENARIO("Creaciòn de Carga", "[carga]"){
    GIVEN("Una Carga llamada prueba"){
        WHEN("Se crea con 5 parametros: prueba(x,y,q,x1,y1)"){
            Carga prueba(10.0,5.0,2.0,10.0,20.0);
            THEN("Se establecen 3 atributos de manera directa"){
                REQUIRE(prueba.get_x()==10.0);
                REQUIRE(prueba.get_y()==5.0);
                REQUIRE(prueba.get_q()==2.0);
            }
            THEN("Se calcula y se establece el atributo Potencia"){
                REQUIRE(prueba.get_v()==Approx(1198666666.67));
            }
        }
    }
    }

SCENARIO("Creaciòn de Simulador", "[simulador]"){
//
    GIVEN("Un Simulador llamado prueba_simulador"){
Simulador prueba_simulador(10.0,5.0,2.0,3.0,10.0,20.0,2.0);
    WHEN("Se crea con 7 parametros: prueba_simulador(h,w,n,m,x1,y1,q)"){
        THEN("Se crea vector de largo n*m"){
            vector<Carga> prueba_vector = prueba_simulador.get_cargas();
            int prueba_tamano = 3*2;
            REQUIRE(prueba_vector.size()==prueba_tamano);
        }
    }
    WHEN("Se imprime el vector"){
        THEN("Se imprime cada elemento"){
            THEN("Cada linea de impresiòn contiene 2 comas, 2 espacios y 1 fin de lìnea"){
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
                REQUIRE(prueba_nespacios == 2);
                REQUIRE(prueba_ncomas == 2);
                REQUIRE(prueba_findelinea == true);
            }
        }
    }
    }
    }