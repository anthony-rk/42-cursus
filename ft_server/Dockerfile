FROM debian:buster

MAINTAINER Anthony Kowalski, <akowalsk@student.42.fr>

RUN apt update -y && apt upgrade -y && apt install -y \
	nginx \
	mariadb-server \
	mariadb-client \
	php7.3 \
	php7.3-fpm \
	php7.3-mysql \
	php-common \
	php7.3-cli \
	php7.3-common \
	php7.3-json \
	php7.3-opcache \
	php7.3-readline \
	nano \
	openssl

COPY ./srcs/start_setup.sh .
COPY ./srcs/nginx.conf /etc/nginx/sites-available/localhost

COPY ./srcs/autoindex_on.sh .
COPY ./srcs/autoindex_off.sh .
RUN chmod 755 ./autoindex*

COPY ./srcs/wp-config.php .
COPY ./srcs/config.inc.php .

COPY ./srcs/wordpress-5.7.tar.gz .
COPY ./srcs/phpMyAdmin-5.0.1-english.tar.gz .

CMD bash start_setup.sh && tail -f /dev/null

# // build the image from dockerfile, tag the image as "ft_server"
# sudo docker build . -t ft_server

# // show that the image is created
# sudo docker image ls

# // start a container in background mode
# sudo docker container run --name my_container -t -d -p 8080:80 -p 443:443 ft_server

# // start a container in interactive mode
# sudo docker container run --name my_container -it -p 8080:80 -p 443:443 ft_server

# // show that the container is running
# sudo docker ps

# // use exec to get to bash into a running container
# sudo docker exec -it my_container bash

# // stop a container
# sudo docker stop ${container id}

# To set autoindex=off: sudo docker exec -d my_container /autoindex_off.sh
# To set autoindex=on: sudo docker exec -d my_container /autoindex_on.sh