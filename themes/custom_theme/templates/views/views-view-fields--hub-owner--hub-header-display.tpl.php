<?php

/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */

//x($row->nid);
?>

<div class="row-fluid">
	<div class="span12">
		<!-- Breadcrumbs -->
		<a href="/hubs"><?php echo t('Hubs'); ?></a> <i class="icon-angle-right"></i> <span><?php echo $fields['title']->raw; ?></span>  
	</div>
</div>
<div class="row-fluid">
	<div class="span9 ui-header-img-container">
		<div class="ui-header-content" >
			<!-- Hub title & info -->
			<h1>
				<span class="ui-inline"><i class="icon-group"></i>&nbsp;<?php echo $fields['title']->content; ?>&nbsp;</span>
				<span class="label ui-inline-label"><?php echo $fields['meta_og_state_state']->content; ?></span>
				<?php echo meta_og_state_is_open($fields['nid']->raw) ?  '<span class="label label-info ui-inline-label"> <i class="icon-unlock-alt"></i> '.t('Open Hub').' </span>' : '<span class="label ui-inline-label">  <i class="icon-lock"></i> '.t('Closed Hub').' </span>'; ?> 
			</h1> 
			<span class="ui-header-description"><?php echo $fields['field_tag_line']->content; ?></span>
		</div>

		<div class="ui-hub-feature-img">
			<!-- Hub img -->
		    <span><?php echo $fields['field_featured_hub_image']->content; ?></span>
		</div>

	</div>
	<div class="span3">
		<!-- Organisation image -->
		<ul class="thumbnails ui-hubs-organisation-thumbnail">
		  <li class="span12">
		    <div class="thumbnail">
		      <span class="ui-org-img"><?php echo $fields['field_organisation_image']->content; ?></span>
		      <div class="row-fluid">
				<div class="span3">
					<div class="user-picture-small"><?php echo $fields['picture']->content; ?>  </div>
				</div>
				<div class="span9">
					<h5>Hosted by <span class="ui-inline"><?php echo $fields['name']->content;?></span></h5>
        			<span class="ui-inline"><?php echo $fields['field_business_position']->content;?></span> at <span class="ui-inline"><?php echo $fields['field_organisation_ref']->content;?> </span>
				</div>
			  </div>

		    </div>
		  </li>
		</ul>			
	</div>

</div>

          