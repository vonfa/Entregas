//ejercicio reto 1 guia del video L1.13 https://www.youtube.com/watch?v=GzZHz5VUDEE&list=PL64O0POFYjHoW3-FDElau5TfKyoRO13Jf&index=13
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // necesario para atof
#include <ctype.h>

int Palindromo(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0; // No es palíndromo
        }
    }
    return 1; // Es palíndromo
}
void toMayus(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}
int main(int argc, char *argv[]) {

    char peticion[100];
    char resultado[100];
	char name[100];

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
	
	printf("Ingrese su nombre: ");
    scanf("%s", name);

    if (Palindromo(name)) {
        printf("%s es un palíndromo.\n", name);
    } else {
        printf("%s no es un palíndromo.\n", name);
    }

    toMayus(name);
    printf("En mayúsculas: %s\n", name);
	
 
}
