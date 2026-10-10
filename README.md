# Programación Orientada a Objetos en C++

![C++](https://img.shields.io/badge/C%2B%2B17-00599C?style=flat&logo=cplusplus&logoColor=white)

Ejercicio de programación orientada a objetos en C++: registro de los estudiantes de una universidad y cálculo de estadísticas por carrera, sexo, edad y jornada.

## Enunciado

Por cada uno de los *N* estudiantes se registra edad, sexo, carrera (Ingeniería, Contaduría, Derecho u otra) y jornada (diurna o nocturna). El programa obtiene:

1. Promedio de edad de los estudiantes de Contaduría.
2. Porcentaje de hombres que estudian Ingeniería.
3. Porcentaje de mujeres menores de 20 años en la universidad.
4. Promedio de edad de las mujeres de Ingeniería.
5. Porcentaje de hombres mayores de 22 años que estudian Derecho en la jornada nocturna.

## Diseño

- `Estudiante`: encapsula los datos de cada estudiante y valida la entrada por consola.
- `Universidad`: almacena los estudiantes y calcula las estadísticas.
- Enumeraciones para sexo, carrera y jornada en lugar de números sueltos.

## Compilación y ejecución

```bash
g++ -std=c++17 -Wall -o estudiantes estudiantes.cpp
./estudiantes
```

Ejemplo de salida:

```
===== Resultados =====
a) Promedio de edad en Contaduría: 21.00 años
b) Hombres que estudian Ingeniería: 50.00% de los hombres
c) Mujeres menores de 20 años: 25.00% de la universidad
d) Promedio de edad de mujeres en Ingeniería: 19.00 años
e) Hombres mayores de 22 en Derecho nocturno: 50.00% de los hombres
```

## Autor

**César Andrés Torres Bernal** · [GitHub](https://github.com/andrestorresaioros) · [LinkedIn](https://www.linkedin.com/in/andr%C3%A9s-torres10)

## Licencia

Distribuido bajo la licencia MIT. Consulta [LICENSE](LICENSE).
