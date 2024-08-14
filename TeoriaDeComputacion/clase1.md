# Alfabetos, palabras y lenguajes

## Simbolos

Un simbolo es una entidad abstracta indivisible que no se define; una
abreviacion constitudida por una o mas letras, digitos e imagenes, etc.
- Ejemplo: 0, 1, a, 4, A, =, <...

## Alfabetos

Es un conjunto de [simbolos](##simbolos) que se pueden usar de cualquier forma 
dentro de las reglas del mismo


## Palabra o cadena

Es un conjunto finito, o infinito no vacio de [simbolos](##simbolos) tomados
de algun alfabeto tambien finito. se suele denotar una palabra o cadena
con el simbolo w

- Ejemplo 1: _w = qwerty_ es una cadena del alfabeto romano C={a,b,...,z}, tal que cada elemento ([simbolo](##simbolos)) de w esta en C

La cadena vacia se representa con lambda o epsilon, esta **NUNCA** puede 
pertenecer al alfabeto.

La longitud de una cadena w es el numero de posiciones ocupadas por lso simbolos en w y lo denotamos con |w|

La cadena vacia no se toma en cuenta en la longitud de una cadena. Por lo que si
aparece en una cadena no suma a su longitud

Cualquier cadena que contiene cadenas vacias, sin importar el numero de veces que aparezca esta, el resultado siempre dera una cadena original 
(sin simbolos vacios). Por lo tanto son iguales.

## Subcadena
Una subcadena es un conjunto de simbolos secuenciales de una cadena. Estos siempre seran secuenciales y aparece dentro de w

Formalmente, v es subcadena de w si y solo si dos cadenas x e y tal que xvy = w. 
x, y pueden ser cadenas vacias

**Ejemplos:**
w=ab

- Cadenas de longitud 0 = {[?](notas.md#?)}. se asume que ?ab
- Cadenas de longitud 1 = {a,b}
- Cadenas de longitud 2 = {ab}
Subcadena(w) = subcadena(ab) = {?,a,b,ab}. No se repite [?](notas.md#?) por la teoria de conjuntos

## Lenguaje
Lenguaje es un conjuto finito no vacio de [cadenas](##Palabra o cadena) que provienen de un alfabeto, se denota como _L_

Siendo un alfabeto
  L1 = {11, 101, 1}
  L2 = {1111, 111, 1001}

L = 0 es un lenguaje vacio
L = {[?](notas.md#?)} es el lenguaje con la cadena vacia.
Por lo tanto 0 != {[?](notas.md#?)}

Se denota por Sigma sub k de todas las cadenas de longitud k sobre un alfabeto

## Lenguaje universal
Conjunto de todas las [cadenas](##Palabras o cadenas) incluyendo [?](notas.md#?) que se pueden formar con un alfabeto.

Se le denot como Sigma* o herradura de kleene

# Creacion de nuevos lenguajes

## Concatenacion de cadenas
Es una operacion binaria tambien conocida como producto de cadenas. Es la suma de cadenas, poniendo una cadena detras de otra

### Propiedades
Siendo x,y,z cadenas

- **Cerradura:** Para todo x, y dentro del lenguaje universal, xy pertenece al lenguaje universal
- **Asosiatividad:** (xy)z = x(yz)
- **Inversa** Se usa una R sobre la cadena, se invierte la cadena.
  * Palindromo es una cadena tal que su inversa es igual a la misma.
- **Potencia**: Es una cadena concatenada consigo misma n veces. Si esta elevada a 0, la cadena es vacia. su longitud se calcula con n*|w|

## Prefijo
Es una subcadena que aparece al principio en orden secuencial de una cadena.

Ejemplo:

sea w = uacj, prefijo(w) = {[?](notas.md#?), u, ua, uac, uacj}

## Sufijo
Es una subcadena que aparece al final principio en orden secuencial de una cadena.

Es lo opuesto al prefijo

## Prefijo y sufijo propio

Es un sufijo o prefijo propio cuando no es igual a la cadena w y no es [?](notas.md#?)

prefijo - propio(w) = {u,ua,uac}
sufijo - propio(w) = {j,cj,acj,}

# Operaciones con lenguajes

## Union
Es similar a la union de algebra relacional, ya que mezcla dos lenguajes en uno.

### Caso especial
Sea L1={ab, ac, cb}, L2 = 0, donde L2 representa el lenguaje vacio, el resultado sera L1. **NO SE AGREGA UN CARACTER VACIO**

## Concatenacion
Dados dos lenguajes, el producto de estos siempre sera la cononcatenacion de cada cadena con las del otro lenguaje

L1 = {w1,w2,w3,w4} L2 = {v1,v2,v3,v4}

La concatenacion es w1v1, w1v2, w1v3, w1v4
Y sigue con los demas

### Lenguaje vacio
Sea L1 un lenguaje vacio y L2 es cualquier otro lenguaje no vacio la concatenacion es un lenguaje vacio

L1 * L2 = 0
L2 * L1 = 0
