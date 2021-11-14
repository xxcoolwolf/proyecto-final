#ifndef ESTRUCTURAS_C
#define ESTRUCTURAS_C

//definimos las estructuras para fechas
typedef struct {
    int year,mont,day,hour,min,sec;
} fechas;
//contrato_id.txt

//definimos la estructura de los clientes
typedef struct {
    int id,dni,estado_cliente;
	long long int numero;
    char nombre[30],email[100],direccion[100];
} clientes;

//definimos la estructura de los contratos
typedef struct {
    fechas fecha_firma,fecha_fin,fecha_factura,fecha_alta,fecha_baja;
    int id_contrato,id,dni,estado_contrato,estado_factura,estado_renovacion; 
    float total,descuento,deuda;
} contratos;

//definimos las estructura de las facturas
typedef struct {
    fechas fecha_pago,fecha_proximo,fecha_vencimiento;
    int id_contrato,id,estado_cliente,estado_factura; 
} facturas;

//definimos la  estructura para guardar los servicios que selecciono el cliente
typedef struct {
    fechas fecha_alta,fecha_baja;
    //lo vamos a identificar por un id
    int id_contrato,dni,id_servicio,estado_servicio;
    char nombre_servicio[30];
    float precio;
} servicios_clientes;

//definimos la estructura de los servicios
//beta
typedef struct {
    int id,tipo;
    char nombre[30];
    float precio;
} servicios;

#endif //ESTRUCTURAS_C