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
            {"2", "Carlos González Ruiz", "carlos.gonzalez.ruiz@gmail.com", "+52 55 2222 3333"},
            {"3", "Lucía Fernández Díaz", "lucia.fernandez.diaz@gmail.com", "+52 55 3333 4444"},
            {"4", "Jorge Sánchez Pérez", "jorge.sanchez.perez@gmail.com", "+52 55 4444 5555"}
        }
    },
    
    // Ven 2
    {
        {"V002", "Maria Garcia", "maria.garcia@empresa.com","+52 55 2000 3000"},
        {
            {"5", "María Rodríguez García", "maria.rodriguez.garcia@gmail.com", "+52 55 5555 6666"},
            {"6", "Pedro Gómez Martín", "pedro.gomez.martin@gmail.com", "+52 55 6666 7777"},
            {"7", "Sofía Hernández Jiménez", "sofia.hernandez.jimenez@gmail.com", "+52 55 7777 8888"},
            {"8", "Alejandro López Castro", "alejandro.lopez.castro@gmail.com", "+52 55 8888 9999"}
        }
    },
    
    // Ven 3
    {
        {"V003", "Carlos Lopez", "carlos.lopez@empresa.com", "+52 55 3000 4000"},
        {
            {"9", "Elena Ramírez Navarro", "elena.ramirez.navarro@gmail.com", "+52 55 9999 0000"},
            {"10", "David Torres Ortega", "david.torres.ortega@gmail.com", "+52 55 0000 1111"},
            {"11", "Isabel Flores Méndez", "isabel.flores.mendez@gmail.com", "+52 55 1212 3434"},
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
    for(int i=0;i < NUM_PRODUCTOS; i++){
        printf("  %d-Nombre del Producto: %s \n    Descripcion: %s \n    Precio mayoreo %s Precio Menudeo: %s \n\n",i+1, productos[i][0], productos[i][1], productos[i][2], productos[i][3]);
    }
 
}

int seleccionar_Vendedor(){
    int v=0;
    do{
        printf("Vendedores en el sistema: \n");
        for(int i=0;i < 3; i++){
            printf("    %d-.  Nombre:  %s  Contacto: %s\n", i+1, clientes_vendedores[i][0][0][1],  clientes_vendedores[i][0][0][2]);    // Vendedor Nombre y contacto 
        }
        printf("Seleccione el numero del vendedor a registrar la compra: ");
        scanf("%d",&v);
    }while (v < 1 || v > 3);
    return v-1;
}

int seleccionar_cliente(int v){
    int c = 0;
    do{
        printf("Clientes del vendedores seleccionado: \n");
        for(int i=0;i < 4; i++){
            printf("    %s-.  Nombre:  %s  Contacto: %s\n", clientes_vendedores[v][1][i][0], clientes_vendedores[v][1][i][1],  clientes_vendedores[v][1][i][2]);    // Vendedor Nombre y contacto 
        }
        printf("Seleccione el numero del cliente de la compra: ");
        scanf("%d",&c);
    }while (c < 1 || c > 4);
    return c-1;
}

void finalizar_Comprar(){

}

void registrarCompra(){
    int v = seleccionar_Vendedor();
    int c = seleccionar_cliente(v);
    mostrar_Menu_Productos();
    int opcionProducto = 1, cantidad = 0;
    float precioProducto=0,precioTotalProducto=0, subtotal=0, total= 0;
    while (opcionProducto!=0){
        printf("%d %d \n",opcionProducto, cantidad);
        opcionProducto = 0, cantidad = 0;
        printf("Elige el numero del producto a elegir: "), scanf("%d",&opcionProducto);
        if(opcionProducto==0){
            break;
        }else if(opcionProducto==5){
            finalizar_Comprar();
        }
        printf(" Cantidad a escojer: "), scanf("%d", &cantidad);
        if(cantidad>=3 && cantidad <= 50){
            //Se activa el mayoreo
            precioProducto = atof(productos[opcionProducto-1][2]);
        }else if (cantidad > 0 ){
            //No se activa el mayoreo pipipipipi
            precioProducto = atof(productos[opcionProducto-1][3]);
        }else{
            printf("----ERROR----");
        }
        precioTotalProducto =   precioProducto * cantidad; 
        printf("%.2f\n", precioTotalProducto);
        subtotal+= precioTotalProducto;
        printf("%.2f\n", subtotal);

         precioTotalProducto = precioProducto * cantidad;
        subtotal += precioTotalProducto;
        
        printf("\nResumen parcial:\n");
        printf("Producto: %s\n", productos[opcionProducto-1][1]);
        printf("Cantidad: %d\n", cantidad);
        printf("Precio unitario: %.2f\n", precioProducto);
        printf("Total producto: %.2f\n", precioTotalProducto);
        printf("Subtotal acumulado: %.2f\n\n", subtotal);

    }
     
}

int main(){
    
    int opcion;
     do {
        printf("  ID: %s\n", clientes_vendedores[0][1][3][0]);       // Vendedor ID
        printf("  Nombre: %s\n", clientes_vendedores[0][1][3][1]);    // Vendedor Nombre
        printf("  Contacto: %s\n", clientes_vendedores[0][1][3][2]);

        printf("\n");
        printf("========================================\n");
        printf("|        SISTEMA DE VENTAS - EMPRESA   |\n");
        printf("========================================\n");
        printf("| 1. Registrar compra de cliente       |\n");
        printf("| 2. Mostrar reporte mensual de ventas |\n");
        printf("| 3. Calcular nomina de vendedores     |\n");
        printf("| 4. Salir del sistema                 |\n");
        printf("========================================\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion); 

        switch (opcion) {
            case 1:
                printf("\n-- REGISTRO DE COMPRA --\n");
                
                registrarCompra();
                //suma = atof(productos[0][2]) + atof(productos[0][3]);
                //printf("%.2f", suma);
                system("pause");
                break;
            case 2:
                printf("\n-- REPORTE DE VENTAS --\n");
                //printf("%s", clientes[2][0][0]);
                //printf("%s", clientes[2][1][0]);
                //printf("%s", vendedores[1][0]);
                //mostrarReporte();
                printf("  ID: %s\n", clientes_vendedores[0][0][0]);
            printf("  Nombre: %s\n", clientes_vendedores[0][0][1]);
            printf("  Contacto: %s\n", clientes_vendedores[0][0][2]);

                system("pause");
                break;
            case 3:
                printf("\n-- CALCULO DE NÓMINA --\n");
                
                for(int i = 0;i<3;i++){
                    printf("%s \n", clientes_vendedores[i][4]);
                }
                //calcularNomina();
                system("pause");
                break;
            case 4:
                printf("\nSaliendo del sistema... ¡Hasta luego!\n");
                break;
            default:
                printf("\nOpcion no valida. Intente de nuevo.\n");
                break;
        }
    } while (opcion != 4);
    
}