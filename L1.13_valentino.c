//ejercicio guia del video L1.13 https://www.youtube.com/watch?v=GzZHz5VUDEE&list=PL64O0POFYjHoW3-FDElau5TfKyoRO13Jf&index=13
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // necesario para atof

int main(int argc, char *argv[]) {

    char peticion[100];
    char resultado[100];

    strcpy(peticion, "Miguel/47/Juan/12/Maria/22/Marcos/19");
    // Resultado deseado: "Miguel 47-Maria 22-Marcos*19"

    char nombre[20];
    int edad;

    char *p = strtok(peticion, "/");

    while (p != NULL) {
        strcpy(nombre, p);
        p = strtok(NULL, "/"); // Avanzamos al siguiente token

        edad = atoi(p);
        if (edad > 18) {
            sprintf(resultado, "%s%s*%d-", resultado, nombre, edad);
        }

        p = strtok(NULL, "/"); // Avanzamos al siguiente token
    }
	repuesta [strlen (respuesta) - 1] = '/0';
    printf ("Resultado: %s/n" , resultado);
 
}
