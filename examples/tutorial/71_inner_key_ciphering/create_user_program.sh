#!/bin/sh

cp game/game ./program
cp game/sexy.png ./sexy.png

./cipher 42 -p ./program
./cipher 42 -r shaker ./sexy.png

./program
