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
    ~Local();
    int getId();
    double getX();
    double getY();
    void setTag(string tag);
};

