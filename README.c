#include <stdio.h>
#include <string.h>

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int id, stock = 0, cantidad, opcion, descuento;
    float precio = 0, total_ganancias = 0, venta = 0, precio_con_descuento;
    char nombre[30], respuesta[3];
    int producto_registrado = 0;

    do {
        printf("\nMen\u00fa de Opciones:\n");
        printf("1. Registrar producto\n");
        printf("2. Vender producto\n");
        printf("3. Reabastecer produ0cto\n");
        printf("4. Mostrar informaci\u00f3n del producto\n");
        printf("5. Mostrar total de ganancias\n");
        printf("6. Salir\n");
        printf("Seleccione una opci\u00f3n: ");
        
        if (scanf("%d", &opcion) != 1) {
            limpiarBuffer();
            printf("Opci\u00f3n inv\u00e1lida. Intente nuevamente.\n");
            continue;
        }
        limpiarBuffer();

        switch(opcion) {
            case 1:
                printf("Ingrese el ID del producto: ");
                scanf("%d", &id);
                limpiarBuffer();

                printf("Ingrese el nombre del producto: ");
                fgets(nombre, 30, stdin);
                nombre[strcspn(nombre, "\n")] = '\0';

                do {
                    printf("Ingrese la cantidad inicial en stock: ");
                    if (scanf("%d", &stock) != 1 || stock < 1) {
                        printf("La cantidad inicial del stock debe ser mayor a 0\n");
                        limpiarBuffer();
                    }
                } while(stock < 1);

                do {
                    printf("Ingrese el precio unitario del producto: ");
                    if (scanf("%f", &precio) != 1 || precio < 1) {
                        printf("El precio unitario del producto debe ser mayor que 0\n");
                        limpiarBuffer();
                    }
                } while(precio < 1);
                limpiarBuffer();

                producto_registrado = 1;
                break;
            
            case 2:
                if(producto_registrado == 0) {
                    printf("No se ha registrado ning\u00fan producto. Para seguir registre un producto en la opci\u00f3n 1\n");
                    break;
                }

                do {
                    printf("Ingrese la cantidad a vender: ");
                    if (scanf("%d", &cantidad) != 1) {
                        limpiarBuffer();
                        cantidad = -1; 
                    }

                    if(cantidad < 1) {
                        printf("La cantidad debe ser mayor a cero, vuelva a ingresar la cantidad\n");
                    } else if(cantidad > stock) {
                        printf("No existe el stock necesario para esta venta, vuelva a ingresar la cantidad\n");
                    }
                } while(cantidad < 1 || cantidad > stock);

                if (cantidad >= 10) {
                    descuento = 10;
                } else if (cantidad >= 5) {
                    descuento = 5;
                } else {
                    descuento = 0;
                }

                precio_con_descuento = precio * (1 - (descuento / 100.0));
                venta = cantidad * precio_con_descuento;
                total_ganancias += venta;
                stock -= cantidad;

                printf("El precio de la venta con descuento del %d%% es: %.2f\n", descuento, venta);
                printf("Stock restante: %d\n", stock);
                break;

            case 3:
                if(producto_registrado == 0) {
                    printf("No se ha registrado ning\u00fan producto. Para seguir registre un producto en la opci\u00f3n 1\n");
                    break;
                }
                
                do {
                    printf("Ingrese la cantidad a agregar al stock: ");
                    if (scanf("%d", &cantidad) != 1 || cantidad <= 0) {
                        printf("La cantidad a agregar debe ser mayor que 0\n");
                        limpiarBuffer();
                    }
                } while(cantidad <= 0);
                
                stock += cantidad;
                printf("Stock actualizado. Nuevo stock: %d\n", stock);
                break;

            case 4:
                if(producto_registrado == 0) {
                    printf("No se ha registrado ning\u00fan producto. Para seguir registre un producto en la opci\u00f3n 1\n");
                    break;
                }
                
                printf("\nInformaci\u00f3n del producto:\n");
                printf("ID:\t\t\t%d\n", id);
                printf("Nombre:\t\t%s\n", nombre); 
                printf("Stock disponible:\t%d\n", stock);
                printf("Precio unitario:\t$%.2f\n", precio);
                break;

            case 5:
                if(producto_registrado == 0) {
                    printf("No se ha registrado ning\u00fan producto. Para seguir registre un producto en la opci\u00f3n 1\n");
                    break;
                }

                printf("Total de ganancias: $%.2f\n", total_ganancias);
                break;

            case 6:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opci\u00f3n inv\u00e1lida. Intente nuevamente.\n");
        }
    } while (opcion != 6);

    return 0;
}
