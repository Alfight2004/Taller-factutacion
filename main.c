#include <stdio.h>

int main(void) {
    char nombre[30];
    char fecha1[10];
    char cedula[10];
    char telefono[10];
    int opcion;

    printf("Ingrese el nombre y apellido:\n");
    gets(nombre);

    printf("Ingrese la fecha:\n");
    scanf("%s", fecha1);

    printf("Ingrese la cedula:\n");
    scanf("%s", cedula);

    printf("Ingrese su numero de telefono:\n");
    scanf("%s", telefono);

    int deseaComprar = 0;
    double total = 0;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Desea comprar productos\n");
        printf("2. Ingrese mas productos\n");
        printf("3. Gracias por su compra\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                deseaComprar = 1;
                while (deseaComprar) {
                    printf("Productos:\n");
                    printf("1. Llantas (Precio: $150)\n");
                    printf("2. Kit Pastillas de freno (Precio: $55)\n");
                    printf("3. Kit de embrague (Precio: $180)\n");
                    printf("4. Faro (Precio: $70)\n");
                    printf("5. Radiador (Precio: $120)\n");

                    int producto;
                    int unidades;
                    double precio = 0;

                    printf("Seleccione el producto (1-5) o 0 para finalizar la compra: ");
                    scanf("%d", &producto);
                    if (producto == 0) {
                        break;
                    }

                    printf("Ingrese la cantidad de unidades: ");
                    scanf("%d", &unidades);

                    switch (producto) {
                        case 1:
                            precio = 150;
                            break;
                        case 2:
                            precio = 55;
                            break;
                        case 3:
                            precio = 180;
                            break;
                        case 4:
                            precio = 70;
                            break;
                        case 5:
                            precio = 120;
                            break;
                        default:
                            printf("Producto no válido.\n");
                            continue;
                    }

                    double subtotal = unidades * precio;
                    total += subtotal;

                    printf("Subtotal para este producto: $%.2lf\n", subtotal);
                }
                break;

            case 2:
                printf("Desea agregar más productos?\n");
                deseaComprar = 1;
                break;

            case 3:
                if (deseaComprar) {
                    double descuento = 0;

                    if (total <= 100) {
                        descuento = 0;
                    } else if (total <= 500) {
                        descuento = 0.05;
                    } else if (total <= 1000) {
                        descuento = 0.07;
                    } else {
                        descuento = 0.10;
                    }

                    double descuentoDinero = total * descuento;
                    double totalConDescuento = total - descuentoDinero;

                    printf("\nFactura:\n");
                    printf("Nombre y Apellido: %s\n", nombre);
                    printf("Fecha: %s\n", fecha1);
                    printf("Cedula: %s\n", cedula);
                    printf("Teléfono: %s\n", telefono);
                    printf("Subtotal: $%.2lf\n", total);
                    printf("Descuento aplicado: %.2lf%%\n", descuento * 100);
                    printf("Total con descuento: $%.2lf\n", totalConDescuento);

                    printf("Gracias por su compra.\n");

                    deseaComprar = 0;
                } else {
                    printf("Gracias por su compra.\n");
                }
                break;

            default:
                printf("Opción no válida. Por favor, seleccione una opción válida.\n");
        }

        if (opcion == 3) {
            break;
        }
    }

    return 0;
}
