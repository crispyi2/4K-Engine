package;

 import flixel.addons.ui.FlxButtonPlus;

 class PlayButton extends FlxButtonPlus
 {
     public function new(x:Float = 0, y:Float = 0, ?Callback:() ‑> Void, ?Label:String, Width:Int = 100, Height:Int = 20)
     {
         super(x, y, ?Callback, ?Label, Width, Height);
		 
		 new FlxButtonPlus(20, 20, null, "cool", 100, 100);
     }
 }