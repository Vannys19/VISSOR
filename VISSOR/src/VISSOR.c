#include <stdio.h>
#include <string.h>

#define MAX_DISPOSITIVOS 10
#define MAX_NOMBRE 50
#define MAX_TIPO 50
#define MAX_ESTADO 20

// Arreglos para almacenar la información de los dispositivos
char nombres[MAX_DISPOSITIVOS][MAX_NOMBRE];
char tipos[MAX_DISPOSITIVOS][MAX_TIPO];
char estados[MAX_DISPOSITIVOS][MAX_ESTADO];

// Función para inicializar los dispositivos
void inicializarDispositivos() {
  for (int i = 0; i < MAX_DISPOSITIVOS; i++) {
    snprintf(nombres[i], MAX_NOMBRE, "Dispositivo_%d", i);
    strcpy(tipos[i], "No definido");
    strcpy(estados[i], "Apagado");
  }
}

// Función para mostrar todos los dispositivos
void mostrarDispositivos() {
  printf("\n=== Monitoreo de Dispositivos ===\n");
  for (int i = 0; i < MAX_DISPOSITIVOS; i++) {
    printf("[%d] Nombre: %s | Tipo: %s | Estado: %s\n", i, nombres[i], tipos[i],
           estados[i]);
  }
}

// Función para registrar un dispositivo
void registrarDispositivo() {
  int id;
  printf("\nIngrese el ID del dispositivo (0-9): ");
  scanf("%d", &id);

  if (id >= 0 && id < MAX_DISPOSITIVOS) {
    printf("Ingrese el nombre del dispositivo: ");
    scanf("%s", nombres[id]);

    printf("Ingrese el tipo del dispositivo: ");
    scanf("%s", tipos[id]);

    strcpy(estados[id], "Apagado");
    printf("Dispositivo registrado exitosamente.\n");
  } else {
    printf("ID no válido.\n");
  }
}

// Función para gestionar el estado de un dispositivo
void gestionarDispositivo() {
  int id, accion;
  printf("\nIngrese el ID del dispositivo a gestionar (0-9): ");
  scanf("%d", &id);

  if (id >= 0 && id < MAX_DISPOSITIVOS) {
    printf("Dispositivo: %s\nEstado actual: %s\n", nombres[id], estados[id]);
    printf("Seleccione una acción:\n1. Encender\n2. Apagar\n3. Reiniciar\n");
    scanf("%d", &accion);

    switch (accion) {
    case 1:
      strcpy(estados[id], "Encendido");
      break;
    case 2:
      strcpy(estados[id], "Apagado");
      break;
    case 3:
      strcpy(estados[id], "Reiniciando");
      break;
    default:
      printf("Acción no válida.\n");
      return;
    }
    printf("Acción realizada exitosamente.\n");
  } else {
    printf("ID no válido.\n");
  }
}

// Función principal con el menú integrado
int main() {
  int opcion;
  inicializarDispositivos();

  do {
    printf("\n===== Sistema VISSOR (Primitivo) =====\n");
    printf("1. Registrar dispositivo\n");
    printf("2. Monitorear dispositivos\n");
    printf("3. Gestionar dispositivo\n");
    printf("4. Salir\n");
    printf("Seleccione una opción: ");
    scanf("%d", &opcion);

    switch (opcion) {
    case 1:
      registrarDispositivo();
      break;
    case 2:
      mostrarDispositivos();
      break;
    case 3:
      gestionarDispositivo();
      break;
    case 4:
      printf("Saliendo del sistema...\n");
      break;
    default:
      printf("Opción no válida.\n");
    }
  } while (opcion != 4);

  return 0;
}
