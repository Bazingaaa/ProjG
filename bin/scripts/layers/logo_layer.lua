
module ( "LayerLogo", package.seeall );

require( "scripts/resources_define" );




function create( durationTime )
	local layer = CCLayer:create();

	local timeCount = 0.0;

	local logoRect = Resource.LOGO_RECT;

	local s = CCDirector:sharedDirector():getWinSize();
	local logoImg = CCSprite:create( Resource.LOGO_IMG, logoRect );

	logoImg:setPosition( ccp( s.width * 0.5, s.height * 0.5) );
	logoImg:setScaleX( s.width / logoRect.size.width );
	logoImg:setScaleY( s.height / logoRect.size.height );

	layer:addChild( logoImg );

	local scheduler = CCDirector:sharedDirector():getScheduler();
	local updateScheduleEntry = nil;

	local function update( elapsedTime )
		require( "scripts/scene_mgr" );
		
		timeCount = elapsedTime + timeCount;
		if( timeCount >= durationTime ) then
			SceneManager:replaceMainMenuScene();
			timeCount = 0;
			scheduler:unscheduleScriptEntry( updateScheduleEntry );
		end
	end

	updateScheduleEntry = scheduler:scheduleScriptFunc( update, 1.0, false );

	return layer;
end

