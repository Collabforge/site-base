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
    <?php $picture = theme('user_picture', array('account' => $user));
    print($picture);
   ?>
 </div>
  <div class="btn-group" id="navigation-profile-details">
    <button class="btn dropdown-toggle" data-toggle="dropdown"><?php print $user->realname; ?></button>
    <button class="btn dropdown-toggle" data-toggle="dropdown">
      <span class="caret"></span>
    </button>
    <ul class="dropdown-menu">
    <li class="first leaf active-trail" style="list-style:none;"><a href="/" style="color:#ed6a26;"><i class="icon-rss">&nbsp;</i>  Activity Feed</a></li>
    <li class="first leaf" style="list-style:none;"><a href="/user" ><i class="icon-user">&nbsp;</i> My Profile</a></li>
    <li class="first leaf" style="list-style:none;"><a href="/your-topics" ><i class="icon-list">&nbsp;</i> My Topics</a></li>
    <li class="first leaf" style="list-style:none;"><a href="/profile/hubs" ><i class="icon-globe">&nbsp;</i> My Hubs</a></li>
    <li class="first leaf" style="list-style:none;"><a href="/user/<?php print $user->uid; ?>/edit" style="color:#666;"><i class="icon-cog">&nbsp;</i>  Account settings</a></li>
    <li class="last leaf" style="list-style:none;"><a href="/user/logout" title="icon-signout" style="color:#666;"><i class="icon-signout">&nbsp;</i> Log out</a></li>
    </ul>
  </div>
</div>
