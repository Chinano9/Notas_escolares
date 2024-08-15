# Expresiones regulares

El prceso de escritura se puede simplificar asi:

- Formar cadenas a partir de la agrupacion de simbolos que provienen de un alfabeto. (lexico)
- Las cadenas se unen con otras y se colocan siguiendo un orden. (gramatica)
- Se analiza la frase (semantica)

La expresion regular es un tipo de expresion algebraica que permite describir als cadenas que pertenecen a un lenguaje regular.

Las expresiones regulares

Una expresion regular se denota como _R_

Cuando escribimos L(R) se denota un lenguaje regular cuyas cadenas estan descritas por R

## Lenguaje basico
### Cadenas de longitud
Dado un lenguaje, a partir de el se pueden obtener dos tipos de cadenas basicas, que conforman cada una de ellas un lenguaje basico.

### Lenguaje vacio

Un lenguaje que no contiene nada

### Cadena vacia

Un lenguaje el cual solo posee la cadena vacia

## Expresiones regulares basicas

Para todo simbolo en el alfabeto, este simbolo es una expresion regular R = a

La constante vacia es una expresion regular R=?

La constante 0 es una expresion regular R=0


## Operaciones

La construccion de las expresiones regulares mas ricas se realiza por medio de las operaciones la vistas previamente

### Union

R1 = 0 y R2 = 1
La union se exprersa como R=0+1 o R=0|1

La union de cualquier expresion regular con el lenguaje vacio siempre sera el mismo lenguaje vacio

La union con la cadena vacia, el resultado va a ser el mismo lenguaje **MAS** la cadena vacia

### Concatenacion

Sea R1=0 y R1=1

Se denota como R1.R2=01

por lo tanto R=01

En la concatenacion con el lenguaje vacio, **siempre** es igual al vacio

### Kleene

R* es una union de lenguajes de potencia 1,2,3,4,...

Solo afecta al que esta junto a el, por ejemplo en ab*, solo afectara a b

Sea R = 0
entocnes R* = 0*

por lo tanto L(R*) = {?,0,00,000,...}

Si R = 0, si lo ponemos como R* = 0*, **es la cadena vacia**

# Como se resuelve?

(b+a).ba*

1. Parentesis
2. Complemento
3. Los operadores * o positiva *
4. Concatenacion
5. Union
