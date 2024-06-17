# Base de Datos
Les presentamos nuestro proyecto de app para agendar eventos, manejando una base de datos interna eficiente y accesible. Este proyecto ha sido desarrollado con el propósito de proporcionar una solución simple y efectiva para la gestión de eventos, permitiendo a los usuarios agregar, eliminar, buscar e imprimir eventos asociados a fechas específicas. La implementación se ha realizado usando estructuras de datos báscias y funciones estándares en C++, lo cual asegura un rendimiento óptimo y una facilidad de uso para el uso de los usuarios.

# El problema
Eres un desarrollador C++ en una empresa y se te ha solicitado crear un modelo de base de datos simple. Pero antes te piden investigar sobre todas las bases de datos existentes y hacer una comparativa para justificar esta implementacion. Entonces, primero se debe realizar dicha comparativa estudiar las existentes y escribir una justificacion del desarrollo de un nuevo manejador de base de datos. Luego, es necesario analizar el problema y escribir un programa en C++ que implemente el trabajo con una base de datos simple (abreviado «BD»). El programa se comunicará con el usuario a través de la entrada y salida estándar (flujos stdin y stdout). Almacenaremos en nuestra BD pares del tipo: fecha, evento. Definiremos la fecha como una cadena en el formato Año-Mes-Día, donde Año, Mes y Día son números enteros. Definiremos el evento como una cadena de caracteres imprimibles arbitrarios sin separadores dentro (espacios, tabulaciones, etc.). Un evento no puede ser una cadena vacía. En una misma fecha pueden ocurrir muchos eventos diferentes, la BD debe ser capaz de almacenarlos todos. No es necesario guardar eventos idénticos que ocurran el mismo día: basta con guardar solo uno de ellos. Nuestra BD debe entender ciertos comandos para que se pueda interactuar con ella:
- agregar evento: Add Fecha Evento
- eliminar evento: Del Fecha Evento
- eliminar todos los eventos de una fecha específica: Del Fecha
- buscar eventos en una fecha específica: Find Fecha
- imprimir todos los eventos de todas las fechas: Print
Todos los comandos, fechas y eventos en la entrada están separados por espacios. Los comandos se leen desde la entrada estándar. En una línea puede haber exactamente un comando, pero se pueden ingresar varios comandos en varias líneas. También pueden haber líneas vacías en la entrada, las cuales deben ser ignoradas, y continuar procesando los nuevos comandos en las líneas siguientes.
## Agregar evento (Add Fecha Evento)
Al agregar un evento, la BD debe recordarlo y luego mostrarlo durante la búsqueda (comando Find) o impresión (comando Print). Si el evento especificado para una fecha determinada ya existe, se debe ignorar la repetición de su adición. En caso de una entrada correcta, el programa no debe mostrar nada en la pantalla.
## Eliminar evento (Del Fecha Evento)
El comando debe eliminar un evento agregado anteriormente con el nombre especificado en la fecha indicada, si existe. Si el evento se encuentra y se elimina, el programa debe mostrar la línea "Deleted successfully" (sin comillas). Si no se encuentra el evento en la fecha especificada, el programa debe mostrar la línea "Event not found" (sin comillas).
## Eliminar varios eventos (Del Fecha)
El comando elimina todos los eventos previamente agregados para la fecha indicada. El programa siempre debe mostrar una línea en el formato "Deleted N events", donde N es la cantidad de eventos encontrados y eliminados. N puede ser igual a cero si no hubo ningún evento en la fecha especificada.
## Buscar eventos (Find Fecha)
Encuentra e imprime los eventos previamente agregados en la fecha indicada. El programa debe imprimir solo los eventos, uno por línea. Los eventos deben estar ordenados en orden ascendente según la comparación de cadenas (tipo string).
## Imprimir todos los eventos (Print)
Con este comando se puede mostrar todo el contenido de nuestra BD. El programa debe imprimir todas las parejas Fecha Evento, una por línea. Todas las parejas deben estar ordenadas por fecha, y los eventos dentro de una misma fecha deben estar ordenados en orden ascendente según la comparación de cadenas (tipo string). Las fechas deben estar formateadas de manera especial: AAAA-MM-DD, donde A, M, D son los dígitos de los números del año, mes y día respectivamente. Si algún número tiene menos dígitos, debe completarse con ceros, por ejemplo, 0001-01-01 es el primero de enero del primer año. No necesitarás imprimir una fecha con un valor de año negativo.
## Manejo de errores de entrada
La entrada en esta tarea no siempre es correcta: tu programa debe manejar correctamente algunos errores de entrada.
### Qué errores de entrada manejar
Si el usuario ingresa un comando desconocido, el programa debe informar de ello, mostrando la línea "Unknown command: COMMAND", donde COMMAND es el comando que ingresó el usuario. Se considera comando la primera palabra en la línea (hasta el espacio). 
Si la fecha no corresponde al formato Año-Mes-Día, donde Año, Mes y Día son números enteros arbitrarios, el programa debe imprimir "Wrong date format: DATE", donde DATE es lo que el usuario ingresó en lugar de la fecha (hasta el espacio). Ten en cuenta que las partes de la fecha están separadas por un guion exacto, y la fecha no debe contener caracteres adicionales ni antes del año ni después del día. Las partes de la fecha no pueden estar vacías, pero pueden ser cero o incluso negativas.
Si el formato de la fecha es correcto, se debe verificar la validez del mes y el día.
Si el número del mes no es un número del 1 al 12, muestra "Month value is invalid: MONTH", donde MONTH es el número de mes incorrecto, por ejemplo, 13 o -1.
Si el mes es correcto, pero el día no está en el rango de 1 a 31, muestra "Day value is invalid: DAY", donde DAY es el número de día incorrecto en el mes, por ejemplo, 39 o 0.
Ten en cuenta que:
- No es necesario verificar el valor del año por separado.
- No es necesario verificar la corrección del calendario: se considera que el número de días en cada mes es 31, no se necesita considerar años bisiestos.
Si tanto el mes como el día son incorrectos, se debe mostrar solo un mensaje de error sobre el mes.
### Ejemplos:
1-1-1 — fecha correcta
-1-1-1 — fecha correcta (año -1, mes 1, día 1)
1--1-1 — fecha en formato correcto, pero con un mes incorrecto -1
1---1-1 — fecha en formato incorrecto: el mes no puede comenzar con dos guiones
1-+1-+1 — fecha correcta, ya que +1 es un número entero
  Después de manejar cualquiera de los errores de entrada descritos y mostrar el mensaje, el
programa debe terminar su ejecución.
### Qué errores de entrada no manejar
No se busca romper tu programa de todas las formas posibles, por lo tanto, aparte de lo
descrito en el punto anterior, puedes confiar en la corrección de la entrada. En particular, se
garantiza que:
- Cada comando ocupa exactamente una línea completa, aunque en la entrada puede haber líneas vacías (que deben ser ignoradas).
- Los eventos siempre contienen el número indicado de argumentos: después del comando Add siempre siguen la fecha y el evento, después del comando Find siempre sigue la fecha, después del comando Del siempre sigue la fecha y, posiblemente, el evento, y el comando Print no contiene información adicional.
- Todos los comandos, fechas y eventos son cadenas no vacías y no contienen espacios u otros caracteres de espacio. (En particular, nuestras pruebas no contienen el comando "Add 2018-02-12", ya que no tiene un nombre de evento después de la fecha). Por otro lado, el comando Del puede no contener un evento después de la fecha: en este caso, se deben eliminar todos los eventos para la fecha especificada (ver sección "Eliminar varios eventos").
- Aunque una fecha con un valor de año negativo se considera correcta, las pruebas están diseñadas de tal manera que no necesitarás imprimirla en el comando Print.
## Ejemplos
### Entrada correcta:
Add 0-1-2 event1
Add 1-2-3 event2
Find 0-1-2

Del 0-1-2
Print
Del 1-2-3 event2
Del 1-2-3 event2
### Salida:
event1
Deleted 1 events
0001-02-03 event2
Deleted successfully
Event not found
### Entrada Incorrecta
Add 0-13-32 event1
### Salida:
Month value is invalid: 13
## Observaciones
Conversión de un número a una cadena Para, teniendo el número MONTH, formar la cadena
«El valor del mes no es válido: MONTH», se puede utilizar la función to_string, que convierte
el número a una cadena. De esta manera, se puede formar la cadena necesaria de la
siguiente manera:
string error = "Month value is invalid: " + to_string(month); 
## Búsqueda en un diccionario constante
Al implementar este patrón, es posible que necesites utilizar la búsqueda con corchetes para
un diccionario pasado a la función por referencia constante. Como se mostró anteriormente,
esto no será posible, ya que el acceso a una clave inexistente con corchetes la agregará al
diccionario, lo cual no es permisible para un diccionario constante.
En este caso, en lugar de corchetes, utiliza el método at: en caso de ausencia de la clave,
lanzará una excepción y, por lo tanto, puede ser utilizado para un objeto constante.
Por ejemplo, en lugar del código
void DoSomething(const map<int, int>& m) {
// ...
if (m.count(key) > 0) {
value = m[key]; / No compilara
}
// ...
}

Use este codigo:
void DoSomething(const map<int, int>& m) {
// ...
if (m.count(key) > 0) {
value = m.at(key); / Todo bien
}
// ...
}

## Bases de Datos Existentes
Una base de datos es un sistema para gestionar eficientemente grandes cantidades de información.
 A continuación se muestra una comparación de algunos tipos y ejemplos  de bases de datos comunes.
 - 1. Base de datos relacional (RDBMS) Ejemplos:  MySQL, PostgreSQL, SQLite.
 Características de : Utilice tablas  para almacenar datos y habilitar relaciones entre ellos.
 SQL (lenguaje de consulta estructurado) se utiliza para la gestión de datos.
 Beneficios de : Eficiencia, integridad referencial y coherencia para consultas complejas.
 Desventajas: Puede ser demasiado complejo para aplicaciones simples y requiere un sistema predefinido.
 MySQL MySQL es una base de datos muy popular y ampliamente utilizada que facilita la búsqueda de soluciones a problemas y la obtención de soporte.
 Funciona en múltiples plataformas y es compatible con muchos lenguajes de programación.
 Sin embargo, son menos flexibles que las bases de datos NoSQL.
 Al ser de código abierto, no cuenta con el respaldo oficial de una empresa acreditada y tiene una seguridad de  menor calidad  que una base de datos propietaria.
 PostgreSQL PostgreSQL es altamente extensible y le permite crear tipos de datos  y funciones personalizados.
 Además, está optimizado para garantizar la confiabilidad de las transacciones y  manejar consultas complejas y grandes cantidades de datos.
 Sin embargo, debido a que es altamente personalizable, su configuración y mantenimiento requieren más tiempo y esfuerzo, lo que la convierte en una de las bases de datos más complejas de administrar inicialmente.
 - 2. Bases de datos NoSQL Ejemplos: MongoDB, Cassandra, Redis.
 Características de : está diseñado para manejar  grandes cantidades de datos distribuidos y no estructurados.
 Los tipos comunes incluyen bases de datos de documentos, bases de datos en columnas y bases de datos de clave/valor.
 Beneficios de : Escalabilidad y flexibilidad al trabajar con datos no estructurados.
 Desventajas: Mala coherencia transaccional y falta de estándares de consulta universales.
 MongoDB MongoDB es una base de datos no relacional, por lo que es muy flexible y no requiere un esquema fijo.
 Está diseñado para manejar grandes cantidades de datos.
 También es muy rápido, lo que facilita la integración en aplicaciones modernas.
 Sin embargo, dada la cantidad de datos de entrada, normalmente requiere una gran cantidad de memoria.
 - 3. Bases de datos en memoria Ejemplos: Redis, Memcached.
 Características: Almacena datos en  RAM para un acceso muy rápido.
 Ventajas de : Velocidad y eficiencia del acceso a datos de .
 Desventajas: Volatilidad de los datos y limitaciones del tamaño de almacenamiento.
 Redis Redis es una base de datos muy rápida y es ideal para operaciones de lectura y escritura.
 Admite múltiples estructuras de datos, como cadenas, listas y conjuntos.
 Sin embargo, está limitado por la cantidad de RAM disponible y su estructura no es muy robusta.
 Además, se utiliza  para el almacenamiento en caché y el almacenamiento temporal (RAM) de datos en lugar de una base de datos a largo plazo.
 - 4. Base de datos orientada a objetos Ejemplo: db4o, ObjectDB.
 Función: Almacena datos en forma de objetos utilizados en la programación orientada a objetos.
 Ventajas de : Integración directa con  lenguajes de programación orientados a objetos, fácil gestión de datos complejos.
 Desventajas: Menos popular y menos compatible con herramientas  de análisis de datos estándar.

 ## Justificación del Nuevo Desarrollo
 - Hay varias razones importantes para crear una nueva base de datos específicamente para nuestro proyecto.
 - Sencillez e idoneidad para su proyecto: Las bases de datos existentes pueden ser demasiado complejas y no adaptarse completamente a las necesidades de su empresa, por lo que necesita un sistema sencillo para manejarlas.
 evento.
 - Optimización de recursos: El uso de una base de datos existente puede consumir recursos innecesarios y llevar tiempo configurar y administrar funciones no utilizadas.
 El desarrollo personalizado es más fácil y está optimizado para cada propósito.
 - Control total del desarrollo: Desarrollar un sistema  desde cero proporciona un control total y le da al cliente confianza en su operación, lo que permite realizar ajustes a medida que cambian los requisitos.
 - Seguridad y confidencialidad: La necesidad de almacenar datos confidenciales requiere una base de datos confiable que no esté regulada por  una organización internacional.
 Al crear su propia base de datos, puede cumplir con los requisitos de seguridad y protección de datos de su empresa.

## Descripcion de Funciones y Estructuras

El repositorio consta de 4 elementos importantes que son:
- examen.h (Todos los prototipos)
- main.cpp (El main de nuestro codigo)
- examen.cpp (Todos los cuerpos de las funciones)
- README.md (Toda la explicacion detallada)

## Descripcion de Funciones y Estructuras

struct Date
Esta estructura mantiene los componentes de año, mes y día de una fecha ingresada por el usuario. Todos los componentes son de tipo entero para su uso a lo largo de todas las funciones.

void add_event(map<string, set<string>>& events, const string& date_str, const string& event);
Esta función agrega un evento a la fecha especificada. Recibe como parámetros un mapa de eventos, la fecha a la que se debe agregar el evento (de tipo Date) y la descripción del evento (de tipo string) que el usuario desea agregar.

bool delete_event(map<string, set<string>>& events, const string& date_str, const string& event);
Esta función elimina un evento específico de una fecha especificada. Retorna un valor booleano que indica si el evento fue eliminado con éxito o no. Los parámetros son el mapa de eventos, la fecha (de tipo Date) y la descripción del evento (de tipo string) a eliminar.

bool validate_date(const string& date_str, string& error_msg);
Esta función valida el formato y los valores de una fecha, verificando si son válidos. Recibe como parámetros el año, mes y día (todos de tipo int) y una referencia a una cadena (string) que contendrá el mensaje de error si la fecha es inválida.

int delete_date(map<string, set<string>>& events, const string& date_str);
Esta función elimina todos los eventos de una fecha específica. Los parámetros son el mapa de eventos y la fecha (de tipo Date) de la cual se deben eliminar todos los eventos. Retorna un entero que indica el número de eventos eliminados.

set<string> find(map<string, set<string>>& events, const string& date_str);
Esta función encuentra y retorna todos los eventos en una fecha específica. Recibe como parámetros el mapa de eventos y la fecha (de tipo Date).

void print_events();
Esta función imprime todos los eventos para todas las fechas almacenadas en el mapa de eventos. No recibe parámetros adicionales aparte del mapa de eventos.

## Diagrama De Flujo 
![alt text](<Diagrama sin título.drawio.png>)


## Créditos
- Lucas Alberto Soria Soliz
- Ariany Lopéz (mas que nada en el inicio)

## Herramientas utilizadas