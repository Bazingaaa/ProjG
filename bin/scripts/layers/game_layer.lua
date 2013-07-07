module( "LayerGame", package.seeall );

require( "scripts/game_objs/map/map" );
require( "scripts/game_objs/entity/player" );

function create()
	local layer = CCLayer:create();
	local player;
	
	
	local function onTouch( eventType, x, y )
		local switch = false;
		if eventType == CCTOUCHBEGAN or eventType == CCTOUCHMOVED then
			
			local winSize = CCDirector:sharedDirector():getWinSize();
			local screenCenter = CCPoint:new_local( winSize.width * 0.5, winSize.height * 0.5 );

			local touchPosX = x - screenCenter.x;
			local touchPosY = y - screenCenter.y;
			local projViewCenter = ProjectionView.getCenter();
			touchPosX = touchPosX + projViewCenter.x;
			touchPosY = touchPosY + projViewCenter.y;
			player.moveTo( touchPosX,touchPosY );
		end

		return true;
	end

	local function init()
		local map = Map.create();
		map.init( layer );
		map.generateRandom();

		layer:setTouchEnabled( true );
		layer:registerScriptTouchHandler( onTouch );

		player = Player.create( layer, "images/SMALL.PNG", ccp(0,0), 1.0, 0.0 );
		player.moveTo( 0, 0 );
	end

	init();

	return layer;
end
