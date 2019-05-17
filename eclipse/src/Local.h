#include <string>

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

