#include <cstring>
#include "VintagePort.h"

VintagePort::VintagePort()
{
    nickname = new char[strlen("none")+1];
    strcpy(nickname, "none");
    year = 0;
}

VintagePort::VintagePort(const char* br, int b, const char* nn, int y) : Port(br, "vintage", b)
{
    nickname = new char[strlen(nn)+1];
    strcpy(nickname, nn);
    year = y;
}

VintagePort::VintagePort(const VintagePort& vp) : Port(vp)
{
    delete[] nickname;
    nickname = new char[strlen(vp.nickname) + 1];
    strcpy(nickname, vp.nickname);
    year = vp.year;
}

VintagePort& VintagePort::operator=(const VintagePort& vp)
{
    if (this == &vp)
        return *this;
    Port::operator=(vp);
    delete[] nickname;
    nickname = new char[strlen(vp.nickname) + 1];
    strcpy(nickname, vp.nickname);
    year = vp.year;
    return *this;
}

void VintagePort::Show() const
{
    Port::Show();
    cout << "Nickname: " << nickname << endl;
    cout << "Year: " << year << endl;
}

ostream& operator<<(ostream& os, const VintagePort& vp)
{
    return os << (Port) vp << ", " << vp.nickname << ", " << vp.year;
}