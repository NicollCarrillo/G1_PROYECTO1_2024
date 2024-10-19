#include <iostream>

using namespace std;

//Struct (estructura)
struct MaquinaExpendedora{
    
    //Variables entrada
    string nombreProducto[4];
	int precioProducto[4];
	int cantidadProducto[4];
	bool donacionFopre[4];
	
	//Variables salida
	double valorTotalCompras;
    int cantidadTotalCompras;
    int saldoMonedas;
    int productosComprados[4];
    int cantidadInicialProducto[4];
    int cantidadMaximaProductos;
    int donacionTotalFopre;
    int valorDonacionProducto[4];
    int unidadDonacionProducto[4];
	
    //Constructor
    MaquinaExpendedora(string _nombreProducto[4], int _precioProducto[4], int _cantidadProducto[4], bool _donacionFopre[4]){
        cantidadMaximaProductos = 0;
        for(int i=0; i<4; i++){
            
            //Almacenamos los datos de entrada 
            nombreProducto[i] = _nombreProducto[i];
            precioProducto[i] = _precioProducto[i];
            cantidadProducto[i] = _cantidadProducto[i];
            donacionFopre[i] = _donacionFopre[i];
            
            //Inicializamos las variables a cero
            productosComprados[i] = 0;
            cantidadInicialProducto[i] = 0;
            valorDonacionProducto[i] = 0;
            unidadDonacionProducto[i] = 0;
            
            //Almacenamos la informacion inicial de los productos 
            cantidadInicialProducto[i] = cantidadProducto[i];
            cantidadMaximaProductos += cantidadProducto[i];
        }
        
        //Inicializamos las variables a cero
            double valorTotalCompras = 0;
            cantidadTotalCompras = 0;
            saldoMonedas = 0;
            cantidadMaximaProductos = 0;
            donacionTotalFopre = 0;
    }
};

//INICIALIZAMOS EL STRUCT (MaquinaExpendedora) por fuera del main para que quede de manera global
string nombreProducto[100] = {"Hit individual", "Oreo x 4 undides","Gansito x unidad","SpeedMax litro"};
int precioProducto[100] = {2000, 800, 1800, 3000};
int cantidadProducto[100] = {12, 12, 12, 12};
bool donacionFopre[100] = {true, false, true, false};

MaquinaExpendedora maquina(nombreProducto, precioProducto, cantidadProducto, donacionFopre);

//LLamando a las funciones para utilizarlas en el main
int getPrecioProducto(int indiceProducto);
string getNombreProducto(int indiceProducto);
int getCantidadProducto(int indiceProducto);
int getValorDonacionProducto(int indiceProducto);
int getDonacionTotalFopre();
void setDonacionTotalFopre(int donacion);
void getMostrarProductos(bool mostrarParaComprar);
int getCalcularCantidadProductosComprados();
int getCalcularValorProductosComprados();
int getCalcularDisponibilidadMaquina();
string getCalcularProductoMasComprado();
void setAnadirMonedas(int opcion);
int getMostrarMonedas();
void setComprarProducto(int opcionProducto);
void getConocerValorDonacionTipoProducto();
void getConocerUnidadDonacionProducto();
void mostrarMenuPrincipal();
void mostrarMonedas();
void clear();



int main(){

    //Variables a utilizar para el do while
	int opcion, opcionProducto;
	bool salirMenu = false, confirmarCompra = false, confirmarMonedas = false;
	
	do{
	    
	    //Muestra el menu por consola, pidiendo al usuario una opcion
		clear();
		mostrarMenuPrincipal();
		cout<<"\n\nOpcion: ";
		cin>>opcion;
		
		switch(opcion){
		    //En el caso que oprima 1
			case 1:{
				getMostrarProductos(false);
				break;
			}
			case 2:{
				do{
					clear();
					mostrarMonedas();
					cout<<"\n\nTienes "<<getMostrarMonedas()<<" pesos de saldo";
					cout<<"\n\nOpcion: ";
					cin>>opcion;
					setAnadirMonedas(opcion);
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
					getMostrarProductos(true);
					cout<<"\n\nRecuerda que tienes un saldo de "<<getMostrarMonedas()<<" pesos en la maquina";
					cout<<"\n\nOpcion: ";
					cin>>opcionProducto;
					if(opcionProducto <= 4 && opcionProducto > 0){
						if(getCantidadProducto(opcionProducto) > 0){
							if(getMostrarMonedas() >= getPrecioProducto(opcionProducto)){
							    clear();
								cout<<"\nEstas seguro de comprar "<<getNombreProducto(opcionProducto);
								cout<<"\n1."<<" SI";
								cout<<"\n2."<<" NO";
								cout<<"\n\nOpcion: ";
								cin>>opcion;
								if(opcion == 1){
									setComprarProducto(opcionProducto);
									cout<<"\nTe sobro "<<getMostrarMonedas()<<" de la compra";
									confirmarCompra = true;
								}else if(opcion == 2){
									confirmarCompra = true;
								}else{
								    cout<<"Seleccion invalida!!";
									confirmarCompra = false;
								}
							}else{
								confirmarCompra = true;
								cout<<"\nSaldo insuficiente!!";
							}
						}else{
							confirmarCompra = true;
							cout<<"\nSin productos disponibles :/";
						}	
					}else{
						confirmarCompra = true;
						cout<<"\nOpcion invalida !!";	
					}
				}while(confirmarCompra != true);
				break;
			}
			case 4:{
				cout<<"\nCompraste en total: "<<getCalcularCantidadProductosComprados()<<" unidades de todo tipo producto";
				break;
			}
			case 5:{
				cout<<"\nEl valor total de compras es de: "<<getCalcularValorProductosComprados()<<" pesos";
				break;
			}
			case 6:{
				cout<<"\nEl porcentaje disponible de la maquina es de "<<getCalcularDisponibilidadMaquina()<<" %";
				break;
			}
			case 7:{
				cout<<"\nEl producto mas comprado es: "<<getCalcularProductoMasComprado();
				break;
			}
			case 8:{
				cout<<"\nEl valor total de donaciones al FOPRE es de: "<<getDonacionTotalFopre()<<" pesos";
				break;
			}
			case 9:{
				getConocerValorDonacionTipoProducto();
				break;
			}
			case 10:{
				getConocerUnidadDonacionProducto();
				break;
			}
			case 0:{
				salirMenu = true;
				break;
			}
			//En el caso que oprima todo menos lo anterior
			default:{
			    cout<<"\nInserte una opcion valida!!";
			}
		}
		//Muestra en pantalla si el usuario quiere continuar en la maquina
		cout<<"\n\nDesea continuar en la maquina?";
		cout<<"\n1."<<" SI";
		cout<<"\n2."<<" NO";
		cout<<"\n\nOpcion: ";
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

//Funciones

//Retorna lo que hay guardado en precioProducto por el indice
int getPrecioProducto(int indiceProducto){
    return maquina.precioProducto[indiceProducto - 1];
}

//Retorna lo que hay guardado en nombreProducto por el indice
string getNombreProducto(int indiceProducto){
    return maquina.nombreProducto[indiceProducto - 1];
}

//Retorna lo que hay guardado en cantidadProducto por el indice
int getCantidadProducto(int indiceProducto){
	return maquina.cantidadProducto[indiceProducto - 1];
}

//Retoran lo que hay guardado en valorDonacionProducto por el indice
int getValorDonacionProducto(int indiceProducto){
	return maquina.valorDonacionProducto[indiceProducto - 1];
}

//retorna la dornacionTotalFrope que se tiene almacenado
int getDonacionTotalFopre(){
	return maquina.donacionTotalFopre;
}

//Se suma el parametro donacion en donacionTotalFopre 
void setDonacionTotalFopre(int donacion){
	maquina.donacionTotalFopre += donacion;
}

//Muestra en pantalla la serie de informacion relacionado con productos
void getMostrarProductos(bool mostrarParaComprar){
	if(mostrarParaComprar == false){
	    string mensaje[4];
	    for(int i=0; i<4; i++){
	        mensaje[i] = (donacionFopre[i] ? "SI":"NO");
		    cout<<"\n\nNombre producto: "<<maquina.nombreProducto[i];
			cout<<"\nPrecio: "<<maquina.precioProducto[i];
			cout<<"\nCantidad disponible: "<<maquina.cantidadProducto[i];
			cout<<"\nPertenece a FOPRE: "<<mensaje[i];
		}
		  
	}else{
	    for(int i=0; i<4; i++){
	        cout<<"\n\nPrecione "<<i+1<<" para comprar:";
		    cout<<"\nNombre producto: "<<maquina.nombreProducto[i];
		    cout<<"\nPrecio: "<<maquina.precioProducto[i];
		    cout<<"\nCantidad disponible: "<<maquina.cantidadProducto[i];
	    }
	}
}

//retorna lo que hay guardado en cantidadTotalCompras
int getCalcularCantidadProductosComprados(){
	return maquina.cantidadTotalCompras;
}

int getCalcularValorProductosComprados(){
	return maquina.valorTotalCompras;
}

//Calcula el porcentaje la cantidad disponible de la maquina y lo retorna
int getCalcularDisponibilidadMaquina(){
	int cantidadDisponibleProductos = 0;
	int porcentajeDisponibleMaquina;
	for(int i = 0; i<4; i++){
		cantidadDisponibleProductos += maquina.cantidadProducto[i];
	}
	porcentajeDisponibleMaquina = cantidadDisponibleProductos * 100 / maquina.cantidadMaximaProductos;
	return porcentajeDisponibleMaquina;
}

//Calcula el producto mas comprado en general y lo retorna
string getCalcularProductoMasComprado(){
	int numeroMaximo, indice = 0;
	numeroMaximo = maquina.productosComprados[0];
	int longuitud = sizeof(maquina.productosComprados) / sizeof(maquina.productosComprados[0]);
	
	if(maquina.productosComprados[0] != maquina.cantidadInicialProducto[0] ||
	maquina.productosComprados[1] != maquina.cantidadInicialProducto[1] ||
	maquina.productosComprados[2] != maquina.cantidadInicialProducto[2] ||
	maquina.productosComprados[3] != maquina.cantidadInicialProducto[3] ){
		for(int i = 0; i<longuitud; i++){
			if(maquina.productosComprados[i] > numeroMaximo){
				numeroMaximo = maquina.productosComprados[i];
				indice = i;
			}
		}
	}else{
	    //No se han comprado productos
		return "";
	}
	return maquina.nombreProducto[indice];
}

//Anade monedas dependiendo del parametro opcion
void setAnadirMonedas(int opcion){
	switch(opcion){
		case 1:{
			maquina.saldoMonedas += 100;
			break;
		}
		case 2:{
			maquina.saldoMonedas += 200;
			break;
		}
		case 3:{
			maquina.saldoMonedas += 500;
			break;
		}
		case 4:{
			maquina.saldoMonedas += 1000;
			break;
		}
		default:{
			break;
		}
	}
}

int getMostrarMonedas(){
	return maquina.saldoMonedas;
}

//Funcion para comprar producto
void setComprarProducto(int opcionProducto){
    if(maquina.donacionFopre[opcionProducto-1] == true){
		//Si el producto dona para FOPRE entonces se aporta el 6% del valor del producto
		maquina.donacionTotalFopre += maquina.precioProducto[opcionProducto-1] * 0.06;
		//Anadir el valor al array para tener valor independiente
		maquina.valorDonacionProducto[opcionProducto-1] += maquina.precioProducto[opcionProducto-1] * 0.06;
		//Anadir la unidad al array para tener la cantidad por unidades 
		maquina.unidadDonacionProducto[opcionProducto -1 ] += 1;
	}
	//Quitar cantidad producto
	maquina.cantidadProducto[opcionProducto-1] -= 1;
	//Aumentamos valor total de compras
	maquina.valorTotalCompras += maquina.precioProducto[opcionProducto-1];
	//Aumentamos la cantidad total de compras 
	maquina.cantidadTotalCompras++;
	//Aumentamos la iteracion del producto comprado
	maquina.productosComprados[opcionProducto - 1] += 1;	
	//Actualizar saldoMonedas
	maquina.saldoMonedas -= maquina.precioProducto[opcionProducto - 1];
    
}

//Funcion mostrar el valor de donacion por cada producto aplicado para FOPRE
void getConocerValorDonacionTipoProducto(){
	for(int i = 0; i<4; i++){
		if(maquina.donacionFopre[i] == true){
			cout<<"\n\nTipo producto: "<<maquina.nombreProducto[i];
			cout<<"\nRecaudo donacion: "<<maquina.valorDonacionProducto[i];
		}
	}
}


//Funcion mostrar la unidad comprada por cada producto para FOPRE
void getConocerUnidadDonacionProducto(){
	for(int i = 0; i<4; i++){
		if(maquina.donacionFopre[i] == true){
			cout<<"\n\nTipo producto: "<<maquina.nombreProducto[i];
			cout<<"\nUnidadades compradas: "<<maquina.unidadDonacionProducto[i];
		}
	}
}

void mostrarMenuPrincipal(){
	cout<<"\n-------MAQUINA EXPENDEDORA--------";
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
	cout<<"\n\nPresiona...";
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
