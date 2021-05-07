emcc \
    src/Game.cpp \
    --preload-file assets \
    --emrun \
    --shell-file ./src/html/shell.html \
    -o build/game.html \
    -s MAX_WEBGL_VERSION=3 \
    -s FULL_ES3=1