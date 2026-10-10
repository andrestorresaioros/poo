/*
 * Ejercicio de programación orientada a objetos en C++.
 *
 * Por cada uno de los N estudiantes de la universidad se registra:
 *   - Edad
 *   - Sexo     (1. Masculino; 2. Femenino)
 *   - Carrera  (1. Ingeniería; 2. Contaduría; 3. Derecho; 4. Otra)
 *   - Jornada  (1. Diurna; 2. Nocturna)
 *
 * El programa calcula:
 *   a) Promedio de edad de los estudiantes de Contaduría.
 *   b) Porcentaje de hombres que estudian Ingeniería.
 *   c) Porcentaje de mujeres menores de 20 años de la universidad.
 *   d) Promedio de edad de las mujeres de Ingeniería.
 *   e) Porcentaje de hombres mayores de 22 años que estudian Derecho en la noche.
 */
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

enum Sexo { MASCULINO = 1, FEMENINO = 2 };
enum Carrera { INGENIERIA = 1, CONTADURIA = 2, DERECHO = 3, OTRA = 4 };
enum Jornada { DIURNA = 1, NOCTURNA = 2 };

class Estudiante {
private:
    int edad;
    int sexo;
    int carrera;
    int jornada;

    static int leerOpcion(const string& mensaje, int minimo, int maximo) {
        int valor;
        while (true) {
            cout << mensaje;
            if (cin >> valor && valor >= minimo && valor <= maximo) {
                return valor;
            }
            cout << "  Valor no válido. Ingrese un número entre " << minimo << " y " << maximo << ".\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

public:
    Estudiante() : edad(0), sexo(MASCULINO), carrera(OTRA), jornada(DIURNA) {}

    void adquirirDatos() {
        edad = leerOpcion("  Edad: ", 1, 120);
        sexo = leerOpcion("  Sexo (1. Masculino; 2. Femenino): ", 1, 2);
        carrera = leerOpcion("  Carrera (1. Ingeniería; 2. Contaduría; 3. Derecho; 4. Otra): ", 1, 4);
        jornada = leerOpcion("  Jornada (1. Diurna; 2. Nocturna): ", 1, 2);
    }

    int getEdad() const { return edad; }
    int getSexo() const { return sexo; }
    int getCarrera() const { return carrera; }
    int getJornada() const { return jornada; }
};

class Universidad {
private:
    vector<Estudiante> estudiantes;

    static double porcentaje(int parte, int total) {
        return total == 0 ? 0.0 : 100.0 * parte / total;
    }

    static double promedio(int suma, int cantidad) {
        return cantidad == 0 ? 0.0 : static_cast<double>(suma) / cantidad;
    }

public:
    void registrar(int n) {
        for (int i = 0; i < n; i++) {
            cout << "\nEstudiante " << (i + 1) << ":\n";
            Estudiante e;
            e.adquirirDatos();
            estudiantes.push_back(e);
        }
    }

    void mostrarResultados() const {
        int total = static_cast<int>(estudiantes.size());
        int sumaEdadContaduria = 0, contaduria = 0;
        int hombres = 0, hombresIngenieria = 0;
        int mujeresMenores20 = 0;
        int sumaEdadMujeresIng = 0, mujeresIngenieria = 0;
        int hombresDerechoNocheMayores22 = 0;

        for (const Estudiante& e : estudiantes) {
            if (e.getCarrera() == CONTADURIA) {
                sumaEdadContaduria += e.getEdad();
                contaduria++;
            }
            if (e.getSexo() == MASCULINO) {
                hombres++;
                if (e.getCarrera() == INGENIERIA) hombresIngenieria++;
                if (e.getCarrera() == DERECHO && e.getJornada() == NOCTURNA && e.getEdad() > 22) {
                    hombresDerechoNocheMayores22++;
                }
            } else {
                if (e.getEdad() < 20) mujeresMenores20++;
                if (e.getCarrera() == INGENIERIA) {
                    sumaEdadMujeresIng += e.getEdad();
                    mujeresIngenieria++;
                }
            }
        }

        cout << fixed << setprecision(2);
        cout << "\n===== Resultados =====\n";
        cout << "a) Promedio de edad en Contaduría: " << promedio(sumaEdadContaduria, contaduria) << " años\n";
        cout << "b) Hombres que estudian Ingeniería: " << porcentaje(hombresIngenieria, hombres) << "% de los hombres\n";
        cout << "c) Mujeres menores de 20 años: " << porcentaje(mujeresMenores20, total) << "% de la universidad\n";
        cout << "d) Promedio de edad de mujeres en Ingeniería: " << promedio(sumaEdadMujeresIng, mujeresIngenieria) << " años\n";
        cout << "e) Hombres mayores de 22 en Derecho nocturno: " << porcentaje(hombresDerechoNocheMayores22, hombres) << "% de los hombres\n";
    }
};

int main() {
    int n;
    cout << "Número de estudiantes: ";
    while (!(cin >> n) || n <= 0) {
        cout << "Ingrese un número entero positivo: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    Universidad universidad;
    universidad.registrar(n);
    universidad.mostrarResultados();
    return 0;
}
