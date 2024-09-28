#include<iostream>

using namespace std;


class MaquinaExpendedoraAlimentos{
	//Atributos
	private:
		//Valores entrada
		string nombreProducto[4];
		int precioProducto[4];
		int cantidadProducto[4];
		bool donacionFopre[4];
		
		//Valores salida
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
	public:
	MaquinaExpendedoraAlimentos(string _nombreProducto[4],int _precioProducto[4],int _cantidadProducto[4], bool _donacionFopre[100]){
		this->cantidadMaximaProductos = 0;
		for(int i=0; i<4; i++){
			this->nombreProducto[i] = _nombreProducto[i];
			this->precioProducto[i] = _precioProducto[i];
			this->cantidadProducto[i] = _cantidadProducto[i];
			this->donacionFopre[i] = _donacionFopre[i];
			this->cantidadMaximaProductos += _cantidadProducto[i];
			this->cantidadInicialProducto[i] = cantidadProducto[i];
			this->productosComprados[i] = 0;
			this->valorDonacionProducto[i] = 0;
			this->unidadDonacionProducto[i] = 0;
		}
		this->valorTotalCompras = 0;
		this->cantidadTotalCompras = 0;
		this->saldoMonedas = 0;		
	}
	
	//Metodos
	
	//Retorna lo que hay guardado en precioProducto por el indice
	int getPrecioProducto(int indiceProducto){
		return precioProducto[indiceProducto - 1];
	}
	
	//Retorna lo que hay guardado en nombreProducto por el indice
	string getNombreProducto(int indiceProducto){
		return nombreProducto[indiceProducto - 1];
	}
	
	//Retorna lo que hay guardado en cantidadProducto por el indice
	int getCantidadProducto(int indiceProducto){
		return cantidadProducto[indiceProducto - 1];
	}
	
	//Retoran lo que hay guardado en valorDonacionProducto por el indice
	int getValorDonacionProducto(int indiceProducto){
		return valorDonacionProducto[indiceProducto - 1];
	}
	
	//retorna la dornacionTotalFrope que se tiene almacenado
	int getDonacionTotalFopre(){
		return donacionTotalFopre;
	}
	
	//Se suma el parametro donacion en donacionTotalFopre 
	void setDonacionTotalFopre(int donacion){
		this->donacionTotalFopre += donacion;
	}
	
	//Muestra en pantalla la serie de informacion relacionado con productos
	void getMostrarProductos(bool mostrarParaComprar,string BLANCO, string VERDE, string AZUL){
		if(mostrarParaComprar == false){
			cout<<BLANCO<<"\nNombre producto: "<<VERDE<<nombreProducto[0];
			cout<<BLANCO<<"\nPrecio: "<<VERDE<<precioProducto[0];
			cout<<BLANCO<<"\nCantidad disponible: "<<VERDE<<cantidadProducto[0];
			cout<<BLANCO<<"\nPertenece a FOPRE: "<<VERDE<<donacionFopre[0];
			cout<<BLANCO<<"\n\nNombre producto: "<<VERDE<<nombreProducto[1];
			cout<<BLANCO<<"\nPrecio: "<<VERDE<<precioProducto[1];
			cout<<BLANCO<<"\nCantidad disponible: "<<VERDE<<cantidadProducto[1];
			cout<<BLANCO<<"\nPertenece a FOPRE: "<<VERDE<<donacionFopre[1];
			cout<<BLANCO<<"\n\nNombre producto: "<<VERDE<<nombreProducto[2];
			cout<<BLANCO<<"\nPrecio: "<<VERDE<<precioProducto[2];
			cout<<BLANCO<<"\nCantidad disponible: "<<VERDE<<cantidadProducto[2];
			cout<<BLANCO<<"\nPertenece a FOPRE: "<<VERDE<<donacionFopre[2];
			cout<<BLANCO<<"\n\nNombre producto: "<<VERDE<<nombreProducto[3];
			cout<<BLANCO<<"\nPrecio: "<<VERDE<<precioProducto[3];
			cout<<BLANCO<<"\nCantidad disponible: "<<VERDE<<cantidadProducto[3];
			cout<<BLANCO<<"\nPertenece a FOPRE: "<<VERDE<<donacionFopre[3];
		}else{
			cout<<AZUL<<"Precione 1 para comprar:";
			cout<<BLANCO<<"\nNombre producto: "<<VERDE<<nombreProducto[0];
			cout<<BLANCO<<"\nPrecio: "<<VERDE<<precioProducto[0];
			cout<<BLANCO<<"\nCantidad disponible: "<<VERDE<<cantidadProducto[0];
			cout<<AZUL<<"\n\nPrecione 2 para comprar:";
			cout<<BLANCO<<"\nNombre producto: "<<VERDE<<nombreProducto[1];
			cout<<BLANCO<<"\nPrecio: "<<VERDE<<precioProducto[1];
			cout<<BLANCO<<"\nCantidad disponible: "<<VERDE<<cantidadProducto[1];
			cout<<AZUL<<"\n\nPrecione 3 para comprar:";
			cout<<BLANCO<<"\nNombre producto: "<<VERDE<<nombreProducto[2];
			cout<<BLANCO<<"\nPrecio: "<<VERDE<<precioProducto[2];
			cout<<BLANCO<<"\nCantidad disponible: "<<VERDE<<cantidadProducto[2];
			cout<<AZUL<<"\n\nPrecione 4 para comprar:";
			cout<<BLANCO<<"\nNombre producto: "<<VERDE<<nombreProducto[3];
			cout<<BLANCO<<"\nPrecio: "<<VERDE<<precioProducto[3];
			cout<<BLANCO<<"\nCantidad disponible: "<<VERDE<<cantidadProducto[3];
		}
	}
		
	//retorna lo que hay guardado en cantidadTotalCompras
	int getCalcularCantidadProductosComprados(){
		return cantidadTotalCompras;
	}
	
	int getCalcularValorProductosComprados(){
		return valorTotalCompras;
	}
	
	//Calcula el porcentaje la cantidad disponible de la maquina y lo retorna
	int getCalcularDisponibilidadMaquina(){
		int cantidadDisponibleProductos = 0;
		int porcentajeDisponibleMaquina;
		for(int i = 0; i<4; i++){
			cantidadDisponibleProductos += cantidadProducto[i];
		}
		porcentajeDisponibleMaquina = cantidadDisponibleProductos * 100 / cantidadMaximaProductos;
		return porcentajeDisponibleMaquina;
	}
	
	//Calcula el producto mas comprado en general y lo retorna
	string getCalcularProductoMasComprado(){
		int numeroMaximo, indice = 0;
		numeroMaximo = productosComprados[0];
		int longuitud = sizeof(productosComprados) / sizeof(productosComprados[0]);
		if(productosComprados[0] != cantidadInicialProducto[0] ||
		productosComprados[1] != cantidadInicialProducto[1] ||
		productosComprados[2] != cantidadInicialProducto[2] ||
		productosComprados[3] != cantidadInicialProducto[3] ){
			for(int i = 0; i<longuitud; i++){
				if(productosComprados[i] > numeroMaximo){
					numeroMaximo = productosComprados[i];
					indice = i;
				}
			}
		}else{
			return ""; //No se han comprado productos
		}
		return nombreProducto[indice];
	}
	
	
	//Anade monedas dependiendo del parametro opcion
	void setAnadirMonedas(int opcion){
		switch(opcion){
			case 1:{
				saldoMonedas += 100;
				break;
			}
			case 2:{
				saldoMonedas += 200;
				break;
			}
			case 3:{
				saldoMonedas += 500;
				break;
			}
			case 4:{
				saldoMonedas += 1000;
				break;
			}
			default:{
				break;
			}
		}
	}
	
	int getMostrarMonedas(){
		return saldoMonedas;
	}
	
	//Metodo para comprar producto 
	void setComprarProducto(int tipoProducto){
		//Si el producto dona para FOPRE entonces se aporta el 6% del valor del producto
		if(donacionFopre[tipoProducto-1] == true){
			setDonacionTotalFopre(precioProducto[tipoProducto-1] * 0.06);
			
			//Anadir el valor al array para tener valor independiente
			valorDonacionProducto[tipoProducto-1] += precioProducto[tipoProducto-1] * 0.06;
			
			//Anadir la unidad al array para tener la cantidad por unidades 
			unidadDonacionProducto[tipoProducto -1 ] += 1;
		}
		//Quitar cantidad producto
		cantidadProducto[tipoProducto-1] -= 1;
		//Aumentamos valor total de compras
		valorTotalCompras += precioProducto[tipoProducto-1];
		//Aumentamos la cantidad total de compras 
		cantidadTotalCompras++;
		//Aumentamos la iteracion del producto comprado
		productosComprados[tipoProducto - 1] += 1;	
		//Actualizar saldoMonedas
		saldoMonedas -= precioProducto[tipoProducto - 1];

	}
	
	
	//Mostrar el valor de donacion por cada producto aplicado para FOPRE
	void getConocerValorDonacionTipoProducto(string AZUL_CLARO, string VERDE){
		for(int i = 0; i<4; i++){
			if(donacionFopre[i] == true){
				cout<<AZUL_CLARO<<"\n\nTipo producto: "<<VERDE<<nombreProducto[i];
				cout<<AZUL_CLARO<<"\nRecaudo donacion: "<<VERDE<<valorDonacionProducto[i];
			}
		}
	}
	
	//Mostrar la unidad comprada por cada producto para FOPRE
	void getConocerUnidadDonacionProducto(string AZUL_CLARO, string VERDE){
		for(int i = 0; i<4; i++){
			if(donacionFopre[i] == true){
				cout<<AZUL_CLARO<<"\n\nTipo producto: "<<VERDE<<nombreProducto[i];
				cout<<AZUL_CLARO<<"\nUnidadades compradas: "<<VERDE<<unidadDonacionProducto[i];
			}
		}
	}
	
	
};