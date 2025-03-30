#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <conio.h> // Para getch() en Windows
#endif

#define ARCHIVO_DISPOSITIVOS "../data/dispositivos.txt"

// Definir la estructura para representar un dispositivo
typedef struct
{
  int id;
  char dispositivo[50];
  char categoria[50];
  char valor[50];
  char estado[50];
} Dispositivo;

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
  getchar(); // Captura el Enter adicional que queda en el buffer
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

void mostrarTablaCSV()
{
  FILE *archivo = fopen(ARCHIVO_DISPOSITIVOS, "r");
  if (archivo == NULL)
  {
    printf("Error al abrir el archivo\n");
    return;
  }

  char linea[200]; // Buffer para leer cada línea

  // Encabezado de la tabla
  printf("+----+-----------------+----------------------+-------+--------------------------------------------+\n");
  printf("| ID | Dispositivo     | Categoría           | Valor | Estado                                     |\n");
  printf("+----+-----------------+----------------------+-------+--------------------------------------------+\n");

  Dispositivo disp; // Variable de tipo struct para almacenar cada fila del CSV

  // Leer y mostrar cada línea del CSV
  while (fgets(linea, sizeof(linea), archivo))
  {
    // Extraer los valores y almacenarlos en la estructura
    if (sscanf(linea, "%d,%49[^,],%49[^,],%49[^,],%49[^\n]",
               &disp.id, disp.dispositivo, disp.categoria, disp.valor, disp.estado) == 5)
    {
      // Imprimir la fila en formato tabular
      printf("| %-2d | %-15s | %-20s | %-5s | %-42s |\n",
             disp.id, disp.dispositivo, disp.categoria, disp.valor, disp.estado);
    }
  }

  printf("+----+-----------------+----------------------+-------+--------------------------------------------+\n");

  fclose(archivo);
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
      mostrarTablaCSV();
      esperarEnter();
      limpiarpantalla();
      break;
    case 2:
      // agregarDispositivo(); // Agregar un nuevo dispositivo
      limpiarpantalla();
      mostrarTablaCSV();
      esperarEnter();
      limpiarpantalla();
      break;
    case 3:
      printf("Saliendo del sistema...\n\n");
      esperarEnter();
      limpiarpantalla();
      break;
    default:
      printf("[ERROR] - Opción no válida. Intente nuevamente.\n");
    }
  } while (opcion != 3);

  return 0;
}