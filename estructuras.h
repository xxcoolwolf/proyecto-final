#ifndef ESTRUCTURAS_C
#define ESTRUCTURAS_C

//definimos las estructuras para fechas
typedef struct {
    int year,mont,day,hour,min,sec;
} fechas;

//definimos la estructura de los clientes
typedef struct {
    int id,dni;
	long long int numero;
    char nombre[30],email[100],direccion[100];
} clientes;
//hola melani como estas
//definimos la estructura de los contratos
typedef struct {
    fechas fecha_firma,fecha_fin,fecha_factura,fecha_alta,fecha_baja;
    int id,estado_cliente,estado_factura,estado_renovacion; 
    float total,descuento,deuda;
} contratos;

//definimos la estructura para guardar los servicios que selecciono el cliente
typedef struct {
    fechas fecha_alta,fecha_baja;
    //lo vamos a identificar por un id
    int dni,id_servicio,estado_servicio;
    char nombre_servicio[30];
} servicios_clientes;

//definimos la estructura de los servicios
//beta
typedef struct {
    int id,tipo;
    char nombre[30];
    float precio;
} servicios;

#endif //ESTRUCTURAS_C