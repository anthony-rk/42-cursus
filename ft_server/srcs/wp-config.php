<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'root' );

/** MySQL database password */
define( 'DB_PASSWORD', '' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/** Allow the Fiele System to be updated without asking for FTP credentials */
define('FS_METHOD', 'direct');


/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         'RO$ [{{+HuIAr<* O|rY2w~3=:J/uxLn@^D6<yG]yYp`~e,0,UFraLNZPaYPoox]');
define('SECURE_AUTH_KEY',  'yj>co<Dfp#$i5H?,ZB5ztB%-tRC}uxP=<A$hzp`0dn:rp,`9TIai}x%6VG|`w/vo');
define('LOGGED_IN_KEY',    '-r,wbuX)7A9qr<*dvhgHy`>)YE]pPZR8*r:](r*l53f;73|`|QaW@?d7?xpapS;h');
define('NONCE_KEY',        'oD^ KL|:}*tI&:2o-5-<t-Jo#|K6g/#^I`;tAz4+*|-s)WjmZj<DH??TT&9$}Pg|');
define('AUTH_SALT',        'dex&;j1.g`{0b7J &7YkLpm,:t|BV,@U@p0*|<~STxj&{$u5-N7FtU:9A-AbQL@D');
define('SECURE_AUTH_SALT', 'xQge ZiSh2jYi?_f^B;PUAc{]}Ri7EB%7!I+[]6tf5?271:_uesdH;2{(3|[jh/b');
define('LOGGED_IN_SALT',   '#uxP-R7F, LX5m]F3`V2^Ta^(oB)t&Cm&0{W#vks=:X&B_:DN4ANtO-KXFn`mr*n');
define('NONCE_SALT',       '~2+8x&pLqbH3:&[~x}}C!frf;?<w3NcO673RN~2]~iiQJ}+v|cRL8z75 -`uh[%b');

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';