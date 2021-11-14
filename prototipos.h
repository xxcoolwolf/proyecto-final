#ifndef PROTOTIPOS_C
#define PROTOTIPOS_C


void registrar_clientes(); //funcion para registrar a los clientes en el struct
void listar_clientes();
void registrar_servicios();
void listar_servicios(int);
void detalles_cliente(int,int);
void generador_id(int *,char *);
void seleccionar_servicio(int *,int,int);
void verificacion_dni();
void modificar_clientes(int);
void modificar_servicios();
void fecha(int,int);
void modificar_servicios_clientes(int);
void fecha_diferenciador(int, int, int, int *, int *, int *, int);
void listar_contrataciones();
void listar_operaciones();
void generador_facturas(int,int,int,int);
void pago_facturas();
void estado_clientes();
void puesto(int *);
void mayor_contratacion();
void generador_txt(int);
void buscador_id_dni(int, int);
float realizar_descuento(float);
void listar_contratos_de_cliente(int);
void devolver_estado_cliente(int, int *);
void verificador_vencimiento_contrato();
#endif //PROTOTIPOS_C