package;

import flixel.FlxState;
import flixel.ui.FlxButton;
import flixel.addons.ui.FlxButtonPlus;
import flixel.addons.ui.FlxUIButton;
import flixel.FlxG;
import flixel.math.FlxVelocity;
import flixel.math.FlxMath;
import flixel.system.scaleModes.FillScaleMode;
import flixel.system.scaleModes.FixedScaleMode;
import flixel.system.scaleModes.RatioScaleMode;
import flixel.system.scaleModes.RelativeScaleMode;
import flixel.system.scaleModes.FixedScaleAdjustSizeScaleMode;
import flixel.text.FlxText;
import flixel.util.FlxColor;
import flixel.addons.ui.interfaces.IFlxUIButton;
import flixel.FlxGame;
import openfl.display.Sprite;
import flixel.addons.ui.FlxUIPopup;

class MainMenuState extends FlxState
{

	var startButton:FlxUIButton;
	var communityButton:FlxUIButton;
	var dataButton:FlxUIButton;
	var dataPopup:FlxUIPopup;

	override public function create()
	{
		dataPopup = new FlxUIPopup(FlxColor.WHITE);
	
		super.create();
		
		dataPopup.create();
		
		
		startButton = new FlxUIButton(0, 200, "Start", clickStart, true, false, 0xFF691069);
		startButton.resize(300, 100);
		startButton.setLabelFormat(null, 20, FlxColor.WHITE, null, null, FlxColor.TRANSPARENT, true);
		startButton.screenCenter(X);
		
		communityButton = new FlxUIButton(0, 0, "Community", clickCommunity, true, false, 0xFF691069);
		communityButton.resize(300, 100);
		communityButton.setLabelFormat(null, 20, FlxColor.WHITE, null, null, FlxColor.TRANSPARENT, true);
		communityButton.screenCenter();
		
		dataButton = new FlxUIButton(0, 420, "Data", clickData, true, false, 0xFF691069);
		dataButton.resize(300, 100);
		dataButton.setLabelFormat(null, 20, FlxColor.WHITE, null, null, FlxColor.TRANSPARENT, true);
		dataButton.screenCenter(X);
		
		add(startButton);
		add(communityButton);
		add(dataButton);
	}

	function clickStart()
	{
		FlxG.switchState(new StartMenuState());
	}
	
	function clickCommunity()
	{
	
	}
	
	function clickData()
	{
		add(dataPopup);
	}

	override public function update(elapsed:Float)
	{
		super.update(elapsed);
	}
}