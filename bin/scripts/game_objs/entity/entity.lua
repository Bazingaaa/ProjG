module( "Entity", package.seeall );

function create( rootNode, fileName, pos, scale, rotate )

	local entity = {};

	local sprite;

	function entity.load( fileName )
		sprite = CCSprite:create( fileName );
		rootNode:addChild( sprite );
	end

	function entity.setPos( pos )
		sprite:setPosition( pos );
	end

	function entity.getPos()
		return sprite:getPosition();
	end

	function entity.setScale( scale )
		sprite:setScale(scale);
	end

	function entity.setRotate( rotate )
		sprite:setRotation( rotate );
	end

	function entity.moveTo( destPosX, destPosY, duration )
		duration = duration or 1.0;

		local destPos = CCPoint:new_local( destPosX, destPosY );
		local moveAction = CCMoveTo:create( duration, destPos );
		sprite:runAction( moveAction );
	end


	entity.load( fileName );
	entity.setPos( pos );
	entity.setScale( scale );
	entity.setRotate( rotate );

	return entity;
end
