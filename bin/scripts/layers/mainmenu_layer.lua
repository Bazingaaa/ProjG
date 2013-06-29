module( "LayerMainMenu", package.seeall );

require( "scripts/ui_texts_chs" );


local function onPlay( sender )
	require( "scripts/scene_mgr" );
	SceneManager.replaceGameScene();
end

local function onQuit( sender )
	CCDirector:sharedDirector():endToLua();
end


function create()
	local layer = CCLayer:create();

	local playItem = CCMenuItemFont:create(UIText.TEXT_PLAY);
	playItem:registerScriptTapHandler( onPlay );

	local quitItem = CCMenuItemFont:create(UIText.TEXT_QUIT);
	quitItem:registerScriptTapHandler( onQuit );

	local menu = CCMenu:create();
	menu:addChild(playItem);
	menu:addChild(quitItem);
	menu:alignItemsVerticallyWithPadding( 100.0 );

	local s = CCDirector:sharedDirector():getWinSize();
	menu:setPosition( ccp( s.width * 0.5, s.height * 0.5 ) );

	layer:addChild(menu);

	return layer;
end
