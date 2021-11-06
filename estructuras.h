#ifndef ESTRUCTURAS_C
#define ESTRUCTURAS_C
//definimos la estructura de los clientes
typedef struct {
    int id,dni,estado_cliente,fecha_alta,fecha_baja,estado_factura;//estado_cliente(0,1 = inactivo, activo), estado_factura(0,1 = no pagado, pagado)
	long long int numero;
    char nombre[30],email[100],direccion[100];
    float total;
} clientes;

//definimos la estructura para guardar los servicios que selecciono el cliente
typedef struct {
    //lo vamos a identificar por un id
    int dni,id_servicio,estado_servicio,fecha;
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