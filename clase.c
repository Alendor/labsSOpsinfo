#include <stdio.h>
#include <stdlib.h>

char ruta[80];

 char respuesta[51];
  char ID[10];
  char name[200];
  float grade;
  FILE *fp;

struct estudiante {
  char ID[9];
  char nombre[41];
  float nota; 
};

typedef struct estudiante student;
int traerinfo (char *);
int traerlista (char *);

int main(int argc, char *argv[]) {
  // 1. Open
  for(int index = 1; index < argc; ++index){
    if (strncmp( argv[index], "-l", 3) == 0){
      traerlista(argv[index]);
    }else{
      traerinfo (argv[index]);
    }
  }
  // 2. Process
  //  while(fscanf(fp,"%[^;];%[^;];%f",ID,name,&grade)!=EOF) {
   //   printf("%s -  %s - %f",ID,name,grade);
   // } 
  //fscanf(fp,"%s %s",name, respuesta);
  
  // while(fscanf(fp,"%s %s",name, respuesta)!=EOF) {
      //if(name.equals('Name:')){
       
//printf("%s",name);
        // printf("%d",i);
       // }
       
      
       //}
    //} 
  // fscanf(fp,"%[^;];%[^;];%f",ID,name,&grade);
  // printf("%s -  %s - %f",ID,name,grade);
  // fseek ( fp , 6, SEEK_SET );
  // fscanf(fp,"El nombre de %s",name);
  // printf("%s",name);
  //fscanf(fp,"%[^;];%[^;];%f",ID,name,&grade);
  //printf("%s -  %s - %f",ID,name,grade);
  
  // 3. Close
 
}

int traerinfo (char *entrada){
  char nombre[20];
  char estado[25];
  char size[20];
  char tamtext[20];
  char tamdata[20];
  char tanstack[20];
  char cambiovolun[20];
  char cambionovolun[20]; 
  strcpy(ruta, "/proc/");
  strcat(ruta, entrada );
  strcat(ruta, "/status" );
  //printf("open %s\n", ruta);
  //char filename[80] = "ejem.txt";
  

  fp = fopen(ruta,"r");
  if(fp == NULL) {
    printf("Can not open %s\n", ruta);
    exit(1);
  }

  printf("Archivo abierto\n");
  
  for(int i=0;i<54;i++){ 
        //fscanf(fp,"%s %s",name, respuesta);
         
         //strcmp(cadena1, cadena2)
       
        //if(i==40){
        if (i==0){
          fgets(name,200,fp);
          //nombre = name;
          strcpy(nombre, name); 

        }else if(i==2){
          fgets(name,200,fp);
           strcpy(estado, name); 

        }else if(i==16){
          fgets(name,200,fp);
           strcpy(size, name); 
          
        }
        else if(i==27){
          fgets(name,200,fp);
           strcpy(tamtext, name); 
          
        }
        else if(i==25){
          fgets(name,200,fp);
           strcpy(tamdata, name); 
          

        }else if(i==26){
          fgets(name,200,fp);
           strcpy(tanstack, name); 
          

        }else if(i==52){
          fgets(name,200,fp);
           strcpy(cambiovolun, name); 
          

        }else if(i==53){
          fgets(name,200,fp);
           strcpy(cambionovolun, name);

        }else{
          fgets(name,200,fp);
        }
       }
        printf("El nombre del proceso es: %s", nombre);
        printf("El estado del proceso es: %s", estado);
        printf("El tamaño Maximo del proceso es: %s", size);
        printf("Tamaño de la memoria en la región TEXT es: %s", tamtext);
        printf("Tamaño de la memoria en la región DATA es: %s", tamdata);
        printf("Tamaño de la memoria en la región STACK: es: %s", tanstack);
        printf("Numero de cambios de contexto realizados(voluntarios-no voluntarios): %s - %s", cambiovolun, cambionovolun);



        fclose(fp);
  printf("\nArchivo cerrado\n");
  exit(0);
}

int traerinfo (char *entrada){

  
}

/**

int main() {
  // Open
  char filename[80] = "notas.txt";
  char linea[51];
  char id[20];
  char nom[45]; 
  float not;

  FILE *fp;
  fp = fopen(filename,"r");
  if(fp == NULL) {
    printf("Can not open %s\n", filename);
    exit(1);
  }
  printf("Archivo abierto\n");
  // Process  
  //https://www.daniweb.com/programming/software-development/threads/334515/reading-comma-separated-values-with-fscanf
  


  while(fscanf(fp, "%s%*c%s%*c%f",id,nom,&not)!=EOF) {
    //printf("%s\n",linea);
    printf("**********%s - %s - %f",id,nom,not);
    printf("\n");
  } 
  
  // Close  
  fclose(fp);
  printf("Archivo cerrado\n");
  exit(0);
}

*/