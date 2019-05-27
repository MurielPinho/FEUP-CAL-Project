#include <string>
#include "graphviewer.h"
#include <algorithm>
using namespace std;

class Local
{
private:
    int id;
    double x, y;
    string tag;
    bool isGarage, isDepo;

public:
    /**
    * Construtor de Local que recebe um id e coordenadas x e y como parametro.
    */
    Local(int id, double x, double y);

    /**
    * Funcao que retorna o id do local.
    */
    int getId() const;

    /**
    * Funcao que retorna a coordenada X do local.
    */
    double getX() const;

    /**
    * Funcao que retorna a coordenada Y do local.
    */
    double getY() const;

    /**
    * Funcao que recebe uma tag como parametro e coloca no local.
    */
    void setTag(string tag);

    /**
    * Funcao que coloca o membro dado isGarage como true.
    */
    void setGarage();

    /**
    * Funcao que coloca o membro dado isDepo como true.
    */
    void setDepo();

    /**
    * Funcao que retorna o membro dado isGarage.
    */
    bool getGarage();

    /**
    * Funcao que retorna o membro dado isDepo.
    */
    bool getDepo();

    /**
    * Funcao que retorna a tag do local.
    */
    string getTag();

    bool operator==(const Local &p2) const;
};
