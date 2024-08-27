# Autómatas

## Introducción a los Autómatas

Un autómata es un modelo matemático abstracto que representa un sistema capaz de realizar computaciones al seguir una secuencia de reglas o transiciones definidas. Los autómatas son fundamentales en la teoría de la computación, y se utilizan para modelar y analizar el comportamiento de sistemas que procesan información, como lenguajes formales, compiladores y controladores de sistemas.

Los autómatas son útiles para resolver problemas de decisión, es decir, determinar si una cadena de caracteres pertenece a un cierto lenguaje, y para diseñar máquinas que realicen tareas específicas como reconocimiento de patrones, procesamiento de texto y control de procesos.

### Tipos de Autómatas

Existen varios tipos de autómatas, cada uno con diferentes capacidades y aplicaciones:

    1. Autómatas Finitos (AF): Tienen un número finito de estados y son utilizados principalmente para reconocer lenguajes regulares.

    2. Autómatas de Pila (AP): Extienden los autómatas finitos al añadir una pila, lo que les permite reconocer lenguajes libres de contexto.

    3. Autómatas Linealmente Acotados (LBA): Tienen una memoria limitada y se utilizan para reconocer lenguajes dependientes del contexto.

    4. Máquinas de Turing: Son los modelos más generales y potentes, capaces de reconocer cualquier lenguaje que sea computable. Representan el límite de lo que puede ser computado por cualquier máquina.

## Autómatas Finitos

Los autómatas finitos son el tipo más simple de autómata. Están caracterizados por tener un número finito de estados y transiciones entre ellos. Son especialmente útiles para modelar sistemas con comportamiento finito y predecible, como circuitos digitales, controladores de software, y sistemas de reconocimiento de patrones.
### Clasificación de los Autómatas Finitos

    1. Autómatas Finitos Deterministas (AFD): Para cada estado y cada símbolo de entrada, existe exactamente una transición definida. No hay ambigüedad en la transición de un estado a otro.

    2. Autómatas Finitos No Deterministas (AFND): Para un estado y un símbolo de entrada, puede haber varias transiciones posibles, o ninguna. También pueden incluir transiciones epsilon, que no consumen ningún símbolo de la entrada.

    3. Autómatas Finitos con Salida: Estos son una extensión de los AFD donde cada transición está asociada no solo a un nuevo estado, sino también a una salida. Los más comunes son:
        Máquina de Mealy: La salida depende del estado actual y del símbolo de entrada.
        Máquina de Moore: La salida depende únicamente del estado actual.

## Autómatas Finitos Deterministas (AFD)
### Definición y Componentes

Un Autómata Finito Determinista (AFD) es un tipo de autómata finito donde, para cada estado y cada símbolo del alfabeto de entrada, existe exactamente una transición definida. Esta propiedad de determinismo significa que el comportamiento del autómata es completamente predecible y no hay ambigüedad en la ejecución.
Componentes de un AFD

Un AFD se define formalmente como una quíntuple D=(Q,Σ,δ,q0,F)D=(Q,Σ,δ,q0​,F), donde:

    Q: Es un conjunto finito de estados.
    Σ (Sigma): Es un alfabeto de entrada, que es un conjunto finito de símbolos que el autómata puede procesar.
    δ (delta): Es una función de transición δ:Q×Σ→Qδ:Q×Σ→Q que define el estado al que se transita desde un estado dado cuando se lee un símbolo específico.
    q0q0​: Es el estado inicial donde el autómata comienza su operación, con q0∈Qq0​∈Q.
    F: Es un subconjunto de QQ que contiene los estados de aceptación. Si el autómata finaliza en alguno de estos estados después de procesar toda la cadena de entrada, se dice que la cadena es aceptada.

### Funcionamiento de un AFD

El funcionamiento de un AFD se puede describir de la siguiente manera:

    El autómata comienza en el estado inicial q0q0​.
    Lee el primer símbolo de la cadena de entrada.
    Utiliza la función de transición δδ para determinar el nuevo estado, basado en el estado actual y el símbolo leído.
    Repite el proceso para cada símbolo de la cadena.
    Después de leer toda la cadena, si el autómata se encuentra en un estado que pertenece al conjunto FF (estados de aceptación), la cadena es aceptada; de lo contrario, es rechazada.

### Ejemplos de Aplicación de AFD

    Validación de Cadenas: Un AFD puede ser utilizado para validar si una cadena pertenece a un lenguaje específico, como verificar si una secuencia de paréntesis está bien balanceada o si una cadena representa un número válido en cierto formato.

    Análisis Léxico: En la construcción de compiladores, los AFD se utilizan para reconocer tokens, que son las unidades básicas de significado en un lenguaje de programación.

    Sistemas de Control: Los AFD pueden modelar sistemas con un número finito de estados, como semáforos, ascensores, o máquinas expendedoras.

### Ventajas y Limitaciones

**Ventajas:**

    Simplicidad y facilidad de implementación.
    Procesamiento eficiente de cadenas de entrada.
    Adecuado para lenguajes regulares, que son comunes en muchas aplicaciones prácticas.

**Limitaciones:**

    Solo pueden reconocer lenguajes regulares, lo que limita su capacidad para procesar lenguajes más complejos.
    No pueden manejar estructuras de datos más complejas, como pilas o colas, que son necesarias para reconocer lenguajes libres de contexto.#### Quintupla

Tabla de Transiciones

La tabla de transiciones es una representación tabular de la función de transición δ. En esta tabla, las filas representan los estados y las columnas representan los símbolos del alfabeto. Cada celda de la tabla indica el estado al que se transita desde el estado actual cuando se lee un símbolo específico.
Estado|Símbolo 1|Símbolo 2| ... |Símbolo n|
-----------------------------------------
| q0  | q1  | q2  | ... | q3  |
| q1  | q2  | q1  | ... | q0  |
| ... | ... | ... | ... | ... |
| qn  | q0  | qn  | ... | q2  |
|     |     |     |     |     |



