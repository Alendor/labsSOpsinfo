#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estructuras que representarán a los procesos.
struct Tamano{
  char total[20];
  char text[20];
  char data[20];
  char stack[20];
};

typedef struct Tamano Tamano;

struct Proceso{
  char id[10];
  char nombre[20];
  char estado[25];
  Tamano tam;
  char cambiosv[20];
  char cambiosi[20];
};

typedef struct Proceso Proceso;

FILE *fp;
char ruta[80];

//Definición de las funciones a utilizar.
void procesarProceso(char *, int);
void imprimirProceso(Proceso);
void guardarProceso(Proceso);

int main(int argc, char *argv[]){
  int bandera = 0;

  if(argc == 1){
    printf("No se ingresó ningún parámetro.\n");
  } else if(strncmp( argv[1], "-l", 3) == 0 || strncmp( argv[1], "-r", 3) == 0){
    printf("no y qué");
    if(strncmp( argv[1], "-r", 3) == 0){
      bandera = 1;
    } 
    for(int index = 2; index < argc; ++index){
       procesarProceso(argv[index], bandera);
    }
  } else{
    procesarProceso(argv[1], bandera);
  }
  return 0;
}
/*
Este método traerá las características del proceso con id ingresado por parámetro.
Además dependiendo de la bandera imprimirá o escribirá en un archivo dichas características:
0 para imprimir en pantalla, cualquier otro valor para escribir en un archivo.
*/
void procesarProceso(char *id, int bandera){
  Proceso proc;
  char aux[200];
  //strcpy(ruta,"ejem.txt"); PRUEBA PORQUE NO TENGO LINUX
  strcpy(ruta, "/proc/");
  strcat(ruta, id );
  strcat(ruta, "/status" );
  fp = fopen(ruta, "r");
  if (fp == NULL){
    printf("Can not open %s\n", ruta);
    exit(1);
  }
  printf("Archivo abierto\n");
  strcpy(proc.id, id);
  for (int i = 0; i < 54; i++){
    if (i == 0){
      fgets(aux, 200, fp);
      strcpy(proc.nombre, aux);
    }
    else if (i == 2){
      fgets(aux, 200, fp);
      strcpy(proc.estado, aux);
    }
    else if (i == 16){
      fgets(aux, 200, fp);
      strcpy(proc.tam.total, aux);
    }
    else if (i == 27){
      fgets(aux, 200, fp);
      strcpy(proc.tam.text, aux);
    }
    else if (i == 25){
      fgets(aux, 200, fp);
      strcpy(proc.tam.data, aux);
    }
    else if (i == 26){
      fgets(aux, 200, fp);
      strcpy(proc.tam.stack, aux);
    }
    else if (i == 52){
      fgets(aux, 200, fp);
      strcpy(proc.cambiosv, aux);
    }
    else if (i == 53){
      fgets(aux, 200, fp);
      strcpy(proc.cambiosi, aux);
    }
    else{
      fgets(aux, 200, fp);
    }
  }
  fclose(fp);
  printf("Archivo cerrado\n");
  if(bandera == 0){
    imprimirProceso(proc);
  } else{
    guardarProceso(proc);
  }
  //exit(0);
}

void imprimirProceso(Proceso p){
  printf("Pid: %s\nEl nombre del proceso es: %s\nEl estado del proceso es: %s\nEl tamano Maximo del proceso es: %s\nTamano de la memoria en la región TEXT es: %s\nTamano de la memoria en la región DATA es: %s\nTamano de la memoria en la región STACK es: %s\nNumero de cambios de contexto realizados(voluntarios - no voluntarios): %s - %s\n", 
          p.id, p.nombre, p.estado, p.tam.total, p.tam.text, p.tam.data, p.tam.stack, p.cambiosv, p.cambiosi);
}

void guardarProceso(Proceso p){
  fp = fopen("psinfo-report-XXXXX.info", "w");
  if (fp == NULL){
    printf("No se pudo crear el archivo");
    exit(1);
  }
  fprintf(fp, "Pid: %s\nEl nombre del proceso es: %s\nEl estado del proceso es: %s\nEl tamano Maximo del proceso es: %s\nTamano de la memoria en la región TEXT es: %s\nTamano de la memoria en la región DATA es: %s\nTamano de la memoria en la región STACK es: %s\nNumero de cambios de contexto realizados(voluntarios - no voluntarios): %s - %s\n", 
          p.id, p.nombre, p.estado, p.tam.total, p.tam.text, p.tam.data, p.tam.stack, p.cambiosv, p.cambiosi);
  fclose(fp);
}