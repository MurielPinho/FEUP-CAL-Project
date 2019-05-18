#include <string>
#include "graphviewer.h"

using namespace std;

class Local
{
private:
    string cidade;
public:
    const string &getCidade() const;

public:
    Local(string cidade);
    ~Local();
};

