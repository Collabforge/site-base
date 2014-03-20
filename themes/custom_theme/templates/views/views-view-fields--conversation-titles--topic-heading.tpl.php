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

<div class="topic-header">
	<div class="container">
		<div class="content">
			<div class="row-fluid">
				<div class="span12">
					<!-- Breadcrumbs -->
					<a href="/topics">Topics</a> <i class="icon-angle-right"></i> <span><?php echo $fields['title']->raw; ?></span>  
				</div>
			</div>
			<div class="row-fluid">
				<div class="span9 ui-header-img-container">
					<div class="ui-header-content" >
						<!-- Topic title & info -->
						<h1>
							<span class="ui-inline"><i class="icon-comments-alt"></i>&nbsp;<?php echo $fields['title']->content; ?>&nbsp;</span>			
						</h1> 
						
					</div>

					<div class="ui-hub-feature-img">
						<!-- Topic feature img -->
					    <span><?php echo $fields['field_featured_image']->content; ?></span>
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

					<!-- If attached to hub -->
					<?php $hub_not_attached = '<div class="field-content"></div>'; 
					if ($fields['og_group_ref']->content != $hub_not_attached) { 

						<ul class="thumbnails ui-hubs-organisation-thumbnail">
						  <li class="span12">
						    <div class="thumbnail">
						      <span class="ui-org-img"><?php echo $fields['field_featured_hub_image']->content; ?></span>
						      <div class="row-fluid">
								<div class="span12">
									<h5>Belongs to hub: <span class="ui-inline"><?php echo $fields['og_group_ref']->content;?></span></h5>
				        			<!-- needs labels for open / closed and tagline -->
								</div>
							  </div>

						    </div>
						  </li>
						</ul>	

					<?php 
							echo $fields['field_featured_hub_image']->content;
							echo $fields['meta_group_access']->raw ? 'Open' : 'Closed';
							echo $fields['field_tag_line']->content;
							echo $fields['og_group_ref']->content;  
						}
					?>

				</div>

			</div>
		</div>
	</div>
</div>




