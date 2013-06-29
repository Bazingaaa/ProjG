module("SceneManager",package.seeall);

require( "scripts/layers/logo_layer" );
require( "scripts/layers/mainmenu_layer" );
require( "scripts/layers/game_layer" );

function createLogoScene()
	local scene = CCScene:create();
	scene:addChild( LayerLogo.create( 0.5 ) );
	CCDirector:sharedDirector():runWithScene(scene)
end


function replaceMainMenuScene()
	local scene = CCScene:create();
	scene:addChild( LayerMainMenu.create() );
	local fadeColor = ccColor3B:new_local();
	fadeColor.r = 0;
	fadeColor.g = 0;
	fadeColor.b = 0;

	CCDirector:sharedDirector():replaceScene( CCTransitionFade:create( 1.0, scene, fadeColor ) );
end

function replaceGameScene()
	local scene = CCScene:create();
	scene:addChild( LayerGame.create() );
	CCDirector:sharedDirector():replaceScene(scene);
end

