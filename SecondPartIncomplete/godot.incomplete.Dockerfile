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
    libxrandr2
# 
RUN wget https://github.com/godotengine/godot/releases/download/${GODOT_VERSION}/Godot_v${GODOT_VERSION}_linux.${ARCH}.zip -O /tmp/godot.zip \
&& unzip /tmp/godot.zip -d /usr/local/bin/ \
&& rm /tmp/godot.zip \
&& mv /usr/local/bin/Godot_v${GODOT_VERSION}_linux.${ARCH} /usr/local/bin/godot \
&& chmod +x /usr/local/bin/godot
RUN     export uid=1000 gid=1001
RUN     mkdir -p /home/docker_user
RUN     echo "docker_user:x:${uid}:${gid}:docker_user,,,:/home/docker_user:/bin/bash" >> /etc/passwd
RUN     echo "docker_user:x:${uid}:" >> /etc/group
RUN     echo "docker_user ALL=(ALL) NOPASSWD: ALL" > /etc/sudoers.d/docker_user
RUN     chmod 0440 /etc/sudoers.d/docker_user
RUN     chown ${uid}:${gid} -R /home/docker_user 
#
USER    docker_user 
ENV     HOME /home/docker_user
CMD ["godot"]