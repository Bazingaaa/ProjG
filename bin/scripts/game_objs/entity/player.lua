module("Player", package.seeall );


require( "scripts/game_objs/entity/entity" );

function create( rootNode, fileName, pos, scale, rotate )
	local player = {};
	local entity;

	function player.moveTo( destPosX, destPosY, duration )
		entity.moveTo( destPosX, destPosY, duration );
	end

	function player.update()
		local posX, posY = entity.getPos();
		ProjectionView.setCenter( posX, posY );
	end

	function player.destroy()
		scheduler:unscheduleScriptEntry( updateEntry );
	end

	local function init()
		entity = Entity.create( rootNode, fileName, pos, scale, rotate );
		setmetatable(player, { __index = entity } );

		local scheduler = CCDirector:sharedDirector():getScheduler();
		updateEntry = scheduler:scheduleScriptFunc( player.update, 0.0, false );
	end

	init();

	return player;

end
