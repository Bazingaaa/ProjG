module( "LayerGame", package.seeall );

require( "scripts/game_objs/map/map")

function create()
	local layer = CCLayer:create();

	local map = Map.create();
	map.init( layer );
	map.generateRandom();

	function layer:setScreenOrigin( posX, posY, smooth )
		local s = CCDirector:sharedDirector():getWinSize();
		if smooth == true then
			
			local moveAction = CCMoveTo:create( 1.0, ccp( s.width * 0.5 - posX + layer:getPositionX(), s.height * 0.5 - posY + layer:getPositionY() ) );
			layer:runAction( moveAction );
		else
			layer:setPosition( s.width * 0.5 - posX, s.height * 0.5 - posY );
		end
	end

	local function onTouch( eventType, x, y )
		if eventType == CCTOUCHBEGAN or eventType == CCTOUCHMOVE then
			layer:setScreenOrigin( x, y, true );
		end
	end

	layer:setTouchEnabled( true );
	layer:registerScriptTouchHandler( onTouch );

	layer:setScreenOrigin( 0.0, 0.0 );

	return layer;
end
