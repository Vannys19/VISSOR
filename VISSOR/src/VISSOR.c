#include <locale.h>
#include <stdbool.h> // Para usar tipo bool (true/false)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <conio.h> // Para getch() en Windows
#endif

#define ARCHIVO_DISPOSITIVOS "../data/dispositivos.txt" // Ruta del archivo donde se guardan los dispositivos
FILE *archivo;                                          // Puntero al archivo para operaciones de lectura/escritura

// Estructura que representa un dispositivo
typedef struct
{
  int id;
  char dispositivo[50];
  char categoria[50];
  char valor[50];
  char estado[70];
} Dispositivo;

// Variables globales
int opcion;    // Almacena la opción del menú seleccionada
int categoria; // Almacena la categoría seleccionada
int ids[10];   // Arreglo para guardar los IDs ya existentes

// Limpia pantalla dependiendo del sistema operativo
void limpiarPantalla()
{
  printf("Presione Enter para continuar...");
#ifdef _WIN32
  getch();       // Espera una tecla (Windows)
  system("cls"); // Limpia pantalla (Windows)
#elif __linux__
  getchar();       // Espera Enter (Linux)
  system("clear"); // Limpia pantalla (Linux)
  getchar();       // Limpia el buffer
#endif
}

// Carga los primeros 10 IDs desde el archivo
void cargarIDs()
{
  archivo = fopen(ARCHIVO_DISPOSITIVOS, "r"); // Abrir archivo para lectura
  if (archivo == NULL)
  {
    printf("Error al abrir el archivo\n");
    return;
  }

  char linea[200];
  int i = 0;

  // Leer línea por línea y extraer el ID hasta llenar el arreglo
  while (fgets(linea, sizeof(linea), archivo) && i < 10)
  {
    sscanf(linea, "%d", &ids[i]);
    i++;
  }

  fclose(archivo);
}

// Muestra el menú principal y devuelve la opción seleccionada
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

// Muestra el menú de categorías y valida que esté entre 1 y 3
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

// Muestra en pantalla todos los dispositivos guardados en el archivo
void mostrarDatos()
{
  archivo = fopen(ARCHIVO_DISPOSITIVOS, "r");
  if (archivo == NULL)
  {
    printf("Error al abrir el archivo\n");
    return;
  }

  char linea[200];
  Dispositivo disp;

  // Imprime encabezados
  printf("+--------+-----------------+------------------------+-------+-------------------------------------------------------+\n");
  printf("| ID     | Dispositivo     | Categoría             | Valor | Estado\t\t\t\t\t\t    |\n");
  printf("+--------+-----------------+------------------------+-------+-------------------------------------------------------+\n");

  // Leer y mostrar cada línea formateada
  while (fgets(linea, sizeof(linea), archivo))
  {
    if (sscanf(linea, "%d,%49[^,],%49[^,],%49[^,],%70[^\n]", &disp.id,
               disp.dispositivo, disp.categoria, disp.valor,
               disp.estado) == 5)
    {
      printf("| %-6d | %-15s | %-22s | %-5s | %-53s |\n", disp.id,
             disp.dispositivo, disp.categoria, disp.valor, disp.estado);
    }
  }

  printf("+--------+-----------------+------------------------+-------+-------------------------------------------------------+\n");

  fclose(archivo);
}

// Valida que el ID sea único y esté en el rango permitido (1-1000)
int validarID()
{
  int i;
  bool valido;
  int id_dispositivo;

  do
  {
    valido = true; // Suponemos que el ID es válido
    printf("Ingrese el ID del dispositivo entre (1-1000): ");
    scanf("%d", &id_dispositivo);

    // Verificar rango
    if (id_dispositivo < 1 || id_dispositivo > 1000)
    {
      printf("ID inválido. Debe estar entre 1 y 1000.\n");
      valido = false;
    }
    else
    {
      // Verificar si el ID ya está en uso
      for (i = 0; i < 10; i++)
      {
        if (ids[i] == id_dispositivo)
        {
          printf("El ID %d ya está en uso. Por favor, elija otro.\n", id_dispositivo);
          valido = false;
        }
      }
    }

  } while (!valido); // Repetir si no es válido

  return id_dispositivo;
}

// Permite agregar un nuevo dispositivo al archivo
void agregarDispositivo()
{
  int id_dispositivo = validarID(); // Validar ID único

  archivo = fopen(ARCHIVO_DISPOSITIVOS, "a+"); // Abrir para agregar
  if (archivo == NULL)
  {
    printf("Error al abrir el archivo\n");
    return;
  }

  // Contar dispositivos ya registrados
  fseek(archivo, 0, SEEK_SET);
  char linea[200];
  int cantidadDispositivos = 0;
  while (fgets(linea, sizeof(linea), archivo))
  {
    cantidadDispositivos++;
  }

  // Limitar a 10 dispositivos
  if (cantidadDispositivos >= 10)
  {
    printf("\nYa hay 10 dispositivos registrados. No se puede agregar más.\n");
    fclose(archivo);
    return;
  }

  // Preparar nuevo dispositivo
  Dispositivo nuevoDispositivo;
  nuevoDispositivo.id = id_dispositivo;

  categoria = menuCategorias(); // Elegir categoría

  // Asignar categoría según la opción
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

  // Pedir nombre del dispositivo
  printf("Ingrese el nombre del dispositivo: ");
  getchar(); // Limpiar buffer
  fgets(nuevoDispositivo.dispositivo, sizeof(nuevoDispositivo.dispositivo), stdin);
  nuevoDispositivo.dispositivo[strcspn(nuevoDispositivo.dispositivo, "\n")] = '\0';

  // Inicializar campos por defecto
  strcpy(nuevoDispositivo.valor, "_");
  strcpy(nuevoDispositivo.estado, "*");

  // Guardar el nuevo dispositivo en el archivo
  fprintf(archivo, "%d,%s,%s,%s,%s\n", nuevoDispositivo.id,
          nuevoDispositivo.dispositivo, nuevoDispositivo.categoria,
          nuevoDispositivo.valor, nuevoDispositivo.estado);

  printf("Dispositivo agregado correctamente.\n");
  fclose(archivo);
}

// Función principal que ejecuta el programa
int main()
{
  setlocale(LC_ALL, ""); // Soporte para acentos
  do
  {
    cargarIDs();              // Cargar los IDs existentes desde el archivo
    opcion = menuPrincipal(); // Mostrar menú

    switch (opcion)
    {
    case 1:
#ifdef _WIN32
      system("python ./scripts/script.py"); // Ejecutar script en Windows
#elif __linux__
      system("python3 ../src/scripts/script.py"); // Ejecutar script en Linux
#endif
      printf("Monitoreando dispositivos...\n");
      mostrarDatos();    // Mostrar los dispositivos
      limpiarPantalla(); // Pausa
      break;

    case 2:
      mostrarDatos();       // Mostrar antes de agregar
      agregarDispositivo(); // Agregar nuevo
      limpiarPantalla();    // Pausa
      break;

    case 3:
      printf("Saliendo del sistema...\n\n");
      limpiarPantalla(); // Pausa
      break;

    default:
      printf("[ERROR] - Opción no válida. Intente nuevamente.\n");
    }

  } while (opcion != 3); // Repetir hasta que el usuario elija salir

  return 0;
}
