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
    Local(int id, double x, double y);
    //~Local();
    int getId() const;
    double getX() const;
    double getY() const;
    void setTag(string tag);
    bool operator == (const Local &p2) const;
    void setGarage();
    void setDepo();
    bool getGarage();
    bool getDepo();
    string getTag();
};

