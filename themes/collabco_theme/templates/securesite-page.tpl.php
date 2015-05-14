<?php

/**
 * @file
 * Template for Secure Site pages.
 *
 * @see template_preprocess_page()
 */
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language ?>" lang="<?php print $language->language ?>" dir="<?php print $language->dir ?>">

<head>
<title><?php print $head_title ?></title>
<?php print $head ?>
<link type="text/css" rel="stylesheet" media="all" href="<?php print $base_path . drupal_get_path('theme', 'openhub') .'/css/securesite.css' ?>" />
<?php print $scripts ?>
</head>
<body>
<div id="splash-logo"><img class="center" src="<?php print $base_path . drupal_get_path('theme', 'openhub'). '/IIN_logo_final.png' ?>" /></div>
<?php print $messages ?>
<?php print $content ?>
<form><div>
<h1>Create Account</h1>
<p>Create an account <a href="<?php print $base_url ?>/user/register">here</a>.</p>
</div>
</form>
</body>
</html>
