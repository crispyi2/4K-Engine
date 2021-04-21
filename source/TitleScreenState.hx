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

class TitleScreenState extends FlxState
{
	
	var playButton:FlxUIButton;
	var settingsButton:FlxUIButton;

	override public function create()
	{
		super.create();
		
		playButton = new FlxUIButton(0, 0, "4K", clickPlay, true, false, 0xFF691069);
		playButton.resize(100, 100);
		playButton.setLabelFormat(null, 20, FlxColor.WHITE, null, null, FlxColor.TRANSPARENT, true);
		playButton.screenCenter();
		
		settingsButton = new FlxUIButton(0, 0, "Settings", clickSettings, true, false, 0xFF691069);
		settingsButton.resize(FlxG.width, 30);
		settingsButton.setLabelFormat(null, 10, FlxColor.WHITE, null, null, FlxColor.TRANSPARENT, true);
		
		add(settingsButton);
		add(playButton);
	}

	override public function update(elapsed:Float)
	{
		super.update(elapsed);
	}
	
	function clickPlay()
	{
		FlxG.switchState(new MainMenuState());
	}
	
	function clickSettings()
	{
	
	}
}
