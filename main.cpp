#include<iostream>
using namespace std;

// Estructuras para las entidades
struct Producto {
	string nombre;
	int precio;
	int cantidad;
	bool donacionFopre;
};

struct Cliente {
	int saldoMonedas = 0;
};

struct Transaccion {
	int totalCompras = 0;
	double valorTotalCompras = 0;
	int donacionTotalFopre = 0;
	int valorDonacionProducto[4] = {0, 0, 0, 0};
	int unidadDonacionProducto[4] = {0, 0, 0, 0};
	int productosComprados[4] = {0, 0, 0, 0};
};

struct FOPRE {
	double totalDonaciones = 0;
};

struct MaquinaExpendedora {
	Producto productos[4];
	int cantidadMaximaProductos = 0;
};

int main() {
	// Inicializando la maquina expendedora
	MaquinaExpendedora maquina;
	Cliente cliente;
	Transaccion transaccion;
	FOPRE fopre;

	// Definiendo los productos
	maquina.productos[0] = {"Hit individual", 2800, 12, true};
	maquina.productos[1] = {"Oreo x 4 undides", 1200, 12, false};
	maquina.productos[2] = {"Gansito x unidad", 1800, 12, true};
	maquina.productos[3] = {"SpeedMax litro", 4000, 12, false};

	for (int i = 0; i < 4; i++) {
		maquina.cantidadMaximaProductos += maquina.productos[i].cantidad;
	}

	int opcion, opcionProducto;
	bool salirMenu = false, confirmarCompra = false, confirmarMonedas = false;

	// Bucle menC::
	do {
		cout << "\n-------MAQUINA EXPENDEDORA--------";
		cout << "\n1. Mostrar productos disponibles";
		cout << "\n2. Agregar credito - monedas a la maquina";
		cout << "\n3. Comprar producto";
		cout << "\n4. Calcular cantidad total de unidades compradas";
		cout << "\n5. Calcular valor total por las compras realizadas";
		cout << "\n6. Calcular el porcentaje de disponibilidad de la maquina";
		cout << "\n7. Consultar el producto mas comprado";
		cout << "\n8. Calcular el valor de la donacion total al FOPRE por las compras realizadas";
		cout << "\n9. Conocer el valor de la donacion al FOPRE por tipo de producto";
		cout << "\n10. Conocer las unidades compradas de productos FOPRE y por tipo de producto";
		cout << "\n0. Salir de la maquina";
		cout << "\n\nOpcion: ";
		cin >> opcion;

		switch (opcion) {
		case 1: {
			// Mostrar productos
			for (int i = 0; i < 4; i++) {
				cout << "\n\nNombre producto: " << maquina.productos[i].nombre;
				cout << "\nPrecio: " << maquina.productos[i].precio;
				cout << "\nCantidad disponible: " << maquina.productos[i].cantidad;
				cout << "\nPertenece a FOPRE: " << (maquina.productos[i].donacionFopre ? "SI" : "NO");
			}
			break;
		}
		case 2: {
			do {
				cout << "\n\nPresiona...";
				cout << "\n1. Moneda de 100";
				cout << "\n2. Moneda de 200";
				cout << "\n3. Moneda de 500";
				cout << "\n4. Moneda de 1000";
				cout << "\n5. Confirmar monedas";

				cout << "\n\nTienes " << cliente.saldoMonedas << " pesos de saldo";
				cout << "\n\nOpcion: ";
				cin >> opcion;

				switch (opcion) {
				case 1: {
					cliente.saldoMonedas += 100;
					break;
				}
				case 2: {
					cliente.saldoMonedas += 200;
					break;
				}
				case 3: {
					cliente.saldoMonedas += 500;
					break;
				}
				case 4: {
					cliente.saldoMonedas += 1000;
					break;
				}
				case 5: {
					confirmarMonedas = true;  // Se marca como confirmada la opción de monedas
					break;
				}
				default: {
					cout << "\nOpcion invalida. Intenta de nuevo.";//validador para que el usuario escoja una opción correcta para agregar monedas
				}
				}

			} while (!confirmarMonedas);  // Sale del bucle cuando se confirma
			break;
		}
		case 3: {
			do {
				confirmarCompra = false;

				for (int i = 0; i < 4; i++) {
					cout << "\n\nPrecione " << i + 1 << " para comprar:";
					cout << "\nNombre producto: " << maquina.productos[i].nombre;
					cout << "\nPrecio: " << maquina.productos[i].precio;
					cout << "\nCantidad disponible: " << maquina.productos[i].cantidad;
				}

				cout << "\n\nRecuerda que tienes un saldo de " << cliente.saldoMonedas << " pesos en la maquina";
				cout << "\n\nOpcion: ";
				cin >> opcionProducto;

				if (opcionProducto <= 4 && opcionProducto > 0) {
					if (maquina.productos[opcionProducto - 1].cantidad > 0) {
						if (cliente.saldoMonedas >= maquina.productos[opcionProducto - 1].precio) {
							cout << "\nEstas seguro de comprar " << maquina.productos[opcionProducto - 1].nombre;
							cout << "\n1. SI";
							cout << "\n2. NO";
							cout << "\n\nOpcion: ";
							cin >> opcion;

							if (opcion == 1) {
								if (maquina.productos[opcionProducto - 1].donacionFopre) {
									fopre.totalDonaciones += maquina.productos[opcionProducto - 1].precio * 0.06;
									transaccion.valorDonacionProducto[opcionProducto - 1] += maquina.productos[opcionProducto - 1].precio * 0.06;
									transaccion.unidadDonacionProducto[opcionProducto - 1] += 1;
								}
								maquina.productos[opcionProducto - 1].cantidad--; // Reduce la cantidad del producto
								transaccion.valorTotalCompras += maquina.productos[opcionProducto - 1].precio;
								transaccion.totalCompras++;

								// Actualizar el contador de productos comprados
								transaccion.productosComprados[opcionProducto - 1]++;  // Incrementa el contador

								cliente.saldoMonedas -= maquina.productos[opcionProducto - 1].precio;

								cout << "\nTe sobro " << cliente.saldoMonedas << " de la compra";
								confirmarCompra = true;
							} else if (opcion == 2) {
								confirmarCompra = true;
							} else {
								cout << "\nSeleccion invalida!!";//validador de selección compra
								confirmarCompra = false;
							}
						} else {
							confirmarCompra = true;
							cout << "\nSaldo insuficiente!!";
						}
					} else {
						confirmarCompra = true;
						cout << "\nSin productos disponibles :/";
					}
				} else {
					confirmarCompra = true;
					cout << "\nOpcion invalida !!";//validador para opción correcta
				}
			} while (!confirmarCompra);
			break;
		}

		case 4: {
			cout << "\nCompraste en total: " << transaccion.totalCompras << " unidades de todo tipo producto";
			break;
		}

		case 5: {
			cout << "\nEl valor total de compras es de: " << transaccion.valorTotalCompras << " pesos";
			break;
		}
		case 6: {
			int cantidadDisponibleProductos = 0;
			int porcentajeDisponibleMaquina;

			for (int i = 0; i < 4; i++) {
				cantidadDisponibleProductos += maquina.productos[i].cantidad;
			}
			porcentajeDisponibleMaquina = (cantidadDisponibleProductos * 100) / maquina.cantidadMaximaProductos;

			cout << "\nEl porcentaje disponible de la maquina es de " << porcentajeDisponibleMaquina << " %";
			break;
		}
		case 7: {
			int numeroMaximo = transaccion.productosComprados[0];
			int indice = 0;

			if (transaccion.productosComprados[0] != 0 ||
			        transaccion.productosComprados[1] != 0 ||
			        transaccion.productosComprados[2] != 0 ||
			        transaccion.productosComprados[3] != 0) {
				for (int i = 1; i < 4; i++) {  // Comienza desde 1, ya que hemos inicializado con el primer producto
					if (transaccion.productosComprados[i] > numeroMaximo) {
						numeroMaximo = transaccion.productosComprados[i];
						indice = i;
					}
				}
			} else {
				cout << "No se han comprado productos" << endl;
				break;
			}

			cout << "\nEl producto mC!s comprado es: " << maquina.productos[indice].nombre;
			break;
		}

		case 8: {
			// Mostrar el valor total de las donaciones al FOPRE
			cout << "\nEl valor total de donaciones al FOPRE es de: " << fopre.totalDonaciones << " pesos";
			break;
		}
		case 9: {
			// Mostrar el valor de las donaciones al FOPRE por producto
			for (int i = 0; i < 4; i++) {
				if (maquina.productos[i].donacionFopre) {
					cout << "\n\nProducto: " << maquina.productos[i].nombre;
					cout << "\nRecaudaciC3n por donaciC3n: " << transaccion.valorDonacionProducto[i] << " pesos";
				}
			}
			break;
		}
		case 10: {
			// Mostrar las unidades compradas por tipo de producto con donación FOPRE
			for (int i = 0; i < 4; i++) {
				if (maquina.productos[i].donacionFopre) {
					cout << "\n\nProducto: " << maquina.productos[i].nombre;
					cout << "\nUnidades compradas: " << transaccion.unidadDonacionProducto[i];
				}
			}
			break;
		}
		case 0: {
			salirMenu = true;
			cout << "\nGracias por usar la maquina expendedora. !Hasta pronto!";
			break;
		}
		default: {
			cout << "\nOpción invalida. Intenta de nuevo."; //validador para asegurar que el usuario escoja una opciC3n del menC:
			break;
		}
		}
	} while (!salirMenu);

	return 0;
}
