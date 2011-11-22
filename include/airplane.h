#ifndef AIRPLANE_H
#define AIRPLANE_H

#include<stdio.h>
#include<string.h>
#include<string>
#include<limits.h>

extern "C"{
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}

using namespace std;
class airplane
{
public:
    airplane();
    virtual ~airplane();

    static int newairplane(lua_State* L);
    static int getSeat(lua_State* L);
    static int getRange(lua_State* L);
    static int setSeat(lua_State* L);
    static int setRange(lua_State* L);

    void setSeat(int _seat);
    void setRange(int _range);

    int     getSeat();
    int     getRange();

protected:

private:
    int     seat;   //座位
    int     range;  //最大航程
};

#endif // AIRPLANE_H
