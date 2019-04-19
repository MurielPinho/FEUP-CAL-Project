#include <vector>
#include <string>

#include "Camiao.h"
#include "Garagem.h"
#include "Deposito.h"
#include "Local.h"
#include "Produto.h"
#include <list>

using namespace std;

class Empresa
{
private:
    string nome;
    vector<Camiao> frota;
    Garagem *garagem;
    Deposito *deposito;

    list<Produto> produtos;
public:
    const string &getNome() const;

    const vector<Camiao> &getFrota() const;

    Garagem *getGaragem() const;

    Deposito *getDeposito() const;

    void addCamiao(const Camiao &camiao);

    void addProduto(const Produto &produto);

    Empresa(string nome, Camiao camiao, Garagem *garagem, Deposito *deposito);
    ~Empresa(); 
};

