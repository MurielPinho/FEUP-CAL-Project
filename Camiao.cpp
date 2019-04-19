#include "Camiao.h"

int Camiao::num = 0;

Camiao::Camiao(double capacidade)
{
    this->capacidade = capacidade;
    num++;
    this->id = num;
}

Camiao::~Camiao()
{
}
