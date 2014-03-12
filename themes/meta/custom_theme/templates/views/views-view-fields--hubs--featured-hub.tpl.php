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
<div class="row-fluid">
  <div class="span5 topic_feature_left">
    <div class="topic_feature_image"><?php echo $fields['field_featured_hub_image']->content; ?></div>
    <div class="topic_feature_title">Latest</div>
  </div>
  <div class="span7 topic_feature_right">
    <div class="hub-header">
      <div class="row-fluid">
        <div class="span8">
        <h3><?php if (meta_og_state_is_open($gid) || og_is_member('node', $gid)) {
             echo $fields['title']->content; 
            }
             else {
               echo $fields['title']->raw;  
             }
            ?>
           </h3>
           <div class="article_text"><?php echo $fields['field_tag_line']->content; ?></div>
        </div>
        <div class="span4">
          <?php echo meta_og_state_is_open($gid) ?  '<span class="label label-info"> <i class="icon-unlock-alt"></i> Open Hub </span>' : '<span class="label">  <i class="icon-lock"></i> Closed Hub </span>'; ?>
          <!--RESHMA this needs logic : -->
          <span class="label label-success"> <i class="icon-cog"></i> You are hub owner </span>
          <span class="label label-success"> <i class="icon-cog"></i> You are hub co-owner </span>
          <span class="label label-warning"> <i class="icon-flag-alt"></i> You are a hub member </span>
        </div>
      </div>
    </div>
    <div class="article_host row-fluid">
        <?php if (meta_og_state_is_open($gid) || og_is_member('node', $gid)) {  ?>
        
        <div class="span2"> 
          <?php echo $fields['field_organisation_image'] ->content;?> 
        </div>
        <div class="span7"> 
            <h5>Hosted by <span class="ui-inline"><?php echo $fields['name']->content;?></span></h5>
            <span class="ui-inline"><?php echo $fields['field_business_position']->content;?></span> at <span class="ui-inline"><?php echo $fields['field_organisation_ref']->content;?> </span>
        </div>
        <div class="span3"> 
  
            <p><i class="icon-group"></i> 

              <?php echo hub_get_members_count($row->nid);  
                
                if (hub_get_members_count($row->nid)=="1")
                  { 
                    echo " Member";
                  } else {
                    echo " Members";
                  }
              ?>

            </p>
        </div>
         <?php } else { ?>
        <a href='/group/node/<?php echo $gid ?>/subscribe' class="button orangebutton">Request membership</a>  
      <?php  }  ?>
    </div>
  </div>
</div>

