#include "../include/airplane.h"

/*
extern "C"{
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}
*/

int ShowMessage(lua_State* L)
{
    const char* Message = lua_tostring(L, 1);
    lua_pushstring(L, Message);

    return 1;
}

static const struct luaL_Reg airplanelib[] = {
    {"new",     airplane::newairplane},
    {NULL, NULL}
};

static const struct luaL_Reg airplanelib_m[] = {
    {"getseat", airplane::getSeat},
    {"getrange",airplane::getRange},
    {"getname", airplane::getName},
    {"setseat", airplane::setSeat},
    {"setrange",airplane::setRange},
    {"setname", airplane::setName},
    {NULL, NULL}
};

int main()
{
    //---------------------open lua---------------------
    lua_State* L = luaL_newstate();
	luaL_openlibs(L);

    lua_register(L, "ShowMessage", ShowMessage);
    luaL_register(L, "airplane", airplanelib);

    luaL_newmetatable(L, "airplaneMeta");
    lua_pushvalue(L, -1);
    lua_setfield(L, -2, "__index");
    luaL_register(L, NULL, airplanelib_m);

    luaL_dofile(L, "script.lua");

    lua_close(L);
    //---------------------close lua--------------------

    return 0;
}
