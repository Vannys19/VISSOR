#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_DISPOSITIVOS 10
#define MAX_CATEGORIAS 3
#define MAX_NOMBRE 100
#define ARCHIVO_DISPOSITIVOS "dispositivos.txt"

// Definición de la estructura para un dispositivo
typedef struct {
    int id; // ID real usado internamente, pero no se guarda en el archivo como "00"
    char nombre[MAX_NOMBRE];
    char categoria[MAX_NOMBRE];
    int valor;
    char estado[MAX_NOMBRE];
} Dispositivo;

Dispositivo dispositivos[MAX_DISPOSITIVOS];
int contadorDispositivos = 0;

// Arrays para las categorías disponibles
char categorias[MAX_CATEGORIAS][MAX_NOMBRE] = {
    "Motores", "Bombas y Compresores", "Líneas de Producción (Cintas Transportadoras)"
};

// Función para mostrar menú
void mostrarMenu() {
    printf("\n=== Menú VISSOR ===\n");
    printf("1. Monitorear Dispositivos\n");
    printf("2. Agregar Nuevo Dispositivo\n");
    printf("3. Salir\n");
    printf("Seleccione una opción: ");
}

// Función para agregar dispositivos
void agregarDispositivo() {
    if (contadorDispositivos >= MAX_DISPOSITIVOS) {
        printf("[ERROR] - No se pueden agregar más dispositivos, el límite ha sido alcanzado.\n");
        return;
    }

    // Asignar un ID único (aunque será mostrado como "00")
    dispositivos[contadorDispositivos].id = contadorDispositivos + 1;

    printf("\nIngrese el nombre del dispositivo: ");
    scanf(" %[^\n]", dispositivos[contadorDispositivos].nombre);

    // Menú para seleccionar la categoría
    int categoria;
    int categoriaValida = 0;
    while (!categoriaValida) {
        int i;
        printf("\nSeleccione la categoría del dispositivo:\n");
        for (i = 0; i < MAX_CATEGORIAS; i++) {
            printf("%d. %s\n", i + 1, categorias[i]);
        }

        scanf("%d", &categoria);

        if (categoria >= 1 && categoria <= MAX_CATEGORIAS) {
            strcpy(dispositivos[contadorDispositivos].categoria, categorias[categoria - 1]);
            categoriaValida = 1; // Categoría válida
        } else {
            printf("[ERROR] - Opción no válida. Intente nuevamente.\n");
        }
    }

    // Asignar valores y estado predeterminado
    dispositivos[contadorDispositivos].valor = 0;
    strcpy(dispositivos[contadorDispositivos].estado, "*");

    // Escribir el dispositivo en el archivo con el ID como "00"
    FILE *file = fopen(ARCHIVO_DISPOSITIVOS, "a");
    if (file) {
        fprintf(file, "00,%s,%s,%d,%s\n", dispositivos[contadorDispositivos].nombre,
                dispositivos[contadorDispositivos].categoria, dispositivos[contadorDispositivos].valor,
                dispositivos[contadorDispositivos].estado);
        fclose(file);
    } else {
        printf("[ERROR] - No se pudo abrir el archivo.\n");
    }

    contadorDispositivos++;
    printf("[OK] - Dispositivo agregado exitosamente.\n");
}

// Función para monitorear todos los dispositivos (sin importar la categoría)
void monitorearDispositivos() {
    FILE *file = fopen(ARCHIVO_DISPOSITIVOS, "r");
    if (!file) {
        printf("[ERROR] - No se pudo abrir el archivo de dispositivos.\n");
        return;
    }

    printf("\n=== Todos los Dispositivos ===\n");
    printf("| %-5s | %-25s | %-25s | %-10s | %-20s |\n", "ID", "Dispositivo", "Categoría", "Valor", "Estado");
    printf("|------|-------------------------|-------------------------|------------|----------------------|\n");

    int id, valor;
    char nombre[MAX_NOMBRE], categoria[MAX_NOMBRE], estado[MAX_NOMBRE];
    while (fscanf(file, " %d,%99[^,],%99[^,],%d,%99[^\n]", &id, nombre, categoria, &valor, estado) == 5) {
        // Se muestra "00" como ID
        printf("| %-5s | %-25s | %-25s | %-10d | %-20s |\n", "00", nombre, categoria, valor, estado);
    }

    fclose(file);
}

int main() {
    setlocale(LC_ALL, "");
    int opcion;
    do {
        mostrarMenu();
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                monitorearDispositivos(); // Mostrar todos los dispositivos
                break;
            case 2:
                agregarDispositivo(); // Agregar un nuevo dispositivo
                break;
            case 3:
                printf("Saliendo del sistema...\n");
                break;
            default:
                printf("[ERROR] - Opción no válida. Intente nuevamente.\n");
        }
    } while (opcion != 3);

    return 0;
}

