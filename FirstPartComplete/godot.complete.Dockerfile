FROM    ubuntu
ENV GODOT_VERSION="4.4-stable"
ENV ARCH="x86_64"
RUN apt-get update && apt-get install -qqy \
    x11-apps \
    sudo \
    wget \
    unzip \
    mono-complete \
    libxkbcommon-x11-0 \
    libxinerama-dev \
    libxrandr2 \
    libwayland-client0 \
    libwayland-cursor0
#
RUN     export uid=1000 gid=1000
RUN     mkdir -p /home/docker_user
RUN     echo "docker_user:x:${uid}:${gid}:docker_user,,,:/home/docker_user:/bin/bash" >> /etc/passwd
RUN     echo "docker_user:x:${uid}:" >> /etc/group
RUN     echo "docker_user ALL=(ALL) NOPASSWD: ALL" > /etc/sudoers.d/docker_user
RUN     chmod 0440 /etc/sudoers.d/docker_user
RUN     chown ${uid}:${gid} -R /home/docker_user 
#
USER    docker_user 
ENV     HOME /home/docker_user
WORKDIR /app
COPY . .
RUN chmod +x WebSocket_Multiplayer_Demo.x86_64
EXPOSE 8080
CMD ["./WebSocket_Multiplayer_Demo.x86_64"]
