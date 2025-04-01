#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> // Para el tipo booleano
#ifdef _WIN32
#include <conio.h> // Para getch() en Windows
#endif

#define ARCHIVO_DISPOSITIVOS "../data/dispositivos.txt"
FILE *archivo;
// Definir la estructura para representar un dispositivo
typedef struct
{
  int id;
  char dispositivo[50];
  char categoria[50];
  char valor[50];
  char estado[50];
} Dispositivo;

int opcion;    // Variable global para almacenar la opción seleccionada
int categoria; // Variable global para almacenar la categoría seleccionada

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

// Función para mostrar menú
int menuPrincipal()
{
  printf("\n=== Menú VISSOR ===\n");
  printf("1. Monitorear Dispositivos\n");
  printf("2. Agregar Nuevo Dispositivo\n");
  printf("3. Salir\n");
  printf("Seleccione una opción: ");
  scanf("%d", &opcion);
  printf("\n");
  return opcion;
}

// Función para mostrar el menú de categorías
int menuCategorias()
{
  do
  {
    printf("\nSeleccione la categoría del dispositivo:\n");
    printf("1. Motores\n");
    printf("2. Bombas y Compresores\n");
    printf("3. Cintas Transportadoras\n");
    printf("Ingrese el número correspondiente: ");
    scanf("%d", &categoria);

    if (categoria < 1 || categoria > 3)
    {
      printf("Opción inválida. Intente nuevamente.\n");
    }
  } while (categoria < 1 || categoria > 3);
  return categoria;
}

void mostrarDatos()
{
  archivo = fopen(ARCHIVO_DISPOSITIVOS, "r");
  if (archivo == NULL)
  {
    printf("Error al abrir el archivo\n");
    return;
  }

  char linea[200]; // Buffer para leer cada línea

  // Encabezado de la tabla
  printf("+--------+-----------------+------------------------+-------+--------------------------------------------+\n");
  printf("| ID     | Dispositivo     | Categoría             | Valor | Estado                                     |\n");
  printf("+--------+-----------------+------------------------+-------+--------------------------------------------+\n");

  Dispositivo disp; // Variable de tipo struct para almacenar cada fila del CSV

  // Leer y mostrar cada línea del CSV
  while (fgets(linea, sizeof(linea), archivo))
  {
    // Extraer los valores y almacenarlos en la estructura
    if (sscanf(linea, "%d,%49[^,],%49[^,],%49[^,],%49[^\n]",
               &disp.id, disp.dispositivo, disp.categoria, disp.valor, disp.estado) == 5)
    {
      // Imprimir la fila en formato tabular
      printf("| %-6d | %-15s | %-22s | %-5s | %-42s |\n",
             disp.id, disp.dispositivo, disp.categoria, disp.valor, disp.estado);
    }
  }

  printf("+--------+-----------------+------------------------+-------+--------------------------------------------+\n");

  fclose(archivo);
}

int validarID()
{
  archivo = fopen(ARCHIVO_DISPOSITIVOS, "r"); // Abrir el archivo en modo lectura
  if (archivo == NULL)
  {
    printf("Error al abrir el archivo\n");
    return -1; // Retornar un ID inválido
  }

  int id_dispositivo;
  do
  {
    printf("Ingrese el ID del dispositivo entre (1-1000): ");
    scanf("%d", &id_dispositivo);

    if (id_dispositivo < 1 || id_dispositivo > 1000)
    {
      printf("ID inválido. Debe estar entre 1 y 1000.\n");
    }
  } while (id_dispositivo < 1 || id_dispositivo > 1000);
  fclose(archivo);
  return id_dispositivo;
}

// Función para agregar un dispositivo al archivo
void agregarDispositivo()
{
  int id_dispositivo = validarID();            // Validar el ID del dispositivo
  archivo = fopen(ARCHIVO_DISPOSITIVOS, "a+"); // Abre el archivo para agregar datos
  if (archivo == NULL)
  {
    printf("Error al abrir el archivo\n");
    return;
  }

  // Contar cuántos dispositivos ya existen en el archivo
  fseek(archivo, 0, SEEK_SET); // Mover el puntero al inicio del archivo
  char linea[200];
  int cantidadDispositivos = 0;
  while (fgets(linea, sizeof(linea), archivo))
  {
    cantidadDispositivos++;
  }

  // Verificar si ya hay 10 dispositivos
  if (cantidadDispositivos >= 10)
  {
    printf("\nYa hay 10 dispositivos registrados. No se puede agregar más.\n");
    fclose(archivo);
    return;
  }

  // Solicitar al usuario el ID del dispositivo
  Dispositivo nuevoDispositivo;

  nuevoDispositivo.id = id_dispositivo; // Asignar un ID único
  categoria = menuCategorias();         // Llamar a la función del menú de categorías
  // Cambiar la categoría según la opción seleccionada
  switch (categoria)
  {
  case 1:
    strcpy(nuevoDispositivo.categoria, "Motores");
    break;
  case 2:
    strcpy(nuevoDispositivo.categoria, "Bombas y Compresores");
    break;
  case 3:
    strcpy(nuevoDispositivo.categoria, "Cintas Transportadoras");
    break;
  }

  // Solicitar al usuario el nombre del dispositivo
  printf("Ingrese el nombre del dispositivo: ");
  getchar(); // Limpiar el buffer de entrada
  fgets(nuevoDispositivo.dispositivo, sizeof(nuevoDispositivo.dispositivo), stdin);
  nuevoDispositivo.dispositivo[strcspn(nuevoDispositivo.dispositivo, "\n")] = '\0'; // Eliminar el salto de línea
  // Inicializar los valores vacíos antes de escribir en el archivo
  strcpy(nuevoDispositivo.valor, "_");
  strcpy(nuevoDispositivo.estado, "*");

  // Escribir en el archivo con los valores correctamente asignados
  fprintf(archivo, "%d,%s,%s,%s,%s\n",
          nuevoDispositivo.id, nuevoDispositivo.dispositivo, nuevoDispositivo.categoria,
          nuevoDispositivo.valor, nuevoDispositivo.estado);

  printf("Dispositivo agregado correctamente.\n");
  fclose(archivo);
}

int main()
{
  setlocale(LC_ALL, ""); // Español con soporte UTF-8
  do
  {
    opcion = menuPrincipal(); // Llamar a la función del menú principal
    switch (opcion)
    {
    case 1:
      printf("Monitoreando dispositivos...\n");
      mostrarDatos();
      esperarEnter();
      limpiarpantalla();
#ifdef _WIN32
      system(""); // Limpiar pantalla en Windows
#elif __linux__
      system("bash ./scripts/script.bash"); // Limpiar pantalla en Linux
#endif
      break;
    case 2:
      limpiarpantalla();
      mostrarDatos();
      agregarDispositivo();
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