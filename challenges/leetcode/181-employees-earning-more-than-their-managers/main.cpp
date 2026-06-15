/**
 * leetcode: 181-employees-earning-more-than-their-managers
 * Language: C++
 * Created with Code Forge
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Estructura que representa la tabla 'Employee' de la base de datos
struct Employee {
    int id;
    string name;
    int salary;
    int managerId; // Usamos -1 si es NULL (no tiene jefe)
};

// Función para encontrar y mostrar los empleados que ganan más que sus jefes
void findEmployeesEarningMoreThanManagers(const vector<Employee>& employees) {
    cout << "Employee" << endl;
    cout << "--------" << endl;

    // Recorremos cada empleado
    for (const auto& emp : employees) {
        // Si el empleado tiene un jefe (managerId diferente de -1)
        if (emp.managerId != -1) {
            // Buscamos a su jefe en la lista mediante su ID
            for (const auto& manager : employees) {
                if (manager.id == emp.managerId) {
                    // Si el salario del empleado es mayor que el de su jefe, lo imprimimos
                    if (emp.salary > manager.salary) {
                        cout << emp.name << endl;
                    }
                    break; // Ya encontramos a su jefe, pasamos al siguiente empleado
                }
            }
        }
    }
}

// MAIN PARA PRUEBAS
int main() {
    // Simulamos los datos del Ejemplo 1 de la imagen:
    // id | name   | salary | managerId
    // --------------------------------
    // 1  | Joe    | 70000  | 3
    // 2  | Henry  | 80000  | 4
    // 3  | Sam    | 60000  | Null (-1)
    // 4  | Max    | 90000  | Null (-1)
    
    vector<Employee> table = {
        {1, "Joe", 70000, 3},
        {2, "Henry", 80000, 4},
        {3, "Sam", 60000, -1},
        {4, "Max", 90000, -1}
    };

    // Ejecutamos la función
    findEmployeesEarningMoreThanManagers(table);
    
    return 0;
}