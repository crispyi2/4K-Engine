if [ -f src/Purpur.js ]; then
    mv -p src/Purpur.js ./
fi

npx http-server -a 0.0.0.0 -p 3000