<?php
$wp_did_header = true;
require_once( '/....../wp-load.php' );
wp();
require_once( '/......./wp-includes/template-loader.php' );
header('Content-type: application/json');
header_remove('Cache-Control');
header_remove('expires');
http_response_code(200);
$pid=$_GET['id'];
if(!is_numeric($pid))return;
?>
<?php query_posts('p='. $pid)?>
<?php while (have_posts()) : the_post(); ?>
{
"title":"<?php echo  the_title(); ?>",
"body":"<?php
$sr = str_replace( array( "\r\n","&emsp;", "\r", "\n", "\\","[","	", "]"), "" , str_replace( "\"", "'", strip_tags( get_the_content_feed('rss2'),'<img><br><p><h1><h2><h3><h4><li><strong><table><td><tr><th><ul><span><em><div><code><a><b><blockquote><del><col><label><q><tbody>') ) );
$sr = str_replace("<code class='","<code class='codei ",$sr);
$sr = str_replace("<code>","<code class='code'>",$sr);
$sr = str_replace("<img class='","<img class='imgi ",$sr);
$sr = str_replace("<img ","<img class='imgi' ",$sr);
$sr = str_replace("<p>","<p class='p'>",$sr);
$sr = str_replace("</p><p","<p",$sr);
echo $sr;?>"
}
<?php endwhile ?>