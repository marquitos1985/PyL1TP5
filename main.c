#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define ESC 27
#define MAX_ALUMNOS 20

int cargarAlumno(int maximo, int legajos[], char nombres[][30], int anios[]);
void mostrarAlumnos(int validos, int legajos[], char nombres[][30], int anios[]);
int buscarLegajo(int validos, int legajos[], int dato) ;
void buscarNombreLegajo(int v, int legajos[], char alumnos[][30], int anios, int dato);
int menorDelArregloString(int v, char nombres[][30], int comienzo);
void ordenarPorNombreSeleccion(int v, int legajos[], char nombres[][30], int anios);



int main() {

    int legajos [MAX_ALUMNOS];
    char nombres[MAX_ALUMNOS][30];
    int anios[MAX_ALUMNOS];
    int alumCargados = 0;

    opcionesMenu(MAX_ALUMNOS, &alumCargados, legajos, nombres, anios);
    return 0;
}

void muestraMenu() {
    printf("\n=========== MENU PRINCIPAL ===========");
    printf("\n1 - Cargar datos alumnos.");
    printf("\n2 - Mostra datos alumnos.");
    printf("\n3 - Buscar legajo.");
    printf("\n4 - Encontrar alumno a partir de un legajo.");
    printf("\n5 - Ordenar la lista por nombre (seleccion).");

}

void opcionesMenu(int maximoAlumnos, int *alumCargados, int legajos[], char nombres[][30], int anios[]) {

    int opcion;
    int dato;

    do {
        system("cls");

        muestraMenu();

        printf("\nIngrese una opcion (si desea salir ESC): ");
        fflush(stdin);
        opcion = getch();

        switch(opcion) {
        case 49:
            *alumCargados = cargarAlumno(maximoAlumnos, legajos, nombres, anios);
            printf("\nAlumnos cargados: %d ", *alumCargados);
            printf("\n");
            system("pause");
            break;
        case 50:
            if(*alumCargados != 0) {
                mostrarAlumnos(*alumCargados, legajos, nombres, anios);
            } else {
                printf("\nNo hay alumnos cargados...");
            }
            printf("\n");
            system("pause");
            break;
        case 51:
            if(*alumCargados != 0) {
                printf("\nIngrese el legajo a buscar en la lista de alumnos: ");
                fflush(stdin);
                scanf("%d", &dato);
                if(buscarLegajo(*alumCargados, legajos, dato) != -1) {
                    printf("\nEl legajo %d esta en la posicion %d.", dato, buscarLegajo(*alumCargados, legajos, dato));
                } else {
                    printf("\nEl legajo no existe en la lista de alumnos.");
                }
            } else {
                printf("\nNo hay alumnos cargados...");
            }
            printf("\n");
            system("pause");
            break;
        case 52:
            if(*alumCargados != 0) {
                printf("\nIngrese el legajo a buscar en la lista de alumnos: ");
                fflush(stdin);
                scanf("%d", &dato);
                if(buscarLegajo(*alumCargados, legajos, dato) != -1) {
                    buscarNombreLegajo(*alumCargados, legajos, nombres, anios, dato);
                } else {
                    printf("\nEl legajo no existe en la lista de alumnos.");
                }

            } else {
                printf("\nNo hay alumnos cargados...");
            }
            printf("\n");
            system("pause");
            break;
        case 53:
            if(*alumCargados != 0) {
                ordenarPorNombreSeleccion(*alumCargados, legajos, nombres, anios);
            } else {
                printf("\nNo hay alumnos cargados...");
            }
            printf("\n");
            system("pause");
            break;
        case 27:
            printf("\nHasta luego...");
            break;
        default:
            printf("\La opcion ingresada es incorrecta...");
            printf("\n");
            system("pause");
        }
    } while(opcion != ESC);

}

//1. Crear una funci�n que los cargue, hasta que el usuario lo decida.
int cargarAlumno(int maximo, int legajos[], char nombres[][30], int anios[]) { //devuelve la cantidad de alumnos cargada

    int i = 0;
    int opcion;

    do {
        if(i < maximo) {
            printf("\nIngrese el numero legajo del alumno (max 20 digitos): ");
            fflush(stdin);
            scanf("%d", &legajos[i]);

            printf("\nIngrese el nombre del alumno(max 29 caracteres): ");
            fflush(stdin);
            gets(nombres[i]);

            printf("\nIngrese la edad del alumno(max 20 digitos): ");
            fflush(stdin);
            scanf("%d", &anios[i]);

            i++;
        } else {
            printf("\nHa alcanzado la cantidad maxima de alumnos que puede cargar...");
        }

        printf("\nSi desea cargar otro alumno ENTER, para terminar ESC...");
        fflush(stdin);
        opcion = getch();

    } while(opcion != ESC);

    return i;
}

void mostrarAlumnos(int validos, int legajos[], char nombres[][30], int anios[]) {

    char encabezado[][7] = {"Legajo","Alumno","Anios"};

    printf("\n%10s | %19s | %10s |", encabezado[0], encabezado[1], encabezado[2]);

    for(int i = 0; i < validos; i++) {
        printf("\n%10d |%20s |%10d |", legajos[i], nombres[i], anios[i]);
    }

}

//2. Crear una funci�n que busque dentro del arreglo de legajos y retorne la posici�n de un determinado valor.
int buscarLegajo(int validos, int legajos[], int dato) {

    int i = 0;
    int posicion = -1;
    while(i < validos && posicion == -1) {
        if(legajos[i] == dato) {
            posicion = i;
        }
        i++;
    }
    return posicion;
}

//3. Hacer una funci�n que reciba como par�metro todos los arreglos y encuentre el nombre
//correspondiente a un determinado legajo y lo imprima por pantalla. Se debe invocar la funci�n 2.
void buscarNombreLegajo(int v, int legajos[], char nombres[][30], int anios, int dato) {
    printf("\nPosicion legajo %d", buscarLegajo(v, legajos, dato));
    printf("\nnombre: %s", nombres[buscarLegajo(v, legajos, dato)]);
    printf("\nEl legajo %d es del alumno %s.", dato, nombres[buscarLegajo(v, legajos, dato)]);
}

//4. Hacer una funci�n que reciba como par�metro todos los arreglos y los ordene por nombre.
//(por el m�todo de selecci�n o inserci�n).

int menorDelArregloString(int v, char nombres[][30], int comienzo){

    int i = comienzo;
    int posMenor = i;
    i++;

    while(i < v){
        if(strcmpi(nombres[i], nombres[posMenor]) < 0){
            posMenor = i;
        }
        i++;
    }
    return posMenor;
}
void ordenarPorNombreSeleccion(int v, int legajos[], char nombres[][30], int anios){

    char aux[30];
    int posMenor;
    int i = 0;

    while(i < (v - 1)){
       posMenor = menorDelArregloString(v, nombres, i);
       strcpy(aux ,nombres[posMenor]);
       strcpy(nombres[posMenor],nombres[i]);
       strcpy(nombres[i],aux);
       i++;
    }
}
/*
void insertarOrdenado(int v, char nombres[][30], char elemento[]){

    int i = v;

    while(i >= 0 && strcmp(nombres[i],elemento) > 0){
        strcpy(nombres[i+1], nombres[i]);
        i--;
    }
    strcpy(nombres[i+1], elemento);
}
*/
//5. Mostrar por pantalla los 3 arreglos pero de a un �registro� o alumno por vez (es decir: muestra
//el legajo, nombre y a�os del 1er alumno, luego el legajo, nombre y a�os del 2do alumno, y as� sucesivamente)..
//es la funcion mostrar alumnos
