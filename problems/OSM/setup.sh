#!/bin/bash

mkdir -p lib

# TinyXML2
if [ ! -d "lib/tinyxml2" ]; then
    git clone https://github.com/leethomason/tinyxml2.git lib/tinyxml2
    echo "Downloaded tinyxml2"
fi


echo "Setup complete. You can now run: make"
