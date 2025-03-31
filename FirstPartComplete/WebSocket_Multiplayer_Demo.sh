#!/bin/sh
echo -ne '\033c\033]0;WebSocket_Multiplayer_sDemo\a'
base_path="$(dirname "$(realpath "$0")")"
"$base_path/WebSocket_Multiplayer_Demo.x86_64" "$@"
