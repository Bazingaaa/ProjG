

#ifndef LAYER_GAMING_H__
#define LAYER_GAMING_H__

#include "layers_scenes_transitions_nodes/CCLayer.h"


namespace cocos2d
{
	class CCSpriteBatchNode;
	class CCLabelTTF;
	class CCSprite;
	class CCObject;
}

namespace ProjG
{

class DiggingWorld;

using namespace cocos2d;

class LayerGaming : public CCLayer
{
public:
	LayerGaming();
	~LayerGaming();


	/**初始化layer
	 *
	 */
	bool initLayer();

	/**销毁 */
	void deleteLayer();

	///< override
	virtual void keyBackClicked( CCObject *pSender );
	virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
	virtual void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);
	//virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);
	virtual void registerWithTouchDispatcher();
	virtual void onExit();

	///<return the latest constructed layer gaming pointer
	static LayerGaming* sharedLayerGaming() { return s_pSharedLayerGaming; }



protected:

	static LayerGaming *s_pSharedLayerGaming;

};

}


#endif

