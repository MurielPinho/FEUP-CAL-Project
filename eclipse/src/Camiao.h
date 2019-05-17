#include "Produto.h"
class Camiao
{
private:
    double capacidade;
    int id;
    list<Produto*> entrega;
public:
    static int num;

    Camiao(double capacidade);
    ~Camiao();
    int getId();
    void setProd(list<Produto*> prod);
    list<Produto*> getProd();
    void addProduto(Produto *produto);

};
