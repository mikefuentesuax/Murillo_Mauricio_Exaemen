#include <iostream>
#include <map>
#include <any>
#include <string>
#include <stdexcept>

using namespace std;

class Enviroment {
    public:
    void insert( const string& name, const any& value){
        auto result = variables.emplace(name, value);
        if (!result.second){
            if (result.first->second != value){
            throw runtime_error("Variable " + name + " ya extistente");
        }
        }
    }
    any lookup(const string& name) const {
        auto it = variables.find(name);
        if(it != variables.end()){
            return it->second;
            }
            throw runtime_error("Variable " + name + " no encontrada");
        }
        

    bool variableExists(const string& name) const {
        return variables.find(name) != variables.end();
    }
    
    void remove (const string& name){
        auto it = variables.find(name);
    if (it != variables.end()){
        variables.erase(it);
    } else {
        throw runtime_error("No se puede eliminar la variable. " + name + " no encontrada");
    }
    }

    bool isEmpty() const {
        return variables.empty();
    }

    private:
    map<string, any> variables;
};  

int main(){
    Enviroment scriptEnvironment;
    try{
        scriptEnvironment.insert("Resultado", 100);
        scriptEnvironment.insert("Nombre", string("Juan"));

    if (scriptEnvironment.variableExists("Resultado")){
        cout << "La variable Resultado ya existe" << endl;
    }
    } catch (const exception& e){
        cerr << "Error: " << e.what() << endl;
    } 
    return 0;
    }

