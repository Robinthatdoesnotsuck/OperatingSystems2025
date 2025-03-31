FROM    ubuntu 
RUN     apt-get update && apt-get install -qqy x11-apps sudo
# 
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
CMD     xeyes