#include "Base.h"
#include "ScriptController.h"
#include "lua_PhysicsCollisionShapeDefinition.h"
#include "Base.h"
#include "Game.h"
#include "Node.h"
#include "PhysicsCollisionShape.h"
#include "Properties.h"
#include "Ref.h"
#include "lua_PhysicsCollisionShapeType.h"

namespace gameplay
{

void luaRegister_PhysicsCollisionShapeDefinition()
{
    const luaL_Reg lua_members[] = 
    {
        {NULL, NULL}
    };
    const luaL_Reg* lua_statics = NULL;
    std::vector<std::string> scopePath;
    scopePath.push_back("PhysicsCollisionShape");

    ScriptUtil::registerClass("PhysicsCollisionShapeDefinition", lua_members, lua_PhysicsCollisionShapeDefinition__init, lua_PhysicsCollisionShapeDefinition__gc, lua_statics, scopePath);
}

static PhysicsCollisionShape::Definition* getInstance(lua_State* state)
{
    void* userdata = luaL_checkudata(state, 1, "PhysicsCollisionShapeDefinition");
    luaL_argcheck(state, userdata != NULL, 1, "'PhysicsCollisionShapeDefinition' expected.");
    return (PhysicsCollisionShape::Definition*)((ScriptUtil::LuaObject*)userdata)->instance;
}

int lua_PhysicsCollisionShapeDefinition__gc(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA))
            {
                void* userdata = luaL_checkudata(state, 1, "PhysicsCollisionShapeDefinition");
                luaL_argcheck(state, userdata != NULL, 1, "'PhysicsCollisionShapeDefinition' expected.");
                ScriptUtil::LuaObject* object = (ScriptUtil::LuaObject*)userdata;
                if (object->owns)
                {
                    PhysicsCollisionShape::Definition* instance = (PhysicsCollisionShape::Definition*)object->instance;
                    SAFE_DELETE(instance);
                }
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsCollisionShapeDefinition__gc - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_PhysicsCollisionShapeDefinition__init(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 0:
        {
            void* returnPtr = (void*)new PhysicsCollisionShape::Definition();
            if (returnPtr)
            {
                ScriptUtil::LuaObject* object = (ScriptUtil::LuaObject*)lua_newuserdata(state, sizeof(ScriptUtil::LuaObject));
                object->instance = returnPtr;
                object->owns = true;
                luaL_getmetatable(state, "PhysicsCollisionShapeDefinition");
                lua_setmetatable(state, -2);
            }
            else
            {
                lua_pushnil(state);
            }

            return 1;
            break;
        }
        case 1:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA || lua_type(state, 1) == LUA_TNIL))
            {
                // Get parameter 1 off the stack.
                PhysicsCollisionShape::Definition* param1 = ScriptUtil::getObjectPointer<PhysicsCollisionShape::Definition>(1, "PhysicsCollisionShapeDefinition", true);

                void* returnPtr = (void*)new PhysicsCollisionShape::Definition(*param1);
                if (returnPtr)
                {
                    ScriptUtil::LuaObject* object = (ScriptUtil::LuaObject*)lua_newuserdata(state, sizeof(ScriptUtil::LuaObject));
                    object->instance = returnPtr;
                    object->owns = true;
                    luaL_getmetatable(state, "PhysicsCollisionShapeDefinition");
                    lua_setmetatable(state, -2);
                }
                else
                {
                    lua_pushnil(state);
                }

                return 1;
            }
            else
            {
                lua_pushstring(state, "lua_PhysicsCollisionShapeDefinition__init - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 0 or 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

}
