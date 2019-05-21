#include <string>
#include "graphviewer.h"

using namespace std;

class Local
{
private:
	int id;
	double x, y;
	string tag;
public:
    Local(int id, double x, double y);
    //~Local();
    int getId() const;
    double getX() const;
    double getY() const;
    void setTag(string tag);
    bool operator == (const Local &p2) const;
};

