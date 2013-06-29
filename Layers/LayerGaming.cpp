

#include "SceneManager.h"
#include "Layers/LayerGaming.h"
#include "Script/LuaHelper.h"
#include "CocosExt/ADParticleSystemCache.h"

#include "label_nodes/CCLabelTTF.h"
#include "sprite_nodes/CCSpriteBatchNode.h"
#include "sprite_nodes/CCSprite.h"
#include "CCDirector.h"
#include "support/CCPointExtension.h"
#include "platform/CCPlatformMacros.h"
#include "actions/CCActionInterval.h"
#include "touch_dispatcher/CCTouchDispatcher.h"

namespace ProjG
{

LayerGaming* LayerGaming::s_pSharedLayerGaming = NULL;

LayerGaming::LayerGaming()
{
	s_pSharedLayerGaming = this;
}

LayerGaming::~LayerGaming()
{
}



bool LayerGaming::initLayer()
{
	bool bRet = false;

	do
	{
		ADParticleSystemCache::getSingleton().setBatchRootNode( this );

		bRet = true;
	}
	while( false );

	return bRet;
}

void LayerGaming::deleteLayer()
{
	
	ADParticleSystemCache::getSingleton().setBatchRootNode( NULL );
	ADParticleSystemCache::getSingleton().removeAllParticleSystem();
}

void LayerGaming::onExit()
{
	deleteLayer();

	CCLayer::onExit();
}

void LayerGaming::keyBackClicked( CCObject *pSender )
{
	SceneManager::replaceMainMenuScene();
}

void LayerGaming::ccTouchesBegan( CCSet *pTouches, CCEvent *pEvent )
{
}
void LayerGaming::ccTouchesMoved( CCSet *pTouches, CCEvent *pEvent )
{
}

void LayerGaming::registerWithTouchDispatcher( )
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addStandardDelegate(this,0);
}



}
