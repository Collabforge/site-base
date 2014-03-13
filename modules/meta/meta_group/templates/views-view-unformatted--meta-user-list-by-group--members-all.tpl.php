<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */



$groups = array(
	'member' => t('Members')
	, 'coowner' => t('Co-owners')
);

$aRows = array();

foreach ($view->result as $id=>$_row) {
	/*
	A sample:
	stdClass Object
	(
		[users_name] => user a test
		[uid] => 202
		[users_picture] => 1586
		[users_mail] => user.a@test.com
		[profile_users_pid] => 89
		[og_membership_users_id] => 140
		[og_membership_users_gid] => 249
		[og_membership_users_created] => 1394597272
		[field_data_field_business_position_profile2_entity_type] => profile2
		[field_data_field_organisation_ref_profile2_entity_type] => profile2
	)
	*/
	$aRows[$id]['content'] = $rows[$id];
	$aRows[$id]['uid'] = $_row->uid;
	$aRows[$id]['gid'] = $_row->og_membership_users_gid;
	$aRows[$id]['membership_id'] = $_row->og_membership_users_id;
	//entity_load('og_membership', array($_row->og_membership_users_id));

}

$rows_grouped = array();
foreach ($aRows as $id => $row) {
	$group = 'member';
	if (meta_group_is_owner($row['gid'], $row['uid'])) {
		// we do not include the owner in the members listing
		continue;
	}
	if (meta_group_is_coowner($row['gid'], $row['uid'])) {
		$group = 'coowner';
	}
	$rows_grouped[$group][$id] = $row;
}

foreach ($rows_grouped as $group => $aRows) {
	?>
	<div class="ui-members-group">
		<h2 class="ui-membership-title"><?php echo $groups[$group]; ?></h2>
		<?php
		foreach ($aRows as $id => $row) {
			?>
			<div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
				<?php print $row['content']; ?>
			</div>
			<?php
		}
		?>		
	</div>
	<?php
}


