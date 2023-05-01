#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para representar un directorio
typedef struct{
    char nombre[50];  // Nombre del archivo
    char directorio[50];  // Nombre del directorio donde se encuentra el archivo
    int cantidad_de_archivos;  // Cantidad de archivos en el directorio
} directorio;

// Funcion para crear un archivo en un directorio
void crear_archivo(directorio* dir, char* nombre, char* directorio){
    int i;
    for (i = 0; i < dir->cantidad_de_archivos; i++){
        if (strcmp(dir[i].nombre, nombre) == 0 && strcmp(dir[i].directorio, directorio) == 0){
            return;  // El archivo ya existe en el directorio, no hacer nada
        }
    }
    // El archivo no existe en el directorio, agregarlo al final
    strcpy(dir[i].nombre, nombre);
    strcpy(dir[i].directorio, directorio);
    dir->cantidad_de_archivos++;
}

// Funcion para eliminar un archivo de un directorio
int eliminar_archivo(directorio* dir, char* nombre, char* directorio){
    int i;
    // Buscar el archivo en el directorio
    for (i = 0; i < dir->cantidad_de_archivos; i++){
        if (strcmp(dir[i].nombre, nombre) == 0 && strcmp(dir[i].directorio, directorio) == 0){
            // El archivo fue encontrado en el directorio, eliminarlo
            memmove(&dir[i], &dir[i+1], (dir->cantidad_de_archivos - i - 1) * sizeof(directorio));
            dir->cantidad_de_archivos--;
            return 1;  // El archivo fue eliminado exitosamente
        }
    }
    return 0;  // El archivo no fue encontrado en el directorio
}

// Funcion para buscar un archivo en un directorio
int buscar_archivo(directorio* dir, char* nombre, char* directorio){
    int i;
    // Buscar el archivo en el directorio
    for (i = 0; i < dir->cantidad_de_archivos; i++){
        if (strcmp(dir[i].nombre, nombre) == 0 && strcmp(dir[i].directorio, directorio) == 0){
            return i;  // El archivo fue encontrado en el directorio, devolver su indice
        }
    }
    return -1;  // El archivo no fue encontrado en el directorio
}

// Funcion para imprimir los nombres de todos los archivos en un directorio
void presentar_archivos(directorio* dir){
    int i;
    for (i = 0; i < dir->cantidad_de_archivos; i++){
        printf("%s\t%s\n", dir[i].directorio, dir[i].nombre);
    }
    printf("\n");
}

//PUNTO 2
// Estructura para representar un directorio extendido, que incluye informacion adicional sobre el usuario y el tipo de archivo
typedef struct{
    char nombre[50];  // Nombre del archivo
    char directorio[50];  // Nombre del directorio donde se encuentra el archivo
    char usuario[50];  // Nombre del usuario que creo el archivo
    char tipo[50];  // Tipo de archivo (por ejemplo, "imagen", "documento", etc.)
    int cantidad_de_archivos;  // Cantidad de archivos en el directorio
} directorio_extendido;

// Funcion para crear un archivo en un directorio extendido
void crear_archivo_extendido(directorio_extendido* dir, char* nombre, char* directorio, char* usuario, char* tipo){
    int i;
    // Buscar el archivo en el directorio extendido
    for (i = 0; i < dir->cantidad_de_archivos; i++){
        if (strcmp(dir[i].nombre, nombre) == 0 && strcmp(dir[i].directorio, directorio) == 0 && strcmp(dir[i].usuario, usuario) == 0 && strcmp(dir[i].tipo, tipo) == 0){
            return;  // El archivo ya existe en el directorio, no hacer nada
        }
    }
    // El archivo no existe en el directorio, agregarlo al final
    strcpy(dir[i].nombre, nombre);
    strcpy(dir[i].directorio, directorio);
    strcpy(dir[i].usuario, usuario);
    strcpy(dir[i].tipo, tipo);
    dir->cantidad_de_archivos++;
}

// Funcion para eliminar un archivo de un directorio extendido
int eliminar_archivo_extendido(directorio_extendido* dir, char* nombre, char* directorio, char* usuario, char* tipo){
    int i;
    // Buscar el archivo en el directorio extendido
    for (i = 0; i < dir->cantidad_de_archivos; i++){
        if (strcmp(dir[i].nombre, nombre) == 0 && strcmp(dir[i].directorio, directorio) == 0 && strcmp(dir[i].usuario, usuario) == 0 && strcmp(dir[i].tipo, tipo) == 0){
            // El archivo fue encontrado en el directorio extendido, eliminarlo
            memmove(&dir[i], &dir[i+1], (dir->cantidad_de_archivos - i - 1) * sizeof(directorio_extendido));
            dir->cantidad_de_archivos--;
            return 1;  // El archivo fue eliminado exitosamente
        }
    }
    return 0;  // El archivo no fue encontrado en el directorio extendido
}

// Funcion para buscar un archivo en un directorio extendido
int buscar_archivo_extendido(directorio_extendido* dir, char* nombre, char* directorio, char* usuario, char* tipo){
    int i;
    // Buscar el archivo en el directorio extendido
    for (i = 0; i < dir->cantidad_de_archivos; i++){
        if (strcmp(dir[i].nombre, nombre) == 0 && strcmp(dir[i].directorio, directorio) == 0 && strcmp(dir[i].usuario, usuario) == 0 && strcmp(dir[i].tipo, tipo) == 0){
            return i;  // El archivo fue encontrado en el directorio extendido, devolver su indice
        }
    }
    return -1;  // El archivo no fue encontrado en el directorio extendido
}

// Funcion para imprimir los nombres de todos los archivos en un directorio extendido, junto con la informacion adicional
void presentar_archivos_extendido(directorio_extendido* dir){
    int i;
    for (i = 0; i < dir->cantidad_de_archivos; i++){
        printf("%s\t%s\t%s\t%s\n", dir[i].directorio, dir[i].nombre, dir[i].usuario, dir[i].tipo);
    }
    printf("\n");
}

int main(){
    int opcion;
    directorio dir;  // Directorio simple
    directorio_extendido dir_extendido;  // Directorio extendido
    char nombre[50];
    char directorio[50];
    char usuario[50];
    char tipo[50];
    int encontrado;
    
    // Inicializar los directorios
    dir.cantidad_de_archivos = 0;
    dir_extendido.cantidad_de_archivos = 0;
    
    //menu
    while(1){
        printf("\n");
        printf("Seleccione una opcion:\n");
        printf("1. Crear archivo\n");
        printf("2. Eliminar archivo\n");
        printf("3. Buscar archivo\n");
        printf("4. Presentar archivos\n");
        printf("5. Crear archivo extendido\n");
        printf("6. Eliminar archivo extendido\n");
        printf("7. Buscar archivo extendido\n");
        printf("8. Presentar archivos extendido\n");
        printf("9. Salir\n");
        scanf("%d", &opcion);
        printf("\n");

        switch(opcion){
            case 1:
                printf("Ingrese el nombre del archivo: ");
                scanf("%s", nombre);
                printf("Ingrese el nombre del directorio: ");
                scanf("%s", directorio);
                crear_archivo(&dir, nombre, directorio);
                break;

            case 2:
                printf("Ingrese el nombre del archivo: ");
                scanf("%s", nombre);
                printf("Ingrese el nombre del directorio: ");
                scanf("%s", directorio);
                encontrado = eliminar_archivo(&dir, nombre, directorio);
                if(encontrado){
                    printf("El archivo fue eliminado exitosamente.\n");
                }
                else{
                    printf("El archivo no fue encontrado en el directorio.\n");
                }
                break;

            case 3:
                printf("Ingrese el nombre del archivo: ");
                scanf("%s", nombre);
                printf("Ingrese el nombre del directorio: ");
                scanf("%s", directorio);
                encontrado = buscar_archivo(&dir, nombre, directorio);
                if(encontrado != -1){
                    printf("El archivo fue encontrado en el directorio en la posicion %d.\n", encontrado);
                }
                else{
                    printf("El archivo no fue encontrado en el directorio.\n");
                }
                break;
                
            case 4:
                presentar_archivos(&dir);
                break;
            case 5:
                printf("Ingrese el nombre del archivo: ");
                scanf("%s", nombre);
                printf("Ingrese el nombre del directorio: ");
                scanf("%s", directorio);
                printf("Ingrese el nombre del usuario: ");
                scanf("%s", usuario);
                printf("Ingrese el tipo de archivo: ");
                scanf("%s", tipo);
                crear_archivo_extendido(&dir_extendido, nombre, directorio, usuario, tipo);
                break;

            case 6:
                printf("Ingrese el nombre del archivo: ");
                scanf("%s", nombre);
                printf("Ingrese el nombre del directorio: ");
                scanf("%s", directorio);
                printf("Ingrese el nombre del usuario: ");
                scanf("%s", usuario);
                encontrado = encontrado = eliminar_archivo_extendido(&dir_extendido, nombre, directorio, usuario, tipo);
                if(encontrado){
                    printf("El archivo extendido fue eliminado exitosamente.\n");
                }
                else{
                    printf("El archivo extendido no fue encontrado en el directorio.\n");
                }
                break;

            case 7:
                printf("Ingrese el nombre del archivo: ");
                scanf("%s", nombre);
                printf("Ingrese el nombre del directorio: ");
                scanf("%s", directorio);
                printf("Ingrese el nombre del usuario: ");
                scanf("%s", usuario);
                encontrado = buscar_archivo_extendido(&dir_extendido, nombre, directorio, usuario, tipo);
                if(encontrado != -1){
                    printf("El archivo extendido fue encontrado en el directorio en la posicion %d.\n", encontrado);
                }
                else{
                    printf("El archivo extendido no fue encontrado en el directorio.\n");
                }
                break;

            case 8:
                presentar_archivos_extendido(&dir_extendido);
                break;

            case 9:
                printf("Chao!\n");
                return 0;
                
            default:
                printf("Opcion invalida. Intente de nuevo.\n");
                break;
        }
    }
    return 0;
}