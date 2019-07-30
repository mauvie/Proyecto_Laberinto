#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#include "minunit.h"
#include "../Laberinto/funciones.h" //Aqui va el nombre de su tarea y el .h de la funcioneuauus

MU_TEST(test_funcion_puntuacion)
{
    mu_check(a_puntuacion(2, "Historial.txt")== 1);
}

MU_TEST(test_funcion_puntuacion_2)
{
    mu_check(a_puntuacion(2, "manzana")== 1);
}

MU_TEST(test_funcion_puntuacion_3)
{
    mu_check(a_puntuacion(2, "hola.txt")== 1);
}

MU_TEST(test_funcion_puntuacion_4)
{
    mu_check(a_puntuacion(2, "maria.txt")== 1);
}

MU_TEST(test_funcion_puntuacion_5)
{
    mu_check(a_puntuacion(2, "https://wwda65415d8a")== -1);
}

MU_TEST(test_funcion_puntuacion_6)
{
    mu_check(a_puntuacion(2, "https://harefnnh")== -1);
}

MU_TEST(test_funcion_puntuacion_7)
{
    mu_check(a_puntuacion(2, "https://wwwmaria")== -1);
}

MU_TEST(test_funcion_puntuacion_8)
{
    mu_check(a_puntuacion(2, "https://juanaquefuncione")== -1);
}

MU_TEST(test_funcion_puntuacion_9)
{
    mu_check(a_puntuacion(2, "Marta.txt")== 1);
}

MU_TEST(test_funcion_puntuacion_10)
{
    mu_check(a_puntuacion(2, "Juana.txt")== 1);
}


MU_TEST_SUITE(test_suite)
{
    MU_RUN_TEST(test_funcion_puntuacion);
    MU_RUN_TEST(test_funcion_puntuacion_2);
    MU_RUN_TEST(test_funcion_puntuacion_3);
    MU_RUN_TEST(test_funcion_puntuacion_4);
    MU_RUN_TEST(test_funcion_puntuacion_5);
    MU_RUN_TEST(test_funcion_puntuacion_6);
    MU_RUN_TEST(test_funcion_puntuacion_7);
    MU_RUN_TEST(test_funcion_puntuacion_8);
    MU_RUN_TEST(test_funcion_puntuacion_9);
    MU_RUN_TEST(test_funcion_puntuacion_10);
}

int main()
{
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return 0;
}

