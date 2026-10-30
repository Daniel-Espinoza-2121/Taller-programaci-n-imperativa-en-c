#Taller de programación imperativa en c

**Integrantes**
- [Daniel Espinoza Vega] ([2024231208])

**Lenguaje:** C (estándar C11)

## Instrucciones de ejecución

```bash
gcc -std=c11 -Wall -Wextra -pedantic main.c -o taller
./taller
```

## Respuestas a preguntas del taller

### Ejercicio 1 (swap)
**¿Porque punteros?**
C pasa los argumentos por valor, así que la función recibiría copias. Con direcciones puede modificar las variables originales de quien llama.

**¿Diferencia entre modificar a y *a?**
Modificar a solo cambia solo cambia la copia local dentro de la función mientras que modificar *a cambia el valor de la variable dentro y fuera de la función

**¿Alcance de la variable auxiliar?**
Existe solo desde que se declara hasta que finaliza la función y solo existe dentro de la función.

### Ejercicio 3 (copia)
Asignar un puntero a otro solo copia la dirección de memoria a la que apunta ese puntero pero no el valor guardado en esa dirección de memoria.

### Ejercicio 5 (dos índices)
Con el arreglo ordenado, si values[i] + values[j] < target, el values[i] actual no puede formar par con ningún elemento a la izquierda de j, porque todos son menores o iguales a values[j]. Entonces se descarta ese extremo y se avanza i. Si la suma es mayor, pasa lo mismo con values[j] y se retrocede j. Cada comparación descarta un extremo sin perder soluciones.

### Cómo 3Sum evita ternas duplicadas
Primero se ordena el array lo que nos permite que al encontrar una terna avanzar ambos punteros y al encotrar números repetidos simplemente ignorarlos.

### Por qué el agua depende del menor de los dos máximos
El agua siempre se dersborda por el lado con la pared más baja, por lo que el nivel del agua solo podra llegar hasta la altura de esta.

### Ejemplo de alcance de variables
En la función sumar, suma e i son locales a la función; i además solo existe dentro del for. Al terminar la función desaparecen y no se pueden usar desde main. Por eso el resultado se devuelve con return.

### Manejo de memoria: C vs. Go
En C la memoria se maneja completamente manual con el programador indicando cuando se pueden apartar nuevos bloques de memoria y cuando liberarlos, mientras que, en Go existe un garbage collector, asi que, aunque el programador puede apartar bloques de manera manual es el garbage collector quien se encarga de liberarlos.