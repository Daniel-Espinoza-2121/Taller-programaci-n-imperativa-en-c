#include<stdlib.h>
#include<stdio.h>

void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

int sumar(const int *array, int n)
{
    int suma = 0;
    for (int i = 0; i < n; i ++)
    {
        suma += array[i];
    }
    return suma;
}

int min(const int *array, int n)
{
    int minimo = array[0];
    for (int i = 1; i < n; i ++)
    {
        if (array[i] < minimo)
        {
            minimo = array[i];
        }
    }
    return minimo;
}

int max(const int *array, int n)
{
    int maximo = array[0];
    for (int i = 1; i < n; i ++)
    {
        if (maximo < array[i])
        {
            maximo = array[i];
        }
    }
    return maximo;
}

int contar_negativos(const int *array, int n)
{
    int suma = 0;
    for (int i = 0; i < n; i ++)
    {
        if (array[i] < 0)
        {
            suma++;
        }
        
    }
    return suma;
}

void inverso(const int *array, int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        printf("%i ", array[i]);
    }
}

int *copyArray(const int *values, int size)
{
    int *newarray = malloc(sizeof(int) * size);
    if (newarray == NULL) {return NULL;}
    for (int i = 0; i < size; i++)
    {
        newarray[i] = values[i];
    }
    return newarray;
}

void sortAscending(int *values, int size)
{
    for (int i = 0; i < size; i++)
    {
        int key = values[i];
        int j = i - 1;

        while (j >= 0 && values[j] > key)
        {
            values[j + 1] = values[j];
            j = j - 1;
        }

        values[j + 1] = key;
    }
}

int findPair(const int *values, int size, int target)
{
    int *copy = copyArray(values, size);
    sortAscending(copy, size);

    int izq = 0;
    int der = size - -1;

    while (izq < der)
    {
        int sum = copy[izq] + copy[der];
        if (sum == target)
        {
            printf("(%i, %i)\n", copy[izq], copy[der]);
            return 1;
        }
        else if (sum < target)
        {
            izq++;
        }
        else
        {
            der--;
        }
        
    }
    

    return 0;
}

int threeSum(const int *values, int size)
{
    int *copy = copyArray(values, size);

    if (copy == NULL)
    {
        return -1;
    }

    sortAscending(copy, size);

    int cont = 0;

    for (int i = 0; i < size - 2; i++)
    {
        if (i > 0 && copy[i] == copy[i - 1]) { continue; }
        int izq = i + 1;
        int der = size - 1;

        while (izq < der)
        {
            int sum = copy[i] + copy[izq] + copy[der];

            if (sum == 0) {
                printf("(%d, %d, %d)\n",
                       copy[i], copy[izq], copy[der]);

                cont++;

                izq++;
                der--;

                while (izq < der && copy[izq] == copy[izq - 1])
                {
                    izq++;
                }

                while (izq < der && copy[izq] == copy[der + 1])
                {
                    der--;
                }
            }
            else if (sum > 0)
            {
                izq++;
            }
            else
            {
                der--;
            }
        }
    }

    free(copy);

    return cont;
}

void buildLeftMax(const int *height, int size, int *leftMax)
{
    int max = height[0];
    leftMax[0] = max;

    for (int i = 1; i < size; i++)
    {
        if (max < height[i])
        {
            max = height[i];
        }
        leftMax[i] = max;
    }
}


void buildRightMax(const int *height, int size, int *rightMax)
{
    int max = height[size - 1];
    rightMax[size - 1] = max;

    for (int i = size - 2; i >= 0; i--)
    {
        if (max < height[i])
        {
            max = height[i];
        }
        rightMax[i] = max;
    }
}

long long trappedWater(const int *height, int size)
{
    int *leftMax = malloc(sizeof(int) * size);
    int *rightMax = malloc(sizeof(int) * size);

    if (leftMax == NULL || rightMax == NULL)
    {
        free(leftMax);
        free(rightMax);
        return -1;
    }

    buildLeftMax(height, size, leftMax);
    buildRightMax(height, size, rightMax);

    long long total = 0;

    for (int i = 0; i < size; i++)
    {
        int ambos[2] = {leftMax[i], rightMax[i]};
        int nivel = min(ambos, 2);
        total += nivel - height[i];
    }

    free(leftMax);
    free(rightMax);
    return total;
}

void imprimirArreglo(const char *etiqueta, const int *arr, int n)
{
    printf("%s[", etiqueta);
    for (int i = 0; i < n; i++)
    {
        printf("%d%s", arr[i], i < n - 1 ? ", " : "");
    }
    printf("]\n");
}

void mostrarAgua(const int *height, int size)
{
    int *l = malloc(sizeof(int) * size);
    int *r = malloc(sizeof(int) * size);
    if (l == NULL || r == NULL) { free(l); free(r); return; }

    buildLeftMax(height, size, l);
    buildRightMax(height, size, r);

    printf("i  h  L  R  agua\n");
    for (int i = 0; i < size; i++)
    {
        int nivel = l[i] < r[i] ? l[i] : r[i];
        printf("%d  %d  %d  %d  %d\n", i, height[i], l[i], r[i], nivel - height[i]);
    }
    free(l);
    free(r);
}

int main()
{
    // ---------- Ejercicio 1: swap ----------
    printf("=== Ejercicio 1: swap ===\n");
    int a = 8, b = -3;
    printf("Antes: a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("Despues: a = %d, b = %d\n\n", a, b);

    // ---------- Ejercicio 2: estadisticas ----------
    printf("=== Ejercicio 2: estadisticas ===\n");
    int datos[] = {4, -2, 0, 7, -5};
    int n = 5;
    imprimirArreglo("Entrada: ", datos, n);
    printf("Suma: %d  Minimo: %d  Maximo: %d  Negativos: %d\n",
           sumar(datos, n), min(datos, n), max(datos, n),
           contar_negativos(datos, n));
    printf("Inverso: ");
    inverso(datos, n);
    printf("\n");
    imprimirArreglo("Original intacto: ", datos, n);
    printf("\n");

    // ---------- Ejercicio 3: copia independiente ----------
    printf("=== Ejercicio 3: copia independiente ===\n");
    int *copia = copyArray(datos, n);
    if (copia == NULL)
    {
        printf("Fallo de reserva\n");
        return 1;
    }
    copia[0] = 99;
    imprimirArreglo("Original: ", datos, n);
    imprimirArreglo("Copia:    ", copia, n);
    free(copia);
    printf("\n");

    // ---------- Ejercicio 4: ordenar una copia ----------
    printf("=== Ejercicio 4: ordenar una copia ===\n");
    int *ordenada = copyArray(datos, n);
    if (ordenada == NULL)
    {
        printf("Fallo de reserva\n");
        return 1;
    }
    sortAscending(ordenada, n);
    imprimirArreglo("Original: ", datos, n);
    imprimirArreglo("Ordenado: ", ordenada, n);
    free(ordenada);
    printf("\n");

    // ---------- Ejercicio 5: findPair ----------
    printf("=== Ejercicio 5: findPair ===\n");
    int p1[] = {-4, -1, 0, 2, 5};
    int p2[] = {0, 0};
    int p3[] = {3};
    printf("[-4,-1,0,2,5], objetivo 1: ");
    if (!findPair(p1, 5, 1)) printf("No existe\n");
    printf("[-4,-1,0,2,5], objetivo 8: ");
    if (!findPair(p1, 5, 8)) printf("No existe\n");
    printf("[0,0], objetivo 0: ");
    if (!findPair(p2, 2, 0)) printf("No existe\n");
    printf("[3], objetivo 6: ");
    if (!findPair(p3, 1, 6)) printf("No existe\n");
    printf("\n");

    // ---------- Ejercicio 6: threeSum ----------
    printf("=== Ejercicio 6: threeSum ===\n");
    int s1[] = {-1, 0, 1, 2, -1, -4};
    int s2[] = {0, 1, 1};
    int s3[] = {0, 0, 0};
    int s4[] = {0, 0, 0, 0};
    int s5[] = {-2, 0, 0, 2, 2};
    int s6[] = {1, 2};   // tamano insuficiente
    printf("[-1,0,1,2,-1,-4]:\n");
    printf("  cantidad = %d\n", threeSum(s1, 6));
    printf("[0,1,1]:\n");
    printf("  cantidad = %d\n", threeSum(s2, 3));
    printf("[0,0,0]:\n");
    printf("  cantidad = %d\n", threeSum(s3, 3));
    printf("[0,0,0,0]:\n");
    printf("  cantidad = %d\n", threeSum(s4, 4));
    printf("[-2,0,0,2,2]:\n");
    printf("  cantidad = %d\n", threeSum(s5, 5));
    printf("[1,2] (tamano insuficiente):\n");
    printf("  cantidad = %d\n\n", threeSum(s6, 2));

    // ---------- Ejercicio 7: maximos desde ambos extremos ----------
    printf("=== Ejercicio 7: leftMax y rightMax ===\n");
    int alturas[] = {3, 0, 2, 0, 4};
    int m = 5;
    int *leftMax = malloc(sizeof(int) * m);
    int *rightMax = malloc(sizeof(int) * m);
    if (leftMax == NULL || rightMax == NULL)
    {
        free(leftMax);
        free(rightMax);
        printf("Fallo de reserva\n");
        return 1;
    }
    buildLeftMax(alturas, m, leftMax);
    buildRightMax(alturas, m, rightMax);
    imprimirArreglo("height:   ", alturas, m);
    imprimirArreglo("leftMax:  ", leftMax, m);
    imprimirArreglo("rightMax: ", rightMax, m);
    free(leftMax);
    free(rightMax);
    printf("\n");

    // ---------- Ejercicio 8: trappedWater ----------
    printf("=== Ejercicio 8: trappedWater ===\n");
    int t1[] = {5};
    int t2[] = {0, 1, 2, 3};
    int t3[] = {3, 2, 1, 0};
    int t4[] = {2, 2, 2};
    int t5[] = {3, 0, 3};
    int t6[] = {3, 0, 2, 0, 4};
    int t7[] = {4, 2, 0, 3, 2, 5};
    int t8[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int propio[] = {2, 0, 1, 0, 2};

    printf("[5]            -> %lld (esperado 0)\n", trappedWater(t1, 1));
    printf("[0,1,2,3]      -> %lld (esperado 0)\n", trappedWater(t2, 4));
    printf("[3,2,1,0]      -> %lld (esperado 0)\n", trappedWater(t3, 4));
    printf("[2,2,2]        -> %lld (esperado 0)\n", trappedWater(t4, 3));
    printf("[3,0,3]        -> %lld (esperado 3)\n", trappedWater(t5, 3));
    printf("[3,0,2,0,4]    -> %lld (esperado 7)\n", trappedWater(t6, 5));
    printf("[4,2,0,3,2,5]  -> %lld (esperado 9)\n", trappedWater(t7, 6));
    printf("[0,1,0,2,1,0,1,3,2,1,2,1] -> %lld (esperado 6)\n",
           trappedWater(t8, 12));
    printf("propio [2,0,1,0,2] -> %lld (esperado 5)\n\n",
           trappedWater(propio, 5));

    printf("Detalle por posicion de [3,0,2,0,4]:\n");
    mostrarAgua(t6, 5);

    return -0;
}