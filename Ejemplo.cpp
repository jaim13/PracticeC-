#include <stdio.h>
#include <conio.h> // Para detectar la tecla presionada
#include <windows.h> // Para Sleep y detectar clics del mouse
#include <stdbool.h> // Para usar variables booleanas


// Función para verificar si se hizo clic en la ventana de la consola
bool CheckForMouseClick() {
    return (GetAsyncKeyState(VK_LBUTTON) & 0x8000) != 0;
}

// Estructura para representar a los pacientes
typedef struct {
    char nombre[20];
    int tiempo_atencion;
    char tipo_atencion[10];
    int tiempo_restante;
} Paciente;

// Función para mostrar el estado de atención de un paciente
void mostrarEstado(Paciente paciente, int tiempo_transcurrido) {
    printf("\t\t\t Atendiendo a %s (Tiempo total: %d min, Tiempo restante: %d min, Tipo de atencion: %s, Tiempo transcurrido: %d seg)\n",
           paciente.nombre, paciente.tiempo_atencion, paciente.tiempo_restante, paciente.tipo_atencion, tiempo_transcurrido);
}

int main() {

    int opcion;
    bool terminarEjecucion = false;
	while (!terminarEjecucion) { // Bucle exterior para volver al menú principal
	printf("\n\n\n\t\t\t Presione la tecla 'A' para detener la ejecucion.");
    printf("\n\n\n\t\t\t ~~~~~~~~~~~~~ MENU PRINCIPAL  ~~~~~~~~~~~~~\n");
    printf("\n\n");
    printf("\t\t\t 1.Proceso Atencion Citas : \t\t\n");
    printf("\t\t\t 2.Proceso Atencion Emergencias : \t\t\n");
    printf("\t\t\t 3.Proceso Atencion Cirugias : \t\t\n");
    printf("\n\n");
    printf("\t\t\t Opcion : ");
    char letra = _getch(); // Lee una tecla sin esperar por Enter
        if (letra == 'A' || letra == 'a') {
            printf("\nInterrupcion del usuario, Se termino la ejecucion del programa.\n");
            break; // Sale del bucle para detener la ejecución
        }

    // Leer la opción ingresada por el usuario
    scanf("%d", &opcion);

    switch (opcion) {
        case 1: {
            int pacientesAtendidos = 0;
            int tiempoAtencion = 10; // Tiempo de atención en segundos
            char interrupcion;
            int interrupcionPorUsuario = 0; // Bandera para la interrupción del usuario

            while (pacientesAtendidos < 10) {
                printf("\n\t\t\t Atendiendo paciente numero %d...", pacientesAtendidos + 1);
                int tiempo = 0;
                
                while (tiempo < tiempoAtencion) {
                	
                    if (_kbhit()) { // Se utiliza para verificar si se ha presionado una tecla en el teclado
                        interrupcion = _getch();
                        if (interrupcion == 'i' || interrupcion == 'I') {
                            interrupcionPorUsuario = 1; // Activar la bandera de interrupción
                            break;
                        }
				        else if(interrupcion == 'A' || interrupcion == 'a') {
				            terminarEjecucion = true;
				            interrupcionPorUsuario = 0;
				            break; // Sale del bucle para detener la ejecución
				        }
				        
				
                    }
                         // Simular el tiempo transcurrido
                    Sleep(1000); // 1000 milisegundos = 1 segundo

                    tiempo++;
                    
    			}

                if (interrupcionPorUsuario) {
                    printf("\n\t\t\t Interrupcion del usuario al precionar la tecla i. Volviendo al menu principal.");
                    break; // Salir del bucle principal
                }
                else if (interrupcionPorUsuario = 0){
                	printf("\n\n\t\t\t Atencion a todas las citas completada.");
				}
                
                if (terminarEjecucion){
                	printf("\n\t\t\t Interrupcion del usuario. Ejecucion terminada.");
                    break; // Salir del bucle principal
				}

                if (tiempo == tiempoAtencion) {
                    printf("\n\t\t\t Atencion paciente numero %d terminada normalmente", pacientesAtendidos + 1);
                }

                pacientesAtendidos++;

                // Pausa para simular el siguiente paciente
                printf("\n\t\t\t Presione P para atender al siguiente paciente...");
                fflush(stdin);
                getchar();
            }


            break;
        }
		    case 2: {
		    printf("\n\t\t\t Ha seleccionado el proceso de atencion a emergencias.\n");
		    printf("\t\t\t ______________\n");
		    printf("\t\t\t |            |\n");
		    printf("\t\t\t |Interrupcion|\n");
		    printf("\t\t\t |____________|\n");
		    int pacientesAtendidos = 0;
		    int tiempoTotalAtencion = 20; // Tiempo de atención total por paciente en segundos
		    bool interrupcionPorUsuario = false; // Bandera para la interrupción del usuario
		
		    while (pacientesAtendidos < 10) {
		        printf("\n\t\t\t Atendiendo al paciente %d...", pacientesAtendidos + 1);
		        int tiempo = 0;
				char letra = _getch(); // Lee una tecla sin esperar por Enter
		        if (letra == 'A' || letra == 'a') {
		            printf("\n\t\t\t Interrupcion del usuario, Se termino la ejecucion del programa.\n");
		            break; // Sale del bucle para detener la ejecución
		        }
		        while (tiempo < tiempoTotalAtencion) {
		            if (_kbhit()) { // Se utiliza para verificar si se ha presionado una tecla en el teclado
		                char tecla = _getch();
		                if (tecla == 'K' || tecla == 'k') {
		                    printf("\n\t\t\t Interrupcion por tecla 'K' durante la atencion al paciente %d. Volviendo al menu principal.\n", pacientesAtendidos + 1);
		                    interrupcionPorUsuario = true;
		                    break;
		                }
		                else if(tecla == 'A' || tecla == 'a') {
				            terminarEjecucion = true;
				            break; // Sale del bucle para detener la ejecución
				        }
		            
		            } 
				
		            
		
		            if (tiempo >= 5) {
		                // Habilitar la interrupción por pantalla al llegar al segundo 10
		                if (CheckForMouseClick()) {
		                    printf("\n\t\t\t Interrupcion por clic en boton durante la atencion al paciente %d. Volviendo al menu principal.\n", pacientesAtendidos + 1);
		                    interrupcionPorUsuario = true;
		                    break;
		                }
		            }
		
		            // Mostrar el tiempo transcurrido para el paciente actual
		            printf("\n\t\t\t Paciente %d, Tiempo de atencion: %d segundos", pacientesAtendidos + 1, tiempo + 1);
		
		            // Simular el tiempo transcurrido
		            Sleep(1000); // 1000 milisegundos = 1 segundo
		
		            tiempo++;
		        }
		
		        if (interrupcionPorUsuario) {
		            break; // Salir del bucle principal si hubo interrupción
		        }
		        
		
		        pacientesAtendidos++;
		
		        // Pausa para simular el siguiente paciente
		        printf("\n\t\t\t Presione P para atender al siguiente paciente...");
		        fflush(stdin);
		        getchar();
		    }
		
		    if (!interrupcionPorUsuario) {
		        printf("\n\t\t\t Atencion a emergencias completada (sin interrupciones).\n");
		    }
		    
		    if (terminarEjecucion){
                	printf("\n\t\t\t Interrupcion por Usuario. Ejecucion terminada.");
                    break; // Salir del bucle principal
				}
		   
		
		    break;
		}
        case 3:{
        	
                printf("\t\t\tHa seleccionado el proceso de atencion a cirugias.\n");

                // Definir los pacientes y sus atributos
                Paciente pacientes[] = {
                    {"\n\t\t\t Paciente 1", 7, "Rojo", 7},
                    {"\n\t\t\t Paciente 2", 8, "Normal", 8},
                    {"\n\t\t\t Paciente 3", 5, "Normal", 5},
                    {"\n\t\t\t Paciente 4", 11, "Rojo", 11},
                    {"\n\t\t\t Paciente 5", 9, "Verde", 9},
                    {"\n\t\t\t Paciente 6", 3, "Normal", 3}
                };

                int tiempo_total_empleado = 0;
                int tiempo_quantum = 5; // Quantum de tiempo en segundos
				
		        
                while (1) {
                	bool interrupcionPorUsuario = false;
                    bool atendiendo_paciente = false;
					if (_kbhit()) { // Se utiliza para verificar si se ha presionado una tecla en el teclado
		                char tecla = _getch();
		                if (tecla == 'A' || tecla == 'a') {
						printf("\n\t\t\t Interrupcion del usuario, Se termino la ejecucion del programa.\n");		                    
						terminarEjecucion = true;
						atendiendo_paciente = true;
		            	break;
		                }
		            }
                    for (int i = 0; i < 6; i++) {
                        if (pacientes[i].tiempo_restante > 0) {
                            atendiendo_paciente = true;
                            int tiempo_transcurrido = tiempo_quantum < pacientes[i].tiempo_restante ? tiempo_quantum : pacientes[i].tiempo_restante;
                            pacientes[i].tiempo_restante -= tiempo_transcurrido;

                            mostrarEstado(pacientes[i], tiempo_transcurrido);
                            Sleep(1000); // Simular el paso del tiempo

                            if (pacientes[i].tiempo_restante == 0) {
                                printf("\n\t\t\t Paciente %s ha sido atendido completamente.\n", pacientes[i].nombre);
                            }

                            tiempo_total_empleado += tiempo_transcurrido;
                            
                          
                        }
                    }

                    if (!atendiendo_paciente) {
                        break;
                    }
                    
                    if (terminarEjecucion){
                	printf("\n\t\t\t Interrupcion por Usuario. Ejecucion terminada.");
                    break; // Salir del bucle principal
				}
                }

                printf("\n\t\t\t Tiempo total empleado para la atencion en cuarto de todos los pacientes: %d segundos (%.2f minutos)\n",
                       tiempo_total_empleado, (float)tiempo_total_empleado / 60);
                
            }
            break;


        default:
            // Opción inválida
            printf("\n\t\t\t Opcion invalida.\n");
            break;
    }
}
    return 0;
}
