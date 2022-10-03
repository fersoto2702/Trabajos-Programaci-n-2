#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int main ()
{
	int opc, control=1, control1=1, pin, clave=2702,saldo= 20000, nclave;
	double retiro;
		
		while(control==1)
		{	system("cls");
			printf("#############################################\n");
			printf("BIENVENIDO(A) A SU CAJERO \n");
			printf("#############################################\n");
			printf("INGRESE SU CLAVE PARA ACCEDER: \n");
			scanf("%d",&pin);
			system("Pause");
			if(pin==clave)
			{
					control1==1;
					while (control==1)
					{
			printf("#############################################\n");
			printf("CAJERO \n");
			printf("#############################################\n");
			printf("1.CONSULTAR SU SALDO DISPONIBLE\n");
			printf("2.RETIRAR DINERO\n");
			printf("3.CAMBIAR SU NIP\n");
			printf("4.SALIR\n");
			printf("INGRESE UNA OPCION\n");
			scanf("%d",&opc);
			switch(opc)
			{
				case 1:
				system("cls");
				printf("CONSULTAR SALDO DISPONIBLE  \n");
				printf("SU SALDO DISPONIBLE ES: %d\n",saldo);
				system("Pause");
				break;
				case 2:
				system("cls");
				printf("RETIRAR SALDO  \n");
				printf("LA CANTIDAD A RETIRAR ES: \n");	
				scanf("%lf",&retiro);
				if(retiro>saldo)
				{
				printf("LA CANTIDAD A RETIRAR ES MAYOR QUE EL SALDO DISPONIBLE: \n");
				printf("SU SALDO DISPONIBLE ES: \n",saldo);
				system("Pause");
				}
				else
				{
					saldo=saldo-retiro;
					printf("EL RETIRO HAS SIDO EXITOSO \n");
					system("Pause");
				}
				break;
				case 3:
					system("cls");
					printf("CAMBIAR NIP  \n");
					printf("INGRESE SU CLAVE ACTUAL:  \n");
					scanf("%d",&pin);
					if (pin==clave)
					{
					printf("INGRESE SU NUEVA CLAVE \n");
					scanf("%d",&nclave);
					clave=0;
					clave=clave;
					printf("CAMBIO DE NIP EJECUTADO PERFECTAMENTE  \n");
					printf("PARA VOLVER A INGRESAR AL BANCO TENDRÁ QUE INTRODUCIR SU NUEVO NIP:  \n");
					system("Pause");
					control1=0;
					}
					else
					{
						printf("LA CLAVE ES INCORRECTA  \n");
						printf("PARA VOLVER A INGRESAR AL BANCO TENDRÁ QUE INTRODUCIR SU NUEVO NIP:  \n");
						system("Pause");
					}
					break;
					case 4:
						system("cls");
			}			printf("Salir \n");
						system("Pause");
						printf("Saliendo del sistema...... \n");
						exit(-1);
						break;
						printf("opción incorrecta\n");
						printf("PARA VOLVER A INGRESAR AL BANCO TENDRÁ QUE INTRODUCIR SU NUEVO NIP:  \n");
						system("Pause");
						break;
					}
			}
			else
			{
				printf("CLAVE INCORRECTA\n");
				printf("PARA VOLVER A INGRESAR AL BANCO TENDRÁ QUE INTRODUCIR SU NUEVO NIP:  \n");
				system("Pause");
			}			
		}
}		
