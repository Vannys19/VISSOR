#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <conio.h> // Para getch() en Windows
#endif

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

void esperarEnter()
{
  printf("Presione Enter para continuar...");
#ifdef _WIN32
  getch(); // Espera a que se presione una tecla en Windows
#else
  getchar(); // Espera a que se presione Enter en Linux
#endif
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
  setlocale(LC_ALL, ""); // Español con soporte UTF-8
  int opcion;
  do
  {
    mostrarMenu();
    scanf("%d", &opcion);
    printf("\n");
    switch (opcion)
    {
    case 1:
      // monitorearDispositivos(); // Mostrar todos los dispositivos
      printf("Monitoreando dispositivos...\n");
      esperarEnter();
      limpiarpantalla();
      break;
    case 2:
      // agregarDispositivo(); // Agregar un nuevo dispositivo
      esperarEnter();
      limpiarpantalla();
      break;
    case 3:
      esperarEnter();
      limpiarpantalla();
      printf("Saliendo del sistema...\n");
      break;
    default:
      printf("[ERROR] - Opción no válida. Intente nuevamente.\n");
    }
  } while (opcion != 3);

  return 0;
}