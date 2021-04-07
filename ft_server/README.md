# ft_server

>Summary: This is a System Administration subject. You will discover Docker and you
>will set up your first web server

The goal of this project was to create a Docker image/container that works as a full web server. Here I used the LEMP stack (Linux (Debian:Buster), Nginx, MySQL (MariaDB), and PHP) and have also included Wordpress for building the front-end of the website and phpMyAdmin to access the database. 


### Building the Image
 - In order to test the project, you can download the repo and then run the following command from the root directory:
   - `docker build . -t ft_server`

### Starting the Container
 - The next step is to run the container. To achieve this, run the following command to start the container in background mode:
   - `docker container run --name my_container -t -d -p 8080:80 -p 443:443 ft_server`
 - Alternatively, run the following command to start the container in interactive mode:
   - `docker container run --name my_container -it -p 8080:80 -p 443:443 ft_server`

### Toggling Autoindex
 - To set Autoindex back to ON, run the following command:
     - `docker exec -d my_container /autoindex_off.sh`
 - To set Autoindex back to ON, run the following command:
     - `docker exec -d my_container /autoindex_off.sh`

### Stopping the Container
 - To stop the container, run the following command with the correct container id:
   - `docker stop ${container_id}`

