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
            printf("(%i, %i)\n");
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

    long long total = 0;

    for (int i = 0; i < size; i++)
    {
        int ambos[2] = {leftMax[i], rightMax[i]};
        int nivel = min(ambos, 2);
        total += nivel - height[i];
    }
}

int main()
{
}