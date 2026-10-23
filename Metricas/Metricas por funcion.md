# Metricas por funcion

El metodo de punto de funcion de Allen Albrecht es una tecnica estandarizada para medir el tamaño funcional de un sistema de software. Esta metodologia se basa en la idea de que el valor de un sistema de software puede ser medido en terminos de las funciones que proporciona a los usuarios, en lugar de medirlo en terminos de lineas de codigo o complejidad tecnica.

La complejidad de un sistema de software se mide con respecto a los puntos de entrada por items.

Se clasifican en cinco tipos de funciones:
1. Entradas Externas (EE): Son los procesos o transacciones que reciben datos o control desde el exterior del sistema. Estos pueden incluir formularios de entrada, interfaces de usuario, o cualquier otro mecanismo que permita a los usuarios interactuar con el sistema.
2. Salidas Externas (SE): Son los procesos o transacciones que envian datos o control desde el sistema hacia el exterior. Estos pueden incluir informes, mensajes, o cualquier otro mecanismo que permita al sistema comunicarse con los usuarios o con otros sistemas.
3. Consultas Externas (CE): Son los procesos o transacciones que permiten a
  los usuarios obtener informacion del sistema sin modificar su estado. Estos pueden incluir consultas de bases de datos, busquedas, o cualquier otro mecanismo que permita a los usuarios acceder a la informacion almacenada en el sistema.
4. Archivos Lógicos Internos (ALI): Son los grupos de datos o archivos que son mantenidos y gestionados por el sistema. Estos pueden incluir bases de datos, archivos de configuracion, o cualquier otro mecanismo que permita al sistema almacenar y organizar la informacion.
5. Archivos de Interfaz Externa (AIE): Son los grupos de datos o archivos que son utilizados por el sistema pero que son mantenidos por otros sistemas. Estos pueden incluir archivos compartidos, servicios web, o cualquier otro mecanismo que permita al sistema interactuar con otros sistemas.

Cada una de estas funciones se clasifica en tres niveles de complejidad: baja, media y alta. La complejidad se determina en funcion de varios factores, como el numero de campos de datos, el numero de archivos involucrados, y la cantidad de logica de negocio requerida para procesar la funcion.

## Cuenta total

| Descripcion | Simple | Promedio | Complejo |
|-------------|--------|----------|----------|
| Entradas Externas (EE) | 3 | 4 | 6 |
| Salidas Externas (SE) | 4 | 5 | 7 |
| Consultas Externas (CE) | 3 | 4 | 6 |
| Archivos Lógicos Internos (ALI) | 7 | 10 | 15
| Archivos de Interfaz Externa (AIE) | 5 | 7 | 10 |
| **Cuenta Total** | | | |
| **Total Puntos de Funcion No Ajustados (PFNA)** | | | |
| **Total Puntos de Funcion Ajustados (PFA)** | | | |
| **Total Horas Estimadas** | | | |

## Calculo de Puntos de Funcion

PFA = Cuenta Total * [0.65 + 0.01 * SUMA DE 14 FACTORES DE COMPLEJIDAD]

## Grado total de influencia ( 14 factores )

Valores de Di
- 0: Sin influencia
- 1: Influencia Incidental
- 2: Influencia Moderada
- 3: Influencia Mediada
- 4: Influencia Significativa
- 5: Influencia Esencial

## Metricas por funcion - Medicion

Productividad = PF / Esfuerzo (horas)
Calidad = Errores / PF
Costo = Moneda / PF
