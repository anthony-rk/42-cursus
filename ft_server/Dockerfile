FROM debian:buster

MAINTAINER Anthony Kowalski, <akowalsk@student.42.fr>

RUN apt update
RUN apt upgrade
RUN apt install -y nginx
RUN apt install -y mariadb-server mariadb-client
RUN apt install -y php7.3 php7.3-fpm php7.3-mysql php-common php7.3-cli php7.3-common php7.3-json php7.3-opcache php7.3-readline
RUN apt install -y nano
RUN apt install -y openssl

# ENV AUTOINDEX=on

COPY ./srcs/start_setup.sh .
COPY ./srcs/nginx.conf /etc/nginx/sites-available/localhost

COPY ./srcs/autoindex_on.sh .
COPY ./srcs/autoindex_off.sh .

COPY ./srcs/wp-config.php .
COPY ./srcs/config.inc.php .

COPY ./srcs/wordpress-5.7.tar.gz .
COPY ./srcs/phpMyAdmin-5.0.1-english.tar.gz .

CMD bash start_setup.sh && tail -f /dev/null

# To set autoindex=off: docker exec ft_server /autoindex_off.sh
# To set autoindex=on: docker exec ft_server /autoindex_on.sh

