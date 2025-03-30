#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARCHIVO_DISPOSITIVOS "../data/dispositivos.txt"

// Función para mostrar menú
void mostrarMenu()
{
  printf("\n=== Menú VISSOR ===\n");
  printf("1. Monitorear Dispositivos\n");
  printf("2. Agregar Nuevo Dispositivo\n");
  printf("3. Salir\n");
  printf("Seleccione una opción: ");
}

void limpiarpantalla()
{
#ifdef _WIN32
  system("cls"); // Comando para listar directorios en Windows
#elif __linux__
  system("clear"); // Comando para listar directorios en Linux
#else
  printf("[ERROR] - Sistema operativo no soportado.\n");
#endif
}

int main()
{
  setlocale(LC_ALL, ""); // Espa�ol con soporte UTF-8
  int opcion;
  do
  {
    mostrarMenu();
    scanf("%d", &opcion);
    printf("\n");
    getchar();
    switch (opcion)
    {
    case 1:
      // monitorearDispositivos(); // Mostrar todos los dispositivos
      printf("Monitoreando dispositivos...\n");
      getchar();
      limpiarpantalla();
      break;
    case 2:
      // agregarDispositivo(); // Agregar un nuevo dispositivo
      getchar();
      limpiarpantalla();
      break;
    case 3:
      getchar();
      limpiarpantalla();
      printf("Saliendo del sistema...\n");
      break;
    default:
      printf("[ERROR] - Opción no válida. Intente nuevamente.\n");
    }
  } while (opcion != 3);

  return 0;
}