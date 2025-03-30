#!/bin/bash

# Archivo donde están los dispositivos
archivo="../data/dispositivos.txt"
temp_file="../data/temp_dispositivos.txt"

# Verificar si el archivo de dispositivos existe
if [[ ! -f $archivo ]]; then
    echo "[ERROR] El archivo $archivo no existe."
    exit 1
fi

# Función para generar un valor aleatorio dependiendo de la categoría
generar_valor() {
    local categoria=$1
    case $categoria in
        "Motores")
            # Para motores, generamos un valor entre 0 y 100
            echo "$((RANDOM % 101))"
            ;;
        "Líneas de Producción (Cintas Transportadoras)")
            # Para las bandas transportadoras, generamos un valor entre 0 y 500
            echo "$((RANDOM % 501))"
            ;;
        "Bombas y Compresores")
            # Para bombas y compresores, generamos un valor entre 0 y 700
            echo "$((RANDOM % 701))"
            ;;
        *)
            echo "0"
            ;;
    esac
}

# Función para determinar el estado basado en la categoría y valor
determinar_estado() {
    local categoria=$1
    local valor=$2
    case $categoria in
        "Motores")
            if (( valor > 80 )); then
                echo "[ALERTA] Motor con alta velocidad!"
            else
                echo "[OK] Motor funcionando correctamente."
            fi
            ;;
        "Líneas de Producción (Cintas Transportadoras)")
            if (( valor > 400 )); then
                echo "[ALERTA] Banda transportadora con velocidad muy alta!"
            else
                echo "[OK] Banda transportadora funcionando correctamente."
            fi
            ;;
        "Bombas y Compresores")
            if (( valor > 600 )); then
                echo "[ALERTA] Bomba con presión muy alta!"
            else
                echo "[OK] Bomba funcionando correctamente."
            fi
            ;;
        *)
            echo "*"
            ;;
    esac
}

# Abrir el archivo y actualizar los valores y estados
{
    id_counter=1
    while IFS=, read -r id nombre categoria valor estado
    do
        # Generar un ID con formato de 2 dígitos (con ceros a la izquierda)
        id_formateado=$(printf "%02d" "$id_counter")

        # Generar un valor aleatorio dependiendo de la categoría
        valor_aleatorio=$(generar_valor "$categoria")

        # Determinar el estado basado en el valor aleatorio y la categoría
        estado_aleatorio=$(determinar_estado "$categoria" "$valor_aleatorio")

        # Escribir los datos con el nuevo ID, valor y estado
        printf "%s,%s,%s,%d,%s\n" "$id_formateado" "$nombre" "$categoria" "$valor_aleatorio" "$estado_aleatorio"

        # Incrementar el contador de ID
        ((id_counter++))
    done < "$archivo"
} > "$temp_file"

# Reemplazar el archivo original con el archivo temporal actualizado
mv "$temp_file" "$archivo"
