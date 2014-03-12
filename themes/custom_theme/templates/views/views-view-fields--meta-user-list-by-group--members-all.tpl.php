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


?>
 
<div class="row-fluid">
  <div class="span12">
      <div class="span3">
        <div class="user-picture-small"><?php echo $fields['picture']->content; ?>  </div>
      </div>
      <div class="span9">
        <h5><span class="ui-inline"><?php echo $fields['name']->content;?></span></h5>
        <span class="ui-inline"><strong><?php echo $fields['field_business_position']->content;?></strong></span><br>
        <span class="ui-inline"><?php echo $fields['field_organisation_ref']->content;?> </span><br>
        <a href="/group/node/<?php echo $fields['gid']->raw ?>/admin/people/delete-membership/<?php echo $fields['id'] ->raw;?>"><i class="icon-remove"></i></a>
      </div>
  </div>
</div>







   