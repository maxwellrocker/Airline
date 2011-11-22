#include "../include/airplane.h"

#define BITS_PER_WORD (CHAR_BIT*sizeof(unsigned int))
#define I_WORD(i) ((unsigned int)(i) / BITS_PER_WORD)

airplane::airplane()
{
    //ctor
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
    //
    size_t      nbytes;
    airplane*   _airplane;

    _seat = luaL_checkint(L, 1);
    _range= luaL_checkint(L, 2);
    nbytes= sizeof(airplane) + sizeof(int)*I_WORD(2);
    _airplane = (airplane*)lua_newuserdata(L, nbytes);

    _airplane->seat = _seat;
    _airplane->range= _range;

    return 1;
}

int airplane::getSeat(lua_State* L)
{
    airplane* a = (airplane*)lua_touserdata(L, 1);
    lua_pushinteger(L, a->seat);

    return 1;
}

int airplane::getRange(lua_State* L)
{
    airplane* a = (airplane*)lua_touserdata(L, 1);
    lua_pushinteger(L, a->range);

    return 1;
}

int airplane::setSeat(lua_State* L)
{
    airplane* a = (airplane*)lua_touserdata(L, 1);
    int _seat   = luaL_checkint(L, 2);

    a->seat = _seat;

    return 1;
}

int airplane::setRange(lua_State* L)
{
    airplane* a = (airplane*)lua_touserdata(L, 1);
    int _range  = luaL_checkint(L, 2);

    a->range = _range;

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


int airplane::getSeat()
{
    return seat;
}

int airplane::getRange()
{
    return range;
}

