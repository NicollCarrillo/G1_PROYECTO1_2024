#include<iostream>
#include "MaquinaExpendedoraAlimentos.cpp"


using namespace std;

//Variables para aplicar color por consola
string ROJO = "\033[31m";
string VERDE = "\033[32m";
string AMARILLO = "\033[33m";
string AZUL = "\033[34m";
string MORADO = "\033[35m";
string AZUL_CLARO = "\033[36m";
string BLANCO = "\033[37m";
string RESET = "\033[0m";

//LLamando a las funciones para poderlas aplicar en el main
void mostrarMenuPrincipal();
void mostrarMonedas();
void clear();


int main(){
	string nombreProductos[100] = {"Hit individual", "Oreo x 4 undides","Gansito x unidad","SpeedMax litro"};
	int precioProductos[100] = {2000, 800, 1800, 3000};
	int cantidadProductos[100] = {12, 12, 12, 12};
	bool donacionFrope[100] = {true, false, true, false};
	bool salirMenu = false, confirmarCompra = false, confirmarMonedas = false;
	int opcion, opcionProducto;
	
	//Creando objeto (maquina)
	MaquinaExpendedoraAlimentos maquina = MaquinaExpendedoraAlimentos(nombreProductos,precioProductos,cantidadProductos,donacionFrope);
	
	//Bucle menu
	do{
	    //Muestra el menu por consola, pidiendo al usuario una opcion
		clear();
		mostrarMenuPrincipal();
		cout<<AZUL_CLARO<<"\n\nOpcion: "<<AMARILLO;
		cin>>opcion;
		
		switch(opcion){
		    //En el caso que oprima 1
			case 1:{
				maquina.getMostrarProductos(false,BLANCO,VERDE,AZUL);
				break;
			}
			case 2:{
				do{
					clear();
					mostrarMonedas();
					cout<<MORADO<<"\n\nTienes "<<VERDE<<maquina.getMostrarMonedas()<<MORADO<<" pesos de saldo";
					cout<<AZUL_CLARO<<"\n\nOpcion: "<<AMARILLO;
					cin>>opcion;
					maquina.setAnadirMonedas(opcion);
					if(opcion == 5){
						confirmarMonedas = true;
					}else{
						confirmarMonedas = false;
					}
				}while(confirmarMonedas != true);
				break;
			}
			case 3:{
			    do{
					clear();
					confirmarCompra = false;
					maquina.getMostrarProductos(true,BLANCO,VERDE,AZUL);
					cout<<MORADO<<"\n\nRecuerda que tienes un saldo de "<<VERDE<<maquina.getMostrarMonedas()<<MORADO<<" pesos en la maquina";
					cout<<AZUL_CLARO<<"\n\nOpcion: "<<AMARILLO;
					cin>>opcionProducto;
					if(opcionProducto <= 4 && opcionProducto > 0){
						if(maquina.getCantidadProducto(opcionProducto) > 0){
							if(maquina.getMostrarMonedas() >= maquina.getPrecioProducto(opcionProducto)){
							    clear();
								cout<<MORADO<<"\nEstas seguro de comprar "<<maquina.getNombreProducto(opcionProducto);
								cout<<AMARILLO<<"\n1."<<BLANCO<<" SI";
								cout<<AMARILLO<<"\n2."<<BLANCO<<" NO";
								cout<<AZUL_CLARO<<"\n\nOpcion: "<<AMARILLO;
								cin>>opcion;
								if(opcion == 1){
									maquina.setComprarProducto(opcionProducto);
									cout<<MORADO<<"\nTe sobro "<<VERDE<<maquina.getMostrarMonedas()<<MORADO<<" de la compra";
									confirmarCompra = true;
								}else if(opcion == 2){
									confirmarCompra = true;
								}else{
								    cout<<ROJO<<"Seleccion invalida!!"<<BLANCO;
									confirmarCompra = false;
								}
							}else{
								confirmarCompra = true;
								cout<<ROJO<<"\nSaldo insuficiente!!"<<BLANCO;
							}
						}else{
							confirmarCompra = true;
							cout<<ROJO<<"\nSin productos disponibles :/"<<BLANCO;
						}	
					}else{
						confirmarCompra = true;
						cout<<ROJO<<"\nOpcion invalida !!";	
					}
				}while(confirmarCompra != true);
				break;
			}
			case 4:{
				cout<<MORADO<<"\nCompraste en total: "<<VERDE<<maquina.getCalcularCantidadProductosComprados()<<MORADO<<" unidades de todo tipo producto";
				
				break;
			}
			case 5:{
				cout<<MORADO<<"\nEl valor total de compras es de: "<<VERDE<<maquina.getCalcularValorProductosComprados()<<MORADO<<" pesos";
				break;
			}
			case 6:{
				cout<<MORADO<<"\nEl porcentaje disponible de la maquina es de "<<VERDE<<maquina.getCalcularDisponibilidadMaquina()<<MORADO<<" %";
				break;
			}
			case 7:{
				cout<<MORADO<<"\nEl producto mas comprado es: "<<VERDE<<maquina.getCalcularProductoMasComprado();
				break;
			}
			case 8:{
				cout<<MORADO<<"\nEl valor total de donaciones al FOPRE es de: "<<VERDE<<maquina.getDonacionTotalFopre()<<MORADO<<" pesos";
				break;
			}
			case 9:{
				maquina.getConocerValorDonacionTipoProducto(AZUL_CLARO, VERDE);
				break;
			}
			case 10:{
				maquina.getConocerUnidadDonacionProducto(AZUL_CLARO, VERDE);
				break;
			}
			case 0:{
				salirMenu = true;
				break;
			}
			//En el caso que oprima todo menos lo anterior
			default:{
			    cout<<ROJO<<"\nInserte una opcion valida!!";
			}
		}
		//Muestra en pantalla si el usuario quiere continuar en la maquina
		cout<<MORADO<<"\n\nDesea continuar en la maquina?";
		cout<<AMARILLO<<"\n1."<<BLANCO<<" SI";
		cout<<AMARILLO<<"\n2."<<BLANCO<<" NO";
		cout<<AZUL_CLARO<<"\n\nOpcion: "<<AMARILLO;
		cin>>opcion;
		if(opcion == 1){
			salirMenu = false;
		}else if(opcion == 2){
			salirMenu = true;
		}else{
			salirMenu = false;
		}
	}while(salirMenu != true);
	
	return 0;
}

//Funcion para mostrar Menu principal
void mostrarMenuPrincipal(){
	cout<<AZUL<<"\n-------MAQUINA EXPENDEDORA--------"<<BLANCO;
	cout<<"\n1. Mostrar productos disponibles";
	cout<<"\n2. Agregar credito - monedas a la maquina";
	cout<<"\n3. Comprar producto";
	cout<<"\n4. Calcular cantidad total de unidades compradas";
	cout<<"\n5. Calcular valor total por las compras realizadas";
	cout<<"\n6. Calcular el porcentaje de disponibilidad de la maquina";
	cout<<"\n7. Consultar el producto mas comprado";
	cout<<"\n8. Calcular el valor de la donacion total al FOPRE por las compras realizadas";
	cout<<"\n9. Conocer el valor de la donacion al FOPRE por tipo de producto";
	cout<<"\n10. Conocer las unidades compradas de productos FOPRE y por tipo de producto";
	cout<<"\n0. Salir de la maquina";
	
}
//Funcion para mostrar las monedas que se puede insertar
void mostrarMonedas(){
	cout<<AZUL<<"\n\nPresiona..."<<BLANCO;
	cout<<"\n1. Moneda de 100";
	cout<<"\n2. Moneda de 200";
	cout<<"\n3. Moneda de 500";
	cout<<"\n4. Moneda de 1000";
	cout<<"\n5. Confirmar monedas";
}
//Funcion para limpiar consola cuando se necesite
void clear() {
    cout<<"\033[2J\033[1;1H";
}