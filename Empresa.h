#include <vector>
#include <string>

#include "Camiao.h"
#include "Garagem.h"
#include "Deposito.h"
#include "Local.h"

using namespace std;

class Empresa
{
private:
    string nome; 

    vector<Camiao> frota;
    Garagem *garagem;
    Deposito *deposito;
    Local *local;
public:
    const string &getNome() const;

    const vector<Camiao> &getFrota() const;

    Garagem *getGaragem() const;

    Deposito *getDeposito() const;

    Local *getLocal() const;

public:
    Empresa();
    ~Empresa(); 
};

