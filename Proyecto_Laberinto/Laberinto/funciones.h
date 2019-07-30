#ifndef funciones_h
typedef struct
{
    char *nombre;
    int tiempo;
} jugador;

int guardarSeg; //variable global

void menu();
void juego(char n[100]);
int a_puntuacion(int t, char *nombre);
void mostrar_hist();
void Ocultar_Cursor();
void gotoxy(int x,int y);
void llenar(char tt[100][100], char nivel[100]);
void generar(char nivel[100]);
void menu_niveles();
char * leer();
#endif // funciones_h
