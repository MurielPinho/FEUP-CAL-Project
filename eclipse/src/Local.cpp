#include "Local.h"

Local::~Local()
{
}

Local::Local(string cidade) {
    this->cidade = cidade;
}

const string &Local::getCidade() const {
    return cidade;
}
