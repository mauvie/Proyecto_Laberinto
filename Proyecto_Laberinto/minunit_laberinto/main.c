#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#include "minunit.h"
#include "../Laberinto/funciones.h" //Aqui va el nombre de su tarea y el .h de la funcioneuauus

MU_TEST(test_funcion_puntuacion){
	mu_check(a_puntuacion(2, "Historial.txt")== 1);
}

MU_TEST(test_funcion_puntuacion_2){
	mu_check(a_puntuacion(2, "manzana")== -1);
}


MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_funcion_puntuacion);
    MU_RUN_TEST(test_funcion_puntuacion_2);

}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return 0;
}
