#include<iostream>


using namespace std;

//Variables globales

//Valores salida
double valorTotalCompras = 0;
int cantidadTotalCompras = 0;
int saldoMonedas = 0 ;
int productosComprados[4] = {0,0,0,0};
int cantidadInicialProducto[4] = {0,0,0,0};
int cantidadMaximaProductos = 0;
int donacionTotalFopre = 0;
int valorDonacionProducto[4] = {0,0,0,0};
int unidadDonacionProducto[4] = {0,0,0,0};


int main(){
    //Definiendo variables de entrada
	string nombreProducto[4] = {"Hit individual", "Oreo x 4 undides","Gansito x unidad","SpeedMax litro"};
	int precioProducto[4] = {2800, 2100, 1800, 3000};
	int cantidadProducto[4] = {15, 24, 12, 18};
	bool donacionFopre[4] = {true, false, true, false};
	bool salirMenu = false, confirmarCompra = false, confirmarMonedas = false;

    for(int i=0; i<4; i++){
        cantidadInicialProducto[i] = cantidadProducto[i];
        cantidadMaximaProductos += cantidadProducto[i];
    }
    
	int opcion, opcionProducto;

	//Bucle menu
	do{
	    //Muestra el menu por consola, pidiendo al usuario una opcion
		
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
		cout<<"\n\nOpcion: ";
		cin>>opcion;
		
		switch(opcion){
		    //En el caso que oprima 1
			case 1:{
			    //Variable para convertir el valor de booleano a texto
			    string mensaje[4];
			    
			    for(int i=0; i<4; i++){
			        mensaje[i] = (donacionFopre[i] ? "SI":"NO");
			        
			        cout<<"\n\nNombre producto: "<<nombreProducto[i];
			        cout<<"\nPrecio: "<<precioProducto[i];
			        cout<<"\nCantidad disponible: "<<cantidadProducto[i];
			        cout<<"\nPertenece a FOPRE: "<<mensaje[i];
			    }
		        
			    
				break;
			}
			case 2:{
				do{
				    //Mostramos la disponibilidad de monedas
					
					cout<<"\n\nPresiona...";
	                cout<<"\n1. Moneda de 100";
	                cout<<"\n2. Moneda de 200";
	                cout<<"\n3. Moneda de 500";
	                cout<<"\n4. Moneda de 1000";
	                cout<<"\n5. Confirmar monedas";
					
					cout<<"\n\nTienes "<<saldoMonedas<<" pesos de saldo";
					cout<<"\n\nOpcion: ";
					cin>>opcion;
					
					//Recorre opcion para saber si se añade una moneda o no
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
		            
		            //En el caso que se oprima 5 sale del bucle
					if(opcion == 5){
						confirmarMonedas = true;
					}else{
					    //De lo contrario se repite el bucle
						confirmarMonedas = false;
					}
				}while(confirmarMonedas != true);
				break;
			}
			case 3:{
			    do{
					
					confirmarCompra = false;
					
					for(int i=0; i<4; i++){
					    //Muestra los productos disponibles 
					    cout<<"\n\nPrecione "<<i+1<<" para comprar:";
			            cout<<"\nNombre producto: "<<nombreProducto[i];
			            cout<<"\nPrecio: "<<precioProducto[i];
			            cout<<"\nCantidad disponible: "<<cantidadProducto[i];
					}
  
					cout<<"\n\nRecuerda que tienes un saldo de "<<saldoMonedas<<" pesos en la maquina";
					cout<<"\n\nOpcion: ";
					cin>>opcionProducto;
					
					//Condiciones para evitar que el producto sea mal seleccionado
					if(opcionProducto <= 4 && opcionProducto > 0){
					    //Condicion para saber si hay cantidad del prodcuto suficiente para comprar
						if(cantidadProducto[opcionProducto - 1] > 0){
						    //Condicion para saber si hay saldo suficiente para comprar el producto
							if(saldoMonedas >= precioProducto[opcionProducto - 1]){
							    
								cout<<"\nEstas seguro de comprar "<<nombreProducto[opcionProducto - 1];
								cout<<"\n1."<<" SI";
								cout<<"\n2."<<" NO";
								cout<<"\n\nOpcion: ";
								cin>>opcion;
								
								//Condicion si acepto la compra
								if(opcion == 1){
								
		                            if(donacionFopre[opcionProducto-1] == true){
		                                //Si el producto dona para FOPRE entonces se aporta el 6% del valor del producto
		                                donacionTotalFopre += precioProducto[opcionProducto-1] * 0.06;
		                            	//Anadir el valor al array para tener valor independiente
		                            	valorDonacionProducto[opcionProducto-1] += precioProducto[opcionProducto-1] * 0.06;
		                            	//Anadir la unidad al array para tener la cantidad por unidades 
		                            	unidadDonacionProducto[opcionProducto -1 ] += 1;
		                            }
		                            
		                            //Quitar cantidad producto
		                            cantidadProducto[opcionProducto-1] -= 1;
		                            //Aumentamos valor total de compras
		                            valorTotalCompras += precioProducto[opcionProducto-1];
		                            //Aumentamos la cantidad total de compras 
		                            cantidadTotalCompras++;
		                            //Aumentamos la iteracion del producto comprado
		                            productosComprados[opcionProducto - 1] += 1;	
		                            //Actualizar saldoMonedas
		                            saldoMonedas -= precioProducto[opcionProducto - 1];
		                            
									
									cout<<"\nTe sobro "<<saldoMonedas<<" de la compra";
									confirmarCompra = true;
									
								}else if(opcion == 2){
								    //Caso en el que no acepte la compra
									confirmarCompra = true;
								}else{
								    //Caso en el que seleccione otra opcion
								    cout<<"\nSeleccion invalida!!";
									confirmarCompra = false;
								}
							}else{
							    //En el caso del usuario que tenga menor saldo del precio producto
								confirmarCompra = true;
								cout<<"\nSaldo insuficiente!!";
							}
						}else{
						    //En el caso de que no haya productos en la maquina
							confirmarCompra = true;
							cout<<"\nSin productos disponibles :/";
						}	
					}else{
					    //En el caso que el usuario seleccione una opcion invalida
						confirmarCompra = true;
						cout<<"\nOpcion invalida !!";	
					}
				}while(confirmarCompra != true);
				break;
			}
			case 4:{
				cout<<"\nCompraste en total: "<<cantidadTotalCompras<<" unidades de todo tipo producto";
				break;
			}
			case 5:{
				cout<<"\nEl valor total de compras es de: "<<valorTotalCompras<<" pesos";
				break;
			}
			case 6:{
			    
			    int cantidadDisponibleProductos = 0;
	            int porcentajeDisponibleMaquina;
	            
	            for(int i = 0; i<4; i++){
	                //Almacena la cantidad total de productos segun la cantidad de productos 
	            	cantidadDisponibleProductos += cantidadProducto[i];
	            }
	            //Convierte la cantidad disponible de productos y lo convierte en un porcntaje
	            porcentajeDisponibleMaquina = cantidadDisponibleProductos * 100 / cantidadMaximaProductos;
	            
				cout<<"\nEl porcentaje disponible de la maquina es de "<<porcentajeDisponibleMaquina<<" %";
				break;
			}
			case 7:{
			    
			    int numeroMaximo, indice = 0;
		        numeroMaximo = productosComprados[0];
		        
		        //Si los productos comprados son diferentes a la cantidad inicial entonces calcula el producto mas comprado
		        if(productosComprados[0] != cantidadInicialProducto[0] ||
		        productosComprados[1] != cantidadInicialProducto[1] ||
		        productosComprados[2] != cantidadInicialProducto[2] ||
		        productosComprados[3] != cantidadInicialProducto[3] ){
		        	for(int i = 0; i<4; i++){
		        	    //Si el producto iterado es mayor al numero maximo entonces se atualiza el estado
		        		if(productosComprados[i] > numeroMaximo){
		        			numeroMaximo = productosComprados[i];
		        			indice = i;
		        		}
		        	}
		        }else{
		            //No se han comprado productos
		        	cout<<"No se han comprado productos";
		        }
		        
				cout<<"\nEl producto mas comprado es: "<<nombreProducto[indice];
				break;
			}
			case 8:{
			    
				cout<<"\nEl valor total de donaciones al FOPRE es de: "<<donacionTotalFopre<<" pesos";
				break;
			}
			case 9:{
			    
			    for(int i = 0; i<4; i++){
			        //Si el producto peretenece a donacion FOPRE muestra...
			        if(donacionFopre[i] == true){
			        	cout<<"\n\nTipo producto: "<<nombreProducto[i];
			        	cout<<"\nRecaudo donacion: "<<valorDonacionProducto[i];
			        }
		        }
		        
				break;
			}
			case 10:{
				
				for(int i = 0; i<4; i++){
				    //Si el producto peretenece a donacion FOPRE muestra...
			        if(donacionFopre[i] == true){
			        	cout<<"\n\nTipo producto: "<<nombreProducto[i];
			        	cout<<"\nUnidadades compradas: "<<unidadDonacionProducto[i];
			        }
		        }
				break;
			}
			
			case 0:{
			    //EN el caso que oprima 0 sale del menu
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
