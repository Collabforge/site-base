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
<?php
  global $base_path;
  $library_type = ($fields['sticky']->raw == 1) ? 'sticky' : 'non-sticky';
?>

<div class="index_item library-file row-fluid <?php echo $library_type; ?>">
  <div class="span12">
    <a href='<?php echo $base_path . "node/$row->nid"; ?>'
       <i class="icon-file"></i>
       <h2><?php echo $row->node_title; ?></h2>
       <p><?php echo $fields['body']->content;?></p>
    </a>
  </div>
</div>

<!-- OLD VERSION
<div class=index_item row-fluid <?php echo $library_type;?> >
  <div class="span2">
    <?php echo $fields['field_featured_ko_image'] ->content;?> 
  </div>
  <div class="span10 topic_item">
    <h3><?php echo $fields['title'] ->content;?> </h3>
    <div class="article_text"><?php echo $fields['body'] ->content;?> </div>
    <div class="article_host">
      <div class="topic_feature_body"><?php echo $fields['sticky'] ->content;?> </div>
      <table class="user_block">
        <tr>
          <td>
            <div class="user-picture-small"><?php echo $fields['picture'] ->content;?> </div>
          </td>
          <td>
            <p>
              Hosted by <span class="article_host_name"><a href="#"><?php echo $fields['name'] ->content;?> </a></span><br />
              <?php echo $fields['field_business_position'] ->content;?>  &#64; <?php echo $fields['field_organisation_ref'] ->content;?> 
            </p>
          </td>
        </tr>
      </table>
    </div>
  </div>
</div>

-->