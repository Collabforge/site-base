<?php
/**
 * @file
 * Default theme implementation for PCP block
 *
 * Available variables:
 *  $uid: Current user ID.
 *  $current_percent: From 0 to 100% of how much the profile is complete.
 *  $next_percent: The percent if the user filled the next field.
 *  $completed: How many fields the user has filled.
 *  $incomplete: The inverse of $completed, how many empty fields left.
 *  $total: Total number of fields in profile.
 *  $nextfield_title: The name of the suggested next field to fill (human readable name).
 *  $nextfield_name: The name of the suggested next field to fill (machine name).
 *  $nextfield_id: The id of the $nextfield.
 *
 * @see template_preprocess_pcp_profile_percent_complete()
 */
?>

<div id="user_details" class="row-fluid">
  <div class="navigation-profile-picture" >
    <?php
      global $base_url;
      $picture = theme('user_picture', array('account' => $user));
      echo $picture;
    ?>
  </div>
  <div class="btn-group" id="navigation-profile-details">
    <button class="btn dropdown-toggle" data-toggle="dropdown">
      <?php print $user->realname; 
      ?>
    </button>
    <button class="btn dropdown-toggle" data-toggle="dropdown">
      <span class="caret"></span>
    </button>
    <ul class="dropdown-menu user-nav">
      <li class="first leaf user-nav-activity-feed" ><a href="<?php echo "$base_url/dashboard"; ?>"><i class="icon-rss">&nbsp;</i> <?php echo t('Activity Feed'); ?></a></li>
      <li class="first leaf user-nav-my-profile" ><a href="<?php echo "$base_url/user"; ?>"><i class="icon-user">&nbsp;</i> <?php echo t('My Profile'); ?></a></li>
      <li class="first leaf user-nav-my-topics" ><a href="<?php echo "$base_url/your-topics"; ?>"><i class="icon-list">&nbsp;</i> <?php echo t('My Topics'); ?></a></li>
      <li class="first leaf user-nav-my-hubs" ><a href="<?php echo "$base_url/your-hubs" ; ?>"><i class="icon-globe">&nbsp;</i> <?php echo t('My Hubs'); ?></a></li>
      <li class="first leaf user-nav-my-library" ><a href="<?php echo "$base_url/my-library"; ?>"><i class="icon-folder-close-alt">&nbsp;</i> <?php echo t('My Library'); ?></a></li>
      <li class="first leaf user-nav-account-settings" ><a href="<?php echo "$base_url/user/$user->uid/edit"; ?>" style="color:#666;"><i class="icon-cog">&nbsp;</i> <?php echo t('Account settings'); ?></a></li>
      <li class="last leaf user-nav-logout" ><a href="<?php echo "$base_url/user/logout"; ?>" title="icon-signout" style="color:#666;"><i class="icon-signout">&nbsp;</i> <?php echo t('Log out'); ?></a></li>
    </ul>
  </div>
</div>
