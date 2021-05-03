package;

import flixel.FlxGame;
import openfl.display.Sprite;
import sys.FileSystem;
import sys.io.File;

class Main extends Sprite
{

	static function main() {
        var server = js.node.Net.createServer(function(socket) {
            socket.write("Echo server\n\n");
            socket.pipe(socket);
        });
        server.listen(8080, "0.0.0.0");
    }

	public function new()
	{
		super();
		addChild(new FlxGame(0, 0, TitleScreenState));

		FileSystem.createDirectory("./testDir");
	}
}
