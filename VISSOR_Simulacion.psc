Proceso VISSOR_Simulacion
    // Variables
    Definir opcion, id_dispositivo, accion, i Como Entero;
    Definir dispositivos Como Caracter; // Declaramos que la matriz será de tipo carácter
    Dimension dispositivos[10, 3]; // Matriz de 10 dispositivos, 3 datos: nombre, estado y tipo
    Definir nombre, tipo Como Cadena;
	
    // Inicializar dispositivos
    Para i <- 0 Hasta 9 Hacer
        dispositivos[i, 0] <- "Dispositivo_" + ConvertirATexto(i); // Nombre
        dispositivos[i, 1] <- "No definido";          // Estado
        dispositivos[i, 2] <- "No definido";     // Tipo
    Fin Para
    
    // Menú principal
    Repetir
        LimpiarPantalla;
        Escribir "===================================== Sistema VISSOR =====================================";
        Escribir Sin Saltar "| Registrar dispositivo ";
        Escribir Sin Saltar "| Monitorear dispositivos ";
        Escribir Sin Saltar "| Gestionar dispositivo ";
        Escribir Sin Saltar "|    Salir    | ";
		Escribir " ";
		Escribir Sin Saltar "           [1]";
        Escribir Sin Saltar "                      [2]";
        Escribir Sin Saltar "                      [3]";
        Escribir Sin Saltar "                [4]";
		Escribir " ";
        Leer opcion;
        Segun opcion Hacer
            Caso 1:
				Escribir "=== Registro de dispositivos ===";
                Escribir "Ingrese el ID del dispositivo (0-9): ";
                Leer id_dispositivo;
                Si id_dispositivo >= 0 Y id_dispositivo <= 9 Entonces
                    Escribir "Ingrese el nombre del dispositivo: ";
                    Leer nombre;
                    Escribir "Ingrese el tipo del dispositivo: ";
                    Leer tipo;
                    dispositivos[id_dispositivo, 0] <- nombre;
                    dispositivos[id_dispositivo, 2] <- tipo;
                    dispositivos[id_dispositivo, 1] <- "Apagado";
					Escribir " ";
                    Escribir "Dispositivo registrado exitosamente.";
					Escribir " ";
					Escribir "--------------";
					Escribir "Presione una tecla para continuar";
					Esperar Tecla;
                Sino
                    Escribir "ID no válido.";
					Esperar Tecla;
                Fin Si;
                
            Caso 2:
                Escribir "=== Monitoreo de dispositivos ===";
                Para i <- 0 Hasta 9 Hacer
                    Escribir "[", i, "] - " , "[", dispositivos[i, 0],"]" ,"  Tipo: [", dispositivos[i, 2], "] - Estado: [", dispositivos[i, 1], "]";
                Fin Para;
				Escribir " ";
				Escribir "--------------";
                Escribir "Presione una tecla para continuar";
                EsperarTecla;
            Caso 3:
				Escribir "=== Gestionar de dispositivos ===";
                Escribir "Ingrese el ID del dispositivo a gestionar (0-9): ";
                Leer id_dispositivo;
                Si id_dispositivo >= 0 Y id_dispositivo <= 9 Entonces
                    Escribir "Dispositivo: ", dispositivos[id_dispositivo, 0];
                    Escribir "Estado actual: ", dispositivos[id_dispositivo, 1];
                    Escribir "Seleccione una acción:";
                    Escribir "1. Encender";
                    Escribir "2. Apagar";
                    Escribir "3. Reiniciar";
                    Leer accion;
                    Segun accion Hacer
                        Caso 1: dispositivos[id_dispositivo, 1] <- "Encendido";
                        Caso 2: dispositivos[id_dispositivo, 1] <- "Apagado";
                        Caso 3: dispositivos[id_dispositivo, 1] <- "Reiniciando";
                        De Otro Modo:
                            Escribir "Acción no válida.";
                    Fin Segun
					Escribir "";
                    Escribir "Acción realizada exitosamente.";
					Escribir "";
					Escribir "--------------";
					Escribir "Presione una tecla para continuar";
					Esperar Tecla;
                Sino
                    Escribir "ID no válido.";
					Esperar Tecla;
					Escribir " ";
					Escribir "--------------";
					Escribir "Presione una tecla para continuar";
                Fin Si;
                
            Caso 4:
                Escribir "Saliendo del sistema...";
            De Otro Modo:
                Escribir "Opción no válida.";
        Fin Segun;
    Hasta Que opcion = 4;
FinProceso
