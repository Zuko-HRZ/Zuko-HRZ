/*
UNIVERSIDAD TECNOLOGICA DE BOLIVAR
TRABAJO SEMANA 14
NOMBRE DEL PROGRAMA: ArchivosDeIMC
FECHA: 28/10/2024
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

struct datos {
    string nombre;
    int eda;
    float peso;
    float altura;
    char genero;
    float imc;
};

// Prototipos
void llenar_Datos(datos p[], int n);
void Guardar_Datos(datos p[], int n, const string& nombre_Archivo);
void Guardar_F(datos p[], int n, const string& nombre_archivo);
void Guardar_M(datos p[], int n, const string& nombre_archivo);
void Guardar_JSP(datos p[], int n, const string& nombre_archivo);
void Guardar_JBP(datos p[], int n, const string& nombre_archivo);
void Guardar_P_OB(datos p[], int n, const string& nombre_archivo);
void Guardar_A_M(datos p[], int n, const string& nombre_archivo);
void menu();
void menu_2();
void menu_2_Desarrollo(datos p[], int n);

// Función principal
int main() {
    int num_p, opcion_1;
    datos persona[20];
    
    cout << "Número de personas <1/30>: ";
    cin >> num_p;
    while (num_p < 1 || num_p > 30) {
        cout << "Valor no aceptado; Ingresa de nuevo <1/30>: "; 
        cin >> num_p;
    }
    
    do {
        menu();
        cin >> opcion_1;
        switch (opcion_1) {
            case 1:
                llenar_Datos(persona, num_p);
                Guardar_Datos(persona, num_p, "Datos.csv");
                break;
            case 2:
                menu_2_Desarrollo(persona, num_p);
                break;
            case 3:
                opcion_1 = 0;
                cout << "\nTenga un excelente día." << endl;
                break;
            default:
                cout << "Opción no identificada.\n";
                break;
        }
    } while (opcion_1 != 0);

    return 0;
}

// Llenar los datos en el struct
void llenar_Datos(datos p[], int n) {
    cin.ignore(); // Ignorar el salto de línea residual después de leer num_p
    for (int i = 0; i < n; i++) {
        cout << "Nombre de la persona #" << i + 1 << ": "; 
        getline(cin, p[i].nombre);
        cout << "Edad de la persona #" << i + 1 << ": "; 
        cin >> p[i].eda;
        cout << "Peso de la persona #" << i + 1 << ": "; 
        cin >> p[i].peso;
        cout << "Altura de la persona #" << i + 1 << ": "; 
        cin >> p[i].altura;
        cout << "Género <m/f> de la persona #" << i + 1 << ": "; 
        cin >> p[i].genero;
        cin.ignore();
        
        while (p[i].genero != 'm' && p[i].genero != 'f') {
            cout << "Introduzca nuevamente el género <m/f>: "; 
            cin >> p[i].genero;
        }
    }

    for (int h = 0; h < n; h++) {
        p[h].imc = p[h].peso / pow(p[h].altura, 2);
        cout << "IMC Persona #" << h + 1 << ": " << p[h].imc << endl;
    }
}

// Guardar los datos en el archivo
void Guardar_Datos(datos p[], int n, const string& nombre_Archivo) {
    ofstream archivo(nombre_Archivo);
    if (archivo.is_open()) {
        archivo << "Datos de todos los Individuos\n";
        archivo << "Nombre;Edad;Peso;Altura;Género;IMC\n";
        for (int i = 0; i < n; i++) {
            archivo << p[i].nombre << ";"
                    << p[i].eda << ";"
                    << p[i].peso << ";"
                    << p[i].altura << ";"
                    << p[i].genero << ";"
                    << p[i].imc << "\n";
        }
        archivo.close();
        cout << "El archivo fue generado correctamente\n";
    } else {
        cout << "El archivo no fue generado\n";
    }
}

// Guardar datos de las mujeres (Datos-F.csv)
void Guardar_F(datos p[], int n, const string& nombre_archivo) {
    ofstream archivo(nombre_archivo);
    int con_f = 0;
    if (archivo.is_open()) {
        archivo << "Datos de las personas con género femenino (f)\n";
        archivo << "Nombre;Edad;Peso;Altura;Género;IMC\n";
        for (int i = 0; i < n; i++) {
            if (p[i].genero == 'f') {
                con_f++;
                archivo << p[i].nombre << ";"
                        << p[i].eda << ";"
                        << p[i].peso << ";"
                        << p[i].altura << ";"
                        << p[i].genero << ";"
                        << p[i].imc << "\n";
            }
        }
        if (con_f == 0) {
            archivo << "\nNo hay individuos válidos para este documento\n";
        }
        archivo.close();
        cout << "El archivo con los datos de las mujeres ha sido escrito correctamente ('Datos-F.csv')\n";
    } else {
        cout << "El archivo no pudo ser generado correctamente\n";
    }
}

// Guardar datos de los hombres (Datos-M.csv)
void Guardar_M(datos p[], int n, const string& nombre_archivo) {
    ofstream archivo(nombre_archivo);
    int con_m = 0;
    if (archivo.is_open()) {
        archivo << "Datos de las personas con género masculino (m)\n";
        archivo << "Nombre;Edad;Peso;Altura;Género;IMC\n";
        for (int i = 0; i < n; i++) {
            if (p[i].genero == 'm') {
                con_m++;
                archivo << p[i].nombre << ";"
                        << p[i].eda << ";"
                        << p[i].peso << ";"
                        << p[i].altura << ";"
                        << p[i].genero << ";"
                        << p[i].imc << "\n";
            }
        }
        if (con_m == 0) {
            archivo << "\nNo hay individuos válidos para este documento\n";
        }
        archivo.close();
        cout << "El archivo con los datos de los hombres se generó correctamente ('Datos-M.csv')\n";
    } else {
        cout << "El archivo no pudo ser generado correctamente\n";
    }
}

// Guardar datos de jóvenes con sobrepeso (Datos-J-SP.csv)
void Guardar_JSP(datos p[], int n, const string& nombre_archivo) {
    ofstream archivo(nombre_archivo);
    int con_JSP = 0;
    if (archivo.is_open()) {
        archivo << "Datos de los jóvenes con sobrepeso\n";
        archivo << "Nombre;Edad;Peso;Altura;Género;IMC\n";
        for (int i = 0; i < n; i++) {
            if (p[i].eda < 25 && p[i].imc > 25) {
                con_JSP++;
                archivo << p[i].nombre << ";"
                        << p[i].eda << ";"
                        << p[i].peso << ";"
                        << p[i].altura << ";"
                        << p[i].genero << ";"
                        << p[i].imc << "\n";
            }
        }
        if (con_JSP == 0) {
            archivo << "\nNo hay individuos válidos para este archivo\n";
        }
        archivo.close();
        cout << "El archivo con los datos de los jóvenes con sobrepeso ('Datos-J-SP.csv') ha sido generado\n";
    } else {
        cout << "El archivo no pudo ser generado correctamente\n";
    }
}

// Guardar datos de jóvenes con bajo peso (Datos-J-BP.csv)
void Guardar_JBP(datos p[], int n, const string& nombre_archivo) {
    ofstream archivo(nombre_archivo);
    int con_JBP = 0;
    if (archivo.is_open()) {
        archivo << "Datos de jóvenes con bajo peso\n";
        archivo << "Nombre;Edad;Peso;Altura;Género;IMC\n";
        for (int i = 0; i < n; i++) {
            if (p[i].eda < 25 && p[i].imc < 18.5) {
                con_JBP++;
                archivo << p[i].nombre << ";"
                        << p[i].eda << ";"
                        << p[i].peso << ";"
                        << p[i].altura << ";"
                        << p[i].genero << ";"
                        << p[i].imc << "\n";
            }
        }
        if (con_JBP == 0) {
            archivo << "\nNo hay individuos válidos para este archivo\n";
        }
        archivo.close();
        cout << "El archivo con los datos de los jóvenes con bajo peso ('Datos-J-BP.csv') se generó\n";
    } else {
        cout << "El archivo no pudo ser generado correctamente\n";
    }
}

// Guardar personas con obesidad (Datos-P-OB.csv)
void Guardar_P_OB(datos p[], int n, const string& nombre_archivo) {
    ofstream archivo(nombre_archivo);
    int con_POB = 0;
    if (archivo.is_open()) {
        archivo << "Datos de personas con obesidad\n";
        archivo << "Nombre;Edad;Peso;Altura;Género;IMC\n";
        for (int i = 0; i < n; i++) {
            if (p[i].imc > 30) {
                con_POB++;
                archivo << p[i].nombre << ";"
                        << p[i].eda << ";"
                        << p[i].peso << ";"
                        << p[i].altura << ";"
                        << p[i].genero << ";"
                        << p[i].imc << "\n";
            }
        }
        if (con_POB == 0) {
            archivo << "\nNo hay individuos válidos para este archivo\n";
        }
        archivo.close();
        cout << "El archivo con los datos de las personas con obesidad ('Datos-P-OB.csv') se generó correctamente\n";
    } else {
        cout << "El archivo no pudo ser generado correctamente\n";
    }
}

// Guardar adultos mayores (Datos-A-M.csv)
void Guardar_A_M(datos p[], int n, const string& nombre_archivo) {
    ofstream archivo(nombre_archivo);
    int con_A_M = 0;
    if (archivo.is_open()) {
        archivo << "Datos de adultos mayores\n";
        archivo << "Nombre;Edad;Peso;Altura;Género;IMC\n";
        for (int i = 0; i < n; i++) {
            if (p[i].eda >= 60) {
                con_A_M++;
                archivo << p[i].nombre << ";"
                        << p[i].eda << ";"
                        << p[i].peso << ";"
                        << p[i].altura << ";"
                        << p[i].genero << ";"
                        << p[i].imc << "\n";
            }
        }
        if (con_A_M == 0) {
            archivo << "\nNo hay individuos válidos para este archivo\n";
        }
        archivo.close();
        cout << "El archivo con los datos de los adultos mayores ('Datos-A-M.csv') se generó correctamente\n";
    } else {
        cout << "El archivo no pudo ser generado correctamente\n";
    }
}

// Menú principal
void menu() {
    cout << "\nMENU PRINCIPAL:\n";
    cout << "1. Registrar los datos de las personas\n";
    cout << "2. Generar archivos CSV específicos\n";
    cout << "3. Salir\n";
    cout << "Seleccione una opción: ";
}

// Menú secundario
void menu_2() {
    cout << "\nMENU SECUNDARIO:\n";
    cout << "1. Guardar datos de las mujeres\n";
    cout << "2. Guardar datos de los hombres\n";
    cout << "3. Guardar datos de jóvenes con sobrepeso\n";
    cout << "4. Guardar datos de jóvenes con bajo peso\n";
    cout << "5. Guardar personas con obesidad\n";
    cout << "6. Guardar adultos mayores\n";
    cout << "0. Regresar al menú principal\n";
    cout << "Seleccione una opción: ";
}

// Desarrollo del menú secundario
void menu_2_Desarrollo(datos p[], int n) {
    int opcion_2;
    do {
        menu_2();
        cin >> opcion_2;
        switch (opcion_2) {
            case 1:
                Guardar_F(p, n, "Datos-F.csv");
                break;
            case 2:
                Guardar_M(p, n, "Datos-M.csv");
                break;
            case 3:
                Guardar_JSP(p, n, "Datos-J-SP.csv");
                break;
            case 4:
                Guardar_JBP(p, n, "Datos-J-BP.csv");
                break;
            case 5:
                Guardar_P_OB(p, n, "Datos-P-OB.csv");
                break;
            case 6:
                Guardar_A_M(p, n, "Datos-A-M.csv");
                break;
            case 0:
                cout << "Regresando al menú principal...\n";
                break;
            default:
                cout << "Opción no válida. Intente de nuevo.\n";
                break;
        }
    } while (opcion_2 != 0);
}
