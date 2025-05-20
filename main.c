#include<stdio.h>
#include <stdlib.h> // Para atof()
#include <string.h>

#define NUM_PRODUCTOS 5
#define NUM_ATRIBUTOS 4  
#define CAPACIDAD_MAX 100
char productos[NUM_PRODUCTOS][NUM_ATRIBUTOS][CAPACIDAD_MAX]={ 
    // Producto 0 en el array
    {"Producto 1", 
     "Descripcion detallada del producto 1 con sus caracteristicas principales", 
     "999.99",   // Precio mayoreo
     "1299.99"}, // Precio menudeo
    
    // Producto 1 en el array
    {"Producto 2", 
     "Descripcion detallada del producto 2 con sus caracteristicas principales", 
     "1499.99", 
     "1799.99"},
    
    // Producto 2 en el array
    {"Producto 3", 
     "Descripcion detallada del producto 3 con sus caracteristicas principales", 
     "799.99", 
     "999.99"},
    
    // Producto 3 en el array
    {"Producto 4", 
     "Descripcion detallada del producto 4 con sus caracteristicas principales", 
     "1999.99", 
     "2399.99"},
    
    // Producto 4 en el array
    {"Producto 5", 
     "Descripcion detallada del producto 5 con sus caracteristicas principales", 
     "599.99", 
     "799.99"}
};


 char clientes_vendedores[3][2][4][4][150]={
    // Vendedor 1
    {
        // Datos del vendedor id nombre y contacto
        {"V001", "Juan Perez", "juan.perez@empresa.com","+52 55 1000 2000"},
        
        // Sus 4 clientes
        {
            {"1", "Ana Martinez Lopez", "ana.martinez.lopez@gmail.com", "+52 55 1111 2222"},
            {"2", "Carlos Gonzalez Ruiz", "carlos.gonzalez.ruiz@gmail.com", "+52 55 2222 3333"},
            {"3", "Lucia Fernandez Diaz", "lucia.fernandez.diaz@gmail.com", "+52 55 3333 4444"},
            {"4", "Jorge Sanchez Perez", "jorge.sanchez.perez@gmail.com", "+52 55 4444 5555"}
        }
    },
    
    // Ven 2
    {
        {"V002", "Maria Garcia", "maria.garcia@empresa.com","+52 55 2000 3000"},
        {
            {"5", "Maria Rodriguez Garcia", "maria.rodriguez.garcia@gmail.com", "+52 55 5555 6666"},
            {"6", "Pedro Gomez Martin", "pedro.gomez.martin@gmail.com", "+52 55 6666 7777"},
            {"7", "Sofia Hernandez Jimenez", "sofia.hernandez.jimenez@gmail.com", "+52 55 7777 8888"},
            {"8", "Alejandro Lopez Castro", "alejandro.lopez.castro@gmail.com", "+52 55 8888 9999"}
        }
    },
    
    // Ven 3
    {
        {"V003", "Carlos Lopez", "carlos.lopez@empresa.com", "+52 55 3000 4000"},
        {
            {"9", "Elena Ramirez Navarro", "elena.ramirez.navarro@gmail.com", "+52 55 9999 0000"},
            {"10", "David Torres Ortega", "david.torres.ortega@gmail.com", "+52 55 0000 1111"},
            {"11", "Isabel Flores Mendez", "isabel.flores.mendez@gmail.com", "+52 55 1212 3434"},
            {"12", "Ricardo Vargas Soto", "ricardo.vargas.soto@gmail.com", "+52 55 4545 6767"}
        }
    }
};  

/*     [grupo de vendedor][tanda dentro del vendedor][posicionamiento de la entidad][atributo individual de la entidad]                        

        printf("  ID: %s\n", clientes_vendedores[0][0][0][0]);       // Vendedor ID
        printf("  Nombre: %s\n", clientes_vendedores[0][0][0][1]);    // Vendedor Nombre
        printf("  Contacto: %s\n", clientes_vendedores[0][0][0][2]);
        
        printf("  ID: %s\n", clientes_vendedores[0][1][0][0]);       // Vendedor ID
        printf("  Nombre: %s\n", clientes_vendedores[0][1][0][1]);    // Vendedor Nombre
        printf("  Contacto: %s\n", clientes_vendedores[0][1][0][2]);
        
*/



void mostrar_Menu_Productos(){
        system("cls");
        printf("---------------------------------------------------------------------\n");
        printf("|                  LISTA DE ARTICULOS Y OPCIONES                     |\n");
        printf("---------------------------------------------------------------------\n");
    for(int i=0;i < NUM_PRODUCTOS; i++){
        printf("  %d- Nombre del Producto: %s \n    Descripcion: %s \n    Precio mayoreo $%s   Precio Menudeo: $%s \n\n",i+1, productos[i][0], productos[i][1], productos[i][2], productos[i][3]);
    }
 
}
 
void mostrar_Error(){
    printf("\n>>>Error - sistema no acepta la opcion\n");
    fflush(stdin);
    system("pause");
}
 
int seleccionar_Vendedor(){
    int v=0;
    system("cls");
    do{
        system("cls");
        printf("---------------------------------------------------------------------\n");
        printf("|                     VENDEDORES EN EL SISTEMA                      |\n");
        printf("---------------------------------------------------------------------\n");
        for(int i=0;i < 3; i++){
            printf("    %d-  Nombre:  %s  Contacto: %s \n", i+1, clientes_vendedores[i][0][0][1],  clientes_vendedores[i][0][0][2]);    // Vendedor Nombre y contacto 
        }
        printf("Seleccione el numero del vendedor(1-3): ");
        scanf("%d",&v);
        if (v < 1 || v > 3){
            mostrar_Error();
        }
        
    }while (v < 1 || v > 3);
    return v-1;
}

int seleccionar_cliente(int v){
    int c = 0;
    do{
        system("cls");
        printf("---------------------------------------------------------------------\n");
        printf("|                       CLIENTES DEL VENDEDOR                       |\n");
        printf("---------------------------------------------------------------------\n");
        printf("Los clientes del vendedores -%s: \n", clientes_vendedores[v][0][0][1]);
        for(int i=0;i < 4; i++){
            printf("    %d-.  Nombre:  %s  Contacto: %s\n", i + 1, clientes_vendedores[v][1][i][1],  clientes_vendedores[v][1][i][2]);    // Vendedor Nombre y contacto 
        }
        printf("Seleccione el numero del cliente de la compra(1-4): ");
        scanf("%d",&c);

        if (c < 1 || c > 4){
            mostrar_Error();
        }
    }while (c < 1 || c > 4);
    return c-1;
}

void finalizar_Comprar(float subtotal,int cantidadTotalProducto, int v, int c) {
    int d, m, a;
    float cantidadRecibida, pagoTotal, cambio;

    // fecha para luego firtral en el reporte, CHISPASSSSS
    system("cls");
    printf("---------------------------------------------------------------------\n");
    printf("|                         FINALIZAR COMPRA                          |\n");
    printf("---------------------------------------------------------------------\n\n");
    printf("    Dia (1-31): ");   scanf("%d", &d);
    printf("    Mes (1-12): ");   scanf("%d", &m);
    printf("    Year (Ejemplo. 2025): "); scanf("%d", &a);
    printf("---------------------------------------------------------------------\n\n");
    printf("Total a pagar:  $%.2f\n", subtotal);
    do {
        printf("Pago recibido:  $"), scanf("%f", &cantidadRecibida);
        pagoTotal+=cantidadRecibida;
        if (pagoTotal < subtotal)
            printf("  Faltan %.2f\n", subtotal - pagoTotal);
    } while (pagoTotal <= subtotal);
    cambio = (subtotal - pagoTotal) * -1;
    printf("---------------------------------------------------------------------\n\n");
    printf("Cambio:         $%.2f\n\n", cambio);

    // abirmos el archimo que esta sepado por comas y comas
    FILE *f = fopen("ventas.csv", "a");
    if (!f) {
        printf("Error al abrir ventas.csv\n");
        return;
    }
    //           día,mes,año,vendedor,cliente,total
    fprintf(f, "%02d,%02d,%04d,%d,%d,%d,%.2f\n",d, m, a,v, c,cantidadTotalProducto,subtotal);
    fclose(f);

    printf("Venta guardada en archivo.\n\n");
}

void registrarCompra(){
    int v = seleccionar_Vendedor();
    int c = seleccionar_cliente(v);

    //mostrar_Menu_Productos();
    int opcionProducto = 1, cantidadTotal = 0 , cantidadXProducto;
    float precioProducto=0,precioTotalProducto=0, subtotal=0, total= 0;
    while (opcionProducto!=0){

       
        opcionProducto = 0, cantidadXProducto = 0;
        system("cls");
        printf("\n Cuenta del cliente: %s---", clientes_vendedores[v][1][c][1] );
        mostrar_Menu_Productos();
        printf("\n  0- Salir al menu \n");
        printf("  6- Borrar venta(Completa) \n");
        printf("  7- Finalizar compra \n");
        printf("Elige el numero del producto a elegir: "), scanf("%d",&opcionProducto);
        if (opcionProducto > 7 || opcionProducto < 0){
            /* code */
            printf("Entro al if");
            mostrar_Error();
        }else if(opcionProducto == 0){
            break;
        }else if(opcionProducto == 6 ){
            // BORRAR toda la venta actual
            subtotal      = 0.0f;
            total         = 0.0f;
            cantidadTotal = 0;
            printf("\n>>> Venta actual borrada. Se han reiniciado todos los valores.\n\n");
            system("pause");
            continue; 
        }else if(opcionProducto == 7){
            finalizar_Comprar(subtotal,cantidadTotal, v, c);
            break;
        }else{
            printf(" Cantidad a escojer: "), scanf("%d", &cantidadXProducto);
            cantidadTotal+=cantidadXProducto;
            if(cantidadXProducto>=3 && cantidadXProducto <= 50){
                //Se activa el mayoreo
                precioProducto = atof(productos[opcionProducto-1][2]);
            }else if (cantidadXProducto > 0 ){
                //No se activa el mayoreo pipipipipi
                precioProducto = atof(productos[opcionProducto-1][3]);
            }else{
                printf("----ERROR----");
            }
            precioTotalProducto =   precioProducto * cantidadXProducto; 
            subtotal+= precioTotalProducto;
            total+=subtotal;
            

            printf("---------------------------------------------------------------------\n");
            printf("|                           RESUMEN PACIAL                          |\n");
            printf("---------------------------------------------------------------------\n");
            printf("    Producto:  %s\n", productos[opcionProducto-1][0]);
            printf("    Cantidad:           %d\n", cantidadXProducto);
            printf("    Precio unitario:    %.2f\n", precioProducto);
            printf("    Total producto:     %.2f\n", precioTotalProducto);
            printf("----------------------------------------------------------------------\n");
            printf("    Subtotal acumulado: %.2f\n\n", subtotal);
            system("pause");

        }
    

            
    }
     
}

void mostrar_reporte_mensual(){
    
    int mesBuscado;
    char linea[64]; // maximo de caracteres leeidos por linea en el archivo
    system("cls");
    printf("---------------------------------------------------------------------\n");
    printf("|                           REPORTE MESUAL                          |\n");
    printf("---------------------------------------------------------------------\n");

    printf("Que mes (1-12) quieres reportar? "), scanf("%d", &mesBuscado);

    // abrir el archivo             R de read en inglish
    FILE *f = fopen("ventas.csv", "r");
    if (!f) {
        printf("No se encontró el archivo ventas.csv\n");
        return;
    }
    
    
    printf("\n  Ventas del mes %d:\n\n", mesBuscado);

    int day, month, year, v, c, qty, cont = 0; // los datos que vamos a recibir del archivo .cvs, execto el cont ese es un contador para un ciclo
    float total, totalVendedor;

    // recorrer las lineas 
    while (fgets(linea, sizeof(linea), f)) {
        
        if (sscanf(linea, "%d,%d,%d,%d,%d,%d,%f",&day, &month, &year,&v, &c,&qty, &total) == 7) {
            
            if (month == mesBuscado) {
                cont++;
                printf("%2d) %02d/%02d/%04d | Id Vendedor: %s | Vendedor: %s | Cliente: %s | Cantidad: %d | Total: %.2f\n",cont,day, month, year,
                       clientes_vendedores[v][0][0][0], //es el id del vendedor
                       clientes_vendedores[v][0][0][1], // name del vendedor
                       clientes_vendedores[v][1][c][1],  //name del cliente
                       qty,
                       total);
            }
        }
    }

    if (cont == 0) {
        printf("No hubo ventas en ese mes.\n");
    }
    printf("\n");

    fclose(f);
}

float total_Venta_Vendedor(int IdVendedor, int mes){
    FILE *f = fopen("ventas.csv", "r");
    if (!f) {
        printf("No existe ventas.csv\n");
        return 0.0f;
    }

    char linea[64];
    int day, month, year, v, c, qty;
    float total, sumatoria = 0.0f;

    while (fgets(linea, sizeof(linea), f)) {
        if (sscanf(linea, "%d,%d,%d,%d,%d,%d,%f",
                   &day, &month, &year,
                   &v, &c, &qty, &total) == 7)
        {
            if (v == IdVendedor && month == mes) {
                sumatoria += total;
            }
        }
    }
    fclose(f);
    return sumatoria;
}


void calcular_Nomina(){
    int v = 0,m, horasTrabajadas=0;
    float pagoHora= 60, ventaTotalV,bonoVentas, bonoGas=200.00, subsueldo, impuesto, totalSueldo;
    system("cls");
    printf("---------------------------------------------------------------------\n");
    printf("|                           CALCULAR NOMINA                         |\n");
    printf("---------------------------------------------------------------------\n");
    system("pause");
    v = seleccionar_Vendedor();
    printf("---------------------------------------------------------------------\n");
    printf("Mes (1-12)?: "), scanf("%d", &m);
    
    printf("Cuantas horas trabajo(Di un numero de horas enterras): "), scanf("%d", &horasTrabajadas);
    subsueldo = pagoHora * horasTrabajadas;
    impuesto = subsueldo * 0.10;

    ventaTotalV = total_Venta_Vendedor(v, m);
    printf("Venta del vendedor es %.2f \n", ventaTotalV);
    bonoVentas = ventaTotalV * 0.05;
    totalSueldo+=subsueldo;
    totalSueldo-=impuesto;
    totalSueldo+=bonoGas;
    totalSueldo+=bonoVentas;
    printf("---------------------------------------------------------------------\n");
    printf("                       RESUMEN DE NOMINA\n");
    printf("---------------------------------------------------------------------\n");
    printf("Sueldo base    (%d h x %.2f) : $%.2f\n",horasTrabajadas, pagoHora, subsueldo);
    printf("(-) Retencion 10%%          :    -%.2f\n", impuesto);
    printf("(+) Bono gasolina         :     +%.2f\n", bonoGas);
    printf("(+) Comision 5%% sobre %.2f : +%.2f\n", ventaTotalV, bonoVentas);
    printf("----------------------------------------------------------------------\n");
    printf("  Sueldo neto               :  $%.2f\n\n", totalSueldo);

}


int main(){
    
    int opcion;
     do {
        printf("\n");
        system("cls");
        printf("=================================================================\n");
        printf("|                                                               |\n");
        printf("|                 SISTEMA DE VENTAS - EMPRESA                   |\n");
        printf("|                                                               |\n");
        printf("=================================================================\n");
        printf("|                 Opciones del sistema:                         |\n");
        printf("| 1. Registrar compra de cliente                                |\n");
        printf("| 2. Mostrar reporte mensual de ventas                          |\n");
        printf("| 3. Calcular nomina de vendedores                              |\n");
        printf("| 4. Salir del sistema                                          |\n");
        printf("|                                                               |\n");
        printf("=================================================================\n");
        printf("Seleccione una opcion(1-4): ");
        scanf("%d", &opcion); 

        switch (opcion) {
            case 1:
                //printf("\n-- REGISTRO DE COMPRA --\n");
                registrarCompra();
                system("pause");
                break;
            case 2:
                //printf("\n-- REPORTE DE VENTAS --\n");
                mostrar_reporte_mensual();
                system("pause");
                break;
            case 3:
                printf("\n-- CALCULO DE NÓMINA --\n");
                calcular_Nomina();

                system("pause");
                break;
            case 4:
                printf("\nSaliendo del sistema... ¡Hasta luego!\n");
                break;
            default:
                printf("\nOpcion no valida. Intente de nuevo.\n");
                system("pause");
                break;
        }
    } while (opcion != 4);
    
}