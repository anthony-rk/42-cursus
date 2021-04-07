#!/bin/bash

# Make a directory for files for the website aka localhost:
mkdir var/www/localhost

echo "mysql starting..."
service mysql start

# Give proper permissions 
chown -R www-data /var/www/*
chmod -R 755 /var/www/*

# Symlink to enable localhost site
ln -s /etc/nginx/sites-available/localhost /etc/nginx/sites-enabled/
rm -rf /etc/nginx/sites-enabled/default

# SSL configuration
mkdir /etc/nginx/ssl
openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/nginx/ssl/localhost.key -out /etc/nginx/ssl/localhost.pem -subj "/C=US/ST=CA/L=SF/O=42SV/OU=akowalsk/CN=localhost"

# Allow users to access database
echo "CREATE DATABASE wordpress;" \
		| mysql -u root --skip-password
echo "UPDATE mysql.user SET plugin = 'mysql_native_password' WHERE user='root';" \
		| mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* to 'root'@'localhost';" \
		| mysql -u root --skip-password
echo "FLUSH PRIVILEGES" \
		| mysql -u root --skip-password

# Get files for wordpress
tar -zvxf wordpress-5.7.tar.gz
rm wordpress-5.7.tar.gz
mv wordpress var/www/localhost
mv wp-config.php var/www/localhost/wordpress

# Get files for phpMyAdmin
tar -zvxf phpMyAdmin-5.0.1-english.tar.gz
rm phpMyAdmin-5.0.1-english.tar.gz
mv phpMyAdmin-5.0.1-english phpMyAdmin
mv phpMyAdmin var/www/localhost
mv config.inc.php var/www/localhost/phpMyAdmin

echo "php7.3-fpm starting..."
service php7.3-fpm start

echo "nginx starting..."
service nginx start