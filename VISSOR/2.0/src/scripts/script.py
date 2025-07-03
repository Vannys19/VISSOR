import random

# Archivos de entrada y salida
archivo = "../data/dispositivos.txt"
temp_file = "../data/temp_dispositivos.txt"

# Verificar si el archivo de dispositivos existe
try:
    with open(archivo, "r") as f:
        dispositivos = f.readlines()
except FileNotFoundError:
    print(f"[ERROR] El archivo {archivo} no existe.")
    exit(1)

# Función para generar un valor aleatorio dependiendo de la categoría
def generar_valor(categoria):
    if categoria == "Motores":
        return random.randint(0, 100)
    elif categoria == "Cintas Transportadoras":
        return random.randint(0, 500)
    elif categoria == "Bombas y Compresores":
        return random.randint(0, 700)
    else:
        return 0

# Función para determinar el estado basado en la categoría y valor
def determinar_estado(categoria, valor):
    if categoria == "Motores":
        return "[ALERTA] Motor con alta velocidad!" if valor > 80 else "[OK] Motor funcionando correctamente."
    elif categoria == "Cintas Transportadoras":
        return "[ALERTA] Banda transportadora con velocidad muy alta!" if valor > 400 else "[OK] Banda transportadora funcionando correctamente."
    elif categoria == "Bombas y Compresores":
        return "[ALERTA] Bomba con presión muy alta!" if valor > 600 else "[OK] Bomba funcionando correctamente."
    else:
        return "*"

# Leer el archivo, procesar las líneas y escribir en el archivo temporal
with open(temp_file, "w") as f_temp:
    for linea in dispositivos:
        # Separar los campos en cada línea
        campos = linea.strip().split(",")
        id_dispositivo, nombre, categoria, valor, estado = campos

        # Mantener el ID y nombre sin cambios, y generar los nuevos valores y estado
        nuevo_valor = generar_valor(categoria)
        nuevo_estado = determinar_estado(categoria, nuevo_valor)

        # Escribir los resultados actualizados en el archivo temporal
        f_temp.write(f"{id_dispositivo},{nombre},{categoria},{nuevo_valor},{nuevo_estado}\n")

# Reemplazar el archivo original con el archivo temporal actualizado
import shutil
shutil.move(temp_file, archivo)
