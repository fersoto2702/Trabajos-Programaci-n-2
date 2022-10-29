#include<fstream>
#include<string.h>
#include<string>
#include<iostream>
#include<list>
#include<locale.h>

using namespace std;


int codigoProd(list<string> codigos){
	int largoLista = codigos.size(), aux;
	string vector[largoLista];
	int valorRet=0;
	aux=0;
	while(!codigos.empty()){
		vector[aux] = codigos.front();
		codigos.pop_front();
		aux++;
	}
	for(int i = 0; i <= aux; i++){
		if(i < (largoLista - 1)){
			if(vector[i] == vector[largoLista-1]){
				valorRet = 10;
			    break;
		    }
		}
		
		
	}
	return valorRet;
}

int busquedaProducto(string codigoProducto , list<string> codigo, list<string> productos, list<double> precioVenta, list<double> cantidades){
	int aux0,aux1,aux2;
	int valorRet=1;
	aux0 = codigo.size();
	aux1 = productos.size();
	aux2 = precioVenta.size();
	string vecCodigo[aux0];
	string vecProd [aux1];
	double vecPrecio [aux2];
	aux2=0;
	aux2 = cantidades.size();
	double vecCant[aux2];
	aux0=0; aux1=0; aux2=0; 
	
	while(codigo.empty()){
		vecCodigo[aux0] = codigo.front();
		codigo.pop_front();
		aux0++;
	}
	
	while(productos.empty()){
		vecProd[aux1] = productos.front();
		productos.pop_front();
		aux1++;
	}
		
	while(precioVenta.empty()){
		vecPrecio[aux2] = precioVenta.front();
		precioVenta.pop_front();
		aux2++;
	}
	aux2=0;
	while(cantidades.empty()){
		vecCant[aux2] = cantidades.front();
		cantidades.pop_front();
		aux2++;
	}
	for(int i=0; i<= aux0; i++){
		if(vecCodigo[i] == codigoProducto){
			cout<<"NOMBRE DEL PRODUCTO ########## PRECIO DEL PRODUCTO ########## CANTIDAD EN EXISTENCIA DEL PRODUCTO "<<vecProd[i]<<"----$"<<vecPrecio[i]<<"----"<<vecCant[i]<<endl;
			valorRet = 12;
			break;
		}
	}
	
	return valorRet;
}

double venta(double cantidad, list<double> inventario, string codigoProducto , list<string> codigo, list<string> productos, list<double> precioVenta){
	int aux0,aux1,aux2;
	double valorRet=1;
	aux0 = codigo.size();
	aux1 = productos.size();
	aux2 = precioVenta.size();
	string vecCodigo[aux0];
	string vecProd [aux1];
	aux1=0;
	aux1 = inventario.size();
	double vecPrecio [aux2], vecInvent[aux1];
	aux0=0; aux1=0; aux2=0; 
	
	while(codigo.empty()){
		vecCodigo[aux0] = codigo.front();
		codigo.pop_front();
		aux0++;
	}
	
	while(productos.empty()){
		vecProd[aux1] = productos.front();
		productos.pop_front();
		aux1++;
	}
		
	while(precioVenta.empty()){
		vecPrecio[aux2] = precioVenta.front();
		precioVenta.pop_front();
		aux2++;
	}
	aux2=0;
	while(inventario.empty()){
		vecInvent[aux2] = inventario.front();
		inventario.pop_front();
		aux2++;
	}
	for(int i=0; i<=aux0-1;i++){
		if(vecCodigo[i] == codigoProducto){
			if(vecInvent[i] >= cantidad){
				if(vecInvent[i] == cantidad){
					cout<<"Se agotaron todas las unidades en existencia del producto, es hora de surtir mas producto";
				}else if((vecInvent[i] - cantidad) <= 5){
					cout<<"Solo quedan "<<vecInvent[i] - cantidad<<" unidades en existencia\n";
				}
				valorRet = vecPrecio[i] * cantidad;
			    break;
			}else{
				cout<<"\nNo cuenta con suficiente producto en inventario  \n";
				valorRet = 0;
				break;
			}
			
		}
		
	}
	
	return valorRet;
}


list<string> modificarCodigo(string auxCodigo,list<string> codigo){
	int aux0;
	aux0 = codigo.size();
	string vecCodigo[aux0];
	aux0=0;
	
	while(codigo.empty()){
		vecCodigo[aux0] = codigo.front();
		codigo.pop_front();
		aux0++;
	}
	for(int i =0; i<=aux0-1;i++){
		if(vecCodigo[i] == auxCodigo){
			preguntaCodigo:
			cout<<"Ingrese el nuevo codigo para el producto: ";
			cin>>auxCodigo;
			if(auxCodigo == vecCodigo[i]){
				cout<<"\nIngrese otro codigo\n";
				goto preguntaCodigo;
			}
			for(int x=0; x<=aux0-1;x++){
				if(vecCodigo[x] != vecCodigo[i]){
					if(vecCodigo[x] == auxCodigo){
						cout<<"El codigo ya está registrado, utilize otro por favor";
						goto preguntaCodigo;
					}
				}
			}
			vecCodigo[i] = auxCodigo;
			cout<<"Se ha cambiado el codigo con exito";
			system("pause");
			break;
		}
	}
	for(int z=0; z<=aux0-1; z++){
		codigo.push_back(vecCodigo[z]);
	}

	
	return codigo;
}

list<double> modificaCantidades(double cantidad, list<double> inventario, string auxCodigo, list<string> codigos){
	int aux0=0;
	aux0 = inventario.size();
	double vecInvent[aux0];
	aux0=0;
	aux0 = codigos.size();
	string vecCodigos[aux0];
	aux0 = 0;
	
	while(inventario.empty()){
		vecInvent[aux0] = inventario.front();
		inventario.pop_front();
		aux0++;
	}
	aux0=0;
	while(codigos.empty()){
		vecCodigos[aux0] = codigos.front();
		codigos.pop_front();
		aux0++;
	}
	for(int i=0; i<=aux0-1;i++){
		if(vecCodigos[i] == auxCodigo){
			vecInvent[i] -= cantidad;
			break;
		}
	}
	for(int x=0; x<=aux0-1; x++){
		inventario.push_back(vecInvent[x]);
	}
	
	return inventario;
}

list<double> modificaInventario(list<double> inventario, string auxCodigo, list<string> codigos, int auxVoid){
	int aux0=0;
	aux0 = inventario.size();
	double vecInvent[aux0];
	aux0=0;
	aux0 = codigos.size();
	string vecCodigos[aux0];
	aux0 = 0;
	double cantidad;
	
	while(inventario.empty()){
		vecInvent[aux0] = inventario.front();
		inventario.pop_front();
		aux0++;
	}
	aux0=0;
	while(codigos.empty()){
		vecCodigos[aux0] = codigos.front();
		codigos.pop_front();
		aux0++;
	}

	for(int i=0; i<=aux0-1;i++){
		if(vecCodigos[i] == auxCodigo){
	pregunta:
	    cout<<"Ingrese cantidad: ";
	    cin>>cantidad;
			if(auxVoid==1){
				vecInvent[i] += cantidad;
			    break;
			}else if(vecInvent[i] > cantidad){
				vecInvent[i] -= cantidad;
				break;
			}else if(vecInvent[i] <= cantidad){
				cout<<"No puede dejar en cero la cantidad. \n";
				goto pregunta;
			}
		}
	}
	for(int x=0; x<=aux0-1; x++){
		inventario.push_back(vecInvent[x]);
	}
	
	return inventario;
}

list<string> modificarProductos(string auxCodigo, list<string> productos, list<string> codigos){
	int aux0;
	aux0 = productos.size();
	string vecProd[aux0];
	aux0=0;
	aux0 = codigos.size();
	string vecCodigos[aux0], basura, nombre;
	aux0=0;
	while(productos.empty()){
		vecProd[aux0] = productos.front();
		productos.pop_front();
		aux0++;
	}
	aux0=0;
	while(codigos.empty()){
		vecCodigos[aux0] = codigos.front();
		codigos.pop_front();
		aux0++;
	}
	for(int i=0; i <=aux0-1; i++){
		if(vecCodigos[i] == auxCodigo){
			pregunta:
			getline(cin,basura);
			cout<<"Ingrese el nuevo nombre del producto que se va a ingresar: ";
			getline(cin, nombre);
			if(nombre == vecProd[i]){
				cout<<"Ingrese otro nombre porfavor";
				goto pregunta;
			}
			for(int x=0; x<=aux0-1;x++){
				if(x != i){
					if(vecProd[x] == nombre){
						cout<<"El nombre que ingresó ya está ocupado, ingrese otro nombre por favor";
						goto pregunta;
					}
				}
			}
			vecProd[i] = nombre;
			cout<<"Se ha cambiado el nombre con exito";
			system("pause");
			break;
		}
	}
	for(int z=0; z<=aux0-1;z++){
		productos.push_back(vecProd[z]);
	}
	
	
	return productos;
}

list<double> modificarPrecioVenta(string auxCodigo, list<string> codigos, list<double> precioVenta, list<double> precioCompra){
	int aux0;
	aux0= codigos.size();
	string vecCodigos[aux0];
    aux0=0;
	aux0 = precioVenta.size();
	double vecPrecios[aux0], precio;
	aux0=0;
	aux0 = precioCompra.size();
	double vecPrecioCompra[aux0];
	aux0=0;
	
	while(codigos.empty()){
		vecCodigos[aux0] = codigos.front();
		codigos.pop_front();
		aux0++;
	}
	aux0=0;
	while(precioVenta.empty()){
		vecPrecios[aux0] = precioVenta.front();
		precioVenta.pop_front();
		aux0++;
	}
	aux0=0;
	while(!precioCompra.empty()){
		vecPrecioCompra[aux0] = precioCompra.front();
		precioCompra.pop_front();
		aux0++;
	}
	
	for(int i=0; i<=aux0-1;i++){
		if(auxCodigo == vecCodigos[i]){
			pregunta:
			cout<<"Ingrese nuevo precio de venta del producto";
			cin>>precio;
			if(precio == vecPrecios[i]){
				cout<<"Ingrese un precio diferente: ";
				goto pregunta;
		}else if(precio <= vecPrecioCompra[i]){
				cout<<"Con este precio no tendrá practicamente nada de ganancias";
				}
		vecPrecios[i] = precio;
		cout<<"\nSe ha cambiado el precio de venta con exito. \n";
		system("pause");
		break;
		}
	}
	for(int x=0; x<=aux0-1; x++){
		precioVenta.push_back(vecPrecios[x]);
	}
	return precioVenta;
}

void imprimirLista(list<string> productos, list<string> codigos, list<double> precios, list<double> inventario){
	cout<<endl<<"#################### LISTA DE PRODUCTOS ####################";
	cout<<"CODIGO DEL PRODUCTO ||| NOMBRE DEL PRODUCTO ||| PRECIO DEL PRODUCTO |||| UNIDADES EN EXISTENCIA DEL PRODUCTO";
	while(codigos.empty()){
		cout<<codigos.front()<<" ||| "<<productos.front()<<" ||| "<<precios.front()<<" ||| "<<inventario.front()<<endl;
		codigos.pop_front();
		productos.pop_front();
		precios.pop_front();
		inventario.pop_front();
	}
}

void ticketDeVenta(list<string> codigosVentaActual,list<double> cantidadesVentaActual,list<string> codigoProducto, list<double> precioVenta, list<string> productos){
	int aux0=0, aux1=0, aux2=0, aux3=0, aux4=0;
	aux1 = codigosVentaActual.size();
	aux0 = cantidadesVentaActual.size();
	aux2 = precioVenta.size();
	aux3 = codigoProducto.size();
	aux4 = productos.size();
	
	string vecProd[aux4], codigos[aux3], vecCodVA [aux1]; 
	double cantVA [aux0], precios [aux2], importe, subtotal;  
	
	aux0=0; aux1=0; aux2=0; aux3=0; aux4=0;
	
	while(codigosVentaActual.empty()){
		vecCodVA[aux1] = codigosVentaActual.front();
		codigosVentaActual.pop_front();
		aux1++;
	}
	while(cantidadesVentaActual.empty()){
		cantVA [aux0] = cantidadesVentaActual.front();
		cantidadesVentaActual.pop_front();
		aux0++;
	}
	while(precioVenta.empty()){
		precios[aux2] = precioVenta.front();
		precioVenta.pop_front();
		aux2++;
	}
	while(codigoProducto.empty()){
		codigos[aux3] = codigoProducto.front();
		codigoProducto.pop_front();
		aux3++;
	}
	while(productos.empty()){
		vecProd[aux4] = productos.front();
		productos.pop_front();
		aux4++;
	}
	system("pause");
	cout<<"######################### TICKET DE VENTA #########################";
	cout<<"CODIGO DEL PRODUCTO ########## NOMBRE DEL PRODUCTO ########## PRECIO UNITARIO DEL PRODUCTO ########## CANTIDAD DEL PRODUCTO ########## IMPORTE ";
	for(int i=0; i<=aux1-1; i++){
		for(int x=0; x <= aux4-1; x++){
			if(vecCodVA[i] == codigos[x]){
				importe = cantVA[i] * precios[x];
				subtotal += importe;
				cout<<vecCodVA[i]<<" --- " << vecProd[x] <<" --- $"<< precios[x] << " --- "<< cantVA[i]<< " --- $"<<importe<<endl;
			}
		}
		
	}
	cout<<"El subtotal es: $"<<subtotal<<endl;
	system("pause");
}

double buscarCliente(list<string> listaClientes,list<double> cuentasPorCobrar,list<int> idClientes, int auxId){
	int aux0, aux1, aux2;
	
	aux0 = listaClientes.size();
	aux1 = cuentasPorCobrar.size();
	aux2 = idClientes.size();
	string clientes[aux0];
	int id[aux2];
	double cuenta[aux1], creditoDisp;
	
	aux0=0;
	while(listaClientes.empty()){
		clientes[aux0] = listaClientes.front();
		listaClientes.pop_front();
		aux0++;
	}
	aux1=0;
	while(cuentasPorCobrar.empty()){
		cuenta[aux1] = cuentasPorCobrar.front();
		cuentasPorCobrar.pop_front();
		aux1++;
	}
	aux2=0;
	while(idClientes.empty()){
		id[aux2] = idClientes.front();
		idClientes.pop_front();
		aux2++;
	}
	
	for(int i=0; i<= aux2-1;i++){
		if(auxId == id[i]){
			cout<<"CLIENTE ENCONTRADO"<<id[i]<<" ########## "<<clientes[i]<<endl;
			cout<<"Debe un total de: ---$"<<cuenta[i]<<endl;
			if(cuenta[i] == 5000){
				cout<<"Ha llegado al limite de su credito.";
			}else if(cuenta[i] < 5000){
				creditoDisp = 5000 - cuenta[i];
				return creditoDisp;
			}
		}
	}
	return 0;
}

list<double> abonoCuenta(list <int> idClientes, list<double> cuenta, list<string> clientes, int auxId){
	list<double> listaCuenta;
	int aux0, aux1, aux2;
	aux0 = idClientes.size();
	aux1 = cuenta.size();
	aux2 = clientes.size();
	int id[aux0];
	double deuda[aux1], cantidadAbonar;
	string nombres[aux2], auxResp, valuador;
	aux0=0; aux1=0; aux2=0;
	
	while(idClientes.empty()){
		id[aux0] = idClientes.front();
		idClientes.pop_front();
		aux0++;
	}
	while(cuenta.empty()){
	    deuda[aux1] = cuenta.front();
		cuenta.pop_front();
		aux1++;
	}
	while(clientes.empty()){
		nombres[aux2] = clientes.front();
		clientes.pop_front();
		aux2++;
	}
	for(int i=0; i<=aux0-1;i++){
		if(id[i] == auxId){
			cout<<"El Cliente seleccionado: "<<nombres[i]<<"Debe un total de: "<<deuda[i]<<endl;
			if(deuda[i] > 0){
				goto ingresarCant;
			}else{
				cout<<"El cliente no puede abonar porque no tiene deuda. \n";
				goto salir;
			}
			ingresarCant:
			cout<<"Cuanto desea abonar? \n";
			cin>>cantidadAbonar;
			if(cantidadAbonar > 0 and cantidadAbonar <= deuda[i]){
				pregunta:
				cout<<"\nSeguro que desea abonar $"<<cantidadAbonar<<" a la cuenta de "<<nombres[i]<<"?"<<endl;
				cout<<"SI o NO\n";
				cin>>auxResp;
				if(auxResp == "SI" or auxResp == "Si" or auxResp == "si"){
					deuda[i] -= cantidadAbonar;
					cout<<"\nSe ha abonado $"<<cantidadAbonar<<" con exito.\nNuevo saldo es: "<<deuda[i]<<endl;
					break;
				}else if(auxResp == "NO" or auxResp == "No" or auxResp == "no"){
					cout<<"Operacion cancelada con exito. \n";
					break; 
				}else{
					cout<<"\nIngrese respuesta valida..\n";
					goto pregunta;
				}
				
			}else{
				cout<<"\nCantidad erronea... Ingrese cantidad valida porfavor.\n";
				system("pause");
				goto ingresarCant;
			}
		}
	}
	salir:
	for(int x=0; x<= aux0-1; x++){
			listaCuenta.push_back(deuda[x]);
	}
	
	system("pause");
	return listaCuenta;
}

list<double> ventaClientes(list<int> idClientes, list<double> cuenta, int auxId, double cantidadVenta){
	int aux0, aux1;
	list<double> listaRet;
	aux0= idClientes.size();
	aux1=cuenta.size();
	int clientes[aux0];
	double deuda[aux1];
	aux0=0; aux1=0;
	
	while(idClientes.empty()){
		clientes[aux0] = idClientes.front();
		idClientes.pop_front();
		aux0++;
	}
	while(cuenta.empty()){
		deuda[aux1] = cuenta.front();
		cuenta.pop_front();
		aux1++;
	}
	for(int i =0; i<=aux0-1;i++){
		if(clientes[i] == auxId){
			deuda[i] += cantidadVenta;
		}	
	}
	for(int x=0; x<=aux1;x++){
		listaRet.push_back(deuda[x]);
	}
	return listaRet;
}

list<double> cancelarVenta(list<double> cantidadesVA, list<double> cantidades, list<string> codigoProducto, list<string> codigosVA){
	int aux0=0, aux1=0, aux2=0, aux3=0;
	aux0= cantidadesVA.size();
	aux1= cantidades.size();
	aux2= codigoProducto.size();
	aux3= codigosVA.size();
	double vecCantVA[aux0], vecCant[aux1];
	string vecCodigos[aux2], vecCodigosVA[aux3];
	aux0=0, aux1=0, aux2=0, aux3=0;
	
	while(cantidadesVA.empty()){
		vecCantVA[aux0] = cantidadesVA.front();
		cantidadesVA.pop_front();
		aux0++;
	}
	while(cantidades.empty()){
		vecCant[aux1] = cantidades.front();
		cantidades.pop_front();
		aux1++;
	}	
	while(codigoProducto.empty()){
		vecCodigos[aux2] = codigoProducto.front();
		codigoProducto.pop_front();
		aux2++;
	}	
	while(codigosVA.empty()){
		vecCodigosVA[aux3] = codigosVA.front();
		codigosVA.pop_front();
		aux3++;
	}	
	
	for(int i=0; i<=aux3-1; i++){
		for(int x=0; x<=aux2-1; x++){
			if(vecCodigosVA[i] == vecCodigos[x]){
				vecCant[x] += vecCantVA[i];
			}
		}
	}
	for(int z=0; z<=aux2-1;z++){
		cantidades.push_back(vecCant[z]);
	}
	return cantidades;
}

void corteCaja(list<string> codigos, list<string> codigosFinal, list<int> idClientes, list<int> idClientesFinal, list<double> cantFinal, list<double> importeFinal, list<string> productos, list<string> listaClientes, list<double> precioCompra){	
	int aux0=0, aux1=0, aux2=0, aux3=0, aux4=0, aux5=0, aux6=0, aux7=0, aux8=0;
	aux0= codigos.size(); aux1= codigosFinal.size(); aux2= idClientes.size(); aux3= idClientesFinal.size();
	aux4= cantFinal.size(); aux5 = importeFinal.size(); aux6= productos.size(); aux7= listaClientes.size();
	aux8= precioCompra.size();
	string vecCod[aux0], vecCodFinal[aux1], vecProd[aux6], vecClientes[aux7];
	int vecIdClientes[aux2], vecIdClientesFinal[aux3];
	double vecCantFinal[aux4], vecImporteFinal[aux5], vecPrecios[aux8], granTotal;
	aux0=0, aux1=0, aux2=0, aux3=0, aux4=0, aux5=0, aux6=0, aux7=0, aux8=0;
	
	while(codigos.empty()){
		vecCod[aux0] = codigos.front();
		codigos.pop_front();
		aux0++;
	}
	while(codigosFinal.empty()){
		vecCodFinal[aux1] = codigosFinal.front();
		codigosFinal.pop_front();
		aux1++;
	}
	while(idClientes.empty()){
		vecIdClientes[aux2] = idClientes.front();
		idClientes.pop_front();
		aux2++;
	}
	while(idClientesFinal.empty()){
		vecIdClientesFinal[aux2] = idClientesFinal.front();
		idClientesFinal.pop_front();
		aux2++;
	}
	while(cantFinal.empty()){
		vecCantFinal[aux4] = cantFinal.front();
		cantFinal.pop_front();
		aux4++;
	}
	while(importeFinal.empty()){
		vecImporteFinal[aux5] = importeFinal.front();
		importeFinal.pop_front();
		aux5++;
	}
	while(productos.empty()){
		vecProd[aux6] = productos.front();
		productos.pop_front();
		aux6++;
	}
	while(listaClientes.empty()){
		vecClientes[aux7] = listaClientes.front();
		listaClientes.pop_front();
		aux7++;
	}
	while(precioCompra.empty()){
		vecPrecios[aux8] = precioCompra.front();
		precioCompra.pop_front();
		aux8++;
	}							

    cout<<"########################## VENTAS DEL DIA ############################### ";
    cout<<" NOMBRE DEL CLIENTE ---- PRODUCTOS ---- CODIGO DEL PRODUCTO---- CANTIDAD ---- PRECIO UNITARIO ---- IMPORTE";
    for(int i=0 ;i <= aux1-1; i++){
    	for(int x=0; x<=aux0-1;x++){
    		if(vecCod[x] == vecCodFinal[i]){
    			for(int z=0; z<=aux2-1; z++){
    				if(vecIdClientesFinal[i] == 0){
    					cout<<"Publico en general ---- ";
    					z = aux2+1;
					}else if(vecIdClientes[z] == vecIdClientesFinal[i]){
						cout<<"\t"<<vecClientes[z]<<" ---- ";
						z = aux2+1;
					}
				}
				cout<<vecProd[x]<<" ---- "<< vecCod[x]<<" ---- "<< vecCantFinal[i]<<" ---- $"<<vecPrecios[x]<<" ---- $"<<vecImporteFinal[i]<<endl;
				granTotal += vecImporteFinal[i];			
			}
		}
	}
	cout<<"######################### ES UN GRAN TOTAL DE $"<<granTotal<<" pesos en efectivo en caja #########################"<<endl;
	
	system("pause");
}

int main(){
	setlocale(LC_CTYPE, "Spanish");
	
	list<string> productos, codigoProducto, codigosVentaActual, listaClientes, codigosFinal;
	list<int> idClientes, idClientesFinal;
	list<double> precioCompra, precioVenta, inventario, cantidadesVentaActual, cuentasPorCobrar, importeFinal, cantidadesFinal;
	double auxPreciosCompra, auxPrecioVenta, cantidadVenta, auxInventario, verificador, iva, credMax=500, creditoCliente;
	int decision, auxVoid, identificador=5, auxIdCliente, movimientos=0;
	string auxProductos, auxCodigo, auxAgregar, basura, nombreCliente, auxCorteCaja;
	
	auxProductos = "Desodorante"; // Se agrega 1 producto para que la lista no inicie en 0
	codigoProducto.push_back("1");
	productos.push_back(auxProductos);
	precioVenta.push_back(20.2);
	precioCompra.push_back(15.12);
	inventario.push_back(20);
	
	auxIdCliente = 0;
	creditoCliente = 120;
	idClientes.push_back(auxIdCliente);
	listaClientes.push_back("Eduardito");
	cuentasPorCobrar.push_back(creditoCliente);
	
	auxProductos = "";
seleccionMenu:
	int auxMenu;
	system("cls");
	cout<<"1.Clientes \n2.-Productos \n3.-Corte de caja \n4.-Salir";
	cin>>auxMenu;
	if(auxMenu == 1){
		movimientos +=1;
		goto menuClientes;
	}else if(auxMenu == 2){
		movimientos +=1;
		goto menu;
	}else if(auxMenu == 3 and movimientos >0){
		goto corteCaja;
	}else if(auxMenu == 4){
		goto salir;
	}else{
		cout<<"\nIngrese respuesta valida.\n";
		system("pause");
		goto seleccionMenu;
	}	

menu:
	system("cls");
	cout<<"1.-Agregar productos nuevos \n2.-Buscar producto \n3.-Modificar inventario \n4.-Realizar venta \n5.-Ver lista de todos los productos \n6.-Volver \n"; 
	cin>>auxMenu; 
	getline(cin,basura);
	switch(auxMenu){
		case 1:
			do{
				cout<<"\nIngrese el código de producto: ";
			    cin>>auxCodigo;
			    codigoProducto.push_back(auxCodigo);
				getline(cin,basura);
				auxMenu = codigoProd(codigoProducto);
				if(auxMenu == 10){
					codigoProducto.pop_back();
					cout<<"Este codigo ya se encuentra registrado\n";
					system("pause");
					goto menu;
				}
				
				
				cout<<"Nombre de producto: "; getline(cin,auxProductos);
				productos.push_back(auxProductos);
			    cout<<"Precio de compra: ";
			    cin>>auxPreciosCompra;
			    precioCompra.push_back(auxPreciosCompra);
			    cout<<"Precio de venta: ";
			    cin>>auxPrecioVenta;
			    precioVenta.push_back(auxPrecioVenta);
			    getline(cin,basura);
			    cout<<"Cantidad: ";
			    cin>>auxInventario;
			    inventario.push_back(auxInventario);
			    preguntaAgregar:
			    cout<<"¿Desea agregar otro producto? SI o NO"<<endl;
			    cin>>auxAgregar;
			    getline(cin,basura);
			    
		    }while(auxAgregar == "Si" or auxAgregar == "SI" or auxAgregar == "si");
		    if(auxAgregar == "No" or auxAgregar == "NO" or auxAgregar == "no"){
		    	goto menu;
			}else{
				cout<<"\n---Ingrese respuesta valida.---\n";
				system("pause");
				system("cls");
				goto preguntaAgregar;
			}
		     
		break;
		case 2:
			system("cls");
			cout<<"\nIngrese codigo de producto a buscar: ";
			cin>>auxCodigo;
			auxMenu = busquedaProducto(auxCodigo, codigoProducto, productos, precioVenta, inventario);
			if(auxMenu == 12){
				system("pause");
				goto menu;
			}else{
				cout<<"\nProducto no encontrado... Volviendo al menu..."<<endl;
				system("pause");
				goto menu;
			}
			break;
		case 3:
			cout<<"\nIngrese el codigo del producto que desea modificar: ";
			cin>>auxCodigo;
			auxMenu = busquedaProducto(auxCodigo, codigoProducto, productos, precioVenta, inventario);
			if(auxMenu == 12){
				system("pause");
				goto preguntaModificar;
			}else{
				cout<<"\nCodigo no encontrado... Volviendo al menu..."<<endl;
				system("pause");
				goto menu;
			}
		preguntaModificar:	
		    system("cls");		
			cout<<"Que desea modificar de este producto? \n";
			cout<<"1.-Codigo identificador \n2.-Nombre de producto \n3.-Precio de venta \n4.-Cantidad \n";
			cin>>identificador;
			switch(identificador){
				case 1:
					codigoProducto = modificarCodigo(auxCodigo, codigoProducto);
					break;
				case 2:
					productos = modificarProductos(auxCodigo, productos, codigoProducto);
					break;
				case 3:
					precioVenta = modificarPrecioVenta(auxCodigo, codigoProducto, precioVenta, precioCompra);
					break;
				case 4:
					cout<<"\nDesea sumar o restar las cantidades? \n1.-Sumar ---- 2.-Restar \n";
					cin>>auxVoid;
					getline(cin,basura);
			        inventario = modificaInventario(inventario, auxCodigo, codigoProducto, auxVoid);
					break;
				default:
				goto preguntaModificar;		
			} 
			goto menu;
			break;
		case 4:
			limpiarListas:
			while(!codigosVentaActual.empty()){
				codigosVentaActual.pop_front();
			}
			while(!cantidadesVentaActual.empty()){
				cantidadesVentaActual.pop_front();
			}
			
			inicioVenta:
			auxPrecioVenta=0;
			creditoCliente=0;
			cout<<creditoCliente;
			cout<<"\n1.-Seleccionar cliente \n2.-Publico en general. \n";
			cin>>auxMenu;
			if(auxMenu == 1){
				cout<<"\nIngrese el ID del cliente.";
				cin>>auxIdCliente;
				creditoCliente = buscarCliente(listaClientes, cuentasPorCobrar, idClientes, auxIdCliente);
				cout<<creditoCliente<<endl;
				system("pause");
				if(creditoCliente <= 500 and creditoCliente > 0){
					goto capturaVenta;
				}else{
					cout<<"\nEste cliente ya no se le puede fiar. Pidale un abono urgentemente.\n";
					system("pause");
					goto inicioVenta;
				}
			}else if(auxMenu == 2){
				cout<<"\nVenta a publico en genral..."<<endl;
				system("pause");
			}
			while(auxCodigo != "OK"){
				auxPrecioVenta=0;
			capturaVenta:
			    getline(cin,basura);
			    system("cls");
			    cout<<"---INGRESE 'OK' PARA FINALIZAR LA VENTA---";
			    cout<<"\nIngrese codigo de producto: ";
			    cin>>auxCodigo;
			    if(auxCodigo == "OK" or auxCodigo == "Ok" or auxCodigo == "ok"){
				    goto finalVenta;
			    }
			    auxMenu = busquedaProducto(auxCodigo, codigoProducto, productos, precioVenta, inventario);
			    if(auxMenu == 12){
				capturaCant:
				    cout<<"\nIngrese cantidad que desea vender: ";
				    cin>>cantidadVenta;
				    if(cantidadVenta > 0){
				    	verificador = auxPrecioVenta;
					    auxPrecioVenta += venta(cantidadVenta,inventario , auxCodigo, codigoProducto, productos, precioVenta);
					    if(verificador == auxPrecioVenta){
					    	goto capturaVenta;
						}else{
							cout<<"\nAGREGADO...\n";
							system("pause");
							codigosVentaActual.push_back(auxCodigo);
							cantidadesVentaActual.push_back(cantidadVenta);
							inventario = modificaCantidades(cantidadVenta, inventario, auxCodigo, codigoProducto);
							goto capturaVenta;
						}
					finalVenta:
					    if(auxPrecioVenta > 0 ){
					    	if(creditoCliente > 0 and creditoCliente > auxPrecioVenta){
					    			iva = (auxPrecioVenta * .16);
									auxPrecioVenta += iva;
					    			cuentasPorCobrar = ventaClientes(idClientes, cuentasPorCobrar, auxIdCliente, auxPrecioVenta);
					    			system("pause");
					    			ticketDeVenta(codigosVentaActual, cantidadesVentaActual, codigoProducto, precioVenta, productos);
						            cout<<"########################### IVA 16 % : $"<< iva<<endl;
							        cout<<"########################### Es un total de $"<<auxPrecioVenta <<endl;
							        idClientesFinal.push_back(auxIdCliente);
							        while(!codigosVentaActual.empty()){
							        	codigosFinal.push_back(codigosVentaActual.front());
							        	codigosVentaActual.pop_front();
									}
									while(!cantidadesVentaActual.empty()){
										cantidadesFinal.push_back(cantidadesVentaActual.front());
										cantidadesVentaActual.pop_front();
									}
									importeFinal.push_back(auxPrecioVenta);
									
									system("pause");
							        goto menu;
							}else if(creditoCliente < auxPrecioVenta and creditoCliente > 0){
								cout<<"\nNo se puede.\n";
								inventario = cancelarVenta(cantidadesVentaActual, inventario, codigoProducto, codigosVentaActual);
								goto limpiarListas;
							}else{
								ticketDeVenta(codigosVentaActual, cantidadesVentaActual, codigoProducto, precioVenta, productos);
					    	    iva = (auxPrecioVenta * .16);
					    	    auxPrecioVenta += iva;
						        cout<<"########################### IVA 16 % : $"<< iva<<endl;
							    cout<<"########################### Es un total de $"<<auxPrecioVenta <<endl;
								auxIdCliente = 0;
								idClientesFinal.push_back(auxIdCliente);
								importeFinal.push_back(auxPrecioVenta);
								while(!codigosVentaActual.empty()){
							        codigosFinal.push_back(codigosVentaActual.front());
							        codigosVentaActual.pop_front();
								}
								while(!cantidadesVentaActual.empty()){
									cantidadesFinal.push_back(cantidadesVentaActual.front());
									cantidadesVentaActual.pop_front();
								}
							    system("pause");
							    goto menu;
							}
					    	
					    }else{
						    system("pause");
						    goto menu;
					    }
					
				    }else{
					    cout<<"\nIngrese una cantidad valida";
					    system("pause");
					    goto capturaCant;
				    }
			    }else{
				    cout<<"El producto no ha sido encontrado"<<endl;
				    system("pause");
				    goto capturaVenta;
			}
		}
		goto menu;
		case 5:
			imprimirLista(productos, codigoProducto, precioVenta, inventario);
			cout<<endl;
			system("pause");
			goto menu;
			break;
			
		case 6:
			goto seleccionMenu;
			break;
		default:
		goto menu;	
	
	}
menuClientes: 
    auxMenu=0;
    system("cls");
    cout<<"1.-Agregar cliente nuevo \n2.-Abonar a cuenta \n3.-Buscar cliente \n";
    cin>>auxMenu;
    switch(auxMenu){
    	case 1:
    		getline(cin, basura);
    		cout<<"\nIngrese el nombre completo del cliente: ";
			getline(cin, nombreCliente);
			auxIdCliente += 1;
			idClientes.push_back(auxIdCliente);
			listaClientes.push_back(nombreCliente);
			cuentasPorCobrar.push_back(1);
			cout<<"\nSe agrego con exito al cliente su ID es: "<<auxIdCliente<<". \nCuenta con un credito maximo de: $"<<credMax<<endl;
			system("pause");
			goto seleccionMenu;
		case 2:
			cout<<"\nIngrese el ID del cliente que desea abonar: \n";
			cin>>auxIdCliente;
			cuentasPorCobrar = abonoCuenta(idClientes, cuentasPorCobrar, listaClientes, auxIdCliente);
		    system("pause");
			goto seleccionMenu;
		    
		case 3:
			cout<<"\nIngrese ID del cliente: ";
			cin>>auxIdCliente;
			auxVoid = buscarCliente(listaClientes, cuentasPorCobrar, idClientes, auxIdCliente);
			system("pause");
			if(auxVoid == 0){
				cout<<"\nNo se encontro ningun cliente con ese ID. \n";
				system("pause");
				goto menuClientes;
			}
			system("pause");
			goto seleccionMenu;    	
    	default:
    		goto menuClientes;
	}
corteCaja:
	getline(cin, basura);
	system("cls");
	cout<<"Seguro que desea realizar el corte de caja? \n";
	cout<<"SI \nNO \n";
	cin>>auxCorteCaja;
	if(auxCorteCaja == "SI" or auxCorteCaja == "Si" or auxCorteCaja == "si"){
		corteCaja(codigoProducto, codigosFinal, idClientes, idClientesFinal, cantidadesFinal, importeFinal, productos, listaClientes, precioVenta);
	}else if(auxCorteCaja == "NO" or auxCorteCaja == "No" or auxCorteCaja == "no"){
		cout<<"Volviendo al menu";
		system("pause");
		goto seleccionMenu;
	}else{
		goto seleccionMenu;
	}
	
	
	goto seleccionMenu; 
	 salir:
	     
	return 0;
}

// Codigo terminado
