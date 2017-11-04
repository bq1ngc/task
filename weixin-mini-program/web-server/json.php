<?php
$wp_did_header = true;
require_once( '/..../wp-load.php' );
wp();
require_once( '/....../wp-includes/template-loader.php' );
header('Content-type: application/json');
header_remove('Cache-Control');
header_remove('expires');
http_response_code(200);
?>
[
<?php query_posts('showposts=10&cat=3')?><?php while (have_posts()) : the_post(); ?>
{
"img":"<?php echo xinphoto_thumbnail();?>",
"pid":"<?php the_id() ?>",
"source":"xinroom.cn",
"title":"<?php echo  the_title() . '"'; ?>,
"body":"<?php global $post;
$description = str_replace( array( "\r\n", "\r", "\n", "\\","[","	", "]"), "", str_replace( "\"", "'", strip_tags( $post->post_content ) ) );
echo mb_substr( $description, 0, 100, 'utf-8' ); ?>..."
},
<?php endwhile;?>
<?php query_posts('showposts=1&cat=40')?><?php while (have_posts()) : the_post(); ?>
{
"img":"<?php echo xinphoto_thumbnail();?>",
"pid":"<?php the_id() ?>",
"source":"xinroom.cn",
"title":"<?php echo  the_title() . '"'; ?>,
"body":"<?php global $post;
$description = str_replace( array( "\r\n", "\r", "\n", "\\","[","	", "]"), "", str_replace( "\"", "'", strip_tags( $post->post_content ) ) );
echo mb_substr( $description, 0, 100, 'utf-8' ); ?>..."
}
<?php endwhile;?>]