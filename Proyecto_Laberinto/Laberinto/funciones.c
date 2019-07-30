#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>

#define Arriba 72
#define Abajo 80
#define Izquierda 75
#define Derecha 77

void gotoxy(int x,int y)   /* Mueve el cursor del texto a la posicion segun las coordenadas especificadas por los argumentos x y y */
{
    HANDLE hcon; //identificador de un objeto o recurso
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  //aqui se aquiere el control de la consola activa
    COORD dwPos; //es una estructura definida en Windows.h, dwPos es el nombre de la estructura
    dwPos.X = x; //X y Y son los atributos de la estructura
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos); //posiciona el curso en algun lugar de la consola
}

void Ocultar_Cursor()
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  //La función GetStdHandle devuelve un manipulador para el dispositivo estándar de entrada, salida o error.
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 2;   //Tamano del cursor
    cci.bVisible = FALSE;  //no me permite que se vea
    SetConsoleCursorInfo(hcon, &cci);
}

void menu()
{

    int opcion, a;
    system("color f0");

    printf("\tJuego de Laberinto.\n");
    printf("\n");
    printf("Menu del laberinto\n\n");
    printf("Seleccione la opcion a desear\n\n ");
    printf("1) Nivel\n");
    printf(" 2) Historial\n");
    printf(" 3) Salir\n");
    printf("\n");
    printf("Opcion: ");
    scanf("%d", &opcion);
    system("cls");

    switch (opcion)
    {

    case 1:
        menu_niveles();
        break;

    case 2:
        mostrar_hist();
        break;

    case 3:
        printf("Seguro que desea salir? Si o No\n");
        printf("\n");
        printf("1- Si\n");
        printf("2- No\n");
        printf("\n");
        printf("Opcion: ");
        scanf("%i", &a);
        printf("\n");
        if (a==1)
        {
            printf("Has salido correctamente\n");
        }
        else
        {
            return menu();

        }
        break;

    default:
        printf("\n");
        printf("Has seleccionado una opcion incorrecta. Vuelva a intentarlo");
        printf("\n");
    }
}

void menu_niveles()
{

    int opcion;
    char * nivel;
    system("color f0");

    printf("Seleccione el nivel\n\n ");
    printf("1) Nivel 1\n");
    printf(" 2) Nivel 2\n");
    printf(" 3) Nivel 3\n");
    printf(" 4) Nivel 4\n");
    printf(" 5) Nivel 5\n");
    printf("\n");
    printf("Opcion: ");
    scanf("%d", &opcion);
    system("cls");

    switch (opcion)
    {

    case 1:
        nivel = "Nivel1.txt";
        break;

    case 2:
        nivel = "Nivel2.txt";
        break;

    case 3:
        nivel = "Nivel3.txt";
        break;
    case 4:
        nivel = "Nivel4.txt";
        break;
    case 5:
        nivel = "Nivel5.txt";
        break;
    default:
        printf("\n");
        printf("Has seleccionado una opcion incorrecta. Vuelva a intentarlo");
        printf("\n");
    }

    juego(nivel);
    char *l;
    l=(char*)malloc(14*sizeof(char));
    l="Historial.txt";
    if(a_puntuacion(guardarSeg,l)== 1)
    {
        printf("\n\n");
        printf("El archivo se ha guardado correctamente");
        printf("\n\n");
        system("pause");
        system("cls");
        menu();
    }
    else
    {
        printf("\n\n");
        printf("El archivo no se ha guardado correctamente");
        printf("\n\n");
        system("pause");
        system("cls");
        menu();
    }

}
void llenar(char tt[100][100], char nivel[100])
{
    FILE *arc;
    arc = fopen(nivel,"r");
    char s;
    int f=0;
    int c=0;

    while (s!=-1)
    {
        s=getc(arc);

        if(s!='\n')
        {
            tt[f][c] = s;
            f+=1;
        }
        else
        {
            c+=1;
            f=0;
        }
    }
}

void generar(char nivel[100])
{

    char s[100][100];
    llenar(s,nivel);

    for(int f=0; f<10; f++)
    {
        for(int c=0; c<37; c++)
        {
            if(s[c][f]=='#')
            {
                printf("\xDB");
            }
            else if(s[c][f]=='*')
            {
                printf(" ");
            }
            else if(s[c][f]=='I')
            {
                printf("I");
            }
            else if(s[c][f]=='F')
            {
                printf("F");
            }
        }
        printf("\n");
    }
}

void juego(char n[100])
{
    char tablero[100][100];
    llenar(tablero,n);

    Ocultar_Cursor();
    generar(n);

    int x = 0, y = 5;
    int seg=0;

    gotoxy(x,y);
    system("color f0"); //color blanco
    printf("%c", 227); //objeto usado

    bool game_over = false; //solo devuelve true o false
    while(!game_over)
    {
        if(kbhit())
        {

            char tecla = getch();
            gotoxy(x,y);
            printf(".");
            if(tablero[x+1][y]!='#')
            {
                if (tecla == Derecha)
                    x++;
            }

            if(tablero[x-1][y]!='#')
            {
                if (tecla == Izquierda)
                    x--;
            }

            if(tablero[x][y+1]!='#')
            {
                if (tecla == Abajo)
                    y++;
            }

            if(tablero[x][y-1]!='#')
            {
                if (tecla == Arriba)
                    y--;
            }
            if(tablero[x][y]=='F')
            {
                game_over=TRUE;
                guardarSeg = seg;
                gotoxy(36,9);
                printf("\nHas logrado llegar a la meta");

            }
            gotoxy(x,y);
            printf("%c", 227);

        }
        Sleep(10);

        seg += 10;
        if(seg % 1000 == 0)
        {
            gotoxy(1,12);
            printf("Tiempo: %d",seg/1000);
        }
    }
}

int a_puntuacion(int t, char *nombre)
{

    FILE *punt;
    jugador jug;
    getchar();
    punt = fopen(nombre,"a+");
    if(punt==NULL)
    {
        return -1;
    }else{
    gotoxy(1,13);

    printf("Ingrese su nombre:  ");
    jug.nombre= leer();
    fprintf(punt,"%s  \t %d\n", jug.nombre,t);
    fclose(punt);
    return 1;
    }
}


void mostrar_hist()
{
    FILE *hist;
    hist = fopen("Historial.txt", "r");
    char a[50];

    if (a!=-1)
    {
        printf("\nNombre\t\tTiempo\n");
        while(fgets(a, 50,hist))
        {
            printf("%s", a);
        }

    }

    fclose(hist);
}
char * leer()
{

    char c, *puntero;
    int i=0;

    puntero = (char *) malloc(1 * sizeof(char));
    *puntero = '\0';

    while ((c=getchar())!='\n')
    {
        puntero = (char *) realloc(puntero, (i + 2) * sizeof(char));
        puntero[i++] = c;
        puntero[i] = '\0';
    }
    return puntero;
}



