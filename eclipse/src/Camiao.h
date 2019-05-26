#include "Produto.h"
class Camiao
{
private:
    double capacidade;
    int id;
    vector<Produto*> entrega;
public:
    static int num;

    Camiao(double capacidade);
    ~Camiao();
    int getId();
    void setProd(vector<Produto*> prod);
    vector<Produto*> getProd();
    void addProduto(Produto *produto);
    double getCapacidade();

};
