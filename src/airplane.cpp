#include "../include/airplane.h"

#define BITS_PER_WORD (CHAR_BIT*sizeof(unsigned int))
#define I_WORD(i) ((unsigned int)(i) / BITS_PER_WORD)
#define checkarray(L) (airplane*)luaL_checkudata(L, 1, "airplaneMeta")

airplane::airplane()
{
    //ctor
    name = "";
    seat = 0;
    range = 0;
}

airplane::~airplane()
{
    //dtor
}

int airplane::newairplane(lua_State* L)
{
    int         _seat;
    int         _range;
    string      _name;
    //
    size_t      nbytes;
    airplane*   _airplane;

    _seat = luaL_checkint(L, 1);
    _range= luaL_checkint(L, 2);
    _name = luaL_checkstring(L, 3);
    nbytes= sizeof(airplane) + sizeof(int)*I_WORD(2) + sizeof(_name);
    _airplane = (airplane*)lua_newuserdata(L, nbytes);

    _airplane->seat = _seat;
    _airplane->range= _range;
    _airplane->name = _name;

    luaL_getmetatable(L, "airplaneMeta");
    lua_setmetatable(L, -2);

    return 1;
}

int airplane::getSeat(lua_State* L)
{
    airplane* a = checkarray(L);
    lua_pushinteger(L, a->seat);

    return 1;
}

int airplane::getRange(lua_State* L)
{
    airplane* a = checkarray(L);
    lua_pushinteger(L, a->range);

    return 1;
}

int airplane::getName(lua_State* L)
{
    airplane* a = checkarray(L);
    lua_pushstring(L, a->name.c_str());

    return 1;
}

int airplane::setSeat(lua_State* L)
{
    airplane* a = checkarray(L);
    int _seat   = luaL_checkint(L, 2);

    a->seat = _seat;

    return 1;
}

int airplane::setRange(lua_State* L)
{
    airplane* a = checkarray(L);
    int _range  = luaL_checkint(L, 2);

    a->range = _range;

    return 1;
}

int airplane::setName(lua_State* L)
{
    airplane* a = checkarray(L);
    string _name = luaL_checkstring(L, 2);

    a->name = _name;

    return 1;
}


void airplane::setSeat(int _seat)
{
    seat = _seat;
    return;
}

void airplane::setRange(int _range)
{
    range = _range;
    return;
}

void airplane::setName(string _name)
{
    name = _name;
    return;
}


int airplane::getSeat()
{
    return seat;
}

int airplane::getRange()
{
    return range;
}

string airplane::getName()
{
    return name;
}

