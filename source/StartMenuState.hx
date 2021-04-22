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
import flixel.FlxSprite;
import flixel.addons.ui.FlxUIBar;

class StartMenuState extends FlxState
{

	var sideBar:FlxSprite;

	override public function create()
	{
		super.create();
		
		sideBar = new FlxSprite(783, 0);
		sideBar.makeGraphic(498, FlxG.height, FlxColor.WHITE);
		add(sideBar);
	}

	override public function update(elapsed:Float)
	{
		super.update(elapsed);
	}
}
