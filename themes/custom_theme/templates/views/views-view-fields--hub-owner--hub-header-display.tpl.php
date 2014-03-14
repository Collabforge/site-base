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
		<a href="/hubs">Hubs</a> <i class="icon-angle-right"></i> <span><?php echo $fields['title']->raw; ?></span>  
	</div>
</div>
<div class="row-fluid">
	<div class="span9" style="position:relative;">

		<div style="z-index:10000; width:100%; height:35%; position:absolute; left:0; bottom:1.5em; background: rgba(0, 0, 0, 0.5); color:#fff; margin:5px; padding:20px;">
			<!-- Hub title -->
			<h1><?php echo $fields['title']->content; ?></h1> 
			<span class="label ui-inline-label"><?php echo $fields['meta_og_state_state']->content; ?></span>
			<?php echo meta_og_state_is_open($fields['nid']->raw) ?  '<span class="label label-info ui-inline-label"> <i class="icon-unlock-alt"></i> Open Hub </span>' : '<span class="label ui-inline-label">  <i class="icon-lock"></i> Closed Hub </span>'; ?> 
			<p><?php echo $fields['field_tag_line']->content; ?> </p>
		</div>

		<ul class="thumbnails">
		  <li class="span12">
		    <div class="thumbnail">
		    	<span><?php echo $fields['field_featured_hub_image']->content; ?></span>
		    </div>
		  </li>
		</ul>

	</div>


	<!--
	<div class="span4">
	<!-- Hub featured image 
	<ul class="thumbnails">
		  <li class="span12">
		    <div class="thumbnail">
		      <span><?php echo $fields['field_featured_hub_image']->content; ?></span>
		    </div>
		  </li>
		</ul>
	</div>

	<div class="span5 ui-hub-info">
	    <!-- Hub title 
		<h1><?php echo $fields['title']->content; ?></h1> 
		<span class="label ui-inline-label"><?php echo $fields['meta_og_state_state']->content; ?></span>
		<?php echo meta_og_state_is_open($fields['nid']->raw) ?  '<span class="label label-info ui-inline-label"> <i class="icon-unlock-alt"></i> Open Hub </span>' : '<span class="label ui-inline-label">  <i class="icon-lock"></i> Closed Hub </span>'; ?> 
		
		<!-- These labels need logic - reimplement when time allows:
          <span class="label ui-inline-label label-success"> <i class="icon-cog"></i> You are hub owner </span>
          <span class="label ui-inline-label label-success"> <i class="icon-cog"></i> You are hub co-owner </span>
          <span class="label ui-inline-label label-warning"> <i class="icon-flag-alt"></i> You are a hub member </span>
       


		<p><?php echo $fields['field_tag_line']->content; ?> </p>

	</div>
	 -->

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

          