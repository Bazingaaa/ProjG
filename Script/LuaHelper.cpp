
#include "Script/LuaHelper.h"

#include "CocosExt/ProjectionDelegate.h"

#include "script_support/CCScriptSupport.h"
#include "CCLuaEngine.h"
#include "cocoa/CCString.h"
#include "cocoa/CCGeometry.h"
#include "CCFileUtils.h"

extern "C" {
	#include "tolua++.h"
	#include "tolua_fix.h"
}


namespace ProjG
{

using namespace cocos2d;

void LuaHelper::s_executeFile( const char *pFileName )
{
	CCLuaEngine *pLuaEngine = static_cast< CCLuaEngine* > ( CCScriptEngineManager::sharedManager()->getScriptEngine() );
	std::string strDirPath( "scripts" );
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    CCString* pstrFileContent = CCString::createWithContentsOfFile((strDirPath + "/" + pFileName).c_str());
    if (pstrFileContent)
    {
    	pLuaEngine->executeString(pstrFileContent->getCString());
    }
#else
    std::string path = CCFileUtils::sharedFileUtils()->fullPathFromRelativePath((strDirPath + "/" + pFileName).c_str());
    pLuaEngine->addSearchPath(path.substr(0, path.find_last_of("/") - strDirPath.length()).c_str());
    pLuaEngine->executeScriptFile(path.c_str());
#endif
}

std::string LuaHelper::s_getStringVar( const char *pVarName )
{
	CCLuaEngine *pLuaEngine = static_cast< CCLuaEngine* > ( CCScriptEngineManager::sharedManager()->getScriptEngine() );
	lua_State *pLuaState = pLuaEngine->getLuaState();

	lua_getglobal( pLuaState, pVarName );

	CCAssert( !lua_isnil( pLuaState, -1 ), "error in LuaHelper::s_getStringVar, the var not exist" );

	std::string strRet = lua_tostring( pLuaState,  -1 );
	lua_pop( pLuaState, 1 );

	return strRet;
}

CCRect LuaHelper::s_getRectVar( const char *pVarName )
{
	CCLuaEngine *pLuaEngine = static_cast< CCLuaEngine* > ( CCScriptEngineManager::sharedManager()->getScriptEngine() );
	lua_State *pLuaState = pLuaEngine->getLuaState();

	lua_getglobal( pLuaState, pVarName );

	CCAssert( !lua_isnil( pLuaState, -1 ), "error in LuaHelper::s_getRectVar, the var not exist" );

	CCRect rect;
	// a rect in lua is a table with 4 number elements
	lua_pushnumber( pLuaState, 1 );
	lua_gettable( pLuaState, -2 );
	CCAssert( !lua_isnil( pLuaState, -1 ), "error in LuaHelper::s_getRectVar" );
	rect.origin.x = lua_tonumber( pLuaState, -1 );
	lua_pop( pLuaState, 1 );

	lua_pushnumber( pLuaState, 2 );
	lua_gettable( pLuaState, -2 );
	CCAssert( !lua_isnil( pLuaState, -1 ), "error in LuaHelper::s_getRectVar"  );
	rect.origin.y = lua_tonumber( pLuaState, -1 );
	lua_pop( pLuaState, 1 );

	lua_pushnumber( pLuaState, 3 );
	lua_gettable( pLuaState, -2 );
	CCAssert( !lua_isnil( pLuaState, -1 ), "error in LuaHelper::s_getRectVar" );
	rect.size.width = lua_tonumber( pLuaState, -1 );
	lua_pop( pLuaState, 1 );

	lua_pushnumber( pLuaState, 4 );
	lua_gettable( pLuaState, -2 );
	CCAssert( !lua_isnil( pLuaState, -1 ), "error in LuaHelper::s_getRectVar" );
	rect.size.height = lua_tonumber( pLuaState, -1 );
	lua_pop( pLuaState, 1 );

	lua_pop( pLuaState, 1 );

	return rect;

}

double LuaHelper::s_getNumberVar( const char *pVarName )
{
	CCLuaEngine *pLuaEngine = static_cast< CCLuaEngine* > ( CCScriptEngineManager::sharedManager()->getScriptEngine() );
	lua_State *pLuaState = pLuaEngine->getLuaState();

	lua_getglobal( pLuaState, pVarName );

	CCAssert( !lua_isnil( pLuaState, -1 ), "error in LuaHelper::s_getNumberVar, the var not exist" );

	double dRet = lua_tonumber( pLuaState,  -1 );
	lua_pop( pLuaState, 1 );

	return dRet;
}

bool LuaHelper::s_protectedCallFunc( int nParams, int nRets )
{
	CCLuaEngine *pLuaEngine = static_cast< CCLuaEngine* > ( CCScriptEngineManager::sharedManager()->getScriptEngine() );
	lua_State *pLuaState = pLuaEngine->getLuaState();

	if( lua_pcall( pLuaState, nParams, nRets, 0 ) != 0 )
	{
		const char *pError = lua_tostring( pLuaState, -1 );
		CCLog( pError );
		return false;
	}

	return true;

}

lua_State* LuaHelper::s_getLuaState()
{
	CCLuaEngine *pLuaEngine = static_cast< CCLuaEngine* > ( CCScriptEngineManager::sharedManager()->getScriptEngine() );
	lua_State *pLuaState = pLuaEngine->getLuaState();

	return pLuaState;

}


/* method: setOrigin of class  ProjectionView */
#ifndef TOLUA_DISABLE_tolua_ProjectionView_setOrigin00
static int tolua_ProjectionView_setOrigin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
	 !tolua_isnumber( tolua_S, 1, 0, &tolua_err ) ||
	 !tolua_isnumber( tolua_S, 2, 0, &tolua_err ) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
	float fX = tolua_tonumber( tolua_S, 1, 0 );
	float fY = tolua_tonumber( tolua_S, 2, 0 );
    ProjectionDelegate::sharedPointer()->setOrigin( fX, fY );
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sharedEngine'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

void LuaHelper::openProjGLuaLibs()
{
	CCLuaEngine *pLuaEngine = static_cast< CCLuaEngine* > ( CCScriptEngineManager::sharedManager()->getScriptEngine() );
	lua_State *pLuaState = pLuaEngine->getLuaState();

	tolua_open(pLuaState);
	tolua_usertype(pLuaState,"ProjectionView");

	tolua_module(pLuaState,NULL,0);
	tolua_beginmodule(pLuaState,NULL);
		tolua_cclass(pLuaState,"ProjectionView","ProjectionView","",NULL);
		tolua_beginmodule(pLuaState,"ProjectionView");
			tolua_function(pLuaState,"setOrigin",tolua_ProjectionView_setOrigin00);
		tolua_endmodule(pLuaState);
	tolua_endmodule(pLuaState);
}


}

