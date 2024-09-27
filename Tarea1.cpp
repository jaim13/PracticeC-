#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <iomanip> 
#include <windows.h> 
#include <vector>

using namespace std;


struct Destino
{
    int unidad;
    string nombreDestino;
    float precio;
    int cantidadPasajeros;
    int kmDestino;
};

vector<Destino> cargarDestinos()
{
    vector<Destino> listaDestinos; 
    ifstream archivo("Destinos.txt");
    if (!archivo.is_open())
    {
        cout << "No se pudo abrir el archivo Destinos.txt" << endl;
        return listaDestinos; 
    }

    string header;
    getline(archivo, header);

    Destino destino;
    while (archivo >> destino.unidad >> destino.nombreDestino >> destino.precio >> destino.cantidadPasajeros >> destino.kmDestino)
    {
        listaDestinos.push_back(destino); 
    }

    archivo.close(); 
    return listaDestinos; 
}

int main()
{
    vector<Destino> listaDestinos = cargarDestinos();
    if (listaDestinos.empty())
    {
        return 1; 
    }
    int Destinos;
    int UniProblemas;

    // Solicitar datos al usuario
    cout << "Cantidad de Destinos: ";
    cin >> Destinos;
    cout << "Unidad con problemas: ";
    cin >> UniProblemas;

    cout << "Presione Enter para continuar..." << endl;
    cin.ignore();
    cin.get();

    vector<float> totales;

    // Comparar los datos
    if (Destinos >= 3 && Destinos <= 7)
    {
        if (UniProblemas > Destinos)
        {
            cout << "Erróneo: no pueden existir más vehículos dañados que viajes salientes." << endl;
        }
        else
        {
            if (UniProblemas == 0)
            {
                // Mostrar encabezado
                cout << left << setw(12) << "No. Unidad"
                     << setw(20) << "Destino"
                     << setw(10) << "Precio"
                     << setw(20) << "Cantidad Pasajeros"
                     << setw(10) << "Km" << endl;

                for (int cont = 1; cont <= Destinos; ++cont)
                {
                    // Mostrar datos de cada unidad
                    cout << left << setw(12) << listaDestinos[cont - 1].unidad
                         << setw(20) << listaDestinos[cont - 1].nombreDestino
                         << setw(10) << fixed << setprecision(2) << listaDestinos[cont - 1].precio
                         << setw(20) << listaDestinos[cont - 1].cantidadPasajeros
                         << setw(10) << listaDestinos[cont - 1].kmDestino << endl;

                    int Pasajeros;
                    while (true)
                    {
                        cout << "Pasajeros: ";
                        cin >> Pasajeros;

                        if (Pasajeros <= 0)
                        {
                            cout << "Error: La cantidad de pasajeros debe ser mayor a 0." << endl;
                        }
                        else if (Pasajeros > listaDestinos[cont - 1].cantidadPasajeros)
                        {
                            cout << "Error: La cantidad de pasajeros no puede ser mayor a la cantidad de pasajeros permitidos en el destino." << endl;
                        }
                        else
                        {
                            break;
                        }
                    }
                    cout << "Presione Enter para continuar..." << endl;
                    cin.ignore();
                    cin.get();

                    cout << "----Empresa los Viajeros----" << endl;
                    cout << "----Salida de unidades----" << endl;
                    cout << "----Guanacaste S.A----" << endl;
                    cout << "No. Unidad: " << listaDestinos[cont - 1].unidad
                         << " Destino: " << listaDestinos[cont - 1].nombreDestino
                         << " Precio: " << fixed << setprecision(2) << listaDestinos[cont - 1].precio
                         << " Kilómetros: " << listaDestinos[cont - 1].kmDestino << endl;
                    cout << "Pasajeros: " << Pasajeros << std::endl;
                    cout << "Avance en KM: ";
                    for (int km = 1; km <= listaDestinos[cont - 1].kmDestino; ++km)
                    {
                        cout << km << " ";
                        Sleep(3000);

                        // Verificar si se presionó una tecla
                        if (_kbhit())
                        {
                            char c = _getch();
                            if (c == 'i' || c == 'I')
                            {
                                cout << "\nHubo un problema con el transporte. Terminado el viaje." << endl;
                                break;
                            }
                        }
                    }
                    cout << endl;
                    float DestinoTotal;

                    DestinoTotal = Pasajeros * listaDestinos[cont - 1].precio;
                    totales.push_back(DestinoTotal);
                    cout << "Total del Destino: $" << fixed << setprecision(2) << DestinoTotal << endl;
                }
                cout << "------------------------------------------------------------------------------" << endl;
                cout << "\nTotales de los destinos:\n";
                for (size_t i = 0; i < totales.size(); ++i)
                {
                    cout << "Destino " << (i + 1) << ": $" << fixed << setprecision(2) << totales[i] << endl;
                }

                float sumaTotal = 0.0f;
                for (const float &total : totales)
                {
                    sumaTotal += total;
                }
                cout << "------------------------------------------------------------------------------" << endl;
                cout << "Suma total de todos los destinos: $" << fixed << setprecision(2) << sumaTotal << endl;
                cout << "Unidades con averias: " << UniProblemas << endl;
                cout << "------------------------------------------------------------------------------" << endl;
            }
            else
            {
                cout << "Pronto se programará." << endl;
            }
        }
    }
    else
    {
        cout << "Cantidad de destinos errónea." << endl;
    }

    return 0;
}
