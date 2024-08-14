# Conceptos básicos

## Tipos de datos

Los tipos de datos definen la clase de datos que se puede almacenar y manipular dentro de un programa. Los tipos de datos comunes incluyen:
- **Enteros (int)**: Números enteros sin punto decimal, por ejemplo, `5`, `-3`.
- **Flotantes (float)**: Números con punto decimal, por ejemplo, `3.14`, `-0.001`.
- **Caracteres (char)**: Representan un solo carácter, por ejemplo, `'a'`, `'1'`.
- **Cadenas (string)**: Conjunto de caracteres, por ejemplo, `"Hola Mundo"`.
- **Booleanos (bool)**: Representan valores de verdad, `true` o `false`.

## Sintaxis básica

La sintaxis básica se refiere a las reglas que definen cómo se deben escribir los programas para que el compilador o intérprete pueda entender y ejecutar el código. Esto incluye:
- **Declaraciones de variables**: Por ejemplo, `int numero = 5;`.
- **Operadores**: Los operadores se utilizan para realizar operaciones sobre variables y valores, por ejemplo, `+`, `-`, `*`, `/`, `=`.
- **Estructuras de control**: Como `if`, `else`, `for`, `while`, que permiten controlar el flujo del programa.

## Funciones

Las funciones son bloques de código reutilizables que realizan una tarea específica y se pueden invocar desde cualquier parte del programa. Esto facilita la modularización y el mantenimiento del código.

### Parámetros

Son variables locales a la función que reciben valores específicos cuando la función es llamada. Estos valores se pasan desde la función que invoca.

### main()

`main()` es la función principal de un programa en muchos lenguajes de programación. Es el punto de entrada donde comienza la ejecución del programa. Todas las demás funciones y estructuras de control generalmente son llamadas o ejecutadas dentro de `main()`.

### printf()

`printf()` es una función utilizada en C y otros lenguajes derivados para imprimir texto y valores en la consola. Permite formatear cadenas de texto con especificadores como `%d` para enteros, `%f` para flotantes, `%c` para caracteres, entre otros.
- Ejemplo: `printf("El valor de x es: %d", x);` imprimirá el valor de `x` en la consola.

# Actividad

``
#include<stdio.h>

int main(){
	printf("");
	return 0;
}
``

