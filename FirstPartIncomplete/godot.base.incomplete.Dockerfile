FROM ubuntu:24.04

RUN wget https://github.com/godotengine/godot/releases/download/4.4-stable/Godot_v4.4-stable_linux.x86_64.zip -O /tmp/godot.zip \
&& rm /tmp/godot.zip \
&& mv /usr/local/bin/Godot_v4.4-stable_linux.x86_64 /usr/local/bin/godot+

CMD ["godot", "--headless"]