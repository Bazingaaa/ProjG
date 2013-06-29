module("Map", package.seeall );

require( "scripts/game_objs/entity/entity" );


function create()
	local map = {};
	local rootNode = nil;

	local function createEntity( fileName, pos, scale, rotate )
		local entity = Entity.create( rootNode, fileName, pos, scale, rotate );
	end

	map.size = {width = 1000, height = 1000};
	map.origin = {x = 0, y = 0};

	function map.load( fileName )

	end

	function map.init(node)
		rootNode = node;
		--node:setScaleX(640/1024);
		--node:setScaleY(320/768);
	end

	function map.generateRandom()
		local x,y;

		for i=0, 40 do
			x = math.random( map.origin.x - map.size.width * 0.5, map.origin.x + map.size.width * 0.5 );
			y = math.random( map.origin.y - map.size.height * 0.5, map.origin.y + map.size.height * 0.5 );

			createEntity( "images/SMALL.PNG", ccp( x, y ), 1.0, math.random( 0, 360 ) );
		end
	end

	return map;
end





