<?php
  $fields = reset($user_profile['profile_profile']['view']['profile2']);
  $full_name = $user_profile['field_first_name']['#object']->name;
  $account = $elements['#account'];
  $is_contactable = _contact_personal_tab_access($account);
  global $base_url;
?>

<div class="user-profile">
	<div class="span2 first">
		<div class="profile-page-user-picture">
			<?php print render ($user_profile['user_picture']); ?>
		</div>
	</div>
	<div class="span7">
		<div class="profile-page-title">    
			<p><?php /* temp removed print($full_name); */ ?></p>
		</div>
	</div>
	<div class="span3 last">
		<div class="profile-page-edit">
			<?php
			if ($user->uid == $account->uid) { ?>
			  <a href="<?php echo "$base_url/user/$account->uid/edit/profile"; ?>"><i class="icon-edit"></i> Edit your profile</a>
			<?php } ?>
		</div>
	</div>
	<br>
	
	<div class="span7 first">
		<div class="profile-page-user-position">
			<?php print render($fields['field_business_position']); ?>
		</div>
		<br>
		<div class="profile-page-user-bio">
			<?php print render($fields['field_personal_bio']); ?>
		</div>
    <br>
		<div class="profile-page-user-organisation">
			<?php print render($fields['field_organisation_ref']); ?>
		</div>
	</div>

	<div class="span3 last">
		<div class="profile-page-user-expertise">
			<?php print render ($fields['field_areas_of_expertise']); ?>
		</div>
		<br>
		<div class="profile-page-user-external">
			<?php print render ($fields['field_external_link']); if(isset($fields['field_external_link'])) { echo "<br>"; } ?>
        </div>
        <?php if ($is_contactable): ?>
        	<br/>
          <div class="profile-page-user-contact">
            <div class="field-label">
              <b>Send <?php print($full_name); ?> an email</b>
            </div>
            <div class="field-item">
              <a href="<?php print "$base_url/user/$account->uid/contact"; ?>">Send a message</a>
            </div>
        </div>
        <?php endif; ?>
	</div>
</div>

