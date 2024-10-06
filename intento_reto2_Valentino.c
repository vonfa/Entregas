#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>



float celsiusToFahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}
void *AtenderCliente(void *arg) {
    int sock = *(int*)arg;
    char buffer[1024] = {0};
    
    while(1) {
        // Leer los datos del cliente
        if (read(sock, buffer, 1024) <= 0) {
            
            break;
        }
        
        // Procesar los datos
        float temp;
        char unit;
        sscanf(buffer, "%f%c", &temp, &unit);
        
        // Realizar la conversión
        float result;
        if (unit == 'C') {
            result = celsiusToFahrenheit(temp);
            sprintf(buffer, "%.2fF", result);
        } else if (unit == 'F') {
            result = fahrenheitToCelsius(temp);
            sprintf(buffer, "%.2fC", result);
        } else {
            sprintf(buffer, "Unidad inválida");
        }
        
        // Enviar el resultado al cliente
        send(sock, buffer, strlen(buffer), 0);
    }
    
    close(sock);
    pthread_exit(NULL);
}

int main() {
   int sock_conn, sock_listen, ret; 
 struct sockaddr_in serv_adr; 
 int sockets[100]; 
 int i; 
 miLista.num=0; 
  
  
 // INICIALITZACIONS 
 // Obrim el socket 
 if ((sock_listen = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
  printf("Error creant socket"); 
 // Fem el bind al port 
  
  
 memset(&serv_adr, 0, sizeof(serv_adr));// inicialitza a zero serv_addr 
 serv_adr.sin_family = AF_INET; 
  
 // asocia el socket a cualquiera de las IP de la m?quina.  
 //htonl formatea el numero que recibe al formato necesario 
 serv_adr.sin_addr.s_addr = htonl(INADDR_ANY); 
 // escucharemos en el port 9050 
 serv_adr.sin_port = htons(9002); 
 if (bind(sock_listen, (struct sockaddr *) &serv_adr, sizeof(serv_adr)) < 0) 
  printf ("Error al bind"); 
 //La cola de peticiones pendientes no podr? ser superior a 4 
 if (listen(sock_listen, 2) < 0) 
  printf("Error en el Listen"); 
  
 pthread_t thread[10]; 
  
 i=0; 
 for (;;){ 
  printf ("Escuchando\n"); 
   
  sock_conn = accept(sock_listen, NULL, NULL); 
  printf ("He recibido conexi?n\n"); 
  //sock_conn es el socket que usaremos para este cliente 
   
  sockets[i]=sock_conn; 
  pthread_create( &thread[i], 
        NULL, 
        AtenderCliente, 
        &sockets[i]); 
  i=i+1; 
 } 
    }
    return 0;
}