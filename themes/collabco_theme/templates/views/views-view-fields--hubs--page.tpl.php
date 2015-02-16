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
<?php  $gid = $fields['nid']->raw ?> 
<div class="index_item row-fluid">
  <div class="span2"> 
    <?php if (meta_og_state_is_open($gid) || og_is_member('node', $gid)) {
    echo $fields['field_featured_hub_image']->content; 
    }
    else { ?>
      <div class="featured-image no-image"><img src="/profiles/collabco/themes/collabco_theme/images/placeholder_square.jpg"></div>
    <?php } ?>
  </div>
  <div class="span10 topic_item">
    <div class="hub-header">
      <div class="row-fluid">
        <div class="span9">
          <h3>
              <?php if (meta_og_state_is_open($gid) || og_is_member('node', $gid)) {
               echo $fields['title']->content; 
              }
               else {
                 echo $fields['title']->raw;  
               }
              ?>
          </h3>
          <div class="article_text"><?php echo $fields['field_tag_line']->content; ?></div>
        </div>
        <div class="span3">
          <?php echo meta_og_state_is_open($gid) ? '<span class="label label-info"> <i class="icon-unlock-alt"></i> '. t('Open Hub') . ' </span>' : '<span class="label">  <i class="icon-lock"></i> '.t('Closed Hub').' </span>'; ?>
          
            <!-- These labels need logic - reimplement when time allows:
              <span class="label label-success"> <i class="icon-cog"></i> You are hub owner </span>
              <span class="label label-success"> <i class="icon-cog"></i> You are hub co-owner </span>
              <span class="label label-warning"> <i class="icon-flag-alt"></i> You are a hub member </span>
            -->

        </div>
      </div>
    </div>
    <div class="article_host row-fluid"> 
      
      <?php
      if (meta_og_state_is_open($gid) or og_is_member('node', $gid)) {

        ?>
        <div class="span2"> 
          <?php echo $fields['field_organisation_image'] ->content;?> 
        </div>
        <div class="span8"> 
          <h5>Hosted by <span class="ui-inline"><?php echo $fields['name']->content;?></span></h5>
          <span class="ui-inline"><?php echo $fields['field_business_position']->content;?></span> at <span class="ui-inline"><?php echo $fields['field_organisation_ref']->content;?> </span>
        </div>
        <div class="span2"> 
          <p>
            <i class="icon-group"></i>
            <?php
            $members_count = hub_get_members_count($row->nid);
            echo format_plural($members_count, '1 Member', '@count Members');
            ?>
          </p>
        </div>
        <?php

      } else {
        // @TODO: better to be done in preprocess functions


        if (_meta_group_is_pending_member($gid)) {
          // So the user is already requested for a membership but yet to be approved or rejected
          
          ?>
          <span class="label"><h3>&nbsp; <i class="icon-info-sign"></i> Membership requested (approval pending) &nbsp;</h3></span>
          <?php

        } else {
          // The user is neither a member nor have requested for a membership

          $url = sprintf('group/node/%d/subscribe', $gid);
          ?>
          <a href="<?php echo $url; ?>" class="btn btn-warning"><i class="icon-plus"></i> Request membership</a> 

          <?php
        
        }
      }
      ?>
       
    </div>
  </div>
</div>

