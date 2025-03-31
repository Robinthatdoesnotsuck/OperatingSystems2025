FROM ubuntu:24.04
#ARG VERSION
#ARG COMPUTER_ARCH
ENV GODOT_VERSION="4.4-stable"
ENV ARCH="x86_64"

RUN apt-get update && apt-get install -y \
wget unzip mono-complete

RUN wget https://github.com/godotengine/godot/releases/download/${GODOT_VERSION}/Godot_v${GODOT_VERSION}_linux.${ARCH}.zip -O /tmp/godot.zip \
&& unzip /tmp/godot.zip -d /usr/local/bin/ \
&& rm /tmp/godot.zip \
&& mv /usr/local/bin/Godot_v${GODOT_VERSION}_linux.${ARCH} /usr/local/bin/godot \
&& chmod +x /usr/local/bin/godot

CMD ["godot", "--headless"]